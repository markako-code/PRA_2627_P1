#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;                         // Puntero al array dinámico
    int max;                        // Capacidad máxima actual
    int n;                          // Número real de elementos
    static const int MINSIZE = 2;   // Tamaño mínimo por defecto

    // Método privado para redimensionar el array
    void resize(int new_size) {
        T* new_arr = new T[new_size];       // 1. Crear nuevo array
        for (int i = 0; i < n; ++i) {
            new_arr[i] = arr[i];            // 2. Copiar contenido
        }
        delete[] arr;                       // 3. Liberar memoria del viejo
        arr = new_arr;                      // 4. Actualizar puntero
        max = new_size;                     // 5. Actualizar capacidad máxima
    }

public:
    // Constructor sin argumentos
    ListArray() {
        arr = new T[MINSIZE];
        max = MINSIZE;
        n = 0;
    }

    // Destructor virtual sobrescrito
    ~ListArray() override {
        delete[] arr;
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        if (pos < 0 || pos >= n) { // size() es igual a n
            throw std::out_of_range("Posición fuera de rango");
        }
        return arr[pos];
    }

    // Sobrecarga del operador << para imprimir la lista
    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
        out << "[";
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i];
            if (i < list.n - 1) out << ", ";
        }
        out << "]";
        return out;
    }

    // --- MÉTODOS HEREDADOS DE List<T> (Sobrescritos) ---
    
    void insert(int pos, T e) override {
        // TODO: Lógica de la siguiente actividad
    }

    void append(T e) override {
        // TODO: Lógica de la siguiente actividad
    }

    void prepend(T e) override {
        // TODO: Lógica de la siguiente actividad
    }

    T remove(int pos) override {
        // TODO: Lógica de la siguiente actividad
        return T(); 
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Fuera de rango");
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) return i;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }
};

#endif
