#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
struct Alumno{
    int codigo;
    char nombre[40];
    double nota;
};
int main(){
    int num;
    cout<<"Ingrese el numero de alumnos: ";
    cin>>num;
    fstream archivo("alumnos.dat",ios::binary|ios::out);
    for(int i=0;i<num;i++){
        Alumno a;
        cout<<"Codigo: ";
        cin>>a.codigo;
        cout<<"Nombre: ";
        cin.ignore();
        cin.getline(a.nombre,40,'\n');
        cout<<"Nota: ";
        cin>>a.nota;
        cin.ignore();
        archivo.write((char*)&a,sizeof(a));
    }
    archivo.close();
    archivo.open("alumnos.dat",ios::binary|ios::out|ios::in);
    for(int i=0;i<num;i++){
        for(int j=0;j<num-i-1;j++){
            Alumno a1,a2;
            archivo.seekg(j*sizeof(Alumno),ios::beg),
            archivo.read((char*)&a1,sizeof(a1));
            archivo.read((char*)&a2,sizeof(Alumno));
            if(a1.nota<a2.nota){
                archivo.seekp(j*sizeof(Alumno),ios::beg);
                archivo.write((char*)&a2,sizeof(a2));
                archivo.write((char*)&a1,sizeof(a1));
            }
        }
    }
    archivo.close();
    Alumno ax;
    archivo.open("alumnos.dat",ios::binary|ios::in);
    cout<<"Registros ordenados por nota (descendente): "<<endl;
    while(archivo.read((char*)&ax,sizeof(Alumno))){
        cout<<"Codigo: "<<ax.codigo<<"  Nombre:  "<<ax.nombre<<"  Nota:  "<<ax.nota<<endl;
    }
    archivo.close();
}