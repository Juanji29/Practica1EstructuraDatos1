//
// Created by juanc on 17/08/2025.
//
#include "Lista.h"
using namespace std;

Lista::Lista() {
    head = nullptr;
    tail = nullptr;
}
void Lista::crearLista() {
    string name;
    int room;
    cout << "Ingrese el nombre y el numero de habitacion o '-1' para finalizar: " << endl;
    while (true) {
        cin >> name;
        if (name == "-1") break;
        cin >> room;
        insertarAlFinal(name, room);
    }
}
void Lista::insertarAlInicio(string name, int room) {
    Nodo* newNode = new Nodo(name, room, head, nullptr);
    if (head != nullptr) {
        head->setPrev(newNode);
    }
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
}
void Lista::insertarAlFinal(string name, int room) {
    Nodo* newNode = new Nodo(name, room, nullptr, tail);
    if (tail != nullptr) {
        tail->setNext(newNode);
    }
    tail = newNode;
    if (head == nullptr) {
        head = newNode;
    }
}
void Lista::insertarDespues(string name, int room, Nodo* anterior) {
    if (anterior == nullptr) {
        insertarAlInicio(name, room);
        return;
    }
    Nodo* newNode = new Nodo(name, room, anterior->getNext(), anterior);
    if (anterior->getNext() != nullptr) {
        anterior->getNext()->setPrev(newNode);
    }
    anterior->setNext(newNode);
    if (anterior == tail) {
        tail = newNode;
    }
}
Nodo* Lista::buscar(string name) {
    Nodo* current = head;
    while (current != nullptr) {
        if (current->getName() == name) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}
void Lista::eliminar(string name) {
    Nodo* current = buscar(name);
    if (current == nullptr) {
        cout << "Nodo no encontrado." << endl;
        return;
    }
    if (current->getPrev() != nullptr) {
        current->getPrev()->setNext(current->getNext());
    } else {
        head = current->getNext();
    }
    if (current->getNext() != nullptr) {
        current->getNext()->setPrev(current->getPrev());
    } else {
        tail = current->getPrev();
    }
    delete current;
}
Nodo* Lista::getUltimo() {
    return tail;
}
void Lista::visualizarLista() {
    Nodo* current = head;
    while (current != nullptr) {
        cout << "Nombre: " << current->getName() << ", Habitacion: " << current->getRoom() << endl;
        current = current->getNext();
    }
}

