#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>


typedef struct cuba{
   char refri;
   float qtdeGelo, qtdeRun, qtdeRefri;
   float runForte, runSuave, runFraco;
   float gpGelo;
   float refriFraco, refriSuave, refriForte;
   float fracoMax, suaveMax, forteMax;
   float gpCuba;
   float preco;
   int paladar[3];
}Bebida;




float calcularLineares(float x1, float x2, float x, int type) {
  if(type == 1){
    // Linear Crescente
    return (x-x1)/(x2-x1);    
  }else {
    // Linear Decescente
    return (x2-x)/(x2-x1);
  }
}

void fuzzification(Bebida *c){ // Realiza o processo de fuzzificação
   
   if( c->refri == 'C' || c->refri == 'c' ){
      /************* Coca Forte ******************/
        if( c->qtdeRefri < 50 || c->qtdeRefri > 54 ){
            c->refriForte = 0;    // Segundo o gráfico, se for menor que 50 ou maior que 54 não é forte
      }   
        if( c->qtdeRefri >= 50 && c->qtdeRefri < 52 ) {
            c->refriForte = 1;    // Segundo o gráfico, se estiver entre 50 e 52 o grau de pertinencia a forte é igual a 1
      }
        if( c->qtdeRefri >= 52 && c->qtdeRefri <= 54 ) {
            c->refriForte = calcularLineares(52, 54, c->qtdeRefri, 2);  // Linear Decrescente, se x for maior ou igual a 52 e menor ou igual a 54 então (x2-x)/(x2-x1)
      }
                             
      /************ Coca Suave *****************/
      if( c->qtdeRefri < 52 || c->qtdeRefri > 58 ){
         c->refriSuave = 0;     // Se for maior que 52 ou maior que 58 não é suave
    }
      if( c->qtdeRefri >= 52 && c->qtdeRefri < 54 ){
          c->refriSuave = calcularLineares(52, 54, c->qtdeRefri, 1);
      //c->refriSuave = ( c->qtdeRefri - 52 ) / (54 - 52);    // Linear Crescente, se for maior ou igual a 52 ou menor igual a 54 então (x-x1)/(x2-x1)
    }      
      if( c->qtdeRefri >= 54 && c->qtdeRefri <= 56 ){
            c->refriSuave = 1;    // se for maior ou igual 54 e menor igual 56 então pertinencia 1 para suave
    }
      if( c->qtdeRefri > 56 && c->qtdeRefri <= 58 ) {
            c->refriSuave = calcularLineares(56, 58, c->qtdeRefri, 2); // Linear Decrescente, se x for maior ou igual a 56 e menor ou igual a 58 então (x2-x)/(x2-x1)
    }    
      
     /************ Coca Fraca *****************/
      if( c->qtdeRefri < 56 || c->qtdeRefri > 60 ){
         c->refriFraco = 0;   // Se for menor uqe 56  ou maior que 60 pertinencia 0 para fraco
    }
      if( c->qtdeRefri >= 56 && c->qtdeRefri < 58 ){
          c->refriFraco = calcularLineares(56, 58, c->qtdeRefri, 1);  // Linear Crescente, se x for maior ou igual 56 e menor ou igual 58 então (x-x1/(x2-x1)
     }
      if( c->qtdeRefri >= 58 && c->qtdeRefri <= 60 ){
          c->refriFraco = 1;    // Se for maior ou igual 58 e menor ou igual 60 então pertinencia 1 para fraco
      }                        
   }
    
    /************** Pepsi ***************/
   if(c->refri == 'p' || c->refri == 'P'){
      /************** Pepsi Forte ***************/
      if( c->qtdeRefri < 60 || c->qtdeRefri > 64 ){
         c->refriForte = 0;   // se for menor que 60 ou maior que 64 grau de pertinencia forte é igual a 0
    }
      if( c->qtdeRefri >= 60 && c->qtdeRefri < 62 ){
          c->refriForte = 1;  // se for maior ou igual a 60 e menor ou igual 62 então grau de pertinencia forte é igual a 1
    }
      if( c->qtdeRefri >= 62 && c->qtdeRefri <= 64 ){
          c->refriForte = calcularLineares(62, 64, c->qtdeRefri, 2);    // Linear Descrescente, se for maior ou igual 62 e menor ou igual 64 então (x2-x)/(x2-x1)
    }
      
      /************** Pepsi Suave ***************/
      if( c->qtdeRefri < 62 || c->qtdeRefri > 68 ){
          c->refriSuave = 0;  // Se fir nebir qye 62 iy nauir qye 68 então grau de pertinencia suave é igual a 0
    }
      if( c->qtdeRefri >= 62 && c->qtdeRefri < 64 ){
          c->refriSuave = calcularLineares(62, 64, c->qtdeRefri, 1);     // Se for maior ou igual 62 e menor que 64 Linear crescente, então, (x-x1)/(x2-x1)
    }
      if( c->qtdeRefri >= 64 && c->qtdeRefri < 66 ){
          c->refriSuave = 1;  // Se for maior ou igual 64  e menor ou igual 66 então grau de pertinencia a suave é igual a 1
    }
      if( c->qtdeRefri >= 66 && c->qtdeRefri <= 68 ){
          c->refriSuave = calcularLineares(66, 68, c->qtdeRefri, 2);  // Linear Descrescente, se for maior ou igual 66 e menor ou igual 68 então, (x2-x)/(x2-x1)
    }
        
      /************** Pepsi Fraca ***************/
      if( c->qtdeRefri < 66 || c->qtdeRefri > 70 ){
          c->refriFraco = 0;  //Se for menor que 66 ou maior que 70 então grau de pertinencia a fraco é igual a 0
    }
      if( c->qtdeRefri >= 66 && c->qtdeRefri < 68 ){
          c->refriFraco = calcularLineares(66, 68, c->qtdeRefri, 1);    //Se for maior ou igual 66 e menor que 68, então Linear crescente, (x-x1)/(x2-x1)
    }
      if( c->qtdeRefri >= 68 && c->qtdeRefri <= 70 ){
          c->refriFraco = 1;    // se for maior ou igual que 68 e menor ou igual 70 então grau de pertinencia fraco igual a 1
    }
   }
   
   /************ Run **********/
   /************** Run Fraco ***************/
   if( c->qtdeRun < 10 || c->qtdeRun > 20 ) {
       c->runFraco = 0;   // Se for menor do que 10 ou maior do que 20 então pgrau de pertinencia igual a 0
   }
   if( c->qtdeRun >= 10 && c->qtdeRun < 15 ) {
       c->runFraco = 1;   // Se for maior ou igual a 10 e menor do que 15 então, grau de pertinencia igual a 1
   }
   if( c->qtdeRun >= 15 && c->qtdeRun <= 20 ) {
     c->runFraco = calcularLineares(15, 20, c->qtdeRun, 2);    // Se for maior ou iugal a 15 e menor ou igual a 20 então linear decrescente, logo (x2-x)/(x2-x1)
   }
   
   /************** Run Suave ***************/
   if( c->qtdeRun < 15 || c->qtdeRun > 27 ) {
       c->runSuave = 0;   // Se  for menor doque 15 ou maior do que 27 então grau de pertinencia é igual a 0
   }
   if( c->qtdeRun >=15 && c->qtdeRun < 20 ) {  
       c->runSuave = calcularLineares(15, 20, c->qtdeRun, 1); // se for maior ou igual a 15 então linear crescente, logo (x-x1)/(x2-x1)
   }
   if( c->qtdeRun >=20 && c->qtdeRun < 25 ) {
       c->runSuave = 1;     // Se for maior ou igual a 20 e menor do que 25 então grau de pertinencia é igual a 1
   }
   if( c->qtdeRun >= 25 && c->qtdeRun <= 27 ) {
       c->runSuave = calcularLineares(25, 27, c->qtdeRun, 2);     // se for maior ou igual a 25 e menor ou igual a 27 então linear decrescente, logo (x2-x)/(x2-x1)
   }

    /************** Run Forte ***************/
   if( c->qtdeRun < 23 || c->qtdeRun > 30) {
       c->runForte = 0;     // Se for menor do queu 23 ou maior do que 30 então grau de pertinencia igual a 0
   }
   if( c->qtdeRun >= 23 && c->qtdeRun < 28 ) {
       c->runForte = calcularLineares(23, 28, c->qtdeRun, 1); // Se for maior ou igual 23 e menor do que 28 então linear crescente, logo (x-x1)/(x2-x1)
   }
   if( c->qtdeRun >= 28 && c->qtdeRun <= 30) {
       c->runForte = 1;   //Se for maior ou igual a 28 e menor ou igual a 30 então grau de pertinencia 1
   }

   /************** Gelo ***************/
   if( c->qtdeGelo < 20 || c->qtdeGelo > 20 )
      c->gpGelo = 0;  //não possui gelo
   else
      c->gpGelo = 1;  // possui gelo
}

