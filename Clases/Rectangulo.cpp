#include <iostream>
using namespace std;
class Rectangulo{
    private:
    double largo;
    double ancho;
    public:
    Rectangulo(double,double);
    void perimetro();
    void area();
};
Rectangulo::Rectangulo(double _largo,double _ancho){
    largo=_largo;
    ancho=_ancho;
}
void Rectangulo::perimetro(){
    float _perimetro;
    _perimetro=(largo+ancho)*2;
    cout<<"Perimetro: "<<_perimetro<<endl;
}
void Rectangulo::area(){
    float _area;
    _area=largo*ancho;
    cout<<"Area: "<<_area<<endl;
}
int main(){
    Rectangulo r(2,3);
    r.perimetro();
    r.area();
    return 0;
}