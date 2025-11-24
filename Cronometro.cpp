#include <iostream>
using namespace std;
struct Etapa{
    int horas;
    int minutos;
    int segundos;
}etp[3],*puntero_time=&etp[0];
int main(){
    int numHoras=0;
    int numMin=0;
    int numSeg=0;
    cout<<"\n===Registro de tiempo==="<<endl;
    for(int i=0;i<3;i++){
        cout<<"Etapa "<<i+1<<endl;
        cout<<"Horas: ";
        cin>>(puntero_time+i)->horas;
        cout<<"Minutos: ";
        cin>>(puntero_time+i)->minutos;
        cout<<"Segundos: ";
        cin>>(puntero_time+i)->segundos;
        numHoras=numHoras+((puntero_time+i)->horas);
        numMin=numMin+((puntero_time+i)->minutos);
        numSeg=numSeg+((puntero_time+i)->segundos);
    }
    numHoras=numHoras+(numMin/60);
    numMin=numMin%60;
    numMin=numMin+(numSeg/60);
    numSeg=numSeg%60;
    cout<<"\n===Mostrando tiempo total==="<<endl;
    cout<<"Horas: "<<numHoras<<endl;
    cout<<"Minutos: "<<numMin<<endl;
    cout<<"Segundos: "<<numSeg<<endl;
    return 0;
}