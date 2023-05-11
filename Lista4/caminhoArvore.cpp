#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Função para inserir um novo nó na árvore
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    } else {
        Node* cur;
        if (data <= root->data) {
            cur = insertNode(root->left, data);
            root->left = cur;
        } else {
            cur = insertNode(root->right, data);
            root->right = cur;
        }
        return root;
    }
}

// Função auxiliar para criar um novo nó na árvore
Node* newNode(int data) { 
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Caminhamento em pré-ordem (preorder traversal)
void preorder(Node* node) { // raiz, esquerda, direita.
    if (node == NULL) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// Caminhamento em pós-ordem (postorder traversal)
void postorder(Node* node) { // esquerda, direita, raiz
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

// Caminhamento em ordem simétrica (inorder traversal)
void inorder(Node* node) { // esquerda, raiz, direita.
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main() {
    // Exemplo de criação de uma árvore binária
    Node* root = NULL;
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 5);
    root = insertNode(root, 1);
    root = insertNode(root, 3);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}

// A complexidade do caminhamento é dominada pelo número de nós, que é O(n).
