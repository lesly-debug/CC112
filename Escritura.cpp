#include <iostream>
#include <stdlib.h>
#include <fstream>
//f->file (archivo)
//Ayuda en la creacion, lectura y escritura de archivos en C++
//Al momento de cerrar el programa los datos se pierden, al crear archivos se pueden crear archivos de texto
//en el cual se pueden introducir datos del programa
//de tal manera que al cerrar el programa y al volver a abrirlo los datos estaran guardados
using namespace std;
void escribir();
int main(){
    escribir();
}
void escribir(){
    //o->(de) ouput Si existe se reemplaza y si no existe se crea un archivo
    ofstream archivo;
    //nombre o ubicacion, modo de optimizar (parametros)
    //ubicacion ejemplo d://prueba//ejemplo.txt, el nombre es ejemplo.txt, prueba es la carpeta, d es el disco
    archivo.open("prueba.txt",ios::out);//abriendo el archivo
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);//sirve para salir del programa, se necesita libreria stdlib.h
    }
    archivo<<"Hola que tal?";
    archivo.close();//sirve para cerrar el archivo
}