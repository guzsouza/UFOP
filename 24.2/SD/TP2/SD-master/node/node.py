import os
import time
import threading
import requests
from flask import Flask, request, jsonify

app = Flask(__name__)

# ID do nó atual, passado como variável de ambiente
NODE_ID = int(os.getenv('NODE_ID', 1))

# Lista de todos os nós no cluster, exceto este nó
NODES = [f'http://node{i}:5000' for i in range(1, 6) if i != NODE_ID]

# Controle da zona crítica
estado = "livre"  # Pode ser "livre", "esperando" ou "na_zona_critica"
timestamp = None
respostas_ok = 0
mutex = threading.Lock()


def enviar_pedido_para_nos():
    """Envia uma solicitação para os outros nós pedindo acesso à zona crítica"""
    global timestamp, respostas_ok, estado

    timestamp = time.time()
    estado = "esperando"
    respostas_ok = 0

    for node in NODES:
        try:
            response = requests.post(f"{node}/check", json={"timestamp": timestamp, "node_id": NODE_ID})
            if response.json().get("response") == "OK":
                respostas_ok += 1
        except:
            print(f"Erro ao conectar com {node}")

    if respostas_ok == len(NODES):  # Se todos responderam OK, podemos entrar na zona crítica
        estado = "na_zona_critica"
        print(f"Nó {NODE_ID} entrou na zona crítica.")


@app.route("/request_access", methods=["POST"])
def request_access():
    """Recebe requisição do cliente e inicia o processo de verificação"""
    global estado

    if estado == "livre":
        enviar_pedido_para_nos()
        if estado == "na_zona_critica":
            return jsonify({"status": "Acesso garantido à zona crítica"})
        else:
            return jsonify({"status": "Aguardando autorização"})
    else:
        return jsonify({"status": "Zona crítica ocupada"})


@app.route("/check", methods=["POST"])
def check_access():
    """Os nós verificam se podem permitir o acesso"""
    global estado, timestamp
    data = request.json
    other_timestamp = data["timestamp"]
    other_node_id = data["node_id"]

    if estado == "livre" or (estado == "esperando" and other_timestamp < timestamp):
        return jsonify({"response": "OK"})

    return jsonify({"response": "WAIT"})


@app.route("/release", methods=["POST"])
def release():
    """Libera a zona crítica"""
    global estado
    estado = "livre"

    for node in NODES:
        requests.post(f"{node}/release_notify", json={"node_id": NODE_ID})

    return jsonify({"message": "Zona crítica liberada"})


@app.route("/release_notify", methods=["POST"])
def release_notify():
    """Recebe a notificação de liberação de outro nó"""
    global estado
    estado = "livre"
    return jsonify({"message": "Notificação recebida"})


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