// Encontra o menor valor passado
float calcularMinimo(float refri, float run, float gelo){
  float x[3];
   x[0] = refri;
   x[1] = run;
   x[2] = gelo;
    
    int i = 0;
    float aux = x[0];
    
    while(i<=1){
       if(aux > x[i+1]){  
         aux = x[i+1];
       }  
    i++;
  }    
   return aux;
}


float calcularMaximo(float combinacaoValor1, float combinacaoValor2, float combinacaoValor3){
  float x[3];
  x[0] = combinacaoValor1;
  x[1] = combinacaoValor2;
  x[2] = combinacaoValor3;
  
   int i = 0;
   float aux = x[0];
    
    while(i<=1){
       if(aux < x[i+1]){  
         aux = x[i+1];
       }  
    i++;
  }    
   return aux;
}


float calcularGrauSuave(Bebida *c){ // processamento do ex 2a
   float suave=0;
   float combinacaoMin1, combinacaoMin2, combinacaoMin3; // Representa as 3 combinações posiveis dadas no exercicio 2A
    
   combinacaoMin1 = calcularMinimo(c->refriForte, c->runFraco, c->gpGelo);
   combinacaoMin2 = calcularMinimo(c->refriSuave, c->runSuave, c->gpGelo);
   combinacaoMin3 = calcularMinimo(c->refriFraco, c->runForte, c->gpGelo);
    
   suave = calcularMaximo(combinacaoMin1, combinacaoMin2, combinacaoMin3); // calcula o maximo dos minimos
   c->suaveMax = suave;
   return suave;
}


