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
    ifstream archivo;
    string nombre;
    string texto;
    cout<<"Ingrese la ubicacion del fichero ";
    getline(cin,nombre);
    archivo.open(nombre.c_str(),ios::in);
    if(archivo.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    while(getline(archivo,texto)){//OJO !archivo.eof() no es recomendado porque se activa al ir mas alla del final
        cout<<texto;
    }
    archivo.close();
}