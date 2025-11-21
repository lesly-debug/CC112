#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
void escribir();
int main(){
    escribir();
    return 0;
}
void escribir(){
    ofstream archivo;
    string nombreArchivo;
    string frases[30];
    int num;
    cout<<"Digite el nombre del archivo: ";
    getline(cin,nombreArchivo);
    archivo.open(nombreArchivo.c_str(),ios::out);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    cout<<"Ingrese el numero de frases";
    cin>>num;
    cin.ignore();
    cout<<"Digite las frases: "<<endl;
    for(int i=0;i<num;i++){
        getline(cin,frases[i]);
        archivo<<frases[i]<<endl;
    }
    archivo.close();
}