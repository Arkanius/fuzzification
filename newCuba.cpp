#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>


typedef struct cuba{
   char refri;
   float qtdeRefri, qtdeRun, qtdeGelo;
   float refriForte, refriSuave, refriFraco;
   float runForte, runSuave, runFraco;
   float gpGelo;
   float suaveMax, forteMax, fracoMax;
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
            c->refriForte = 0; 		// Segundo o gráfico, se for menor que 50 ou maior que 54 não é forte
	    }   
        if( c->qtdeRefri >= 50 && c->qtdeRefri < 52 ) {
            c->refriForte = 1;		// Segundo o gráfico, se estiver entre 50 e 52 o grau de pertinencia a forte é igual a 1
	    }
        if( c->qtdeRefri >= 52 && c->qtdeRefri <= 54 ) {
            c->refriForte = calcularLineares(52, 54, c->qtdeRefri, 2); 	// Linear Decrescente, se x for maior ou igual a 52 e menor ou igual a 54 então (x2-x)/(x2-x1)
	    }
	                           
      /************ Coca Suave *****************/
      if( c->qtdeRefri < 52 || c->qtdeRefri > 58 ){
         c->refriSuave = 0; 		// Se for maior que 52 ou maior que 58 não é suave
	  }
      if( c->qtdeRefri >= 52 && c->qtdeRefri < 54 ){
          c->refriSuave = ( c->qtdeRefri - 52 ) / (54 - 52); 		// Linear Crescente, se for maior ou igual a 52 ou menor igual a 54 então (x-x1)/(x2-x1)
	  }      
   	  if( c->qtdeRefri >= 54 && c->qtdeRefri <= 56 ){
            c->refriSuave = 1;		// se for maior ou igual 54 e menor igual 56 então pertinencia 1 para suave
	  }
      if( c->qtdeRefri > 56 && c->qtdeRefri <= 58 ) {
            c->refriSuave = calcularLineares(56, 58, c->qtdeRefri, 2); // Linear Decrescente, se x for maior ou igual a 56 e menor ou igual a 58 então (x2-x)/(x2-x1)
	  }	   
      
     /************ Coca Fraca *****************/
      if( c->qtdeRefri < 56 || c->qtdeRefri > 60 ){
         c->refriFraco = 0;		// Se for menor uqe 56  ou maior que 60 pertinencia 0 para fraco
	  }
      if( c->qtdeRefri >= 56 && c->qtdeRefri < 58 ){
          c->refriFraco = calcularLineares(56, 58, c->qtdeRefri, 1);
		  //c->refriFraco = ( c->qtdeRefri - 56 ) / (58 - 56);	// Linear Crescente, se x for maior ou igual 56 e menor ou igual 58 então (x-x1/(x2-x1)
	   }
      if( c->qtdeRefri >= 58 && c->qtdeRefri <= 60 ){
          c->refriFraco = 1; 		// Se for maior ou igual 58 e menor ou igual 60 então pertinencia 1 para fraco
	    }
                        
   }
    
    /************** Pepsi ***************/
   if(c->refri == 'p' || c->refri == 'P'){
      /************** Pepsi Forte ***************/
      if( c->qtdeRefri < 60 || c->qtdeRefri > 64 ){
         c->refriForte = 0; 	// se for menor que 60 ou maior que 64 grau de pertinencia forte é igual a 0
	  }
      if( c->qtdeRefri >= 60 && c->qtdeRefri < 62 ){
          c->refriForte = 1; 	// se for maior ou igual a 60 e menor ou igual 62 então grau de pertinencia forte é igual a 1
	  }
      if( c->qtdeRefri >= 62 && c->qtdeRefri <= 64 ){
          c->refriForte = ( 64 - c->qtdeRefri ) / (64 - 62); 	// Linear Descrescente, se for maior ou igual 62 e menor ou igual 64 então (x2-x)/(x2-x1)
	  }
      
      /************** Pepsi Suave ***************/
      if( c->qtdeRefri < 62 || c->qtdeRefri > 68 ){
          c->refriSuave = 0;	// Se fir nebir qye 62 iy nauir qye 68 então grau de pertinencia suave é igual a 0
	  }
      if( c->qtdeRefri >= 62 && c->qtdeRefri < 64 ){
          c->refriSuave = ( c->qtdeRefri - 62) / (64 - 62); // Se for maior ou igual 62 e menor que 64 Linear crescente, então, (x-x1)/(x2-x1)
	  }
      if( c->qtdeRefri >= 64 && c->qtdeRefri < 66 ){
          c->refriSuave = 1; 	// Se for maior ou igual 64  e menor ou igual 66 então grau de pertinencia a suave é igual a 1
	  }
      if( c->qtdeRefri >= 66 && c->qtdeRefri <= 68 ){
          c->refriSuave = ( 68 - c->qtdeRefri ) / (68 - 66); 	// Linear Descrescente, se for maior ou igual 66 e menor ou igual 68 então, (x2-x)/(x2-x1)
	  }
        
      /************** Pepsi Fraca ***************/
      if( c->qtdeRefri < 66 || c->qtdeRefri > 70 ){
          c->refriFraco = 0;	//Se for menor que 66 ou maior que 70 então grau de pertinencia a fraco é igual a 0
	  }
      if( c->qtdeRefri >= 66 && c->qtdeRefri < 68 ){
          c->refriFraco = (c->qtdeRefri - 66) / (68 - 66); //Se for maior ou igual 66 e menor que 68, então Linear crescente, (x-x1)/(x2-x1)
	  }
      if( c->qtdeRefri >= 68 && c->qtdeRefri <= 70 ){
          c->refriFraco = 1;		// se for maior ou igual que 68 e menor ou igual 70 então grau de pertinencia fraco igual a 1
	  }
   }
   
   /************ Run **********/
   /************** Run Fraco ***************/
   if( c->qtdeRun < 10 || c->qtdeRun > 20 ) {
       c->runFraco = 0; 	// Se for menor do que 10 ou maior do que 20 então pgrau de pertinencia igual a 0
   }
   if( c->qtdeRun >= 10 && c->qtdeRun < 15 ) {
       c->runFraco = 1;		// Se for maior ou igual a 10 e menor do que 15 então, grau de pertinencia igual a 1
   }
   if( c->qtdeRun >= 15 && c->qtdeRun <= 20 ) {
       c->runFraco = ( 20 - c->qtdeRun ) / (20 - 15);		// Se for maior ou iugal a 15 e menor ou igual a 20 então linear decrescente, logo (x2-x)/(x2-x1)
   }
   
   /************** Run Suave ***************/
   if( c->qtdeRun < 15 || c->qtdeRun > 27 ) {
       c->runSuave = 0;		// Se  for menor doque 15 ou maior do que 27 então grau de pertinencia é igual a 0
   }
   if( c->qtdeRun >=15 && c->qtdeRun < 20 ) {  
       c->runSuave = ( c->qtdeRun - 15 ) / (20 - 15); 		// se for maior ou igual a 15 então linear crescente, logo (x-x1)/(x2-x1)
   }
   if( c->qtdeRun >=20 && c->qtdeRun < 25 ) {
       c->runSuave = 1; 		// Se for maior ou igual a 20 e menor do que 25 então grau de pertinencia é igual a 1
   }
   if( c->qtdeRun >= 25 && c->qtdeRun <= 27 ) {
       c->runSuave = ( 27 - c->qtdeRun ) / (27 - 25); 		// se for maior ou igual a 25 e menor ou igual a 27 então linear decrescente, logo (x2-x)/(x2-x1)
   }

    /************** Run Forte ***************/
   if( c->qtdeRun < 23 || c->qtdeRun > 30) {
       c->runForte = 0; 		// Se for menor do queu 23 ou maior do que 30 então grau de pertinencia igual a 0
   }
   if( c->qtdeRun >= 23 && c->qtdeRun < 28 ) {
       c->runForte = ( c->qtdeRun - 23 ) / (28 - 23); 		// Se for maior ou igual 23 e menor do que 28 então linear crescente, logo (x-x1)/(x2-x1)
   }
   if( c->qtdeRun >= 28 && c->qtdeRun <= 30) {
       c->runForte = 1;		//Se for maior ou igual a 28 e menor ou igual a 30 então grau de pertinencia 1
   }

   /************** Gelo ***************/
   if( c->qtdeGelo < 20 || c->qtdeGelo > 20 )
      c->gpGelo = 0;	//não possui gelo
   else
      c->gpGelo = 1;	// possui gelo
}


