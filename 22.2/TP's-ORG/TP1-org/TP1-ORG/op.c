#include "op.h"
#include <stdio.h>
#include <stdlib.h>

//soma
float sum(float parcela1, float parcela2){
    return parcela1+parcela2;
}

//subtração
float sub(float minuendo, float subtraendo){
    return minuendo-subtraendo;
}

//multiplicação
float mult(float fator1, float fator2){
    
    float result = 0;
    int neg=0;

    //if ((fator1<1 && fator2>=0)||(fator2<1 && fator1>=0)||(fator2>-1 && fator1<=0)||(fator2>-1 && fator1<=0)||fator1==0||fator2==0)
       // return 0;
    
    if ((fator1<0 && fator2>0) || (fator1>0 && fator2<0))
        neg=1;
  
    fator1 = (fator1<0)? -fator1 : fator1;
    fator2 = (fator2<0)? -fator2 : fator2;

    for (int i = 0; i < fator2; i++)
        result = sum(result, fator1);

    if(neg)
      result *= -1;

    return result;
}

//divisão
float divi(float dividendo, float divisor){

    float result = 0;
    int neg=0;

    //caso algum dos termos seja zero, o resultado será 0
    if (divisor==0||dividendo==0)
        return 0;
    
    //caso um dos termos seja negativo e o outro não, o resultado sempre será negativo
    if ((dividendo<0 && divisor>0) || (dividendo>0 && divisor<0))
        neg=1;
    
    dividendo = (dividendo<0)? -dividendo : dividendo;
    divisor = (divisor<0)? -divisor : divisor;
    
    int auxdiv = divisor;

    while(dividendo >= divisor){
        divisor+=auxdiv;
        result++;
    }

    if(neg)
      result *= -1;

    return result;
}

//fatorial
float fact(float fator){
  float result = 1;

  if(fator>10)
    return 1;
  
  if(fator<0)
    return 0;
  
  if(fator==0 || fator==1)
    return 1;

   while (fator > 1) {
      result *= fator;
      fator--;
    }

  return result;
}

//exponenciação
float expo(float base, float expoente){
  float result=1;

  if(expoente>1000)
    return 1;

  if((expoente<0 && base<0) || base==0 || expoente<0)
    return 0;

  if(expoente==0)
    return 1;

  for(int i = 0; i < expoente; i++){
    result = mult(base, result);
  }
  
  if((base<0 && result>0))
    result= mult(result,-1);

  return result;
}

//fibonacci
float fibonacci(int elemento){
  float backfibo=1, fibo=1, result=0;

  if(elemento>=64||elemento==1||elemento==2)
    return 1;
  
  if(elemento<=0)
    return 0;

  for(int i=0; i<elemento-2; i++){
    result = sum(fibo,backfibo);
    backfibo = fibo;
    fibo=result;
  }
  return result;  
}

//raiz quadrada
float raiz(float valor){

  int raizaux = valor;
  float valormax=valor;
  float result=0;
  float valorprox;

  if (valor>1000)
    return 10;
  if(valor<=0)
    return 0;
  if(valor<=1.5)
    return 1;
  if(valor<=2)
    return 1.4;
  if(valor<=3)
    return 1.5;
  
  for(int i=2;;i++){
    raizaux=divi(valor,i); 

    if(expo(raizaux,2)==valor)
      return raizaux;
    else if(expo(raizaux,2)<valor){ 
        for(int i=raizaux; i<=valormax; i++){
          result= expo(i,2);
          if(result>=valor){
            valorprox=valorprox-valor;
            result=result-valor;
            result = (result<0)? -result : result;
            valorprox = (valorprox<0)? -valorprox : valorprox;
            if(valorprox < result)
              return i-1;
            return i;
          }
          valorprox=result;
        }
    }
    else 
      valormax=raizaux;
  }
}