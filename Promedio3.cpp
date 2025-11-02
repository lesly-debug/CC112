#include <iostream>
using namespace std;
struct Alumno{
    char nombre[30];
    int edad;
    double promedio;
}a[3];
Alumno *puntero_alumno=&a[0];
int main(){
    int pos=0;
    cout<<"===Registro de alumnos==="<<endl;
    for(int i=0;i<3;i++){
        cout<<"Alumno "<<i+1<<endl;
        cout<<"Nombre: ";
        cin.getline((puntero_alumno+i)->nombre,30,'\n');
        cout<<"Edad: ";
        cin>>(puntero_alumno+i)->edad;
        cout<<"Promedio: ";
        cin>>(puntero_alumno+i)->promedio;
        cout<<"\n";
        if((puntero_alumno+i)->promedio>(puntero_alumno+0)->promedio){
            pos=i;
        }
        cin.ignore();
    }
    cout<<"===Mostrando datos del mejor alumno==="<<endl;
    cout<<(puntero_alumno+pos)->nombre<<endl;
    cout<<(puntero_alumno+pos)->edad<<endl;
    cout<<(puntero_alumno+pos)->promedio<<endl;
    return 0;
}