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
float seno(float angulo) {
    return angulo-(angulo*angulo*angulo)/6+(angulo*angulo*angulo*angulo*angulo)/120-(angulo*angulo*angulo*angulo*angulo*angulo*angulo)/5040;
}
float coseno(float angulo) {
    return 1-(angulo*angulo)/2+(angulo*angulo*angulo*angulo)/24-(angulo*angulo*angulo*angulo*angulo*angulo)/720;
}
int main(){
    POLIGONAL poligono;
    float r;
    cout<<"Ingrese la cantidad de vertices: ";
    cin>>poligono.numVertices;
    poligono.punto=new PUNTO2D[poligono.numVertices+1];
    cout<<"Ingrese el radio del poligono regular: ";
    cin>>r;
    float PI=3.14159;
    float theta;
    for(int i=0;i<poligono.numVertices;i++){
        theta=i*((2*PI)/poligono.numVertices);
        poligono.punto[i].x=r*coseno(theta);
        poligono.punto[i].y=r*seno(theta);
    }
    poligono.punto[poligono.numVertices]=poligono.punto[0];
    float cos60 = 0.5;
    float sin60 = 0.8660;
    cout<<"\n--- PRIMERA ITERACION DE KOCH ---"<<endl;
    for(int i=0;i<poligono.numVertices;i++) {
        PUNTO2D A=poligono.punto[i];
        PUNTO2D B=poligono.punto[i+1];

        PUNTO2D P1,P2,P3;
        P1.x=A.x+(B.x-A.x)/3;
        P1.y=A.y+(B.y-A.y)/3;

        P2.x=A.x+2*(B.x-A.x)/3;
        P2.y=A.y+2*(B.y-A.y)/3;

        float dx = P2.x-P1.x;
        float dy = P2.y-P1.y;

        P3.x=P1.x+(dx*cos60-dy*sin60);
        P3.y=P1.y+(dx*sin60+dy*cos60);

        cout<<"Lado "<<i+1<<":\n";
        cout<< "(" <<A.x<<", "<<A.y<<")\n";
        cout<< "(" <<P1.x<<","<<P1.y<<")\n";
        cout<< "(" <<P3.x<<","<<P3.y<<")\n";
        cout<< "(" <<P2.x<<","<<P2.y<<")\n";
        cout<< "(" <<B.x<<", "<<B.y<<")\n\n";
    }

    delete[] poligono.punto;
    return 0;
}