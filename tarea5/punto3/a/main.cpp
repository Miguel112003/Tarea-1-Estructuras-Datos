#include "lista.h"
#include <iostream>

/*Respecto a la complejidad de la operacion "insertarEnListaOrdenada()"
En primera linea se utiliza la operacion "longLista()" que cuenta con una complejidad
de O(n), ya que recorre toda la lista y devuelve el tamaño
Luego en el ciclo while se debe expresar como una sumatoria, ya que al recorrer la lista hasta hallar
el valor en la posicion i usando "infoLista()" se recorre hasta esa posicion de la lista, es decir
en la primera iteracion va hasta la posicion 1, en la siguiente va hasta la 2 y asi hasta que ocurra uno de
los posibles escenarios:
Se realiza el ciclo while bajo la sumatoria desde i = 1, hasta n sumando i; dando como resultado una complejidad
cuadratica en este ciclo. de (n^2+n)/2
Esto nos daria el indice donde poner el elemento, en el peor caso se deberia poner en la posicion anterior a la ultima
ya que al hacer esto utilizamos la funcion insLista, que tiene una complejidad de O(n) siendo n el tamaño de la lista
mientras que por otro lado si se usara anxLista (Insertando el elemento en el ultimo caso) la complejidad de esa operacion
es de O(1), por lo tanto en el peor caso de esta operacion la complejidad resultante es de

O(n^2)

*/

void insertarEnListaOrdenada(Lista &l, Elemento v){
  int len = l.longLista();
  int i = 1;
  while(l.infoLista(i) < v && i <= len)
      i++;
  if(i > len)
    l.anxLista(v);
  else
    l.insLista(v, i);
}

int main(){
  Lista l1;
  l1.anxLista(1);
  l1.anxLista(2);
  l1.anxLista(3);
  l1.anxLista(4);
  l1.anxLista(5);
  l1.anxLista(6);
  l1.anxLista(7);
  l1.anxLista(8);

  Elemento k = 10;

  for(int i = 1; i <= l1.longLista(); i++)
    cout << l1.infoLista(i) << endl;

  insertarEnListaOrdenada(l1,k);

  cout << "Ejemplo insertarEnListaOrdenada" << endl;
  for(int i = 1; i <= l1.longLista(); i++)
    cout << l1.infoLista(i) << endl;

}
