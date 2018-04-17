//
// Created by Hunter on 4/16/2018.
//

#ifndef PROJECT_5_MYLIST_PROJ5_H
#define PROJECT_5_MYLIST_PROJ5_H

#include "ContainerIfc-proj5.h"
#include "Node-proj5.h"

template <class T>
class MyList : public ContainerIfc<T> {
private:
    Node<T> *head;
    Node<T> *tail;
public:
    MyList() {
        head = NULL;
        tail = NULL;
    }

    ~MyList() {
        delete head;
    }

    MyList(const MyList& other) {
        Node<T> *cursor = other.head;
        while(cursor != NULL) {
            pushBack(cursor->data);
            cursor = cursor->next;
        }
    }

    MyList<T>& operator=(MyList& other) {
        Node<T> *cursor = other.head;
        delete head;
        while(cursor != NULL) {
            pushBack(cursor->data);
            cursor = cursor->next;
        }
        return *this;
    }

    MyList<T>& pushFront(T data) {
        if(head == NULL) {
            head = tail = new Node<T>(data);
            head->next = tail->next = NULL;
        } else {
            Node<T> *temp = head;
            head = new Node<T>(data);
            head->next = temp;
        }
        return *this;
    }

    MyList<T>& pushBack(T data) {
        if(head == NULL) {
            head = tail = new Node<T>(data);
        } else {
            tail->next = new Node<T>(data);
            tail = tail->next;
        }
        return *this;
    }

    MyList<T>& popFront(T& data) {
        if(head == NULL) {
            throw BAD_INDEX();
        }
        Node<T> *temp = head;
        data = head->data;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return *this;
    }

    MyList<T>& popBack(T& data) {
        if(head == NULL) {
            throw BAD_INDEX();
        }
        Node<T> *cursor = head;
        if(head == tail)  {
            data = head->data;
            delete head;
            head = tail = NULL;
        } else {
            while (cursor->next != tail) {
                cursor = cursor->next;
            }
            data = cursor->next->data;
            delete cursor->next;
            cursor->next = NULL;
            tail = cursor;
        }
        return *this;
    }

    int getSize() {
        int count = 0;
        Node<T> *cursor = head;
        while(cursor != NULL) {
            count++;
            cursor = cursor->next;
        }
        return count;
    }

    bool isEmpty() {
        return head == NULL;
    }

    T front() {
        if(head == NULL) {
            throw BAD_INDEX();
        }
        return head->data;
    }

    T back() {
        if(head == NULL) {
            throw BAD_INDEX();
        }
        return tail->data;
    }

    T& operator[](int k) {
        Node<T> *cursor = head;
        int i = 0;
        while(i < k && cursor->next != NULL) {
            i++;
            cursor = cursor->next;
        }
        return cursor->data;
    }
};

#endif //PROJECT_5_MYLIST_PROJ5_H
