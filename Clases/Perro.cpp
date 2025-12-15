#include<iostream>
using namespace std;
class Perro{
    private:
    string nombre,raza;
    public:
    Perro(string,string);
    ~Perro();//destruye objeto de la clase
    void mostrarDatos();
    void jugar();
};
Perro::Perro(string _nombre,string _raza){
    nombre=_nombre;
    raza=_raza;
}
Perro::~Perro(){
}
void Perro::mostrarDatos(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Raza: "<<raza<<endl;
}
void Perro::jugar(){
    cout<<"El perro "<<nombre<<" esta jugando"<<endl;
}
int main(){
    Perro perro1("Fido","Doberman");
    perro1.mostrarDatos();
    perro1.jugar();
    perro1.~Perro();
    return 0;
}