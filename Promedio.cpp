#include <iostream>
using namespace std;
struct Promedio{
    double n1;
    double n2;
    double n3;
};
struct Alumno{
    char nombre[30];
    int edad;
    char sexo[20];
    struct Promedio prom;
}a;
int main(){
    double promedio;
    cout<<"===Datos del alumno==="<<endl;
    cout<<"Nombre: ";
    cin.getline(a.nombre,30,'\n');
    cout<<"Edad: ";
    cin>>a.edad;
    cout<<"Sexo: ";
    cin.getline(a.sexo,20,'\n');
    cout<<"===Ingresando notas==="<<endl;
    cout<<"Nota 1:";
    cin>>a.prom.n1;
    cout<<"Nota 2: ";
    cin>>a.prom.n2,
    cout<<"Nota 3: ";
    cin>>a.prom.n3;
    promedio=(a.prom.n1+a.prom.n2+a.prom.n3)/3;
    cout<<"===Mostrando datos==="<<endl;
    cout<<"Nombre: "<<a.nombre;
    cout<<"Edad: "<<a.edad;
    cout<<"Sexo: "<<a.sexo;
    cout<<"Promedio: "<<promedio;
    return 0;
}