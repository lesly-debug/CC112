#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
void escribirFibonacciBinario();
void leerFibonacciBinario();
int main(){
    escribirFibonacciBinario();
    leerFibonacciBinario();
    return 0;
}
void escribirFibonacciBinario(){
    fstream archivo("fibonacci.bin",ios::binary|ios::out);
    if(archivo.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    int Fibonacci[20];
    Fibonacci[0]=0;
    Fibonacci[1]=1;
    for(int i=2;i<20;i++){
        Fibonacci[i]=Fibonacci[i-1]+Fibonacci[i-2];
    }
    archivo.write((char*)Fibonacci,sizeof(Fibonacci));//Escribiendo el arreglo en archivo
    archivo.close();
    cout<<"Terminos de Fibonacci escritos correctamente"<<endl;
}
void leerFibonacciBinario(){
    fstream archivo1("fibonacci.bin",ios::binary|ios::in);
    if(archivo1.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    int F[20];
    archivo1.read((char*)F,sizeof(F));
    for(int i=0;i<20;i++){
        cout<<"Termino "<<i+1<<" : "<<F[i]<<endl;
    }
    archivo1.close();
}