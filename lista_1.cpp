#include<iostream>
using namespace std;
typedef struct tnodo *punt;
struct tnodo{
    int dato;
    punt sig;
};
void menu(int &n);
void crear_lista(punt &lista);
bool es_vacia(punt lista);
void nuevo_nodo(punt &nuevo);
void agregar_inicio (punt &lista, punt nuevo);
void agregar_ordenado(punt &lista, punt nuevo);
void agregar_final(punt &lista,punt nuevo);
bool buscar(punt lista, int dato);
punt eliminar_inicio(punt &lista);
punt eliminar_final(punt &lista);
punt eliminar_nodo(punt &lista, int dato);
void mostrar_lista(punt lista);
int minimo(punt lista);
int main(){
punt lista,nuevo;
int opcion, dato,min;
cout<<"Bienvenido al programa de manejo de listas enlazadas simples"<<endl;
cout<<"Para empezar, cree una lista vacía."<<endl;
crear_lista(lista);
do{
    menu(opcion);
switch(opcion)
{
case 1:
    
    crear_lista(lista);
    cout<<"Lista creada."<<endl;
    break;
case 2:
    nuevo_nodo(nuevo);
    agregar_inicio(lista, nuevo);
break;
case 3:
    nuevo_nodo(nuevo);
    agregar_ordenado(lista, nuevo);
    break;
case 4:
    nuevo_nodo(nuevo);
    agregar_final(lista, nuevo);
    break;  
case 5:
    cout<<"Ingrese el dato a buscar: "; 
    cin>>dato;
    if(buscar(lista, dato)){
        cout<<"El dato "<<dato<<" se encuentra en la lista."<<endl;
    }
    else{
        cout<<"El dato "<<dato<<" no se encuentra en la lista."<<endl;
    }

    break;
case 6:
    nuevo = eliminar_inicio(lista); 
    if(nuevo != NULL){
        cout<<"Nodo eliminado al inicio con dato: "<<nuevo->dato<<endl;
        delete nuevo; // Liberar memoria
    }
    else{
        cout<<"No se pudo eliminar, la lista está vacía."<<endl;
    }
    break;
case 7:
    nuevo = eliminar_final(lista);
    if(nuevo != NULL){
        cout<<"Nodo eliminado al final con dato: "<<nuevo->dato<<endl;
        delete nuevo; // Liberar memoria
    }
    else{
        cout<<"No se pudo eliminar, la lista está vacía."<<endl;
    }
    break;
case 8:
    cout<<"Ingrese el dato a eliminar: ";
    cin>>dato;
    nuevo = eliminar_nodo(lista, dato);
    if(nuevo != NULL){
        cout<<"Nodo eliminado con dato: "<<nuevo->dato<<endl;
        delete nuevo; // Liberar memoria
    }
    else{
        cout<<"No se pudo eliminar, el nodo no se encuentra en la lista."<<endl;
    }
    break;
case 9:
    cout<<"Mostrando lista: ";

    mostrar_lista(lista);
    break;
case 10:
    min = minimo(lista);
    if (min != -999) {
        cout << "El valor mínimo en la lista es: " << min << endl;
    }
    break;
case 11:
    if(es_vacia(lista)){
        cout<<"La lista está vacía."<<endl;
    }
    else{
        cout<<"La lista no está vacía."<<endl;
    }
    break;
case 0:
    cout<<"Saliendo del programa."<<endl;
    break;
default:
    cout<<"Opción no válida, por favor intente de nuevo."<<endl;
    break;
}
}while(opcion!=0);


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
void menu (int &n){
    cout << "Menu de opciones:" << endl;
    cout << "1. Crear lista" << endl;
    cout << "2. Agregar nodo al inicio" << endl;
    cout << "3. Agregar nodo ordenado" << endl;
    cout << "4. Agregar nodo al final" << endl;
    cout << "5. Buscar nodo" << endl;
    cout << "6. Eliminar nodo al inicio" << endl;
    cout << "7. Eliminar nodo al final" << endl;
    cout << "8. Eliminar nodo específico" << endl;
    cout << "9. Mostrar lista" << endl;
    cout << "10. Encontrar mínimo" << endl;
    cout<<"11. Lista vacia?"<<endl;
    cout << "0. Salir" << endl;
    cin >> n;
};