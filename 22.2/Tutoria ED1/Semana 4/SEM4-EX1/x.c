void ordenaUpas(TADupa *upas, int n){
    
    TADupa maior;

    for(int verifyGO = 0; verifyGO < n - 1; verifyGO++){

        maior.Emergencia = -1;
        int coordenada = 0;

        for(int index = verifyGO; index < n; index++){
            
            if(upas[index].Emergencia > maior.Emergencia){
                maior = upas[index];
                coordenada = index;
            }
            else if (upas[index].Emergencia == maior.Emergencia){
                if (maior.Urgencia < upas[index].Urgencia){
                    maior = upas[index];
                    coordenada = index;
                }
                else if ((maior.Urgencia == upas[index].Urgencia) && (maior.semUrgencia < upas[index].semUrgencia)){
                    maior = upas[index];
                    coordenada = index;
                }
                else if ((maior.Urgencia == upas[index].Urgencia) && (maior.semUrgencia == upas[index].semUrgencia) && (maior.Medicos > upas[index].Medicos)){
                    maior = upas[index];
                    coordenada = index;
                }
            }
        }

        //implementar parte que passa o valor do maior para o indice de inicio, ou seja, para o indice verifyGO.

        TADupa aux;
        aux = maior;
        upas[coordenada] = upas[verifyGO];
        upas[verifyGO] = aux;    
    } 
}