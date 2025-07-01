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
void menu(int &n){
    cout<<"Menu de opciones:"<<endl;
    cout<<"1. Ordenar lista 1."<<endl;
    cout<<"2. Ordenar lista 2."<<endl;
    cout<<"3. Mostrar lista 1."<<endl;
    cout<<"4. Mostrar lista 2."<<endl;
    cout<<"5. Combinar listas sin importar el orden."<<endl;
    cout<<"6. Combinar listas importando el orden."<<endl;
    cout<<"7. Salir."<<endl;
    cin>>n;
};
void combinar_desordenado(punt lista, punt lista2, punt &lista3);
void combinar_ordenado(punt lista, punt lista2, punt &lista3,bool &ordenado,bool &ordenado2);

int main(){
    punt lista,lista2,lista3;
    int valor,n;
    bool ordenado=false,ordenado2=false;
do{
cout<<"Ingrese un valor entero para ingresar un numero a la lista 1 (0 para terminar): ";
cin>>valor;
if(valor!=0){
    punt nuevo=crear_nodo(valor);
    push(lista,nuevo);
}
else{
    cout<<"Fin de la insercion de numeros."<<endl;}
}while(n!=0);
do{
cout<<"Ingrese un valor entero para ingresar un numero a la lista 2 (0 para terminar): ";
cin>>valor;
if(valor!=0){
    punt nuevo=crear_nodo(valor);
    push(lista2,nuevo);
}
else{
    cout<<"Fin de la insercion de numeros."<<endl;}
}while(n!=0);
do{
menu(n);
switch(n){
    case 1:
        ordenar(lista,ordenado);
        if(ordenado)
            cout<<"Lista 1 ordenada correctamente."<<endl;
        else
            cout<<"No se pudo ordenar la lista 1."<<endl;
        break;
    case 2:
        ordenar(lista2,ordenado2);
        if(ordenado2)
            cout<<"Lista 2 ordenada correctamente."<<endl;
        else
            cout<<"No se pudo ordenar la lista 2."<<endl;
        break;
    case 3:
        mostrar(lista);
        break;
    case 4:
        mostrar(lista2);
        break;
    case 5:
        combinar_desordenado(lista, lista2, lista3);
        mostrar(lista3);
        break;
    case 6:
        combinar_ordenado(lista, lista2, lista3, ordenado, ordenado2);
        break;
    case 7:
        cout<<"Saliendo del programa."<<endl;
        break;
    default:
        cout<<"Opcion no valida, intente de nuevo."<<endl;
};
}while(n!=0);


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
void combinar_desordenado(punt lista, punt lista2, punt &lista3){
    punt aux1=lista;
    punt aux2=lista2;
    while(aux1!=NULL|| aux2!=NULL){
        if(aux1!=NULL){
            push(lista3,crear_nodo(aux1->dato));
            aux1=aux1->sig;
        }
        if(aux2!=NULL){
            push(lista3,crear_nodo(aux2->dato));
            aux2=aux2->sig;
        }
    }
};
void combinar_ordenado(punt lista, punt lista2, punt &lista3,bool &ordenado,bool &ordenado2){
    if(!ordenado|| !ordenado2)
    {cout<<"Las listas no esta ordenadas, se ordenaran antes de seguir"<<endl;
        ordenar(lista,ordenado);
        ordenar(lista2,ordenado2);
}
else{
    punt aux1=lista;
    punt aux2=lista2;
    while(aux1!=NULL|| aux2!=NULL){
        if(aux1!=NULL && (aux2==NULL || aux1->dato <= aux2->dato)){
            push(lista3,crear_nodo(aux1->dato));
            aux1=aux1->sig;
        }
        else if(aux2!=NULL){
            push(lista3,crear_nodo(aux2->dato));
            aux2=aux2->sig;
        }
    }
}
}