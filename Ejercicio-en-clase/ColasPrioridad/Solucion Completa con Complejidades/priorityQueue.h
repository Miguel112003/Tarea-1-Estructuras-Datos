#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include <iostream>
#include <list>

using namespace std;

class priorityQueue{
    list<int> l;
    public:
        void enQueue(int otro);
        void _deQue_();
        int front_();
        bool empty_();
};


#endif // PRIORITYQUEUE_H_INCLUDED
