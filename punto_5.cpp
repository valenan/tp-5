/*Dada una colección de valores enteros, se pretende ordenar dicha colección
aplicando el algoritmo de ordenación por selección. En virtud de ello, se solicita:
a. Implemente mediante listas simplemente enlazadas la colección de valores
enteros.
b. Desarrolle los procedimientos/funciones necesarios para implementar el
algoritmo de ordenación por selección para la estructura definida.
c. Implemente dos método que permitan combinar dos listas, donde, el
resultado final es una lista única con los elementos de ambas listas.
Considerando que:
i. Para el primer método no importa el orden de los elementos de la
lista.
ii. Para el segundo método si importa el orden de los elementos de la
lista.

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
void ordenar(punt &lista,bool &ordenado);
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

int main(){
    punt lista;
    int valor,n=1;
    bool ordenado=false;
do{
cout<<"Ingrese un valor entero para ingresar un numero a la lista (0 para terminar): ";
cin>>valor;
if(valor!=0){
    punt nuevo=crear_nodo(valor);
    push(lista,nuevo);
}
else{
    cout<<"Fin de la insercion de numeros."<<endl;}
}while(n!=0);
cout<<"Ordenando la lista por seleccion..."<<endl;
ordenar(lista,ordenado);



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
void ordenar(punt &lista,bool &ordenado){
    if (vacia(lista)) 
        cout << "La lista esta vacia, no se puede ordenar." << endl;
    else{
    for(punt i = lista; i != NULL; i = i->sig) {
        punt min = i;
        for(punt j = i->sig; j != NULL; j = j->sig) {
            if(j->dato < min->dato) {
                min = j;
            }
        }
        if(min != i) {
            int temp = i->dato;
            i->dato = min->dato;
            min->dato = temp;
        }
    }
    ordenado=true;
}
};