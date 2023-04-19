#include "lista.h"
#include <iostream>


int main(){
  Lista l1;
  l1.anxLista(3);
  l1.anxLista(4);
  l1.anxLista(5);
  l1.anxLista(6);
  l1.anxLista(7);
  l1.anxLista(8);
  l1.anxLista(9);
  l1.anxLista(0);


  for(int i = 1; i <= l1.longLista(); i++)
    cout << l1.infoLista(i) << endl;
  cout << endl;

  Lista l2;
  l2.anxLista(0);
  l2.anxLista(9);
  l2.anxLista(8);
  l2.anxLista(7);
  l2.anxLista(6);
  l2.anxLista(5);
  l2.anxLista(4);
  l2.anxLista(3);

  for(int i = 1; i <= l2.longLista(); i++)
    cout << l2.infoLista(i) << endl;
  cout << endl;

  Lista l4 = l1+l2;

  Lista l3 = l4 + l1;
  cout << "Listas Sumadas en otra" << endl << endl;
  for(int i = 1; i <= l3.longLista(); i++)
    cout << l3.infoLista(i) << endl;
  cout << endl;

}

