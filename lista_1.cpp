#include<iostream>
using namespace std;
typedef struct tnodo *punt;
struct tnodo{
    int dato;
    punt sig;
};
void menu(int &n);
void crear_lista(punt &lista,punt &cola);
bool es_vacia(punt lista,punt cola);
void nuevo_nodo(punt &nuevo);
void agregar_inicio (punt &lista, punt nuevo,punt &cola);
void agregar_ordenado(punt &lista, punt nuevo, punt &cola);
void agregar_final(punt &lista,punt nuevo, punt cola);
bool buscar(punt lista, int dato, punt cola);
//Los eliminar no liberan memoria, ya que se devolverá el nodo eliminado para que el usuario lo libere.
punt eliminar_inicio(punt &lista);
punt eliminar_final(punt &lista, punt &cola);
punt eliminar_nodo(punt &lista, int dato, punt &cola);
void mostrar_lista(punt lista, punt cola);
int minimo(punt lista, punt cola);
int main(){
punt lista,nuevo,cola;// Puntero para la cola de la lista
int opcion, dato,min;
cout<<"Bienvenido al programa de manejo de listas enlazadas simples"<<endl;
cout<<"Para empezar, cree una lista vacía."<<endl;
crear_lista(lista,cola);
do{
    menu(opcion);
switch(opcion)
{
case 1:
    
    crear_lista(lista,cola);
    cout<<"Lista creada."<<endl;
    break;
case 2:
    nuevo_nodo(nuevo);
    agregar_inicio(lista, nuevo,cola);
break;
case 3:
    nuevo_nodo(nuevo);
    agregar_ordenado(lista, nuevo, cola);
    break;
case 4:
    nuevo_nodo(nuevo);
    agregar_final(lista, nuevo, cola);
    break;  
case 5:
    cout<<"Ingrese el dato a buscar: "; 
    cin>>dato;
    if(buscar(lista, dato, cola)){
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
    nuevo = eliminar_final(lista, cola);
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
    nuevo = eliminar_nodo(lista, dato, cola);
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

    mostrar_lista(lista, cola);
    break;
case 10:
    min = minimo(lista, cola);
    if (min != -999) {
        cout << "El valor mínimo en la lista es: " << min << endl;
    }
    break;
case 11:
    if(es_vacia(lista, cola)){
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
//################################################################################################


//################################################################################################
void crear_lista(punt &lista, punt &cola){
    lista = NULL;
    cola=NULL;
};
bool es_vacia(punt lista, punt cola){
    return lista == NULL&& cola == NULL;
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
void agregar_inicio(punt &lista, punt nuevo, punt &cola){
    if (lista == NULL) // Si la lista estaba vacía antes de insertar
        cola = nuevo;
    nuevo->sig = lista;
    lista = nuevo;
}
void agregar_ordenado(punt &lista, punt nuevo, punt &cola){
    punt i;
    if(es_vacia(lista,cola))// Si la lista está vacía, el nuevo nodo se convierte en el primer nodo
        {lista=nuevo;
        cola=nuevo; // Si la lista estaba vacía, el nuevo nodo también es la cola
        }
        
    else{
        if(nuevo->dato<lista->dato){
            nuevo->sig=lista;
            lista=nuevo;
        }
        else{
            i = lista;
            while(i->sig != NULL && i->sig->dato < nuevo->dato) {
                i = i->sig; // Buscar la posición correcta para insertar el nuevo nodo
            }
            nuevo->sig = i->sig; // El nuevo nodo apunta al siguiente nodo
            i->sig = nuevo; // El nodo anterior apunta al nuevo nodo
            if (nuevo->sig == NULL) { // Si el nuevo nodo es el último,
                cola = nuevo; // Actualizar la cola
            }
            };

        }
    };
void agregar_final(punt &lista,punt nuevo,punt cola){
if (es_vacia(lista,cola)) {
        lista = nuevo;
        cola=nuevo;
    } else {
    cola->sig = nuevo; // El nodo anterior apunta al nuevo nodo
    nuevo->sig = NULL; // El nuevo nodo es el último, por lo que su siguiente es NULL
    cola = nuevo; // Actualizar la cola para que apunte al nuevo nodo
    };
};
bool buscar(punt lista, int dato,punt cola){
    punt i = lista;
    while (i != NULL) {
        if (i->dato == dato) {
            return true;
        }
        i = i->sig;
    }
    return false;
};
punt eliminar_inicio(punt &lista,punt cola){
    punt borrado;
if(es_vacia(lista,cola))
    borrado = NULL;
else{
    borrado = lista;
    lista = lista->sig;
    borrado->sig = NULL;
};
return borrado;
};
punt eliminar_final(punt &lista,punt &cola){
    punt borrado, i;
    if (lista == NULL)
        borrado = NULL;
    else {
        if (lista->sig==NULL){
            borrado=lista;
            lista = NULL;
            cola = NULL; // Si se elimina el único nodo, la cola también se actualiza
        }
        else{
            for (i=lista;(i->sig)->sig!=NULL;i=i->sig){
                borrado =i->sig;
                i->sig = NULL;
                cola = i; // Actualizar la cola para que apunte al nuevo último nodo
            }
        }
    }
    return borrado;
};
punt eliminar_nodo(punt &lista, int dato, punt &cola){
    punt borrado;
    if(es_vacia(lista,cola)) {
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
            if (i->sig == NULL) { // Si se eliminó el último nodo, actualizar la cola
                cola = i;
            }
        }
        else {
            borrado = NULL; // No se encontró el nodo a eliminar
        }
    };
    }
    
        };
        return borrado;
};
void mostrar_lista(punt lista, punt cola){
    punt i = lista;
    if(es_vacia(lista,cola)){
        cout<<"Lista vacia"<<endl;
    }
    else{
        for(; i != NULL; i = i->sig) {
            cout << i->dato << " ";
        }
        cout<<endl;
    }
};
int minimo(punt lista, punt cola){
    int min=-999;
    if(es_vacia(lista,cola)) {
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