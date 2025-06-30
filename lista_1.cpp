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
void agregar_inicio (punt &lista, punt nuevo,punt &cola,int &contdor);
void agregar_ordenado(punt &lista, punt nuevo, punt &cola,int &contador);
void agregar_final(punt &lista,punt nuevo, punt &cola,int &contador);
bool buscar(punt lista, int dato, punt cola);
//Los eliminar no liberan memoria, ya que se devolverá el nodo eliminado para que el usuario lo libere.
punt eliminar_inicio(punt &lista,int &contador);
punt eliminar_final(punt &lista, punt &cola, int &contador);
punt eliminar_nodo(punt &lista, int dato, punt &cola, int &contador);
void mostrar_lista(punt lista, punt cola);
int minimo(punt lista, punt cola);
int buscar_indice(punt lista,punt cola, int dato);
punt buscar_por_indice(punt lista, punt cola, int indice, int contador);


int main(){
punt lista,nuevo,cola;// Puntero para la cola de la lista
int opcion, dato,min,contador=-1;
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
    agregar_inicio(lista, nuevo,cola,contador);
break;
case 3:
    nuevo_nodo(nuevo);
    agregar_ordenado(lista, nuevo, cola,contador);
    break;
case 4:
    nuevo_nodo(nuevo);
    agregar_final(lista, nuevo, cola,contador);
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
    nuevo = eliminar_inicio(lista, contador); 
    if(nuevo != NULL){
        cout<<"Nodo eliminado al inicio con dato: "<<nuevo->dato<<endl;
        delete nuevo; // Liberar memoria
    }
    else{
        cout<<"No se pudo eliminar, la lista está vacía."<<endl;
    }
    break;
case 7:
    nuevo = eliminar_final(lista, cola, contador);
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
    nuevo = eliminar_nodo(lista, dato, cola, contador);
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
case 12:
    cout<<"Ingrese el dato a buscar su indice: ";
    cin>>dato;
    int indice = buscar_indice(lista, cola, dato);
    if(indice != -1){
        cout<<"El dato "<<dato<<" se encuentra en el indice: "<<indice<<endl;
    }
    else{
        cout<<"El dato "<<dato<<" no se encuentra en la lista."<<endl;
    }
    break;
case 13:
    cout<<"Ingrese el indice a buscar: ";
    cin>>dato;
    punt encontrado = buscar_por_indice(lista, cola, dato,contador);
    if(encontrado != NULL){
        cout<<"El dato en el indice "<<dato<<" es: "<<encontrado->dato<<"Puntero: "<<encontrado<<endl;
    }
    else{
        cout<<"No se encontró un nodo en el indice "<<dato<<endl;
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
void agregar_inicio(punt &lista, punt nuevo, punt &cola, int &contador){
    if (lista == NULL) // Si la lista estaba vacía antes de insertar
        cola = nuevo;
    nuevo->sig = lista;
    lista = nuevo;
    contador++;
}
void agregar_ordenado(punt &lista, punt nuevo, punt &cola,int &contador){
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
        contador++;
    };
void agregar_final(punt &lista,punt nuevo,punt &cola,int &contador){
if (es_vacia(lista,cola)) {
        lista = nuevo;
        cola=nuevo;
    } else {
    cola->sig = nuevo; // El nodo anterior apunta al nuevo nodo
    nuevo->sig = NULL; // El nuevo nodo es el último, por lo que su siguiente es NULL
    cola = nuevo; // Actualizar la cola para que apunte al nuevo nodo
    };
    contador++;
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
punt eliminar_inicio(punt &lista,punt cola,int &contador){
    punt borrado;
if(es_vacia(lista,cola))
    borrado = NULL;
else{
    borrado = lista;
    lista = lista->sig;
    borrado->sig = NULL;
    contador--;
};
return borrado;
};
punt eliminar_final(punt &lista, punt &cola, int &contador){
    punt borrado = nullptr;
    if (lista == NULL) {
        return nullptr;
    }
    if (lista->sig == NULL) {
        borrado = lista;
        lista = NULL;
        cola = NULL;
    } else {
        punt i = lista;
        while (i->sig->sig != NULL) {
            i = i->sig;
        }
        borrado = i->sig;
        i->sig = NULL;
        cola = i;
    }
    contador--;
    return borrado;
}
punt eliminar_nodo(punt &lista, int dato, punt &cola,int &contador){
    punt borrado = nullptr;
    if(es_vacia(lista, cola)) {
        return nullptr; // Lista vacía, no se puede eliminar
    }
    // Si el nodo a eliminar es el primero
    if(lista->dato == dato){
        borrado = lista;
        lista = borrado->sig;
        borrado->sig = NULL;
        if (lista == NULL) cola = NULL; // Si la lista queda vacía, actualizar cola
        contador--;
        return borrado;
    }
    // Buscar el nodo a eliminar
    punt i = lista;
    while(i->sig != nullptr && i->sig->dato != dato) {
        i = i->sig;
    }
    if(i->sig != nullptr) {
        borrado = i->sig;
        i->sig = borrado->sig;
        borrado->sig = NULL;
        if(i->sig == NULL) { // Si se eliminó el último nodo, actualizar la cola
            cola = i;
        }
        contador--;
    }
    // Si no se encontró el nodo, borrado queda en nullptr
    return borrado;
}
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
    while(i !=nullptr){
        if (min == -999 || i->dato < min) {
            min = i->dato;
        }
        i = i->sig;

    };
}
return min;
};
int buscar_indice(punt lista, punt cola, int dato){
    int i=-1,j=-1;
    bool band=true;
    punt aux=lista;
    if(es_vacia(lista,cola))
        return -1;
    else{
    while(band){
        i++;
        if(aux->dato==dato){
            band=false;
            j=i;
        }
        if(aux==cola)
            band=false;
        else
            aux=aux->sig;
    };

}
return j;};
punt buscar_por_indice(punt lista, punt cola, int indice, int contador){
    punt aux = lista;
    int i = 0;
    if(es_vacia(lista,cola)|| indice < 0 || indice >= contador) {
        return NULL; // Lista vacía o índice fuera de rango
    }
    else{
    while (aux != NULL) {
        if(i== indice) {
            return aux; // Retorna el nodo en el índice especificado
        }
        aux = aux->sig;
        i++;
    }
    return NULL;
    };
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
    cout<<"12. Buscar indice de un dato"<<endl;
    cout << "13. Buscar segun indice " << endl;
    cout << "0. Salir" << endl;
    cin >> n;
};