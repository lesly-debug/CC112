#include<iostream>
using namespace std;
class Rectangulo{
    private:
    double largo;
    double ancho;
    public:
    Rectangulo(double,double);
    void Perimetro();
    void Area();
};
Rectangulo::Rectangulo(double _largo,double _ancho){
    largo=_largo;
    ancho=_ancho;
}
void Rectangulo Perimetro(){
    cout<<"Perimetro: "<<(largo+ancho)*2<<endl;
}
void Rectangulo Area(){
    cout<<"Area: "<<largo*ancho<<endl;
}
int main(){
    Rectangulo r(2,3);
    r.Perimetro();
    r.Area();
    return 0;
}