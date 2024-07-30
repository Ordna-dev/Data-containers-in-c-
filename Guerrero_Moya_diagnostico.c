#include <stdio.h>
#include <string.h>
struct Persona{
char Nombre[50];
int Edad;
float Peso;
};
struct Persona Personas[50];
int UsuarioRegistrado=0;
void Llenar(){
    UsuarioRegistrado++;
    printf("Dame el nombre de la Persona %d\n",UsuarioRegistrado);
    scanf("%s",Personas[UsuarioRegistrado].Nombre);
    fflush(stdin);
    printf("Dame la edad de la Persona %d\n",UsuarioRegistrado);
    scanf("%d",&Personas[UsuarioRegistrado].Edad);
    printf("Dame el peso de la Persona %d\n",UsuarioRegistrado);
    scanf("%f",&Personas[UsuarioRegistrado].Peso);
}
void Buscar(char NombreUsuario[50]){
int encontrado=0;
    for(int i=0;i<=UsuarioRegistrado;i++){
        if(strcmp(Personas[i].Nombre, NombreUsuario) == 0){
            printf("\nPersona Encontrada !!\n");
            printf("Nombre: %s\n",Personas[i].Nombre);
            printf("Edad: %d\n",Personas[i].Edad);
            printf("Peso: %f\n\n",Personas[i].Peso);
            encontrado=1;
        }
    }
    if(encontrado==1){
        return;
    }
    printf("Persona no encontrada \n\n");
}
void ReemplazarDatos(char NombreUsuario[50], int EdadUsuario, float PesoUsuario){
int posicion=-1;
    for(int i=0;i<=UsuarioRegistrado;i++){
        if(strcmp(Personas[i].Nombre, NombreUsuario)== 0){
            posicion=i;
        }
    }
    for(int i=0;i<=UsuarioRegistrado;i++){
        if(Personas[i].Edad == EdadUsuario){
            posicion=i;
            }
    }
    for(int i=0;i<=UsuarioRegistrado;i++){
        if(Personas[i].Peso == PesoUsuario)
            posicion=i;
    }
    if(posicion>=0){
        printf("Modifica tu nombre\n");
        scanf("%s",Personas[posicion].Nombre);
        printf("Modifica tu edad\n");
        scanf("%d",&Personas[posicion].Edad);
        printf("Modifica tu peso\n");
        scanf("%f",&Personas[posicion].Peso);
    }else{
        printf("Persona no encontrada \n\n");
    }
}
int main(){
int Opcion;
char NombreUsuario[50];
int EdadUsuario;
float PesoUsuario;
printf("Ejercicio Diagnostico de: Seminario de Solucion de problemas de Estructuras de Datos\n");
do{
    printf("Menu de Opciones: \n 1.-Registrar Persona\n 2.-Consultar los datos de la Persona\n 3.-Reemplazar los datos de la Persona\n 4.-Salir del interfaz\n");
    scanf("%d",&Opcion);
        switch(Opcion){
            case 1:
            Llenar();break;
            case 2:
                if(UsuarioRegistrado>=1){
                char busqueda[50];
                    printf("Dame el nombre de la persona para consultar sus datos\n");
                    scanf("%s",busqueda);
                    Buscar(busqueda);
                }else{
                    printf("\nNo hay Personas Registradas\n");
                }break;
            case 3:
                if(UsuarioRegistrado>=1){
                    printf("Ingrese el nombre,la edad y su peso para reemplazar sus datos\n");
                    printf("Nombre:");
                    scanf("%s",NombreUsuario);
                    printf("\nEdad:");
                    scanf("%d",&EdadUsuario);
                    printf("\nPeso:");
                    scanf("%f",&PesoUsuario);
                    ReemplazarDatos(NombreUsuario,EdadUsuario,PesoUsuario);
                }else{
                    printf("\nNo hay Personas Registradas\n");
                }break;
            case 4: printf("Saliendo del interfaz...\n");break;
            default: printf("Opcion no valida\n");break;
}
}while(Opcion!=4);
return 0;
}
