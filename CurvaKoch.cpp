#include <iostream>
using namespace std;
struct PUNTO2D{
    float x;
    float y;
};
struct POLIGONAL{
    int numVertices;
    PUNTO2D* punto;
};
int main(){
    PUNTO2D* vertices;
    POLIGONAL poligono;
    cout<<"Ingrese la cantidad de vertices: ";
    cin>>poligono.numVertices;
    vertices=new PUNTO2D[poligono.numVertices];
    return 0;
}