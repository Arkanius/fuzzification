#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <ctype.h>

void layout(){
	setlocale(LC_ALL, "Portuguese");
    printf("\n"); 
    for(int i =0; i <79; i++)
       printf("-");
       
    printf("\n");
    printf("                       Bem vindo ao bar do Gall�o         ");    
    printf("\n");    
    for(int i =0; i <79; i++)
       printf("-");  
    printf("\n\n"); 
    }
        
void layout_Final(){
	setlocale(LC_ALL, "Portuguese");
    printf("\n"); 
    for(int i =0; i <79; i++)
       printf("-");   
    printf("\n");
    printf("                       Obrigado por usar o Cuba Livre          ");
    printf("\n");
    
    for(int i =0; i <79; i++)
       printf("-");
  
    printf("\n\n");     
     
     }  
     
void layout1(){
       printf("\n"); 
    for(int i =0; i <79; i++)
       printf("-");   
    printf("\n");
    printf("                               Cuba Livre          ");
    printf("\n");
    
    for(int i =0; i <79; i++)
       printf("-");
  
    printf("\n\n");     
     
     }    
     
    bool validarValor(float valor){
  	if(valor == 0){
  	printf("\nPor favor digite um numero ou maior que 0. \n");
  	system("pause");
  	system("cls");
  	layout1();
  	return false;
  }
  return true;
  }
    
