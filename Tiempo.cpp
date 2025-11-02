#include <iostream>
using namespace std;
struct Etapa{
    int horas;
    int minutos;
    int segundos;
};
Etapa *pntr_time;
int main(){
    int n;
    int numHoras=0;
    int numMin=0;
    int numSeg=0;
    cout<<"Digite el numero de etapas: ";
    cin>>n;
    pntr_time=new Etapa[n];
    cout<<"\n===Registro de tiempos==="<<endl;
    cout<<"Digite los datos"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Etapa "<<i+1<<endl;
        cout<<"Horas: ";
        cin>>pntr_time[i].horas;
        cout<<"Minutos: ";
        cin>>pntr_time[i].minutos;
        cout<<"Segundos: ";
        cin>>pntr_time[i].segundos;
        numHoras=numHoras+pntr_time[i].horas;
        numMin=numMin+pntr_time[i].minutos;
        numSeg=numSeg+pntr_time[i].segundos;
        if(pntr_time[i].minutos>=60){
            numHoras=numHoras+1;
            numMin=pntr_time[i].minutos-60;
        }
        if(pntr_time[i].segundos>=60){
            numMin=pntr_time[i].minutos+1;
            numSeg=pntr_time[i].segundos-60;
        }
    }
    cout<<"\n===Mostrando tiempo total==="<<endl;
    cout<<"Horas totales: "<<numHoras<<endl;
    cout<<"Minutos totales: "<<numMin<<endl;
    cout<<"Segundos totales: "<<numSeg<<endl;
    delete[] pntr_time;
    return 0;
}