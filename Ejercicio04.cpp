#include <iostream>
using namespace std;
struct Termino{
    float coeficiente;
    int exponente;
}p1[20],p2[20],p3[40];
int n1,n2;
void pedirDatos();
void mostrarPolinomios();
void multiplicarPolinomios();
int main(){
    pedirDatos();
    mostrarPolinomios();
    multiplicarPolinomios();
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
void multiplicarPolinomios(){
    int k1=0;
    cout<<"\n====MOSTRANDO PRODUCTO===="<<endl;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            p3[k1].coeficiente=p1[i].coeficiente*p2[j].coeficiente;
            p3[k1].exponente=p1[i].exponente+p2[j].exponente;
            k1=k1+1;
        }
    }
    for(int i=0;i<k1;i++){
        for(int j=i+1;j<k1;j++){
            if(p3[i].exponente==p3[j].exponente){
                p3[i].coeficiente=p3[i].coeficiente+p3[j].coeficiente;
                for(int k=j;k<(k1-1);k++){
                p3[k]=p3[k+1];
            }
            k1=k1-1;
            j=j-1;
        }
    }
}
    for(int i=0;i<k1;i++){
        cout<<p3[i].coeficiente<<"x^"<<p3[i].exponente;
        if(i!=(k1-1)){
            cout<<"+";
        }
    }
}