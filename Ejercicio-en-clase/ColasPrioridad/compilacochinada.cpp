#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

class priorityQueue{
    deque<int> l;
    public:
        void enQueue(int otro);
        void deQu();
        int fron();
        bool empt();

};


bool priorityQueue::empt(){
    bool ans = l.empty();
    return ans;
}

//Operacion Auxiliar
void insertarEnListaOrdenada(deque<int> &l2, int v){
    int len = l2.size();
    int i = 1;
    while(l2[i] < v && i <=len)
        i++;
    if(i>len)
        l2.push_back(v);
    else{
        l2.push_back(v);
        //l2.insert(i,v);

    }
}

void priorityQueue::enQueue(int otro){
    insertarEnListaOrdenada(l,otro);
}
void priorityQueue::deQu(){
    l.pop_front();
}

int priorityQueue::fron(){
    return l.front();
}

int main(){
    priorityQueue colaPrio;
    bool vacia = colaPrio.empt();
    cout << "La cola esta vacia? " << vacia << endl;
    colaPrio.enQueue(8);
    colaPrio.enQueue(1);
    colaPrio.enQueue(9);
    colaPrio.enQueue(3);
    colaPrio.enQueue(5);
    int primero = colaPrio.fron();
    cout << primero << endl;
    colaPrio.deQu();
    int segundo = colaPrio.fron();
    cout << segundo << endl;
    colaPrio.deQu();
    int tercero = colaPrio.fron();
    cout << tercero << endl;


}
