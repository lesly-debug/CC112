#include <iostream>
using namespace std;

int* crearArreglo(int);
void leerRespuestas(int*,int);
float calcularPromedio(int*,int);
void mostrarFrecuencias(int*,int);
int* calcularModa(int*,int,int&);
void destruirArreglo(int*&);

int main(){
    int num;
    float prom;
    int* moda;
    int modita;
    cout<<"Ingrese el numero de encuestados: ";
    cin>>num;
    int *valor=crearArreglo(num);
    leerRespuestas(valor,num);
    prom=calcularPromedio(valor,num);
    cout<<"Promedio de satisfaccion: "<<prom;
    mostrarFrecuencias(valor,num);
    moda=calcularModa(valor,num,modita);
    cout<<"Moda(s)"<<endl;
    for(int i=0;i<modita;i++){
        cout<<moda[i]<<" ";
    }
    return 0;
}
int* crearArreglo(int n){
    int* rpta;
    rpta=new int[n];
    return rpta;
}
void leerRespuestas(int* rpta,int n){
    cout<<"Ingrese las respuestas (valores del 1 al 5): ";
    for(int i=0;i<n;i++){
        cin>>rpta[i];
    }
}
float calcularPromedio(int* rpta,int n){
    int suma=0;
    for(int i=0;i<n;i++){
        suma=suma+rpta[i];
    }
    return suma/n;
}
void mostrarFrecuencias(int* rpta,int n){
    int c1=0,c2=0,c3=0,c4=0,c5=0;
    for(int i=0;i<n;i++){
        if(rpta[i]==1){
            c1=c1+1;
        }
        if(rpta[i]==2){
            c2=c2+1;
        }
        if(rpta[i]==3){
            c3=c3+1;
        }
        if(rpta[i]==4){
            c4=c4+1;
        }
        if(rpta[i]==5){
            c5=c5+1;
        }
    }
    cout<<"\nFrecuencia de respuestas: "<<endl;
    cout<<"1: "<<c1<<endl;
    cout<<"2: "<<c2<<endl;
    cout<<"3: "<<c3<<endl;
    cout<<"4: "<<c4<<endl;
    cout<<"5: "<<c5<<endl;
}
int* calcularModa(int* rpta,int n,int& numModas){
    int c1=0,c2=0,c3=0,c4=0,c5=0;
    int* moda;
    for(int i=0;i<n;i++){
        if(rpta[i]==1){
            c1=c1+1;
        }
        if(rpta[i]==2){
            c2=c2+1;
        }
        if(rpta[i]==3){
            c3=c3+1;
        }
        if(rpta[i]==4){
            c4=c4+1;
        }
        if(rpta[i]==5){
            c5=c5+1;
        }
    }
    numModas=0;
    if(c1>=c2&&c1>=c3&&c1>=c4&&c1>=c5){
        numModas++;
    }if(c2>=c1&&c2>=c3&&c2>=c4&&c2>=c5){
        numModas++;
    }
    if(c3>=c1&&c3>=c2&&c3>=c4&&c3>=c5){
        numModas++;
    }
    if(c4>=c1&&c4>=c2&&c4>=c3&&c4>=c5){
        numModas++;
    }
    if(c5>=c1&&c5>=c2&&c5>=c3&&c5>=c4){
       numModas++;
    }
    moda=new int[numModas];
    int indice=0;
    if(c1>=c2&&c1>=c3&&c1>=c4&&c1>=c5){
        moda[indice]=1;
        indice=indice+1;
    }if(c2>=c1&&c2>=c3&&c2>=c4&&c2>=c5){
        moda[indice]=2;
        indice=indice+1;
    }
    if(c3>=c1&&c3>=c2&&c3>=c4&&c3>=c5){
        moda[indice]=3;
        indice=indice+1;
    }
    if(c4>=c1&&c4>=c2&&c4>=c3&&c4>=c5){
        moda[indice]=4;
        indice=indice+1;
    }
    if(c5>=c1&&c5>=c2&&c5>=c3&&c5>=c4){
       moda[indice]=5;
    }
    return moda;
}
//int calcularModa(int* rpta,int n){
    //int c1=0,c2=0,c3=0,c4=0,c5=0;
    //int moda;
    //for(int i=0;i<n;i++){
        //if(rpta[i]==1){
            //c1=c1+1;
        //}
        //if(rpta[i]==2){
            //c2=c2+1;
        //}
        //if(rpta[i]==3){
            //c3=c3+1;
        //}
        //if(rpta[i]==4){
            //c4=c4+1;
        //}
        //if(rpta[i]==5){
            //c5=c5+1;
        //}
    //}
    //if(c1>=c2&&c1>=c3&&c1>=c4&&c1>=c5){
        //moda=1;
    //}
    //if(c2>=c1&&c2>=c3&&c2>=c4&&c2>=c5){
        //moda=2;
    //}
    //if(c3>=c1&&c3>=c2&&c3>=c4&&c3>=c5){
        //moda=3;
    //}
    //if(c4>=c1&&c4>=c2&&c4>=c3&&c4>=c5){
       // moda=4;
    //}
    //if(c5>=c1&&c5>=c2&&c5>=c3&&c5>=c4){
       // moda=5;
    //}else{
        //n=n-1;
    //}
    //return moda;
//} CASO: SOLO UNA MODA, en main solo se le agrega int moda=calcularModa(variables);