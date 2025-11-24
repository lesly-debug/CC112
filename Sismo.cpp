#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
struct Sismo{
    int id;
    char fecha[20];
    char hora[20];
    double magnitud;
    char ubicacion[40];
};
int obtenerUltId();
void mostrarSismos();
void registrarSismos();
int main(){
    int opcion;
    do{
        cout<<"======================================"<<endl;
        cout<<"             MENU DE OPCIONES            "<<endl;
        cout<<"======================================"<<endl;
        cout<<"1. Mostrar todos los sismos registrados"<<endl;
        cout<<"2. Registrar sismo en el archivo"<<endl;
        cout<<"3. Salir del programa"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:{
                mostrarSismos();
                break;
            }
            case 2:{
                registrarSismos();
                break;
            }
        }
    }while(opcion!=3);
}
void mostrarSismos(){
    fstream archivo("sismos.txt",ios::in);
    if(archivo.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    Sismo s;
    while(archivo>>s.id>>s.fecha>>s.hora>>s.magnitud>>s.ubicacion){
        archivo.ignore();
        cout<<s.id<<" "<<s.fecha<<" "<<s.hora<<" "<<s.magnitud<<" "<<s.ubicacion<<endl;
    }
    archivo.close();
}
void registrarSismos(){
    int num;
    cout<<"Digite el numero de sismos por agregar: "<<endl;
    cin>>num;
    fstream archivo1("sismos.txt",ios::app);
    if(archivo1.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    cin.ignore();
    for(int i=0;i<num;i++){
        Sismo sx;
        cout<<"Fecha: ";
        cin.getline(sx.fecha,20);
        cout<<"Hora: ";
        cin.getline(sx.hora,20);
        cout<<"Magnitud: ";
        cin>>sx.magnitud;
        cin.ignore();
        cout<<"Ubicacion: ";
        cin.getline(sx.ubicacion,40);
        archivo1<<obtenerUltId()<<" "<<sx.fecha<<" "<<sx.hora<<" "<<sx.magnitud<<" "<<sx.ubicacion<<endl;
    }
    archivo1.close();
}
int obtenerUltId(){
    int ID=0;
    fstream archivo("sismos.txt",ios::in);
    if(archivo.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    Sismo sy;
    while(archivo>>sy.id>>sy.fecha>>sy.hora>>sy.magnitud>>sy.ubicacion){
        ID=sy.id;
    }
    archivo.close();
    return ID+1;
}