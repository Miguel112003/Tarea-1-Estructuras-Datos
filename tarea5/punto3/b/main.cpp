#include "lista.h"
#include <iostream>


int main(){
  Lista l1;

  l1.insListaOrdenada(1);
  l1.insListaOrdenada(2);
  l1.insListaOrdenada(3);
  l1.insListaOrdenada(4);
  /*
  l1.insListaOrdenada(5);
  l1.insListaOrdenada(6);
  l1.insListaOrdenada(7);
  l1.insListaOrdenada(8);
  */
  Elemento k = 0;

  for(int i = 1; i <= l1.longLista(); i++)
    cout << l1.infoLista(i) << endl;

  cout << endl;
  l1.insListaOrdenada(k);

  cout << "Ejemplo insListaOrdenada" << endl << endl;
  for(int i = 1; i <= l1.longLista(); i++)
    cout << l1.infoLista(i) << endl;



  cout << "Cabeza de la lista: " << l1.infoLista(1) << endl;
}
