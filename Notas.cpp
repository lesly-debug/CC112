#include <iostream>
using namespace std;
struct alumno{
    char nombre[30];
    int edad;
    double promedio;
}a[3];
int main(){
    int posMax=0;
    cout<<"===Registro de alumnos==="<<endl;
    for(int i=0;i<3;i++){
        cout<<"Nombre: ";
        cin.getline(a[i].nombre,30,'\n');
        cout<<"Edad: ";
        cin>>a[i].edad;
        cout<<"Promedio: ";
        cin>>a[i].promedio;
        cin.ignore(); // limpia el salto de línea que dejó el último cin
    }
    cout<<"\n===Mostrando datos==="<<endl;
    for(int i=0;i<3;i++){
        cout<<"Alumno "<<i+1<<endl;
        cout<<"Nombre: "<<a[i].nombre<<endl;
        cout<<"Edad: "<<a[i].edad<<endl;
        cout<<"Promedio: "<<a[i].promedio<<endl;
    }
    for(int i=0;i<3;i++){
        if(a[i].promedio>=a[posMax].promedio){
            posMax=i;
        }
    }
    cout<<"===Alumno con mayor promedio==="<<endl;
    cout<<"Nombre: "<<a[posMax].nombre<<endl,
    cout<<"Edad: "<<a[posMax].edad<<endl;
    cout<<"Nota: "<<a[posMax].promedio<<endl;
    return 0;
}
