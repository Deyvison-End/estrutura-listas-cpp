#ifndef FILAS_LISTA_H
#define FILAS_LISTA_H

#include <vector>
#include <stdexcept>
using namespace std;

// Lista indexada em 1
template <class T>
class Lista {
protected:
    int capacidade;
    int num_itens = 0;
    vector<T> itens;

    T& pega_ref(int idx) {
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");
        return itens[idx - 1];
    }

public:
    explicit Lista(int capacidade) : capacidade(capacidade), itens(capacidade) {
        if (capacidade <= 0) throw runtime_error("Capacidade invalida");
    }

    virtual ~Lista() = default;

    virtual void adicionar(T v) {
        if (num_itens >= capacidade) throw runtime_error("Fila cheia!");
        itens[num_itens++] = v;
    }

    virtual void inserir(int idx, T v) {
        if (num_itens >= capacidade) throw runtime_error("Fila cheia!");
        if (idx <= 0 || idx > num_itens + 1) throw runtime_error("Indice invalido");

        for (int i = num_itens; i >= idx; i--) {
            itens[i] = itens[i - 1];
        }

        itens[idx - 1] = v;
        num_itens++;
    }

    void remover(int idx) {
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");
        for (int i = idx - 1; i < num_itens - 1; i++) {
            itens[i] = itens[i + 1];
        }
        num_itens--;
    }

    int tamanho() const {
        return num_itens;
    }

    T pega(int idx) {
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");
        return itens[idx - 1];
    }

    T& operator[](int idx) {
        return pega_ref(idx);
    }

    virtual int buscar(T valor) {
        for (int i = 0; i < num_itens; i++) {
            if (itens[i] == valor) {
                return i + 1;
            }
        }
        return -1;
    }
};

template <class T>
class ListaOrdenada : public Lista<T> {
public:
    explicit ListaOrdenada(int cap) : Lista<T>(cap) {}

    void inserir(int, T) override {
        throw runtime_error("Operacao nao suportada!");
    }

    void adicionar(T v) override {
        if (this->num_itens >= this->capacidade) throw runtime_error("Fila cheia!");

        int i = this->num_itens - 1;
        while (i >= 0 && this->itens[i] > v) {
            this->itens[i + 1] = this->itens[i];
            i--;
        }
        this->itens[i + 1] = v;
        this->num_itens++;
    }

    int buscar(T v) override {
        
        return Lista<T>::buscar(v);
    }
};

#endif 