float calcularGrauForte(Bebida *c){ // processamento do EXERCÍCIO 2b
   float forte=0;
   float combinacaoMin1, combinacaoMin2, combinacaoMin3; // Representa as 3 combinações posiveis dadas no exercicio 2B
     
   combinacaoMin1 = calcularMinimo(c->refriForte, c->runSuave, c->gpGelo);
   combinacaoMin2 = calcularMinimo(c->refriForte, c->runForte, c->gpGelo);
   combinacaoMin3 = calcularMinimo(c->refriSuave, c->runForte, c->gpGelo);
    
   forte = calcularMaximo(combinacaoMin1, combinacaoMin2, combinacaoMin3); // calcula o maximo dos minimos
   c->forteMax = forte;
   return forte;
}


float calcularGrauFraco(Bebida *c){  // processamento do EXERCÍCIO 2c
   float fraco=0;
   float combinacaoMin1, combinacaoMin2, combinacaoMin3;  // Representa as 3 combinações posiveis dadas no exercicio 2B
    
   combinacaoMin1 = calcularMinimo(c->refriFraco, c->runFraco, c->gpGelo);
   combinacaoMin2 = calcularMinimo(c->refriFraco, c->runSuave, c->gpGelo);
   combinacaoMin3 = calcularMinimo(c->refriSuave, c->runFraco, c->gpGelo);
    
   fraco = calcularMaximo(combinacaoMin1, combinacaoMin2, combinacaoMin3); // calcula o maximo dos minimos
   c->fracoMax = fraco;
   return fraco;
}


