//
// Created by Hunter on 4/16/2018.
//

#ifndef PROJECT_5_CONTAINERIFC_PROJ5_H
#define PROJECT_5_CONTAINERIFC_PROJ5_H

class BAD_INDEX {};

template <class T>
class ContainerIfc {
public:
    virtual ContainerIfc<T>& pushFront(T) = 0;
    virtual ContainerIfc<T>& pushBack(T) = 0;
    virtual ContainerIfc<T>& popFront(T&) = 0;
    virtual ContainerIfc<T>& popBack(T&) = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual T front() = 0;
    virtual T back() = 0;
    virtual T& operator[](int) = 0;
};

#endif //PROJECT_5_CONTAINERIFC_PROJ5_H
