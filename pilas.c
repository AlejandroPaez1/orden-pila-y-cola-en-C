#include<stdio.h>
#include<stdlib.h>

 typedef struct Pila{
     int dato;
     struct Pila *sgte;
 }Pila;

 Pila *primeroP=NULL;

  typedef struct Cola{
  		int dato;
  		struct Cola *sgte;
  }Cola;

  Cola *primeroC=NULL;
  Cola *ultimo = NULL;


 //E AGREGA UN DATO A LA PILA
void agregarPila(){
    Pila *nuevo=(Pila*)malloc(sizeof(Pila));
    printf("escribe un numero: ");
    scanf("%i",&nuevo->dato);
    nuevo->sgte=primeroP;
    primeroP=nuevo;
}


//IMPRIMIR LA PILA
void imprimirPila(){
    int cont=1;
    Pila *actualP=(Pila*)malloc(sizeof(Pila));
    actualP=primeroP;
    if(actualP!=NULL){
        while(actualP!=NULL){
            printf("     |  %i   |  <- %i  en Salir\n",actualP->dato,cont);

            actualP=actualP->sgte;
            cont++;
        }
            printf("     --------\n");
    }else{
            printf("Pila Vacia\n");
    }
    printf("ENTER");
    getch();
}

//ELIMINAR LA PILA
void EliminarPila(){
   Pila *cima;
   cima=primeroP;
   if(cima==NULL){
    printf("no tiene datos la pila");
    printf("ENTER");
    getch();
    //system("cls");
   }else{
    primeroP=primeroP->sgte;
    free(cima);
   }
}

//AÑADIR COLA
void insertarCola(){
	Cola *nuevo=(Cola*)malloc(sizeof(Cola));
	printf("Ingrese un numero: ");
	scanf("%i",&nuevo->dato);
	if(primeroC==NULL){
		primeroC=nuevo;
		primeroC->sgte=NULL;
		ultimo=nuevo;
	}else{
	    
		ultimo->sgte=nuevo;
		nuevo->sgte=NULL;
		ultimo=nuevo;
	}
}

void imprimirCola(){
    int cont=1;
    Cola *actualC = (Cola*)malloc(sizeof(Cola));
    actualC=primeroC;
    if(primeroC!=NULL){
        while(actualC!=NULL){
            printf("     |  %i   |   <- %i  en Salir\n",actualC->dato,cont);
            actualC=actualC->sgte;
            cont++;
        }
            printf("     --------\n");
    }else{
        printf("colas esta vacia \n");
    }
    printf("ENTER");
    getch();
}

void EliminarCola(){
    Cola *inicio;
    inicio=primeroC;
   if(primeroC==NULL){
        printf("Cola Vacia\n");
        printf("ENTER");
   		getch();
   		//system("cls");
    }else{
        primeroC=inicio->sgte;
        free(inicio);
    }

}

 int main(){
      int Opcion,cont,i;
      int contP=0,contC=0;
     do{
        regresarMenu:
        printf("\n|-------------------------------|");
        printf("\n|         QUE OPCION             |");
        printf("\n|-------------------------------|");
        printf("\n|  1. Cola       |  2.  Pilas   |");
        printf("\n|-------------------------------|");
        printf("\nOpcion: ");
        scanf("%i",&Opcion);
        switch(Opcion){
        case 1:
            do{
                printf("\n|------------------------------|");
                printf("\n|       MENU COLA              |");
                printf("\n|------------------------------|");
                printf("\n|1. AÑADIR  | 2. IMRIMIR       | ");
                printf("\n| 3. ELIMINAR | 4. RERESAR MENU|");
                printf("\n|------------------------------|");
                printf("\nOpcion: ");
                scanf("%i",&Opcion);
                switch(Opcion){
                case 1:
                printf("CUANTOS DIGITOS VAS A INGRESAR ");
                scanf("%i",&cont);

                contC = cont+contC;
                for(i=0;i<cont;i++)
                insertarCola();
                    break;
                case 2:
                    if(primeroC!=NULL){
                        printf("  \t\tCOLA\n");
                        printf("Primero en entrar, primero en Salir\n");
                    }

                    imprimirCola();

                    break;
                case 3:
                        EliminarCola();
                   if(primeroC!=NULL)
                    printf("Cola Eliminada\n");
                    break;
                case 4:
                    goto regresarMenu;
                    break;
                default:
                    printf("\nERROR DE OPCION\n");
                }
            }while(Opcion!=4);

            break;
        case 2:
                        do{
                printf("\n|------------------------------|");
                printf("\n|            MENU PILA	     |");
                printf("\n|------------------------------|");
                printf("\n|1. AÑADIR   | 2. IMPRIMIR     |");
                printf("\n| 3. ELIMINAR| 4. VOLVER AL MENU|");
                printf("\n|------------------------------|");
                printf("\nOpcion: ");
                scanf("%i",&Opcion);
                switch(Opcion){
                case 1:
                printf("CUANTOS DIGITOS VAS A INGRESAR ");
                    scanf("%i",&cont);

					contP = cont+contP;
                    for(i=0;i<cont;i++)
                        agregarPila();

                    break;
                case 2:
                    if(primeroP!=NULL){
                        printf("  \t\tPILA\n");
                        printf("Ultimo en entrar, primero en Salir\n");
                    }

                    imprimirPila();
                    break;
                case 3:
                    EliminarPila();

                    printf("se ha elimnado la pila\n");
                    break;
                case 4:
                    goto regresarMenu;
                    break;
                default:
                    printf("\n ERROR \n");
                }
            }while(Opcion!=4);

              default:
                printf("\nOpcion no Disponible\n\n");
        }

     }while(Opcion!=3);

    return 0;
 }
