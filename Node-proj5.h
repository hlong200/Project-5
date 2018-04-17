//
// Created by Hunter on 4/16/2018.
//

#ifndef PROJECT_5_NODE_PROJ5_H
#define PROJECT_5_NODE_PROJ5_H

#include <cstdlib>

template <class T>
class Node {
public:
    T data;
    Node *next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }

    ~Node() {
        delete next;
    }
};

#endif //PROJECT_5_NODE_PROJ5_H
