#include <iostream>
#include <string.h>
using namespace std;
struct corredor{
    string nombre;
    int edad;
    string sexo;
    string club;
}c1;
int main(){
    char categoria[20];
    cout<<"Digite el nombre: ";
    cin>>c1.nombre;
    cout<<"Digite la edad: ",
    cin>>c1.edad;
    cout<<"Sexo: ";
    cin>>c1.sexo;
    cout<<"Club: ";
    cin>>c1.club;
    if(0<c1.edad && c1.edad<=18){
        strcpy(categoria,"Juvenil");
    }else if(18<c1.edad && c1.edad<=40){
        strcpy(categoria,"Senior");
    }else{
        strcpy(categoria,"Veterano");
    }
    cout<<"\nMostrando los datos"<<endl;
    cout<<"Nombre: "<<c1.nombre<<endl;
    cout<<"Edad: "<<c1.edad<<endl;
    cout<<"Sexo: "<<c1.sexo<<endl;
    cout<<"Club: "<<c1.club<<endl;
    cout<<"Categoria: "<<categoria<<endl;
    return 0;
}