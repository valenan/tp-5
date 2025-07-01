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
int primos(punt lista);

int main(){
    punt lista;
    int n=999,i;
    crear_lista(lista);
    do{
        if(n!=999){
            punt nuevo=crear_nodo(n);
            push(lista, nuevo);
        }
        cout << "Ingrese un numero entero a agregar a la lista (999 para terminar): ";
        cin >> n;
    }while(n!=999);
i=primos(lista);
    cout << "La cantidad de numeros primos en la lista es: " << i << endl;


    return 0;
};
punt crear_nodo(int valor){
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
int primos(punt lista){
    int contador = 0;
    punt aux = lista;
    while (aux != NULL) {
        int n = aux->dato;
        if (n > 1) {
            bool es_primo = true;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    es_primo = false;
                    break;
                }
            }
            if (es_primo)
                contador++;
        }
        aux = aux->sig;
    }
    return contador;
}