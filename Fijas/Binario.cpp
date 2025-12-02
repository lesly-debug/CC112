#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
struct Producto{
    int codigo;
    char nombre[20];
    float precio;
};
void pedirProducto();
int main(){
    pedirProducto();
    return 0;
}
void pedirProducto(){
    int num;
    Producto* p;
    cout<<"Numero de productos a registrar: ";
    cin>>num;
    p=new Producto[num];
    for(int i=0;i<num;i++){
        
        cout<<"Codigo: ";
        cin>>p[i].codigo;
        cout<<"Nombre: ";
        cin.ignore();
        cin.getline(p[i].nombre,20,'\n');
        cout<<"Precio: ";
        cin>>p[i].precio;
    }
    fstream archivo("productos.dat",ios::binary|ios::out|ios::app);
    if(archivo.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    for(int i=0;i<num;i++){
        archivo.write((char*)&p[i],sizeof(Producto));
    }
    archivo.close();
    delete[] p;
}