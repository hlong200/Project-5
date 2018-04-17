//
// Created by Hunter on 4/16/2018.
//

#ifndef PROJECT_5_MYVECTOR_PROJ5_H
#define PROJECT_5_MYVECTOR_PROJ5_H

#include <sstream>
#include <string>
#include "ContainerIfc-proj5.h"

using namespace std;

template <class T>
class MyVector : public ContainerIfc<T> {
protected:
    T *data;
    int capacity, size;

    void grow() {
        capacity *= capacity;
        T *temp = data;
        data = new T[capacity];

        for(int i = 0; i < this->size; i++) {
            data[i] = temp[i];
        }

        delete [] temp;
    }

    void shiftRight() {
        for(int i = size; i >= 0; i--) {
            data[i] = data[i - 1];
        }
    }

    void shiftLeft() {
        for(int i = 0; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
    }
public:
    MyVector() {
        size = 0;
        capacity = 2;
        data = new T[capacity];
    }

    ~MyVector() {
        delete [] data;
    }

    MyVector(const MyVector& other) {
        for(int i = 0; i < other.size; i++) {
            pushBack(other[i]);
        }
    }

    MyVector<T>& operator=(MyVector& other) {

    }

    MyVector<T>& pushFront(T data) {
        if(size + 1 == capacity) {
            grow();
        }
        shiftRight();
        this->data[0] = data;
        size++;
    }

    MyVector<T>& pushBack(T data) {
        if(size + 1 == capacity) {
            grow();
        }
        this->data[size] = data;
        size++;
    }

    MyVector<T>& popFront(T& data) {
        data = this->data[0];
        shiftLeft();
        size--;
    }

    MyVector<T>& popBack(T& data) {
        data = this->data[size - 1];
        size--;
    }

    T front() {

    }

    T back() {

    }

    T& operator[](int k) {
        if(k > this->size || k < 0) {
            throw BAD_INDEX();
        }
        return data[k];
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    string toString() {
        ostringstream out;
        out << "Size: " << this->size << endl << "Capacity: " << this->capacity << endl;
        for(int i = 0; i < this->size; i++) {
            out << this->data[i] << " ";
        }
        return out.str();
    }

    void right() {
        shiftRight();
    }

    void left() {
        shiftLeft();
    }
};

#endif //PROJECT_5_MYVECTOR_PROJ5_H
