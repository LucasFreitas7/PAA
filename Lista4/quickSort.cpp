#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);

        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    quickSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// O QuickSort não é um algoritmo estável, o que significa que ele não garante 
// a manutenção da ordem relativa dos elementos iguais. Isso ocorre devido à natureza
// do algoritmo, que consiste em escolher um elemento como pivô e particionar o array
// em duas partes: uma parte com elementos menores que o pivô e outra com elementos 
// maiores. Durante a troca de elementos para particionar o array, elementos iguais
// podem acabar sendo trocados de ordem, o que pode alterar a ordem relativa entre
// eles. Portanto, se houver dois elementos iguais no array original, 
// eles podem não aparecer na ordem relativa correta no array ordenado após a execução do QuickSort.