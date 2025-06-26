#include<iostream>
using namespace std;
typedef struct tnodo *punt;
typedef struct tnodo{
    int dato;
    punt sig;
};
void crear_lista(punt &lista);
bool es_vacia(punt lista);
void nuevo_nodo(punt &nuevo);
void agregar_inicio (punt &lista, punt nuevo);
void agregar_ordenado(punt &lista, punt nuevo);
void agregar_final(punt &lista,punt nuevo);
bool buscar(punt lista, int dato);
punt eliminar_inicio(punt &lista);
punt eliminar_nodo(punt &lista, int dato);
void mostrar_lista(punt lista);
int minimo(punt lista);
int main(){
punt lista,nuevo;

    return 0;
};

void crear_lista(punt &lista){
    lista = NULL;
};
bool es_vacia(punt lista){
    return lista == NULL;
};
void nuevo_nodo(punt &nuevo){
   nuevo = new tnodo;
   if(nuevo != NULL){
    cout<<"Ingrese un dato: ";
    cin>>nuevo->dato;
    nuevo->sig = NULL;
   }
   else{
    cout<<"Memoria insuficiente"<<endl;
   }
};
void agregar_inicio(punt &lista,punt nuevo){
    nuevo -> sig = lista;
    lista = nuevo;
};
void agregar_ordenado(punt &lista, punt nuevo){
    punt i;
    if(lista==NULL)
        lista=nuevo;
    else{
        if(nuevo->dato<lista->dato){
            nuevo->sig=lista;
            lista=nuevo;
        }
        else{
            for(i=lista;i->sig!=NULL && nuevo->dato>(i->sig)->dato;i=i->sig){
                nuevo->sig = i->sig;
            i->sig = nuevo;
            }
            };

        }
    };
void agregar_final(punt &lista,punt nuevo){
if (es_vacia(lista)) {
        lista = nuevo;
    } else {
        punt i = lista;
        while (i->sig != NULL) {
            i = i->sig;
        }
        i->sig = nuevo;
    };
};
bool buscar(punt lista, int dato){
    punt i = lista;
    while (i != NULL) {
        if (i->dato == dato) {
            return true;
        }
        i = i->sig;
    }
    return false;
};
punt eliminar_inicio(punt &lista){
    punt borrado;
if(es_vacia(lista))
    borrado = NULL;
else{
    borrado = lista;
    lista = lista->sig;
    borrado->sig = NULL;
};
return borrado;
};
punt eliminar_final(punt &lista){
    punt borrado, i;
    if (lista == NULL)
        borrado = NULL;
    else {
        if (lista->sig==NULL){
            borrado=lista;
            lista = NULL;
        }
        else{
            for (i=lista;(i->sig)->sig!=NULL;i=i->sig){
                borrado =i->sig;
                i->sig = NULL;
            }
        }
    }
    return borrado;
};
punt eliminar_nodo(punt &lista, int dato){
    punt borrado;
    if(es_vacia(lista)) {
        borrado=nullptr; // Lista vacía, no se puede eliminar
    }
    else{
        if(lista->dato==dato){
    borrado=lista;
    lista=borrado->sig;
    borrado->sig = NULL;
            }
        else{
    for(punt i=lista;i->sig!=nullptr && i->sig->dato!=dato;i=i->sig)
    {
        if (i->sig != NULL) {
            borrado = i->sig;
            i->sig = borrado->sig;
            borrado->sig = NULL;
        }
        else {
            borrado = NULL; // No se encontró el nodo a eliminar
        }
    };
    }
    
        };
        return borrado;
};
void mostrar_lista(punt lista){
    punt i = lista;
    if(es_vacia(lista)){
        cout<<"Lista vacia"<<endl;
    }
    else{
        while(i!=NULL){
            cout<<i->dato<<" ";
            i=i->sig;
        }
        cout<<endl;
    }
};
int minimo(punt lista){
    int min=-999;
    if(es_vacia(lista)) {
        cout << "Lista vacía, no se puede encontrar el mínimo." << endl;
    }
else{
    punt i=lista;
    while(lista !=nullptr){
        if (min == -999 || i->dato < min) {
            min = i->dato;
        }
        i = i->sig;

    };
}
return min;
};
