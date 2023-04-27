#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> arr, int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);

        return binarySearch(arr, mid + 1, right, x);
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int n = arr.size();
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Elemento nao encontrado no vetor" << endl;
    else
        cout << "Element encontrado na posição " << result << endl;
    return 0;
}

// Ao analisar o codigo percebemos que ele sempre ira na proxima execução diminuir a sua entrada pela metade.
// Ao expandir isso iremos perceber que a sua complexidade sera O(log n), justamente por esta sempre diminuindo 
// sua entrada na metade.
// O melhor caso do algortimo sera O(1), caso o numero que voce procure esteja literalmente no meio de vetor.
//  podemos adotar como o primeiro if como trecho que sera mais executado.
