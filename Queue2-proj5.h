//
// Created by Hunter on 4/16/2018.
//

#ifndef PROJECT_5_QUEUE2_PROJ5_H
#define PROJECT_5_QUEUE2_PROJ5_H

#include "MyVector-proj5.h"

template <class T>
class Queue2 : public MyVector<T> {
private:
    int front, rear;

    int wrap(int k) {
        return k % this->getSize();
    }
public:
    Queue2() {

    }

    void enqueue(T data) {
        if(wrap(front + 1) == rear) {
            this->grow();
        }
        
    }

    void dequeue(T& data) {

    }
};

#endif //PROJECT_5_QUEUE2_PROJ5_H