int main (){
    setlocale(LC_ALL, "Portuguese");
    //variaveis
    int tipoRefri, flag;
    float mlRefri, mlRun, mlGelo;
    float resulRefri, resulRun, resulGelo;
    int c,r,p,g;
    int resp=0, soma=0, valor=0;
    char entradarefri [10];
    char entradarun [10];
	char entradagelo [10]; 
    
    do{
         
    //layout
    layout();
    
    system("pause");
    system("cls");
    
    layout1();
        
    //Entrada de dados
        
    do{
        printf("Digite o tipo do seu refrigerante:\n");
        printf("1- Coca-cola\n");
        printf("2- Pepsi\n");
        printf("\n");
        printf("Op��o: ");
        if (scanf("%d", &tipoRefri) != 1) {
        	printf("\nPor favor digite apenas numeros \n");
        	tipoRefri = 10;
        	fflush(stdin);
		}
    }while(tipoRefri<1 ||  tipoRefri>2);
    
    system("cls");
    layout1();
    
    do{
      printf("Digite a quantidade de ml de Refrigerante:\n");
      printf("Coca-Cola (50ml a 60ml) ou Pepsi-Cola (60ml a 70ml)\n");
      printf("Quantidade: ");
      scanf("%s", &entradarefri);
      mlRefri = atof (entradarefri);
	  fflush(stdin);	    	    
	  }while(!validarValor(mlRefri));

    do{ 
	  printf("\nDigite a quantidade de ml de Run\n");
      printf("Run (10ml a 30ml)\n");
      printf("Quantidade: ");
	  scanf("%s", &entradarun);
      mlRun = atof (entradarun);
	  fflush(stdin);	    	    
	  }while(!validarValor(mlRun));
      
    do{
	  printf("\nDigite a quantidade de ml de Gelo\n");
      printf("Gelo (20ml)\n");
      printf("Quantidade: ");
	  scanf("%s", &entradagelo);
	  mlGelo = atof (entradagelo);
	  fflush(stdin);	    	    
	  }while(!validarValor(mlGelo));
    
    printf ("\n");
    //come�a a verificar Coca
    if(tipoRefri == 1)
       //come�a coca forte
       if(mlRefri >= 50 && mlRefri < 52 ){
         c=1;         
         printf("Coca-Forte\n");
       }else 
       if(mlRefri >= 52 && mlRefri < 54){
         resulRefri = ((54-mlRefri)/(54-52));
         c=1;    
         printf("Coca-forte com o grau de: %.0f\n", resulRefri);
      
      //come�a coca suave
      }else if(mlRefri >= 54 && mlRefri <56 ){
         c=2;   
         printf("Coca-Suave\n");
      }else if(mlRefri >= 56 && mlRefri < 58){
         c=2; 
         resulRefri = ((58-mlRefri)/(58-56));
         printf("Coca-suave com o grau de: %.0f\n", resulRefri);
     
     //come�a coca fraca
     }else if(mlRefri >= 58 && mlRefri <= 60 ){
         c=3;  
         printf("Coca-Fraco\n");
       }
      
      //come�a verificar Pepsi
     if(tipoRefri == 2)
        //comecaPepsi forte
       if(mlRefri >= 60 && mlRefri < 62 ){
         p=1;
         printf("Pepsi-Forte\n");
       }else 
       if(mlRefri >= 62 && mlRefri < 64){
         p=1;
         resulRefri = ((64-mlRefri)/(64-62));
         printf("Pepsi-forte com o grau de: %.0f\n", resulRefri);
      
      //comeca Pepsi suave
      }else if(mlRefri >= 64 && mlRefri <66 ){
         p=2;
         printf("Pepsi-Suave\n");
      }else if(mlRefri >= 66 && mlRefri < 68){
         p=2;
         resulRefri = ((68-mlRefri)/(68-66));
         printf("Pepsi-suave com o grau de: %.0f\n", resulRefri);
     
     //comeca pepsi fraca
     }else if(mlRefri >= 68 && mlRefri < 71 ){
         p=3;
         printf("Pepsi-Fraco\n");
       }
       
      
               
      
     //come�a a verficar Run
     //come�a Run fraco
       if(mlRun >= 10 && mlRun < 15 ){
         r=3;
         printf("Run-Fraco\n");

      
      //come�a run suave
      }else if(mlRun >= 20 && mlRun <23 ){
         r=2;
         printf("Run-Suave\n");
       }else if(mlRun >= 15 && mlRun < 20){
         r=2;
         resulRun = ((20-mlRun)/(20-15));
         printf("Run-suave com o grau de: %.0f\n", resulRun);
     
     //come�a run forte
     }else if(mlRun >= 27 && mlRun <= 30 ){
         r=1;
         printf("Run-Forte\n");
      } else 
       if(mlRun >= 23 && mlRun < 27){
         r=1;
         resulRun = ((27-mlRun)/(27-23));
         printf("Run-forte com o grau de: %.0f\n", mlRun);
      }  
      
      
      //come�a a verificar o gelo
      if(mlGelo == 20){
        g=1;
        printf("Gelado\n");
      }else
        printf("Sem gelo\n");
        
      printf("\n\n");
      
      system("pause");
      system("cls");
      
      layout_Final(); 
      

      //Defuzzifica��o
      //come�a a verificar com coca-cola
      //come�a paladar suave com coca
      
      if(tipoRefri == 1) {
      if(c==1 && r==3 && g==1){
         valor=20; 
         printf("\nBebida Com Coca-cola\n");
         printf("Paladar: Suave\n");
         printf("Seu pre�o �: R$ 20,00\n");
                      
      }else if(c==2 && r==2 && g==1){
         valor=20; 
         printf("\nBebida Com Coca-cola\n");
         printf("Paladar: Suave\n");
         printf("Seu pre�o �: R$ 20,00\n");

      }else if(c==3 && r==1 && g==1) {
         valor=20; 
         printf("\nBebida Com Coca-cola\n");
         printf("Paladar: Suave\n");
         printf("Seu pre�o �: R$ 20,00\n");
    
      //come�a paladar forte   
      }else if(c==1 && r==2 && g==1){
         valor=25;
         printf("\nBebida Com Coca-cola\n");
         printf("Paladar: Forte\n");
         printf("Seu pre�o �: R$ 25,00\n"); 
               
      }else if(c==1 && r==1 && g==1){
         valor=25;
         printf("\nBebida Com Coca-cola\n");
         printf("Paladar: Forte\n");
         printf("Seu pre�o �: R$ 25,00\n");
               
      } else if(c==2 && r==1 && g==1){
         valor=25;
         printf("\nBebida Com Coca-cola\n");
         printf("Paladar: Forte\n");
         printf("Seu pre�o �: R$ 25,00\n"); 
      
      //comeca paladar fraco
      }else if(c==3 && r==3 && g==1){
         valor=15;   
         printf("\nBebida Com Coca-cola\n");
         printf("Paladar: Fraco\n");
         printf("Seu pre�o �: R$ 15,00\n");       
         
      }else if(c==3 && r==2 && g==1){
         valor=15;   
         printf("\nBebida Com Coca-cola\n");
         printf("Paladar: Fraco\n");
         printf("Seu pre�o �: R$ 15,00\n"); 
             
      }else if(c==2 && r==3 && g==1){
         valor=15;
         printf("\nBebida Com Coca-cola\n");
         printf("Paladar: Fraco\n");
         printf("Seu pre�o �: R$ 15,00\n");	
		}
      
      }else if(tipoRefri == 2) {	              
	      //Come�a a verificar com pepsi      
	      //come�a paladar suave 
	      if(p==1 && r==3 && g==1){
	         valor=20;     
	         printf("\nBebida Com Pepsi\n");
	         printf("Paladar: Suave\n");
	         printf("Seu pre�o �: R$ 20,00\n");
	          
	      }else if(p==2 && r==2 && g==1){
	         valor=20;
	         printf("\nBebida Com Pepsi\n");
	         printf("Paladar: Suave\n");
	         printf("Seu pre�o �: R$ 20,00\n"); 
	         
	      }else if(p==3 && r==1 && g==1) {
	         valor=20;   
	         printf("\nBebida Com Pepsi\n");
	         printf("Paladar: Suave\n");
	         printf("Seu pre�o �: R$ 20,00\n"); 
	         
	      //come�a paladar forte   
	      }else if(p==1 && r==2 && g==1){
	         valor=25;
	         printf("\nBebida Com Pepsi\n");
	         printf("Paladar: Forte\n");
	         printf("Seu pre�o �: R$ 25,00\n");  
	               
	      }else if(p==1 && r==1 && g==1){
	         valor=25;   
	         printf("\nBebida Com Pepsi\n");
	         printf("Paladar: Forte\n");
	         printf("Seu pre�o �: R$ 25,00\n");  
	               
	      } else if(p==2 && r==1 && g==1){
	         valor=25;
	         printf("\nBebida Com Pepsi\n");
	         printf("Paladar: Forte\n");
	         printf("Seu pre�o �: R$ 25,00\n"); 
	      
	      //come�a paladar fraco
	      }else if(p==3 && r==3 && g==1){
	         valor=15;
	         printf("\nBebida Com Pepsi\n");
	         printf("Paladar: Fraco\n");
	         printf("Seu pre�o �: R$ 15,00\n"); 
	                
	      }else if(p==3 && r==2 && g==1){
	         valor=15;
	         printf("\nBebida Com Pepsi\n");
	         printf("Paladar: Fraco\n");
	         printf("Seu pre�o �: R$ 15,00\n");  
	              
	      }else if(p==2 && r==3 && g==1){
	         valor=15;
	         printf("\nBebida Com Pepsi\n");
	         printf("Paladar: Fraco\n");
	         printf("Seu pre�o �: R$ 15,00\n");
		}
      }else{
         printf("\nSua bebida n�o � Cuba Livre\n");
      }
      
      soma=soma+valor;
      
      system("pause");
      system("cls");
      
      layout1();
      
      do {
      	  flag = 0;
		  printf("Deseja continuar?\n");
	      printf("1-Sim\n");
	      printf("2-Nao\n");
	      if (scanf("%d", &resp) != 1) {      
	        	printf("\nPor favor digite apenas numeros \n");
	       		flag = 1;
	       		fflush(stdin);
			}
	 	 }while(flag==1); 

      
    }while(resp==1);  

    layout_Final();
	if(soma != 0) {    	
    	printf("O valor total da conta �: %i\n\n", soma);
	}
    
    system("pause");
    
    
	}    
