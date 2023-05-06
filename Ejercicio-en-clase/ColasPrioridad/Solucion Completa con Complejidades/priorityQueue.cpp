#include "priorityQueue.h"
#include <algorithm>

/*Analisis de Complejidad front_
Esta funcion solo accede al primmer elemento de una lista
circular doble, lo cual tiene una complejidad de O(1) ya que solo
accede a la cabeza
*/
int priorityQueue::front_(){
    int ans = l.front();
    return ans;
}

/*Analisis de Complejidad empty_
Esta funcion solo accede al primmer elemento de una lista
circular doble, lo cual tiene una complejidad de O(1) ya que solo
accede a la cabeza y verifica si esta vacia
*/
bool priorityQueue::empty_(){
    bool ans = l.empty();
    return ans;
}

//Operacion Auxiliar
/*Analisis de Complejidad insertarEnListaOrdenada
En primera linea se utiliza la operacion "size()" que cuenta con una complejidad
de O(n), ya que recorre toda la lista y devuelve el tamaño
Luego en el ciclo while se debe expresar como una sumatoria, ya que al recorrer la lista hasta hallar
el valor en la posicion  usando el iterador, se recorre hasta esa posicion de la lista, es decir
en la primera iteracion va hasta la posicion 1, en la siguiente va hasta la 2 y asi hasta que ocurra uno de
los posibles escenarios:
Se realiza el ciclo while bajo la sumatoria desde i = 1, hasta n sumando i; dando como resultado una complejidad
cuadratica en este ciclo. de (n^2+n)/2
Esto nos daria el indice donde poner el elemento, en el peor caso se deberia poner en la posicion anterior a la ultima
ya que al hacer esto utilizamos la funcion insert(), que tiene una complejidad de O(k) siendo k la posicion de la lista
mientras que por otro lado si se usara push_back() (Insertando el elemento en el ultimo caso) la complejidad de esa operacion
es de O(1), por lo tanto en el peor caso de esta operacion la complejidad resultante es de
O(n^2)
*/
void insertarEnListaOrdenada(list<int> &l2, int v){
    int len = l2.size();
    int i = 1;
    auto it = l2.begin();
    while((*it) < v && i <=len){
        i++;
        it++;
    }
    if(i>len)
        l2.push_back(v);
    else
        l2.insert(it,v);
}

/*Analisis de Complejidad enQueue
Esta funcion solo invoca a insertarEnListaOrdenada la cual explique mas arriba
*/
void priorityQueue::enQueue(int otro){
    insertarEnListaOrdenada(l,otro);
}
/*Analisis de Complejidad deQueue
Esta funcion solo accede al primmer elemento de una lista
circular doble, lo cual tiene una complejidad de O(1) y lo elimina.
Es decir tiene una complejidad de O(1)
*/
void priorityQueue::_deQue_(){
    l.pop_front();
}
