#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST {
    private:
    TreeNode* node;
    TreeNode* insertHelper(TreeNode* node, int val) {
        if (node == NULL)
            return new TreeNode(val);

        if (val < node->val)
            node->left = insertHelper(node->left, val);
        else if (val > node->val)
            node->right = insertHelper(node->right, val);

        return node;
    }

    TreeNode* searchHelper(TreeNode* node, int val) {
        if (node == NULL || node->val == val)
            return node;

        if (val < node->val)
            return searchHelper(node->left, val);
        else
            return searchHelper(node->right, val);
    }
public:
    BST() {
        node = NULL;
    }

    void insert(int val) {
        node = insertHelper(node, val);
    }

    TreeNode* search(int val) {
        return searchHelper(node, val);
    }


};

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(9);

    TreeNode* node = bst.search(7);
    if (node == NULL)
        cout << "Elemento nao foi encontrado" << endl;
    else
        cout << "Elemento na posição: " << node->val << endl;

    node = bst.search(12);
    if (node == NULL)
        cout << "Elemento nao foi encontrado" << endl;
    else
        cout << "Elemento na posição: " << node->val << endl;

    return 0;
}


// Ao analisermos tanto a inserção quando a busca teremos algumas coisas parecidas.
// Todas as duas terao com melhor caso, ou se voce busca o primeiro elemento da arvore, ou se voce está inserindo. O(1)
// Teremos como pior caso se temos uma arvore desbalencada assim tanto para inserção quando para procura será 0(N)
// Ja como o caso médio seria o caso onde ele sempre vai diminuir a entrada pela metade, deixando de olhar para um lado
// arvore, tendo assim um caso médio de (log n)



