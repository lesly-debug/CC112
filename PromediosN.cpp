#include <iostream>
using namespace std;
struct Promedio{
    double nota1;
    double nota2;
    double nota3;
};
struct Alumno{
    char nombre[30];
    char sexo[20];
    int edad;
    struct Promedio prom;
};
Alumno *pntr_alumno;
int posMax=0;
int main(){
    int n;
    double *promedio;
    cout<<"Digite el numero de alumnos: ";
    cin>>n;
    pntr_alumno=new Alumno[n];
    promedio=new double[n];
    cout<<"===Registrando datos==="<<endl;
    for(int i=0;i<n;i++){
        if(i==0){
            cin.ignore();
        }
        cout<<"Alumno "<<i+1<<endl;
        cout<<"Nombre: ";
        cin.getline(pntr_alumno[i].nombre,30,'\n');
        cout<<"Edad: ";
        cin>>pntr_alumno[i].edad;
        cin.ignore();
        cout<<"Sexo: ";
        cin.getline(pntr_alumno[i].sexo,20,'\n');
        cout<<"Ingrese las notas: "<<endl;
        cin>>pntr_alumno[i].prom.nota1;
        cin>>pntr_alumno[i].prom.nota2;
        cin>>pntr_alumno[i].prom.nota3;
        promedio[i]=(pntr_alumno[i].prom.nota1+pntr_alumno[i].prom.nota2+pntr_alumno[i].prom.nota3)/3;
        cin.ignore();
    }

    cout<<"===Mostrando datos del mejor alumno==="<<endl;
    for(int i=0;i<n;i++){
        if(promedio[i]>promedio[posMax]){
            posMax=i;
        }
    }
    cout<<"Nombre: "<<pntr_alumno[posMax].nombre<<endl;
    cout<<"Edad: "<<pntr_alumno[posMax].edad<<endl;
    cout<<"Sexo: "<<pntr_alumno[posMax].sexo<<endl;
    cout<<"Promedio: "<<promedio[posMax]<<endl;
    return 0;
}