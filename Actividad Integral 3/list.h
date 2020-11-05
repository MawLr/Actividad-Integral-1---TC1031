//
//  list.h
//  act 2.1 tc1031
//  A01706212
//  Created by Manolo Medina on 9/27/20.
//  Copyright © 2020 Manolo Medina. All rights reserved.
//

#ifndef list_h
#define list_h

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T> class List;

template <class T>
class Link {
private:
    Link(T);
    Link(T, Link<T>*);

    T        value;
    Link<T> *next;

    friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}


template <class T>
class List {
public:
    List();
    void clear();
    ~List();

    bool empty() const;
    
    void addFirst(T);
    void add(T);

    T remove(int);
    T removeFirst ();

    void update(int, T);

    int find(T) const;
    string toString() const;

private:
    Link<T> *head;
    int     size;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
void List<T>::clear() {
    Link<T> *p, *q;

    p = head;
    while (p != 0) {
        q = p->next;
        delete p;
        p = q;
    }
    head = 0;
    size = 0;
}

template <class T>
List<T>::~List() {
    clear();
}

template <class T>
bool List<T>::empty() const {
    return (head == 0);
}

template <class T>
void List<T>::addFirst(T val) {
    Link<T> *newLink;

    newLink = new Link<T>(val);

    newLink->next = head;
    head = newLink;
    size++;
}

template <class T>
void List<T>::add(T val) {
    Link<T> *newLink, *p;

    newLink = new Link<T>(val);

    if (empty()) {
    addFirst(val);
    return;
    }

    p = head;
    while (p->next != 0) {
        p = p->next;
    }

    newLink->next = 0;
    p->next = newLink;
    size++;
}

template <class T>
T List<T>::removeFirst() {
    T val;
    Link<T> *p;

    if (empty()) {
        cout<< "Elementos inexistentes" << endl;
    }

    p = head;

    head = p->next;
    val = p->value;

    delete p;
    size--;

    return val;
}

template <class T>
T List<T>::remove(int index) {
  T val;
    Link<T> *p, *q;
    int pos;

    if (index < 0 || index >= size) {
        cout<< "Indice ilegal" << endl;
    }

    if (index == 0) {
    return removeFirst();
    }

    pos = 0;
    p = head;
    q = 0;
    while (pos != index) {
        q = p;
        p = p->next;
        pos++;
    }

    val= p->value;
    q->next = p->next;

    delete p;
    return val;
    size--;
}

template <class T>
void List<T>::update(int index, T val) {
  int pos;
  Link<T> *p;

    if (index < 0 || index >= size) {
        cout<< "Indice ilegal" << endl;
    }

    pos = 0;
    p = head;
    while (pos != index) {
        p = p->next;
        pos++;
    }

    p->value = val;
}

template <class T>
int List<T>::find(T val) const {
  int pos;
    Link<T> *p;

    p = head;
    pos = 0;
    while (p != 0) {
        if (p->value == val) {
            return pos;
        }
        p = p->next;
        pos++;
    }
  return -1;
}

template <class T>
string List<T>::toString() const {
    stringstream aux;
    Link<T> *p;
    p = head;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->next != 0) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

#endif /* list_h */