float Minimo(float refri, float run, float gelo){
   float x[3];
   x[0] = refri;
   x[1] = run;
   x[2] = gelo;
    
   float minimo=0;
   int i=0;
    
   for(i=0, minimo = x[0]; i<=1; i++){
      if(minimo > x[i+1])
         minimo = x[i+1];
      }
   return minimo;
}


float Maximo(float *x){
   int i=0;
   float maximo=0;
    
   for(i=0, maximo = x[0]; i<=1; i++){
      if(maximo < x[i+1])
         maximo = x[i+1];
   }
   return maximo;
}


float suaveMax(Bebida *c){ // processamento do EXERCÍCIO 2a
   float suaveMax=0;
   float suaveMin[3];
    
   suaveMin[0] = Minimo(c->refriForte, c->runFraco, c->gpGelo);
   suaveMin[1] = Minimo(c->refriSuave, c->runSuave, c->gpGelo);
   suaveMin[2] = Minimo(c->refriFraco, c->runForte, c->gpGelo);
    
   suaveMax = Maximo(suaveMin);
   c->suaveMax = suaveMax;
   return suaveMax;
}


float forteMax(Bebida *c){ // processamento do EXERCÍCIO 2b
   float forteMax=0;
   float forteMin[3];
     
   forteMin[0] = Minimo(c->refriForte, c->runSuave, c->gpGelo);
   forteMin[1] = Minimo(c->refriForte, c->runForte, c->gpGelo);
   forteMin[2] = Minimo(c->refriSuave, c->runForte, c->gpGelo);
    
   forteMax = Maximo(forteMin);
   c->forteMax = forteMax;
   return forteMax;
}


