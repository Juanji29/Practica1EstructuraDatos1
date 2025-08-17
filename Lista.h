//
// Created by juanc on 17/08/2025.
//

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <iostream>

using namespace std;

class Lista {
private:
    Nodo* head;
    Nodo* tail;
public:
    Lista();
    void crearLista();
    void insertarAlInicio(string name, int room);
    void insertarAlFinal(string name, int room);
    void insertarDespues(string name, int room, Nodo* anterior);
    Nodo* buscar(string name);
    void eliminar(string name);
    Nodo* getUltimo();
    void visualizarLista();
};
#endif //LISTA_H
