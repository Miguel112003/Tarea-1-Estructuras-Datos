#include "priorityQueue.h"
#include <algorithm>

int priorityQueue::fron(){
    int ans = l.front();
    return ans;
}

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
    else
        l2.insert(i,v);
}

void priorityQueue::enQueue(int otro){
    insertarEnListaOrdenada(l,otro);
}
void priorityQueue::deQu(){
    l.pop_front();
}
