#include <iostream>
using namespace std;
struct Empleado{
    char nombre[20];
    double salario;
};
Empleado *emp;
int numEmp;
int main(){
    int salMayor=0;
    int salMenor=0;
    cout<<"Ingrese el numero de empleados: ";
    cin>>numEmp;
    emp=new Empleado[numEmp];
    cout<<"===Registro de empleados==="<<endl;
    for(int i=0;i<numEmp;i++){
        if(i==0){cin.ignore();}
        cout<<"Nombre: ";
        cin.getline(emp[i].nombre,20,'\n');
        cout<<"Salario: ";
        cin>>emp[i].salario;
        cin.ignore();
    }
    cout<<"\n===Mostrando datos==="<<endl;
    for(int i=0;i<numEmp;i++){
        cout<<"Nombre: "<<emp[i].nombre<<endl;
        cout<<"Salario: "<<emp[i].salario<<endl;
    }
    for(int i=0;i<numEmp;i++){
        if(emp[i].salario>=emp[salMayor].salario){
            salMayor=i;
        }
    }
    for(int i=0;i<numEmp;i++){
        if(emp[i].salario<=emp[salMenor].salario){
            salMenor=i;
        }
    }
    cout<<"===Mostrando sueldo minimo y maximo==="<<endl;
    cout<<"Menor: "<<emp[salMenor].salario<<endl;
    cout<<"Mayor: "<<emp[salMayor].salario<<endl;
    delete[] emp;
    return 0;
}