float fracoMax(Bebida *c){  // processamento do EXERCÍCIO 2c
   float fracoMax=0;
   float fracoMin[3];
    
   fracoMin[0] = Minimo(c->refriFraco, c->runFraco, c->gpGelo);
   fracoMin[1] = Minimo(c->refriFraco, c->runSuave, c->gpGelo);
   fracoMin[2] = Minimo(c->refriSuave, c->runFraco, c->gpGelo);
    
   fracoMax = Maximo(fracoMin);
   c->fracoMax = fracoMax;
   return fracoMax;
}


void validaPaladar(Bebida *c, float *ex2, float ex3){
    
   if(ex3 > 0 && c->gpGelo == 1){
      if(ex3 == ex2[0] && ex3 == ex2[1] && ex3 == ex2[2]){
         c->paladar[0]=1; //forte
         c->paladar[1]=1; //suave
         c->paladar[2]=1; //fraco
         c->preco = 25.00;
      } else
           if(ex3 == ex2[0] && ex3 == ex2[1]){
              c->paladar[0]=1; //forte
              c->paladar[1]=1; //suave
              c->preco = 25.00;
                
           } else
                if(ex3 == ex2[0] && ex3 == ex2[2]){
                   c->paladar[0]=1; //forte
                   c->paladar[2]=1; //fraco
                   c->preco = 25.00;
                } else 
                     if(ex3 == ex2[1] && ex3 == ex2[2]){
                        c->paladar[1]=1; //suave
                        c->paladar[2]=1; //fraco
                        c->preco = 20.00;
                     } else
                          if(ex3 == ex2[0]){
                             c->paladar[0]=1; //forte
                             c->preco = 25.00;
                          } else
                               if(ex3 == ex2[1]){
                                  c->paladar[1]=1; //suave
                                  c->preco = 20.00;
                               } else
                                    if(ex3 == ex2[2]){
                                       c->paladar[2]=1; //fraco
                                       c->preco = 15.00;
                                    } else
                                         c->preco = 0.00; //não é cuba
      return;
   }
   c->preco = 0.00;
}


