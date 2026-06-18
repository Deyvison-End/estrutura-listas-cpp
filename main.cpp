#include <iostream>
#include "lista.h"
using namespace std;

struct tarefa {
    string nome;
    bool feita = false;

    bool operator<(const tarefa &t) const { return nome < t.nome; }
    bool operator>(const tarefa &t) const { return nome > t.nome; }
    bool operator==(const tarefa &t) const { return nome == t.nome; }
};


struct compras {
    string nome;
    int quantidade;
    float preco;

    bool operator<(const compras &c) const { return nome < c.nome; }
    bool operator>(const compras &c) const { return nome > c.nome; }
    bool operator==(const compras &c) const { return nome == c.nome; }
};

int main() {
    cout << " === Testando Lista Simples ==== " << endl;

    vector<int> valores = {11, 4, 7, 9, 10};
    Lista<int> lista(10);
    for (auto &v : valores) lista.adicionar(v);

    cout << "Antes: ";
    for (int i = 1; i <= lista.tamanho(); i++) cout << lista.pega(i) << " ";
    cout << endl;

    lista.inserir(2, 22);
    lista.remover(3);
    lista.adicionar(77);

    cout << "Depois: ";
    for (int i = 1; i <= lista.tamanho(); i++) cout << lista.pega(i) << " ";
    cout << endl;

    cout << "\n === Testando Lista Ordenada ==== " << endl;
    ListaOrdenada<int> listaOrd(10);
    for (auto &v : valores) listaOrd.adicionar(v);

    for (int i = 1; i <= listaOrd.tamanho(); i++)
        cout << i << ": " << listaOrd.pega(i) << "; ";
    cout << endl;

    cout << "\n === Lista Ordenada de Tarefas ==== " << endl;
    ListaOrdenada<tarefa> todo(10);
    vector<tarefa> arr = {
        {"Feira", false}, {"Aluguel", false}, {"Lixo", false},
        {"Estudar", false}, {"Cinema", false}
    };

    for (auto &v : arr) todo.adicionar(v);
    todo[1].feita = true;
    todo[3].feita = true;

    for (int i = 1; i <= todo.tamanho(); i++) {
        cout << i << ": " << todo[i].nome
             << " [" << (todo[i].feita ? "feita" : "nao feita") << "]\n";
    }

    vector<string> str = {"Feira", "Tarefa de casa", "Cinema", "Padaria"};
    for (string &s : str) {
        cout << "- Buscando " << s << ": "
             << todo.buscar({s, false}) << endl;
    }

    // 🛒 === PROBLEMA 2: Lista de Compras ===
    cout << "\n === Lista de Compras === " << endl;

    Lista<compras> listaCompras(10);
    listaCompras.adicionar({"Arroz", 2, 6.50});
    listaCompras.adicionar({"Feijao", 1, 8.20});
    listaCompras.adicionar({"Macarrao", 3, 4.75});

    listaCompras.inserir(2, {"Leite", 4, 5.00});
    listaCompras.remover(3);

    for (int i = 1; i <= listaCompras.tamanho(); i++) {
        auto c = listaCompras.pega(i);
        cout << i << ": " << c.nome << " (x" << c.quantidade
             << ") R$ " << c.preco << endl;
    }

    cout << "\nBuscando itens:" << endl;
    vector<string> itensBusca = {"Feijao", "Ovos", "Leite"};
    for (auto &nome : itensBusca) {
        cout << "- " << nome << ": "
             << listaCompras.buscar({nome, 0, 0.0f}) << endl;
    }

    return 0;
}