void getPaladar(Bebida *c, float *ex2, float maiorPaladar){
    
   if(maiorPaladar > 0 && c->gpGelo == 1){
      if(maiorPaladar == ex2[0] && maiorPaladar == ex2[1] && maiorPaladar == ex2[2]){
         c->paladar[0]=1; //forte
         c->paladar[1]=1; //suave
         c->paladar[2]=1; //fraco
         c->preco = 25.00;
         return;
       } 
        if(maiorPaladar == ex2[0] && maiorPaladar == ex2[1]){
            c->paladar[0]=1; //forte
            c->paladar[1]=1; //suave
            c->preco = 25.00;            
            return;
        }
      if(maiorPaladar == ex2[0] && maiorPaladar == ex2[2]){
          c->paladar[0]=1; //forte0
          c->paladar[2]=1; //fraco
          c->preco = 25.00;
          return;
      }  
        if(maiorPaladar == ex2[1] && maiorPaladar == ex2[2]){
            c->paladar[1]=1; //suave
            c->paladar[2]=1; //fraco
            c->preco = 20.00;
            return;
        }
        if(maiorPaladar == ex2[0]){
            c->paladar[0]=1; //forte
            c->preco = 25.00;
            return;
        } 
       if(maiorPaladar == ex2[1]){
            c->paladar[1]=1; //suave
            c->preco = 20.00;
            return;
       } 
       if(maiorPaladar == ex2[2]){
           c->paladar[2]=1; //fraco
           c->preco = 15.00;
           return;
       }
       
       c->preco = 0.00; //não é cuba
       return;
   }
   c->preco = 0.00;
}


Bebida *processaPaladar(Bebida* c){ // processamento do exercicio 2 e 3
   float maximoForte, maximoFraco, maximoSuave;
   float exer2[3];
   float paladar = 0;
   int i=0;
    
   maximoForte = calcularGrauForte(c); 
   maximoSuave = calcularGrauSuave(c); 
   maximoFraco = calcularGrauFraco(c); 
   
   exer2[0] = maximoForte;
   exer2[1] = maximoSuave;
   exer2[2] = maximoFraco;
    
   paladar = calcularMaximo(maximoForte, maximoSuave, maximoFraco);
   c->gpCuba = paladar; // paladar: exercicio 3
    
   getPaladar(c, exer2, paladar);
    
   return c;
}


Bebida* getDrink(Bebida *cubaLivre, char tipoRefri, float refri, float run, float gelo){// seta no struct as quantidades inseridas
   free(cubaLivre);
   cubaLivre = (Bebida*)malloc(sizeof(Bebida));

   cubaLivre->refri = tipoRefri;
   cubaLivre->qtdeRefri = refri;
   cubaLivre->qtdeRun = run;
   cubaLivre->qtdeGelo = gelo;
            
   fuzzification(cubaLivre);
   processaPaladar(cubaLivre);
   return cubaLivre;
}


