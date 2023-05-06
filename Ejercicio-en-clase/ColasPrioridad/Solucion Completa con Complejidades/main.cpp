#include <iostream>
#include <list>
#include <algorithm>

#include "priorityQueue.h"

int main(){
	priorityQueue colaPrio;
	bool vacia = colaPrio.empty_();
	cout << vacia << " 1 Esta vacia, 0 Tiene datos" << endl;
	colaPrio.enQueue(2);
	colaPrio.enQueue(5);
	colaPrio.enQueue(1);
	bool vacia2 = colaPrio.empty_();
	cout << vacia2 << " 1 Esta vacia, 0 Tiene datos" << endl;
	//Ahora pruebo front_
	int primero = colaPrio.front_();
	cout << primero << endl; //Imprime 1

	//Ahora pruebo el _deQue_
	colaPrio._deQue_(); //Quito el 1
	colaPrio._deQue_(); //Quito el 2

	int nuevoPrim = colaPrio.front_();
	cout << nuevoPrim << endl; //Imprime el 5
}
