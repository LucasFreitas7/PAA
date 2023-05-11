#include <iostream>
using namespace std;

int find_max(int arr[], int start, int end) {
    if (start == end) {
        return start;
    }
    if (end == start + 1) {
        return arr[start] > arr[end] ? start : end;
    }
    int meio = (start + end) / 2;
    int pos_esq = find_max(arr, start, meio);
    int pos_dir = find_max(arr, meio+1, end);
    return arr[pos_esq] > arr[pos_dir] ? pos_esq : pos_dir;
}

int main() {
    int arr[] = {5, 8, 2, 10, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pos = find_max(arr, 0, n-1);
    cout << "O maior elemento está na posição: " << pos << endl;
    return 0;
}

// A) se houver vários elementos no array com o maior valor, a função find_max retornará a posição do 
// primeiro elemento encontrado com o maior valor. Isso ocorre porque a função verifica se o elemento da
//  metade esquerda do array é maior do que o da metade direita e retorna a posição correspondente,sem verificar se há 
//  outros elementos com o mesmo valor. Portanto, se houver vários elementos com o maior valor, 
//  a função retornará a posição do primeiro encontrado.

// B) T(n) = 2T(n/2) + O(1)

// C) O algoritmo de divisão e conquista é mais eficiente do que a solução força bruta que 
// seria percorrer todo o array e comparar cada elemento com o maior valor encontrado até agora. 
// A solução força bruta tem um tempo de execução de O(n). O algoritmo de divisão 
// e conquista tem um tempo de execução de O(log n). Portanto, para arrays grandes, o 
// algoritmo de divisão e conquista será muito mais rápido do que a solução força bruta.


// Pior caso O (n)
// Melhor O (1)
// Medio O(log n)