#include <stdio.h>
#include <stdlib.h>

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
}Cuba;


void fuzzificaQtdes(Cuba *c){ //processamentos para o Exerc�cio 1
   
   if( c->refri == 'C' || c->refri == 'c' ){
      //CocaForte(X)
      if( c->qtdeRefri < 50 || c->qtdeRefri > 54 )
         c->refriForte = 0;
      else
         if( c->qtdeRefri >= 50 && c->qtdeRefri < 52 )
            c->refriForte = 1;
         else
            if( c->qtdeRefri >= 52 && c->qtdeRefri <= 54 )
               c->refriForte = (54 - c->qtdeRefri) / (54 - 52);
                        
      //CocaSuave(X)
      if( c->qtdeRefri < 52 || c->qtdeRefri > 58 )
         c->refriSuave = 0;
      else
         if( c->qtdeRefri >= 52 && c->qtdeRefri < 54 )
            c->refriSuave = ( c->qtdeRefri - 52 ) / (54 - 52);
         else
            if( c->qtdeRefri >= 54 && c->qtdeRefri <= 56 )
               c->refriSuave = 1;
            else
               if( c->qtdeRefri > 56 && c->qtdeRefri <= 58 )
                  c->refriSuave = ( 58 - c->qtdeRefri ) / (58 - 56);
      
      //CocaFraca(X)
      if( c->qtdeRefri < 56 || c->qtdeRefri > 60 )
         c->refriFraco = 0;
      else
         if( c->qtdeRefri >= 56 && c->qtdeRefri < 58 )
            c->refriFraco = ( c->qtdeRefri - 56 ) / (58 - 56);
         else
            if( c->qtdeRefri >= 58 && c->qtdeRefri <= 60 )
               c->refriFraco = 1;
                        
   }
    
   if(c->refri == 'p' || c->refri == 'P'){
      //PepsiForte(X)
      if( c->qtdeRefri < 60 || c->qtdeRefri > 64 )
         c->refriForte = 0;
      else
         if( c->qtdeRefri >= 60 && c->qtdeRefri < 62 )
            c->refriForte = 1;
         else
            if( c->qtdeRefri >= 62 && c->qtdeRefri <= 64 )
               c->refriForte = ( 64 - c->qtdeRefri ) / (64 - 62);
      
      //PepsiSuave(X)
      if( c->qtdeRefri < 62 || c->qtdeRefri > 68 )
         c->refriSuave = 0;
      else
         if( c->qtdeRefri >= 62 && c->qtdeRefri < 64 )
            c->refriSuave = ( c->qtdeRefri - 62) / (64 - 62);
         else
            if( c->qtdeRefri >= 64 && c->qtdeRefri < 66 )
               c->refriSuave = 1;
            else
               if( c->qtdeRefri >= 66 && c->qtdeRefri <= 68 )
                  c->refriSuave = ( 68 - c->qtdeRefri ) / (68 - 66);
        
      //PepsiFraca(X)
      if( c->qtdeRefri < 66 || c->qtdeRefri > 70 )
         c->refriFraco = 0;
      else
         if( c->qtdeRefri >= 66 && c->qtdeRefri < 68 )
            c->refriFraco = (c->qtdeRefri - 66) / (68 - 66);
         else
            if( c->qtdeRefri >= 68 && c->qtdeRefri <= 70 )
               c->refriFraco = 1;
   }
   
   //RunFraco(X)
   if( c->qtdeRun < 10 || c->qtdeRun > 20 )
      c->runFraco = 0;
   else
      if( c->qtdeRun >= 10 && c->qtdeRun < 15 )
         c->runFraco = 1;
      else
         if( c->qtdeRun >= 15 && c->qtdeRun <= 20 )
            c->runFraco = ( 20 - c->qtdeRun ) / (20 - 15);
   
   //RunSuave(X)
   if( c->qtdeRun < 15 || c->qtdeRun > 27 )
      c->runSuave = 0;
   else
      if( c->qtdeRun >=15 && c->qtdeRun < 20 )
         c->runSuave = ( c->qtdeRun - 15 ) / (20 - 15);
      else
         if( c->qtdeRun >=20 && c->qtdeRun < 25 )
            c->runSuave = 1;
         else
            if( c->qtdeRun >= 25 && c->qtdeRun <= 27 )
               c->runSuave = ( 27 - c->qtdeRun ) / (27 - 25);

    //RunForte(X)
   if( c->qtdeRun < 23 || c->qtdeRun > 30)
      c->runForte = 0;
   else
      if( c->qtdeRun >= 23 && c->qtdeRun < 28 )
         c->runForte = ( c->qtdeRun - 23 ) / (28 - 23);
      else
         if( c->qtdeRun >= 28 && c->qtdeRun <= 30)
            c->runForte = 1;

   //Gelo(X)
   if( c->qtdeGelo < 20 || c->qtdeGelo > 20 )
      c->gpGelo = 0;
   else
      c->gpGelo = 1;
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


float suaveMax(Cuba *c){ // processamento do EXERC�CIO 2a
   float suaveMax=0;
   float suaveMin[3];
    
   suaveMin[0] = Minimo(c->refriForte, c->runFraco, c->gpGelo);
   suaveMin[1] = Minimo(c->refriSuave, c->runSuave, c->gpGelo);
   suaveMin[2] = Minimo(c->refriFraco, c->runForte, c->gpGelo);
    
   suaveMax = Maximo(suaveMin);
   c->suaveMax = suaveMax;
   return suaveMax;
}


float forteMax(Cuba *c){ // processamento do EXERC�CIO 2b
   float forteMax=0;
   float forteMin[3];
     
   forteMin[0] = Minimo(c->refriForte, c->runSuave, c->gpGelo);
   forteMin[1] = Minimo(c->refriForte, c->runForte, c->gpGelo);
   forteMin[2] = Minimo(c->refriSuave, c->runForte, c->gpGelo);
    
   forteMax = Maximo(forteMin);
   c->forteMax = forteMax;
   return forteMax;
}


float fracoMax(Cuba *c){  // processamento do EXERC�CIO 2c
   float fracoMax=0;
   float fracoMin[3];
    
   fracoMin[0] = Minimo(c->refriFraco, c->runFraco, c->gpGelo);
   fracoMin[1] = Minimo(c->refriFraco, c->runSuave, c->gpGelo);
   fracoMin[2] = Minimo(c->refriSuave, c->runFraco, c->gpGelo);
    
   fracoMax = Maximo(fracoMin);
   c->fracoMax = fracoMax;
   return fracoMax;
}


void validaPaladar(Cuba *c, float *ex2, float ex3){
    
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
                                         c->preco = 0.00; //n�o � cuba
      return;
   }
   c->preco = 0.00;
}


