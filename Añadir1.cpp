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
    string ubicacion;
    string linea;
    cout<<"Ingrese la ubicacion del fichero ";
    getline(cin,ubicacion);
    archivo.open(ubicacion.c_str(),ios::app);
    if(archivo.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    cout<<"Ingrese el texto para agregar"<<endl;
    while(getline(cin,linea)){
        if(linea=="FIN"){
            break;
        }
        archivo<<linea<<endl;
    }
    archivo.close();
    cout<<"Texto agregado correctamente al archivo";
}