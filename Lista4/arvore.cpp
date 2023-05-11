#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insertNode(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else if (val > root->val) {
        root->right = insertNode(root->right, val);
    }

    return root;
}

int treeSize(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftSize = treeSize(root->left);
    int rightSize = treeSize(root->right);

    return leftSize + rightSize + 1;
}

int main() {
    Node* root = nullptr;

    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 6);
    root = insertNode(root, 5);
    root = insertNode(root, 7);

    cout << "Tamanho da arvore: " << treeSize(root) << endl;

    return 0;
}

// A complexidade do algortimo é O(n), onde n é o número de nós na árvore.
// Isso porque a função percorre todos os nós da árvore exatamente uma vez,
// somando 1 para cada nó visitado. Portanto, a complexidade da função é linear 
// em relação ao número de nós na árvore.