Bebida *exercicios2e3(Bebida* c){ // chama processamentos para os Exercícios 2 e 3
   float maxEx2[3];
   float maxEx3 = 0;
   int i=0;
    
   maxEx2[0] = forteMax(c); //EXERCÍCIO 2b
   maxEx2[1] = suaveMax(c); //EXERCÍCIO 2a
   maxEx2[2] = fracoMax(c); //EXERCÍCIO 2c
    
   maxEx3 = Maximo(maxEx2);
   c->gpCuba = maxEx3; //EXERCÍCIO 3
    
   validaPaladar(c, maxEx2, maxEx3);
    
   return c;
}


Bebida* insereDrink(Bebida *c, char refri, float qtdeRefri, float qtdeRun, float qtdeGelo){
   free(c);
   c = (Bebida*)malloc(sizeof(Bebida));

   c -> refri = refri;
   c->qtdeRefri = qtdeRefri;
   c->qtdeRun = qtdeRun;
   c->qtdeGelo = qtdeGelo;
            
   fuzzification(c);
   exercicios2e3(c);
   return c;
}


void exibeDrink(Bebida *c){
   int *p = c->paladar;
   char cedilha=135, atil=198, agudo=160, egudo=130;

   printf("Paladar: ");

   if(c != NULL){
      if( p[0] == 1 && p[1] == 1 && p[2] == 1 )
         printf("Forte, Suave e Fraco\n");
      else
         if( p[0] == 1 && p[1] == 1 )
            printf("Forte e Suave\n");
         else
            if( p[0] == 1 && p[2] == 1 )
               printf("Forte e Fraco\n");
            else
               if( p[1] == 1 && p[2] ==1 )
                  printf("Suave e Fraco\n");
               else
                  if( p[0] == 1 )
                     printf("Forte\n");
                  else
                     if( p[1] == 1 )
                        printf("Suave\n");
                     else
                        if( p[2] == 1)
                           printf("Fraco\n");
                        else
                           printf("N%co %c Cuba Livre\n", atil, egudo);
      printf("Pre%co: R$ %.2f\n\n", cedilha, c->preco);
      printf("\nResultados:\n");
      printf("2a Suave(m%cx) = %.2f\n", agudo, c->suaveMax);
      printf("2b Forte(m%cx) = %.2f\n", agudo, c->forteMax);
      printf("2c Fraco(m%cx) = %.2f\n", agudo, c->fracoMax);
      printf("3 Paladar(m%cx) = %.2f\n", agudo, c->gpCuba);
   }
   else
      printf("Sem drink!\n");
   system("pause");
}


Bebida* entradasDrink(Bebida *c){
   float qtdeRefri=0;
   float qtdeRun=0;
   float qtdeGelo=0;
   char refri;
   char continuar;
    
   fflush(stdin);
    
   do{
      printf("Digite o refrigerante (C = Coca, P = Pepsi): ");
      scanf(" %c", &refri);
   }while(refri != 'C' && refri != 'c' && refri != 'P' && refri != 'p');
    
   fflush(stdin);
    
   if(refri == 'c' || refri == 'C'){
      printf("\nDigite a quantidade de Coca (de 50ml a 60ml): ");
      scanf("%f", &qtdeRefri);
   }
    
   if( refri == 'p' || refri == 'P'){
      printf("\nDigite a quantidade de Pepsi (de 60ml a 70ml): ");
      scanf("%f", &qtdeRefri);
   }
    
   printf("\nDigite a quantidade de Run (de 10ml a 30ml): ");
   scanf("%f", &qtdeRun);
    
   printf("\nDigite a quantidade de Gelo (20ml): ");
   scanf("%f", &qtdeGelo);
   
   c = insereDrink(c, refri, qtdeRefri, qtdeRun, qtdeGelo);
   return c;
}


int main(){
	setlocale(LC_ALL, "Portuguese");
    int opcao=0;
    Bebida* cuba = NULL;
    
    do{
       system("cls");
       printf(" 1 - Preparar drink\n");
       printf(" 2 - Exibir drink\n");
       printf(" 3 - Sair\n");
       printf("\nOpção\n");
       scanf("%d", &opcao);
       printf("\n\n");
        
      switch(opcao){
         case 1 :
            cuba = entradasDrink(cuba);
         break;
         case 2 :
            exibeDrink(cuba);
         break; 
         case 3 :
            free(cuba);
         break;
      }
   }while(opcao != 3);
   system("pause");
   return 0;
}

