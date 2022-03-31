#include "DequeBaseQueue.h"

void QueueInit(Queue * pq){
    DequeInit(pq);
}

int QIsEmpty(Queue * pq){
    DQIsEmpty(pq);
}

void Enqueue(Queue * pq, Data data){
    DQAddLast(pq, data);
}

Data Dequeue(Queue * pq){
    DQRemoveFirst(pq);
}

Data QPeek(Queue * pq){
    DQGetFirst(pq);
}