/*Utilizando listas simples implemente:
a. TDA Pila y sus operaciones fundamentales.
b. TDA Cola y sus operaciones fundamentales (incluya un contador de
elementos para la cola).
*/
#include <iostream>
using namespace std;
typedef struct tnodo *punt;
struct tnodo{
    int dato;
    punt sig;
};
void init_stack(punt &pila);
void push_stack(punt &pila, int dato);
punt pop_stack(punt &pila);
bool is_empty_stack(punt pila);
//no se aplico la funcion cola llena, ya que la cola se llena si se llena la memoria.
punt top_stack(punt pila);
void menu(int &n);
int main(){
punt pila;
int n;
do{
    menu(n);
    switch(n){
        case 1:
            init_stack(pila);
            cout<<"Pila inicializada."<<endl;
            break;
        case 2:{
            int dato;
            cout<<"Ingrese un dato: ";
            cin>>dato;
            push_stack(pila, dato);
            break;
        }
        case 3:{
            if(!is_empty_stack(pila)){
                punt eliminado = pop_stack(pila);
                cout<<"Dato "<<eliminado->dato<<" eliminado."<<endl;
                delete eliminado; // Liberar memoria
            } else {
                cout<<"La pila está vacía, no se puede eliminar."<<endl;
            }
            break;
        }
        case 4:
            if(is_empty_stack(pila)){
                cout<<"La pila está vacía."<<endl;
            } else {
                cout<<"El elemento en la cima de la pila es: "<<top_stack(pila)->dato<<endl;
            }
            break;
        case 5:
            if(is_empty_stack(pila)){
                cout<<"La pila está vacía."<<endl;
            } else {
                cout<<"La pila no está vacía."<<endl;
            }
            break;
        case 0:
            cout<<"Saliendo del programa..."<<endl;
            break;
        default:
            cout<<"Opción no válida. Intente de nuevo."<<endl;
    }



}while(n!=0);
    return 0;
};

void init_stack(punt &pila) {
    pila = NULL; 
};
void push_stack(punt &pila, int dato){
if (is_empty_stack(pila)){
    pila = new tnodo;
    pila->dato=dato;
    pila->sig = NULL;
}
else{
    punt nuevo= new tnodo;
    nuevo->dato=dato;
    nuevo->sig = pila;
    pila =nuevo;
}
};
punt pop_stack(punt &pila){
    punt eliminado;
    if(is_empty_stack(pila)){
        return NULL;
    }
    else{
        eliminado=pila;
        pila=pila->sig;
        return eliminado;
    }
};
bool is_empty_stack(punt pila){
    return pila == NULL;
};
punt top_stack(punt pila){
    if (is_empty_stack(pila))
        return NULL;
    else{
        return pila;
    }
}
void menu(int &n){
    cout<<"Menu de opciones:"<<endl;
    cout<<"1. Inicializar pila"<<endl;
    cout<<"2. Agregar elemento a la pila"<<endl;
    cout<<"3. Eliminar elemento de la pila"<<endl;
    cout<<"4. Ver elemento en la cima de la pila"<<endl;
    cout<<"5. Verificar si la pila está vacía"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"Ingrese una opción: ";
    cin>>n;
};
