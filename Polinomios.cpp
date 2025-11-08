#include <iostream>
using namespace std;
struct Termino{
    float coeficiente;
    int exponente;
}p1[20],p2[20],p3[20];
int n1,n2;
void pedirDatos();
void mostrarPolinomios();
void sumaPolinomios();
int main(){
    pedirDatos();
    mostrarPolinomios();
    sumaPolinomios();
    return 0;
}
void pedirDatos(){
    cout<<"Ingrese el numero de terminos del primer polinomio: ";
    cin>>n1;
    for(int i=0;i<n1;i++){
        cout<<"Ingrese coeficiente y exponente del termino "<<i+1<<": "<<endl;
        cin>>p1[i].coeficiente;
        cin>>p1[i].exponente;
    }
    cout<<"Ingrese el numero de terminos del segundo polinomio: ";
    cin>>n2;
    for(int i=0;i<n2;i++){
        cout<<"Ingrese coeficiente y exponente del termino "<<i+1<<": "<<endl;
        cin>>p2[i].coeficiente;
        cin>>p2[i].exponente;
    }
}
void mostrarPolinomios(){
    cout<<"===MOSTRANDO POLINOMIOS==="<<endl;
    cout<<"Polinomio 1:";
    for(int i=0;i<n1;i++){
        cout<<p1[i].coeficiente<<"x^"<<p1[i].exponente;
        if(i!=(n1-1)){
            cout<<" + ";
        }
    }
    cout<<"\n";
    cout<<"Polinomio 2:";
    for(int i=0;i<n2;i++){
        cout<<p2[i].coeficiente<<"x^"<<p2[i].exponente;
        if(i!=(n2-1)){
            cout<<" + ";
        }
    }
    cout<<"\n";
}
void sumaPolinomios(){
    cout<<"===SUMA==="<<endl;
    int k=0;
    for(int i=0;i<n1;i++){
        int j;
        for(j=0;j<n2;j++){
            if(p1[i].exponente==p2[j].exponente){
                p3[k].exponente=p1[i].exponente;
                p3[k].coeficiente=p1[i].coeficiente+p2[j].coeficiente;
                k=k+1;
                break;
            }
        }
        if(j==n2){
            p3[k].coeficiente=p1[i].coeficiente;
            p3[k].exponente=p1[i].exponente;
            k=k+1;
        }
    }
    for(int i=0;i<n2;i++){
        int j=0;
        for(j=0;j<n1;j++){
            if(p1[j].exponente==p2[i].exponente){
                break;
            }
        }
        if(j==n1){
            p3[k].coeficiente=p2[i].coeficiente;
            p3[k].exponente=p2[i].exponente;
            k=k+1;
        }
    }
    for(int i=0;i<k;i++){
        cout<<p3[i].coeficiente<<"x^"<<p3[i].exponente;
        if(i!=(k-1)){
            cout<<"+";
        }
    }
}