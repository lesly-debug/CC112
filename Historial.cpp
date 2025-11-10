#include <iostream>
#include <cstring>

using namespace std;
struct Pagina{
    char URL[100];
    char titulo[50];
    char fecha[20];
    char hora[20];
    int ID;
}p[20];
int main(){
    int opcion;
    int c=0;
    p[0].ID=1;
    int id;
    bool encontrado=false;
    cout<<"---HISTORIAL DE NAVEGACION WEB---"<<endl;
    do{
        cout<<"1. Agregar entrada al historial";
        cout<<"\n2. Mostrar historial completo";
        cout<<"\n3. Eliminar una entrada por ID";
        cout<<"\n4. Buscar visitar por URL";
        cout<<"\n5. Limpiar historial completo:";
        cout<<"\n0. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;
        cin.ignore();
        switch(opcion){
        case 1:{
            cout<<"Ingrese la URL: ";
            cin.getline(p[c].URL,100,'\n');
            cout<<"Titulo de la pagina: ";
            cin.getline(p[c].titulo,50,'\n');
            cout<<"Fecha: ";
            cin.getline(p[c].fecha,20,'\n');
            cout<<"Hora: ";
            cin.getline(p[c].hora,20,'\n');
            cout<<">>Entrega agregada con ID: "<<p[c].ID<<endl;
            c=c+1;
            p[c].ID=p[c-1].ID+1;
            break;
        }
        case 2:{
            cout<<"---HISTORIAL DE NAVEGACION---"<<endl;
            for(int i=0;i<c;i++){
            cout<<"ID: "<<p[i].ID<<"| URL: "<<p[i].URL<<"| Titulo:"<<p[i].titulo<<"| Fecha:"<<p[i].fecha<<"| Hora:"<<p[i].hora<<endl;
            }
        break;
        }
        case 3:{
            cout<<"Ingrese el ID de la entrada a eliminar: ";
            cin>>id;
            encontrado=false;
            for(int i=0;i<c;i++){
                if(p[i].ID==id){
                    for(int j=i;j<c-1;j++){
                    p[j]=p[j+1];
                    }
                    c=c-1;
                    encontrado=true;
                }
            }
            if(encontrado){
            cout<<">>Entrada eliminada exitosamente"<<endl;
            }else{
            cout<<"ID ingresado no esta registrado"<<endl;
            }
            break;
        }
        case 4:{
            bool busqueda=false;
            Pagina p1;
            cout<<"Ingrese la URL a buscar: ";
            cin.getline(p1.URL,100,'\n');
            for(int i=0;i<c;i++){
            if(strcmp(p[i].URL,p1.URL)==0){
                p1=p[i];
                busqueda=true;}
            }
            if(busqueda){
                cout<<"Resultado encontrado: "<<endl;
                cout<<"ID: "<<p1.ID<<"| URL: "<<p1.URL<<"| Titulo:"<<p1.titulo<<"| Fecha:"<<p1.fecha<<"| Hora:"<<p1.hora<<endl;
            }else{
                cout<<"Pagina no encontrada"<<endl;
            }
            break;
        }
        case 5:{
            char r;
            cout<<"Confirme si desea borrar el historial (s/n)";
            cin>>r;
            if(r=='s'||r=='S'){
                c=0;
                p[0].ID=1;
                cout<<"Historial limpiado correctamente"<<endl;
            }else{
            cout<<"Opcion cancelada"<<endl;}
            break;
        }
    }
        }while(opcion!=0);
    return 0;
}