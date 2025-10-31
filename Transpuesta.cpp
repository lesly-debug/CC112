#include <iostream>
#include <stdlib.h>
using namespace std;
void pedirDatos();
int numFil,numCol;
int **puntero_matriz;
void mostrarMatriz();
void mostrarTranspuesta();
int **intercambio,aux;
int main(){
    pedirDatos();
    mostrarMatriz();
    mostrarTranspuesta();
    for(int i=0;i<numFil;i++){
        delete[] puntero_matriz[i];
    }
    delete[] puntero_matriz;
    for(int i=0;i<numCol;i++){
        delete[] intercambio[i];
    }
    delete[] intercambio;
}
void pedirDatos(){
    cout<<"Digite el numero de filas: ";
    cin>>numFil;
    cout<<"Digite el numero de columnas: ";
    cin>>numCol;
    puntero_matriz=new int*[numFil];
    for(int i=0;i<numFil;i++){
        puntero_matriz[i]=new int[numCol];
    }
    cout<<"Ingrese los elementos: "<<endl;
    for(int i=0;i<numFil;i++){
        for(int j=0;j<numCol;j++){
            cout<<"Elemento "<<"["<<i+1<<"]"<<"["<<j+1<<"]: ";
            cin>>puntero_matriz[i][j];
        }
    }
    cout<<"\n";
}
void mostrarMatriz(){
    cout<<"\nMostrando la matriz: "<<endl;
    for(int i=0;i<numFil;i++){
        for(int j=0;j<numCol;j++){
            cout<<puntero_matriz[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void mostrarTranspuesta(){
    intercambio=new int*[numCol];
    for(int i=0;i<numCol;i++){
        intercambio[i]=new int[numFil];
    }
    for(int i=0;i<numFil;i++){
        for(int j=0;j<numCol;j++){
            intercambio[j][i]=puntero_matriz[i][j];
        }
    }
    cout<<"\nMostrando la transpuesta: "<<endl;
    for(int i=0;i<numCol;i++){
        for(int j=0;j<numFil;j++){
            cout<<intercambio[i][j];
        }
        cout<<"\n";
    }
}