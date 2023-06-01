#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int collectCoins(vector<vector<int>>& grid, int row, int col) {
    // Verifica se está fora dos limites da grade
    if (row >= grid.size() || col >= grid[0].size()) {
        return 0;
    }

    // Verifica se chegou à célula de destino (canto inferior direito)
    if (row == grid.size() - 1 && col == grid[0].size() - 1) {
        return grid[row][col];
    }

    // Calcula a quantidade máxima de moedas coletadas ao mover para baixo e para a direita
    int coinsDown = collectCoins(grid, row + 1, col);
    int coinsRight = collectCoins(grid, row, col + 1);

    // Retorna o valor máximo acumulado ao escolher o caminho com mais moedas
    return grid[row][col] + max(coinsDown, coinsRight);
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {2, 2, 4},
        {5, 0, 2}
    };

    int maxCoins = collectCoins(grid, 0, 0);

    cout << "O número máximo de moedas que pode ser coletado é: " << maxCoins << endl;

    return 0;
}
