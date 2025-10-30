#include <iostream>
#include <stdlib.h>
using namespace std;
void pedirDatos();
int numFil,numCol;
int **puntero_matriz1,**puntero_matriz2,**suma;
void mostrarMatrices();
void sumaMatriz();

int main (){
    pedirDatos();
    mostrarMatrices();
    sumaMatriz();
    for(int i=0;i<numFil;i++){
        delet[] puntero_matriz1[numFil];//Libera espacio de columnas
    }
    delete[] puntero_matriz1;//Libera espacio de filas
    for(int i=0;i<numFil;i++){
        delete[] puntero_matriz2[numFil];
    }
    delete[] puntero_matriz2;
    return 0;
}
void pedirDatos(){
    cout<<"Ingrese el numero de filas: ";
    cin>>numFil;
    cout<<"Ingrese el numero de columnas: ";
    cin>>numCol;
    puntero_matriz1=new int*[numFil];
    for(int i=0;i<numFil;i++){
        puntero_matriz1[i]=new int[numCol];
    }
    cout<<"Digite los elementos de la Matriz 1: "<<endl;
    for(int i=0;i<numFil;i++){
        for(int j=0;j<numCol;j++){
            cin>>puntero_matriz1[i][j];
        }
    }
    puntero_matriz2=new int*[numFil];
    for(int i=0;i<numFil;i++){
        puntero_matriz2[i]=new int[numCol];
    }
    cout<<"Digite los elementos de la Matriz 2: "<<endl;
    for(int i=0;i<numFil;i++){
        for(int j=0;j<numCol;j++){
            cin>>puntero_matriz2[i][j];
        }
    }
}
void mostrarMatrices(){
    cout<<"\nMostrando matrices"<<endl;
    for(int i=0;i<numFil;i++){
        for(int j=0;j<numCol;j++){
            cout<<puntero_matriz1[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(int i=0;i<numFil;i++){
        for(int j=0;j<numCol;j++){
            cout<<puntero_matriz2[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void sumaMatriz(){
    suma=new int*[numFil];
    for(int i=0;i<numFil;i++){
        suma[i]=new int[numCol];
    }
    for(int i=0;i<numFil;i++){
        for(int j=0;j<numCol;j++){
            suma[i][j]=puntero_matriz1[i][j]+puntero_matriz2[i][j];
        }
        cout<<"\n";
    }
    cout<<"Mostrando matriz suma: "<<endl;
    for(int i=0;i<numFil;i++){
        for(int j=0;j<numCol;j++){
            cout<<suma[i][j]<<" ";
        }
        cout<<"\n";
    }
}