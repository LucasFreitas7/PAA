#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int count = 1; count <= amount; count++) {
        for (int coin : coins) {
            if (count - coin >= 0) {
                dp[count] = min(dp[count], dp[count - coin] + 1);
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        return -1;
    }

    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5}; // Valores das moedas disponíveis
    int amount = 11; // Quantia a ser formada

    int minCoins = coinChange(coins, amount);

    if (minCoins == -1) {
        cout << "Não é possível formar a quantia " << amount << " com as moedas disponíveis." << endl;
    } else {
        cout << "O número mínimo de moedas necessárias para formar a quantia " << amount << " é " << minCoins << "." << std::endl;
    }

    return 0;
}