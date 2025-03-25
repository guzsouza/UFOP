import os
import random
import time
import requests
from flask import Flask, request, jsonify

app = Flask(__name__)

client_id = int(os.getenv('CLIENT_ID', 1))
base_url = f'http://node{client_id}:5000'


def request_access():
    """Solicita acesso ao nó e espera até que a permissão seja concedida"""
    print(f"Cliente {client_id} solicitando acesso ao nó {client_id}.", flush=True)

    url = f'{base_url}/request_access'
    while True:
        try:
            response = requests.post(url, json={'client_id': client_id})
            data = response.json()
            print(f"Cliente {client_id} recebeu resposta: {data}", flush=True)

            if data.get("status") == "Acesso garantido à zona crítica":
                print(f"Cliente {client_id} está na zona crítica.", flush=True)
                time.sleep(random.uniform(1, 3))  # Simula o uso da zona crítica
                requests.post(f'{base_url}/release')
                break

            time.sleep(1)  # Aguarda antes de tentar novamente
        except requests.exceptions.RequestException as e:
            print(f"Erro ao conectar ao nó: {e}", flush=True)
            break


if __name__ == '__main__':
    print(f"Cliente {client_id} iniciado.", flush=True)
    for _ in range(3):
        request_access()
