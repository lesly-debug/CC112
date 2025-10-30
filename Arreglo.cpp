#include <iostream>
#include <stdlib.h>
using namespace std;
void pedirDatos();
int numCalif, *puntero_matriz;
void mostrarNotas();
int main(){
    pedirDatos();
    mostrarNotas();
    delete[] puntero_matriz;
    return 0;
}
void pedirDatos(){
    cout<<"Ingrese el numero de calificaciones: ";
    cin>>numCalif;
    puntero_matriz=new int[numCalif];
    cout<<"Digite las notas: "<<endl;
    for(int i=0;i<numCalif;i++){
        cin>>puntero_matriz[i];
    }
}
void mostrarNotas(){
    cout<<"Mostrando notas: "<<endl;
    for(int i=0;i<numCalif;i++){
        cout<<puntero_matriz[i]<<" ";
    }
}