void exibeDrink(Bebida *c){ // Exibe resultado do drink com seus respectivos paladares
   int *p = c->paladar;

   printf("\nPaladar: ");

   if(c != NULL){
      if(p[0] == 1 && p[1] == 1 && p[2] == 1 ) {
         printf("\nForte, Suave e Fraco");
     }
      if(p[0] == 1 && p[1] == 1 && p[2]!= 1) {
        printf("\nForte e Suave");
     }
      if(p[0] == 1 && p[1]!=1 && p[2] == 1 ) {
        printf("\nForte e Fraco");
     }
      if(p[1] == 1 && p[2] ==1 && p[0]!= 1) {
        printf("\nSuave e Fraco");
     }
      if(p[0] == 1 && p[1] != 1 && p[2] != 1) {
        printf("\nForte");
     }
      if(p[1] == 1 && p[0] != 1 && p[2] != 1) {
        printf("\nSuave");
     }
      if(p[2] == 1 && p[0] != 1 && p[1] != 1) {
        printf("\nFraco");
     }
     if(p[0] != 1 && p[1] != 1 && p[2] != 1){
        printf("\nNão é Cuba Livre");
     }
     
      printf("\nPreço: R$ %.2f", c->preco);
      printf("\n\nResultados:");
      printf("\n Grau suave = %.2f", c->suaveMax); // resultado do exercicio 2a
      printf("\n Grau forte = %.2f", c->forteMax); // resultado do exercicio 2b
      printf("\n Grau fraco = %.2f", c->fracoMax); // resultado do exercicio 2c
      printf("\n Paladar = %.2f\n\n", c->gpCuba); // resultado do exercicio 3
   }
   else
      printf("Fatal Error\n");
   system("pause");
}


Bebida* prepararBebida(Bebida *cubaLivre){
   float qtdeRefri=0, qtdeRun=0, qtdeGelo=0;
   char tipoRefri;
    
   fflush(stdin);
    
   do{
      printf("\nEscolha o refrigerante (C = Coca, P = Pepsi): ");
      scanf(" %c", &tipoRefri);
      if(tipoRefri != 'C' && tipoRefri != 'c' && tipoRefri != 'P' && tipoRefri != 'p'){
        printf("\nPor favor digite apenas as opções válidas");
        fflush(stdin);
    }
   }while(tipoRefri != 'C' && tipoRefri != 'c' && tipoRefri != 'P' && tipoRefri != 'p');
    
   fflush(stdin);
   
  if(tipoRefri == 'c' || tipoRefri == 'C'){
    do{         
        fflush(stdin);
        printf("\nDigite a quantidade de Coca (de 50ml a 60ml): ");
        scanf("%f", &qtdeRefri);
        if (qtdeRefri < 50 || qtdeRefri > 60){
          printf("\nPor favor digite um intervalo válido");
          fflush(stdin);
      }       
    }while(qtdeRefri < 50 || qtdeRefri > 60);
  }
    
  fflush(stdin);
    
   if( tipoRefri == 'p' || tipoRefri == 'P'){
      do{
        printf("\nDigite a quantidade de Pepsi (de 60ml a 70ml): ");
        scanf("%f", &qtdeRefri);        
    if (qtdeRefri < 60 || qtdeRefri > 70){
          printf("\nPor favor digite um intervalo válido");
          fflush(stdin);
      }       
    }while(qtdeRefri < 60 || qtdeRefri > 70);
   }
   
    fflush(stdin);
   
    do{
     printf("\nDigite a quantidade de Run (de 10ml a 30ml): ");
     scanf("%f", &qtdeRun);
    if (qtdeRun < 10 || qtdeRun > 30){
          printf("\nPor favor digite um intervalo válido");
          fflush(stdin);
    }       
   }while(qtdeRun < 10 || qtdeRun > 30);
    
    fflush(stdin);
    
   printf("\nDigite se a bebida terá gelo (20ml): ");
   scanf("%f", &qtdeGelo);
   
   cubaLivre = getDrink(cubaLivre, tipoRefri, qtdeRefri, qtdeRun, qtdeGelo);
   return cubaLivre;
}


int main(){
  setlocale(LC_ALL, "Portuguese");
    int op=0;
    Bebida* cuba = NULL;
    
    do{
       system("cls");
       printf("\n Digite 1 para preparar o drink");
       printf("\n Digite 1 para exibir o drink");
       printf("\n Digite 3 para sair");
       printf("\n Escolha a opção desejada\n");
       scanf("%d", &op);
       printf("\n\n");
        
      if (op == 1) {
        cuba = prepararBebida(cuba);
     }   
        
      if (op == 2) {
        exibeDrink(cuba);        
     }     
           
   }while(op != 3);
   system("pause");
   return 0;
}

