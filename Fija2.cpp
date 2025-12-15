#include <iostream>
#include <string>
#include <fstream>
#include <cmath> 
#include <iomanip> 

using namespace std;

void liberarMatrizInt(int** matriz, int filas) {
    if(matriz){
        for(int i=0;i<filas;++i) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }
}

void liberarMatrizDouble(double** matriz, int filas) {
    if(matriz){
        for(int i=0;i<filas;++i) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }
}

void modelarPreferencias(){
    int N,M;

    cout << "Ingrese numero de estudiantes (N): ";
    if (!(cin>>N)||N<=0) {
        cerr<<"Entrada invalida para el numero de estudiantes."<<endl;
        return;
    }

    cout<<"Ingrese numero de tecnologias (M): ";
    if(!(cin>>M)||M<=0){
        cerr<<"Entrada invalida para el numero de tecnologias."<<endl;
        return;
    }

    int** puntajes=new int*[N];
    for (int i=0;i<N;++i) {
        puntajes[i]=new int[M];
        cout<<"\nIngrese puntajes del estudiante "<<i+1<<" ("<<M<<" puntajes):\n";
        for (int j=0;j<M;++j){
            cout<<"  Tecnologia "<<j+1<<" (1-5): ";
            if (!(cin>>puntajes[i][j])||puntajes[i][j]<1||puntajes[i][j]>5) {
                cerr<<"Error: Puntaje invalido. Debe ser entre 1 y 5."<<endl;
                liberarMatrizInt(puntajes,i+1); 
                return;
            }
        }
    }
    double* promedios = new double[N];
    cout << "\nPromedios:\n";
    
    for (int i=0;i<N;++i) {
        double suma=0.0;
        for (int j=0;j<M;++j){
            suma+=puntajes[i][j];
        }
        promedios[i]=suma/M;
        cout<<"Estudiante "<<i+1<<": "<<fixed<<setprecision(2)<<promedios[i]<<endl;
    }

    double** sim=new double*[N];
    for (int i=0;i<N;++i) {
        sim[i]=new double[N];
    }

    cout<<"\nMatriz de similitud:\n";
    
    cout<<"        ";
    for(int j=0;j<N;++j) {
        cout<<"E"<<j+1<<"      ";
    }
    cout<<endl;

    for(int i=0;i<N;++i) {
        cout<<"E"<<i+1<<"      ";
        for(int j=0;j<N;++j) {
            if(i==j){
                sim[i][j]=1.0;
            }else{
                sim[i][j]=1.0-(fabs(promedios[i]-promedios[j])/4.0);
            }
            cout<<fixed<<setprecision(2)<<sim[i][j]<<"    ";
        }
        cout<<endl;
    }

    double max_similitud=-1.0;
    int est1=-1, est2=-1;

    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            if(sim[i][j]>max_similitud){
                max_similitud=sim[i][j];
                est1=i+1;
                est2=j+1;
            }
        }
    }
    
    if(est1!=-1){
        cout<<"\nLos estudiantes mas similares: " << est1 << " y " <<est2<<" (similitud = "<<fixed<<setprecision(2)<< max_similitud << ")" << endl;
    } else {
        cout << "\nNo hay suficientes estudiantes para comparar." << endl;
    }

    liberarMatrizInt(puntajes, N);
    delete[] promedios;            
    liberarMatrizDouble(sim, N);  
    
    cout << "\nMemoria liberada exitosamente." << endl; // <-- Línea 116 (si está fuera, da error)
}  

int main() {
    modelarPreferencias();
    return 0;
}