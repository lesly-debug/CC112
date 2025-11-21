//Añadir texto al final del archivo
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
void aniadir();
int main(){
    aniadir();
    return 0;
}
void aniadir(){
    ofstream archivo;
    archivo.open("Programacion.txt",ios::app);//Abrimos el archivo en modo añadir, ios::app escribe el texto donde se quedo el marcador (|)
    if(archivo.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    archivo<<"23:43 20/11/2025";
    archivo.close();
}