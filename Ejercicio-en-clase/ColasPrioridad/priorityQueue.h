#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include <iostream>
#include <deque>

using namespace std;

class priorityQueue{
    deque<int> l;
    public:
        priorityQueue();
        void enQueue(int &otro);
        void deQu();
        int fron();
        bool empt();
};


#endif // PRIORITYQUEUE_H_INCLUDED
