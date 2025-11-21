//lectura de un archivo de texto
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
void lectura();
int main(){
    lectura();
    return 0;
}
void lectura(){
    //i->inpout (lectura)
    ifstream archivo;
    string texto;
    //nombre o ubicacion, d:\\carpeta\\nombre del txt
    archivo.open("Programacion.txt",ios::in);//Abriendo el archivo en modo lectura
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    //funcion eof recorre todo el archivo
    while(!archivo.eof()){//mientras no sea el final del archivo
        getline(archivo,texto);//copiando todo lo de archivo en texto
        cout<<texto<<endl;
    }
    archivo.close();//Cerrando el archivo
}