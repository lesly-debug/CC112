#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
void escribir();
int main(){
    escribir();
    return 0;
}
void escribir(){
    ofstream archivo;
    string nombre,frase;
    cout<<"Ingrese el nombre del archivo"<<endl;
    getline(cin,nombre);
    //no se puede colocar directamente nombre, cadena de acracteres, se deben de pasar a comandos de c (c_str() funcion contenida en fstream)
    archivo.open(nombre.c_str(),ios::out);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    cout<<"\nDigite el texto del archivo"<<endl;
    getline(cin,frase);
    archivo<<frase;
    archivo.close();
}