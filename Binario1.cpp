#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
struct Usuario{
    int codigo;
    char nombre[40];
    double saldo;
};
int main(){
    int num;
    Usuario* u;
    cout<<"Ingrese el numero de usuarios: ";
    cin>>num;
    u=new Usuario[num];
    cin.ignore();
    for(int i=0;i<num;i++){
        cout<<"\nCodigo: ";
        cin>>u[i].codigo;
        cin.ignore();
        cout<<"Nombre: ";
        cin.getline(u[i].nombre,40,'\n');
        cout<<"Saldo: ";
        cin>>u[i].saldo;
    }
    fstream archivo("usuario.dat",ios::binary|ios::out|ios::app);
    if(archivo.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    for(int i=0;i<num;i++){
        archivo.write((char*)&u[i],sizeof(Usuario));
    }
    archivo.close();

    cout<<"Archivo creado"<<endl;
    cout<<"Contenido del archivo: "<<endl;
    for(int i=0;i<num;i++){
        cout<<"Codigo:      "<<u[i].codigo<<"       |    Nombre:       "<<u[i].nombre<<endl;
    }
    cout<<"Modificacion de saldo: "<<endl;
    int cod;
    int pos;
    double aumSaldo;
    bool encontrado=false;
    cout<<"Codigo de usuario: ";
    cin>>cod;
    for(int i=0;i<num;i++){
        if(u[i].codigo==cod){
            pos=i;
            encontrado=true;
        }
    }
    if(encontrado)){
        cout<<"Incremento del saldo: ";
        cin>>aumSaldo;
        u[pos].saldo=u[pos].saldo+aumSaldo;
        cout<<"Despues de modificar el saldo: "<<endl;
        cout<<"Nuevo contenido del archivo: "<<endl;
        for(int i=0;i<num;i++){
            cout<<"Codigo:      "<<u[i].codigo<<"       |    Nombre:       "<<u[i].nombre<<"  |     Saldo:          "<<u[i].saldo<<endl;
        }
        archivo.open("usuarios.dat"<ios::binary|ios::app|ios::out);
        archivo.write((char*)&u[pos],sizeof(Usuario));
        cout<<"\nUsuario modificado agregado al final del archivo.\n";
    }else{
        cout<<"Codigo no registrado, no hay cambios en el contenido del archivo";
    }
    archivo.close();
    delete[] u;
    return 0;
}