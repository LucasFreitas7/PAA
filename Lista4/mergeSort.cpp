#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    vector<int> temp(right - left + 1);

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    mergeSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// O MergeSort é um algoritmo estável, o que significa que ele mantém a ordem relativa dos elementos iguais.
// Isso é garantido pelo fato de que o algoritmo, ao dividir o array em sub-arrays menores e depois juntá-los, 
// sempre coloca os elementos iguais ou menores do sub-array da esquerda antes dos elementos maiores do sub-array da
// direita. Portanto, se houver dois elementos iguais no array original, eles aparecerão na ordem relativa 
// correta no array ordenado.



//Por exemplo, considere a lista de pessoas abaixo:
//     Ana, 30 anos
//     João, 25 anos
//     Maria, 30 anos
//     Pedro, 22 anos

// Se ordenarmos esta lista por idade usando um algoritmo estável, a saída será:

//     Pedro, 22 anos
//     João, 25 anos
//     Ana, 30 anos
//     Maria, 30 anos

