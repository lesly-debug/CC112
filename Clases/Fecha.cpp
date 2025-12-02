#include<iostream>
using namespace std;
class Fecha{
    private:
    int dia;
    int mes;
    int anio;
    public:
    Fecha(int,int,int);
    Fecha(long);
    void mostrarFecha();
};
Fecha::Fecha(int _dia,int _mes,int _anio){
    dia=_dia;
    mes=_mes;
    anio=_anio;
}
Fecha::Fecha(long fecha){
    anio=int(fecha/10000);
    mes=int(fecha-anio*10000)/100;
    dia=int(fecha-anio*10000-mes*100);
}
void Fecha::mostrarFecha(){
    cout<<"Fecha: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
int main(){
    Fecha f(20170109);
    f.mostrarFecha();
    return 0;
}