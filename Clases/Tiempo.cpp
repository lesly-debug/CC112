#include<iostream>
using namespace std;
class Tiempo{
    private:
    int horas,minutos,segundos;
    public:
    Tiempo(int,int,int);
    Tiempo(int);
    void mostrarTiempo();
};
Tiempo::Tiempo(int _horas,int _minutos,int _segundos){
    horas=_horas;
    minutos=_minutos;
    segundos=_segundos;
}
Tiempo::Tiempo(int tiempoSeg){
    horas=tiempoSeg/3600;
    tiempoSeg%=3600;
    minutos=tiempoSeg/60;
    segundos=tiempoSeg%60;
}
void Tiempo::mostrarTiempo(){
    cout<<"Hora: "<<horas<<":"<<minutos<<":"<<segundos<<endl;
}
int main(){
    Tiempo horaActual(16,23,30);
    Tiempo HaceUnaHora(55410);
    horaActual.mostrarTiempo();
    HaceUnaHora.mostrarTiempo();
    return 0;
}