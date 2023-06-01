#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int collectCoins(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Cria uma matriz para armazenar os resultados intermediários
    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    // Inicializa o último elemento da matriz dp com o valor da última célula da grade
    dp[rows-1][cols-1] = grid[rows-1][cols-1];

    // Preenche a última coluna da matriz dp
    for (int i = rows - 2; i >= 0; i--) {
        dp[i][cols-1] = dp[i+1][cols-1] + grid[i][cols-1];
    }

    // Preenche a última linha da matriz dp
    for (int j = cols - 2; j >= 0; j--) {
        dp[rows-1][j] = dp[rows-1][j+1] + grid[rows-1][j];
    }

    // Preenche o restante da matriz dp de baixo para cima e da direita para a esquerda
    for (int i = rows - 2; i >= 0; i--) {
        for (int j = cols - 2; j >= 0; j--) {
            dp[i][j] = grid[i][j] + max(dp[i+1][j], dp[i][j+1]);
        }
    }

    // Retorna o valor máximo acumulado na posição inicial (0, 0)
    return dp[0][0];
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {2, 2, 4},
        {5, 0, 2}
    };

    int maxCoins = collectCoins(grid);

    cout << "O número máximo de moedas que pode ser coletado é: " << maxCoins << endl;

    return 0;
}
