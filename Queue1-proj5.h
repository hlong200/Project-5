//
// Created by Hunter on 4/16/2018.
//

#ifndef PROJECT_5_QUEUE1_PROJ5_H
#define PROJECT_5_QUEUE1_PROJ5_H

#include "MyVector-proj5.h"

template <class T>
class Queue1 : public MyVector<T> {
public:
    void enqueue(T data) {
        this->pushBack(data);
    }

    void dequeue(T& data) {
        this->popFront(data);
    }
};

#endif //PROJECT_5_QUEUE1_PROJ5_H