Cuba *exercicios2e3(Cuba* c){ // chama processamentos para os Exerc�cios 2 e 3
   float maxEx2[3];
   float maxEx3 = 0;
   int i=0;
    
   maxEx2[0] = forteMax(c); //EXERC�CIO 2b
   maxEx2[1] = suaveMax(c); //EXERC�CIO 2a
   maxEx2[2] = fracoMax(c); //EXERC�CIO 2c
    
   maxEx3 = Maximo(maxEx2);
   c->gpCuba = maxEx3; //EXERC�CIO 3
    
   validaPaladar(c, maxEx2, maxEx3);
    
   return c;
}


Cuba* insereDrink(Cuba *c, char refri, float qtdeRefri, float qtdeRun, float qtdeGelo){
   free(c);
   c = (Cuba*)malloc(sizeof(Cuba));

   c -> refri = refri;
   c->qtdeRefri = qtdeRefri;
   c->qtdeRun = qtdeRun;
   c->qtdeGelo = qtdeGelo;
            
   fuzzificaQtdes(c);
   exercicios2e3(c);
   return c;
}


void exibeDrink(Cuba *c){
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


Cuba* entradasDrink(Cuba *c){
   char refri;
   float qtdeRefri=0;
   float qtdeRun=0;
   float qtdeGelo=0;
   char continuar;
    
   fflush(stdin);
    
   do{
      printf("Entre com o refrigerante (C = Coca, P = Pepsi): ");
      scanf(" %c", &refri);
   }while(refri != 'C' && refri != 'c' && refri != 'P' && refri != 'p');
    
   fflush(stdin);
    
   if(refri == 'c' || refri == 'C'){
      printf("\nEntre com a quantidade de Coca (de 50ml a 60ml): ");
      scanf("%f", &qtdeRefri);
   }
    
   if( refri == 'p' || refri == 'P'){
      printf("\nEntre com a quantidade de Pepsi (de 60ml a 70ml): ");
      scanf("%f", &qtdeRefri);
   }
    
   printf("\nEntre com a quantidade de Run (de 10ml a 30ml): ");
   scanf("%f", &qtdeRun);
    
   printf("\nEntre com a quantidade de Gelo (20ml): ");
   scanf("%f", &qtdeGelo);
   
   c = insereDrink(c, refri, qtdeRefri, qtdeRun, qtdeGelo);
   return c;
}


int main(){
    int opcao=0;
    Cuba* cuba = NULL;
    char cedilha=135;
    char atil=198;
    
    do{
       system("cls");
       printf(" 1 - Preparar drink\n");
       printf(" 2 - Exibir drink\n");
       printf(" 3 - Sair\n");
       printf("\nOp%c%co: ", cedilha, atil);
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

