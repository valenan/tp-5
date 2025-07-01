#include<iostream>
using namespace std;
typedef struct tnodo *punt;
struct tnodo{
    int dato;
    punt sig;
    punt ant;
};
void iniciar(punt &lista);
punt crear_nodo(int dato);
bool vacia(punt lista);
void pushi(punt &lista, punt nuevo);
void pushf(punt &lista,punt nuevo);
void pusho(punt &lista, punt nuevo);
punt popi(punt &lista);
punt popf(punt &lista);
punt pop(punt &lista,int valor);
bool buscar(punt lista,int valor);
void mostrar(punt lista);
void menu (int &n);

int main(){
punt lista,nuevo;
int dato,n;
iniciar(lista);
do{
    menu(n);
switch(n){
case 1:
cout<<"Ingrese dato a añadir(al principio)"<<endl;
cin>>dato;
nuevo=crear_nodo(dato);
pushi(lista,nuevo);
cout<<"Elemento añadido"<<endl;
break;
case 2:
cout<<"Ingrese dato a añadir(al final)"<<endl;
cin>>dato;
nuevo=crear_nodo(dato);
pushf(lista,nuevo);
cout<<"Elemento añadido"<<endl;
break;
case 3:
cout<<"Ingrese dato a añadir(odenado)"<<endl;
cin>>dato;
nuevo=crear_nodo(dato);
pusho(lista,nuevo);
cout<<"Elemento añadido"<<endl;
break;
case 4:
nuevo=popi(lista);
if(nuevo==NULL)
    cout<<"Lista vacia"<<endl;
else
cout<<"Se extrajo el elemento: "<<nuevo->dato<<" del inicio"<<endl;
break;
case 5:
nuevo=popf(lista);
if(nuevo==NULL)
    cout<<"Lista vacia"<<endl;
else
cout<<"Se extrajo el elemento: "<<nuevo->dato<<" del final"<<endl;
break;
case 6:
cout<<"Ingrese dato a borrar: "<<endl;
cin>>dato;
nuevo=pop(lista,dato);
if(nuevo==NULL)
    cout<<"Lista vacia/no se encontro el dato"<<endl;
else
cout<<"Se extrajo el elemento: "<<nuevo->dato<<endl;
break;
case 7:
cout<<"Ingrese dato a buscar"<<endl;
cin>>dato;
if(buscar(lista,dato))
cout<<"Valor encontrado"<<endl;
else
cout<<"valor no encontrado"<<endl;
break;
case 8:
mostrar(lista);
break;

}
}while(n!=0);



    return 0;
}
void iniciar(punt &lista){
    lista = NULL;
};
punt crear_nodo(int dato){
    punt nuevo = new tnodo;
    nuevo->dato= dato;
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    return nuevo;
}
bool vacia(punt lista){
    return lista == NULL;
}
void pushi(punt &lista, punt nuevo){
    if (vacia(lista))
    lista=nuevo;
    else{
        nuevo->sig=lista;
        lista->ant=nuevo;
        lista=nuevo;
    }
}
void pushf(punt &lista, punt nuevo){
    if (vacia(lista))
    lista=nuevo;
    else{
        punt aux=lista;
        while (aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=nuevo;
        nuevo->ant=aux;
        nuevo->sig=NULL;
    }
}
void pusho(punt &lista, punt nuevo){
    if (vacia(lista))
    lista=nuevo;
    else{
        punt aux=lista;
        while(nuevo->dato>aux->dato&&aux->sig!=NULL){
            aux=aux->sig;
        }
        if (aux->sig==NULL && nuevo->dato>aux->dato){
            aux->sig=nuevo;
            nuevo->ant=aux;
            nuevo->sig=NULL;
    }
    else if (aux==lista)
            pushi(lista,nuevo);
    else{
        nuevo->sig=aux;
        nuevo->ant=aux->ant;
        aux->ant->sig=nuevo;
        aux->ant=nuevo;
    }
    }
}
punt popi(punt &lista){
    if(vacia(lista))
        return NULL;

    punt aux = lista;
    lista = lista->sig;

    if (lista != NULL)
        lista->ant = NULL;

    aux->sig = NULL;
    aux->ant = NULL;
    return aux;
}
punt popf(punt &lista){
    if(vacia(lista))
    return NULL;
    else{
        punt aux=lista;
        while(aux->sig!=nullptr){
            aux=aux->sig;
        }
        if (aux==lista)
            lista=nullptr;
        
        else{
            aux->ant->sig=nullptr;
            aux->ant=nullptr;
    }
    aux->sig=nullptr;
    return aux;
}
    }
punt pop(punt &lista, int valor){
    if(vacia(lista))
        return NULL;

    punt aux = lista;
    while (aux != NULL && aux->dato != valor) {
        aux = aux->sig;
    }

    if (aux == NULL)
        return NULL;
    else if (aux == lista)
        return popi(lista);
    else if (aux->sig == NULL)
        return popf(lista);
    else {
        aux->ant->sig = aux->sig;
        aux->sig->ant = aux->ant;
        aux->sig = NULL;
        aux->ant = NULL;
        return aux;
    }
}
bool buscar(punt lista,int valor){
    punt aux=lista;
while(aux!=nullptr)
{
    if(aux->dato==valor)
    return true;
    aux=aux->sig;
}
    return false;
}
void mostrar (punt lista){
    punt aux=lista;
while(aux!=nullptr)
{
    cout<<aux->dato<<" -> ";
    aux=aux->sig;
}
cout<<endl;
}
void menu (int &n){
    cout<<"MENU"<<endl;
    cout<<"1) Agregar elemento al inicio"<<endl;
    cout<<"2) Agregar elemento al final"<<endl;
    cout<<"3) Agregar elemento ordenado"<<endl;
    cout<<"4) Sustraer primer elemento"<<endl;
    cout<<"5) Sustraer ultimo elemento"<<endl;
    cout<<"6) Sustraer elemento indicado"<<endl;
    cout<<"7) Buscar elemento"<<endl;
    cout<<"8) Mostrar lista"<<endl;
    cout<<"0) Salir"<<endl;
    cin>>n;
}