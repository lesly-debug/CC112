#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
//Autor Lesly Baltazar
struct TFECHA{
    int dia;
    int mes;
};
struct TCARGA{
    int numPasajeros;
    TFECHA* fecha;
};
int main(){
    int A[360];
    srand(time(0));
    for(int i=0;i<360;i++){
        A[i]=rand()%(700-500+1)+500;
    }
    int cargaMax=0;
    for(int i=0;i<360;i++){
        if(cargaMax<A[i]){
            cargaMax=A[i];
        }
    }
    int numDias=0;
    int cargaMin=(0.95*cargaMax);
    for(int i=0;i<360;i++){
        if(cargaMin<=A[i]){
            numDias++;
        }
    }
    cout<<"Se encontraron "<<numDias<<" dias con carga minima de "<<cargaMin<<" pasajeros"<<endl;
    TCARGA* listado;
    int k=0;
    listado=new TCARGA[numDias];
    for(int i=0;i<360;i++){
        if(A[i]>=cargaMin){
            listado[k].fecha=new TFECHA;
            listado[k].fecha->dia=i%30+1;
            listado[k].fecha->mes=i/30+1;
            listado[k].numPasajeros=A[i];
        k++;
        }
    }
    for(int i=0;i<numDias;i++){
        cout<<listado[i].fecha->dia<<" / "<<listado[i].fecha->mes<<" : "<<listado[i].numPasajeros<<endl;
    }
    delete[] listado;
}
