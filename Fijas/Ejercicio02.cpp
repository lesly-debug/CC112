#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
//Autor: Lesly Baltazar
struct Vertice{
    double x;
    double y;
};
int main(){
    int nv;
    int nt;
    fstream archivo("laguna.txt",ios::in);
    if(archivo.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    archivo>>nt;
    archivo>>nv;
    Vertice*  vertices;
    vertices=new Vertice[nv];
    for(int i=0;i<nv;i++){
        archivo>>vertices[i].x>>vertices[i].y;
    }

    int **triangulo;
    triangulo=new int*[nt];
    for(int i=0;i<nt;i++){
        triangulo[i]=new int[3];
        archivo>>triangulo[i][0]>>triangulo[i][1]>>triangulo[i][2];
    }
    archivo.close();
    float areaLaguna=0;
    for(int i=0;i<nt;i++){
        int v1=triangulo[i][0]-1;
        int v2=triangulo[i][1]-1;
        int v3=triangulo[i][2]-1;
        float x1=vertices[v1].x;
        float y1=vertices[v1].y;
        float x2=vertices[v2].x;
        float y2=vertices[v2].y;
        float x3=vertices[v3].x;
        float y3=vertices[v3].y;
        float areaTrian;
        areaTrian=0.5*abs(x1*(y3-y2)+x2*(y1-y3)+x3*(y2-y1));
        areaLaguna=areaLaguna+areaTrian;
    }
    fstream archivo1("area.txt",ios::out);
    if(archivo1.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    archivo1<<"Area de laguna "<<areaLaguna;
    archivo1.close();

    delete[] vertices;
    for(int i=0;i<nt;i++){
        delete[] triangulo[i];
    }
    delete[] triangulo;
    return 0;
}