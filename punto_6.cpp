/*
Haciendo uso de listas genérica que realice:
a. Que la lista se cargue con números enteros y realice una función que busque
números primos dentro de la lista y los cuente. Muestre el resultado de la
cuenta.
b. Que la lista se cargue con caracteres y realice la cuenta de mayúsculas y
minúsculas dentro de la lista. Muestre los resultados por pantalla.
*/
#include <iostream>
using namespace std;
typedef struct tnodo *punt;
struct tnodo{
    int dato;
    punt sig;
};
punt crear_nodo(int valor);
void crear_lista(punt &lista);
void push(punt &lista, punt nuevo);
bool vacia(punt lista){
    return lista==NULL;
};
void mostrar(punt lista){
    punt aux=lista;
    if (vacia(lista)) {
        cout << "La lista esta vacia." << endl;
    }
    else{
        while(aux!=NULL){
            cout<<aux->dato<<" ";
            aux=aux->sig;
        };
        cout<<endl;
    }
};
int mayus(punt lista);
int minusc(punt lista);

int main(){
    punt lista,nuevo;
    char dato,c;
    int may,min;
    crear_lista(lista);
    do{
        cout<<"Ingrese un caracter (/ para terminar): ";
        cin>>dato;
        if(dato!='/'){
            nuevo=crear_nodo(dato);
            push(lista,nuevo);
        }
    }while(c!='/');
    cout<<"Lista cargada: ";
    mostrar(lista);
may=mayus(lista);
min=minusc(lista);
cout<<"Se encontraron "<<may<<" mayusculas y "<<min<<" minusculas."<<endl;
    return 0;
};
punt crear_nodo(char valor){
    punt nuevo=new tnodo;
    nuevo->dato=valor;
    nuevo->sig=NULL;
    return nuevo;
}
void crear_lista(punt &lista){
    lista=NULL;
};
void push(punt &lista, punt nuevo){
    if (vacia(lista))
    lista=nuevo;
    else{
        punt aux=lista;
        while(aux->sig!=NULL){
            aux=aux->sig;
        };
        aux->sig=nuevo;
    }
};
int mayus(punt lista){
    if(vacia(lista)) {
        return 0;
    }
    int contador=0;
    punt aux=lista;
    while(aux!=NULL){
        if (aux->dato >= 'A' && aux->dato <= 'Z') {
            contador++;
        }
        aux = aux->sig;
    };
    return contador;
};
int minusc(punt lista){
    if (vacia(lista)) {
        return 0;
    }
    int contador=0;
    punt aux=lista;
    while(aux!=NULL){
        if (aux->dato >= 'a' && aux->dato <= 'z') {
            contador++;
        }
        aux = aux->sig;
    };  
};
