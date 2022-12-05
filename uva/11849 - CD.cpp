//UVA 11849 - CD
//Done with own implementation of balanced BST as an exercise

#include <cstdio>
#include <algorithm>

using namespace std;

struct CD {
    int num; //Catalog number of the CD -> Key
    int cont; //Number of copies owned

    CD() {
        num = 0;
        cont = 0;
    }

};

//AVL Tree implementation
struct Node {
    int height;
    CD cd;
    Node *left;
    Node *right;
    //Node *parent;

    Node(int num) {
        cd.num = num;
        height = 0;
        left = nullptr;
        right = nullptr;
    }
};

Node* get(int num, Node* node) { //Get node given key
    while(node != nullptr && node -> cd.num != num) {
        if(num < node -> cd.num)
            node = node -> left;
        else
            node = node -> right;
    }
    return node;
}

int height(Node* node) { //Returns height of given node
    if(node == nullptr)
        return -1;
    else return node -> height;
}

Node* rightRotate(Node* node) { //AVL tree operation
    Node* left = node -> left;
    Node* aux = left -> right;

    left -> right = node;
    node -> left = aux;

    node -> height = max(height(node -> left), height(node -> right)) + 1;
    left -> height = max(height(left -> left), height(left -> right)) + 1;

    return left;
}

Node* leftRotate(Node *node) { //AVL tree operation
    Node *right = node -> right;
    Node *aux = right -> left;

    right -> left = node;
    node -> right = aux;

    node -> height = max(height(node -> left), height(node -> right)) + 1;
    right -> height = max(height(right -> left), height(right -> right)) + 1;

    return right;
}

int getBalance(Node* node) { //Balance of node = (Left child's height - right child's height) + 1
    if(node == nullptr)
        return -1;
    else return height(node -> left) - height(node -> right);
}

void insert(int num, Node *&root) {//Pointer passed by reference
    //Standard bst insert
    if(root == nullptr) {
        root = new Node(num);
        return;
    }
    if(num < root -> cd.num)
        insert(num, root -> left);
    else if (num > root -> cd.num)
        insert(num, root -> right);
    else return; //Avoid duplicates

    //Height update
    root -> height = max(height(root -> left), height(root -> right)) + 1;

    //Balance tree
    int balance = getBalance(root);

    if(balance > 1) {
        if(num > root -> left -> cd.num) //Left - Right case
            root -> left = leftRotate(root -> left);
        root = rightRotate(root);
    } else if(balance < -1) {
        if(num < root -> right -> cd.num) //Right - Left case
            root -> right = rightRotate(root -> right);
        root = leftRotate(root);
    }
}

int ownedByBoth(Node* node) { //Count CDs owned by both Jack and Jill
    if(node == nullptr) return 0;
//    if(node -> left == nullptr && node -> right == nullptr) {
//        if(node -> cd.cont > 1) return 1;
//        else return 0;
//    }
    int res = ownedByBoth(node -> left) + ownedByBoth(node -> right);
    if(node -> cd.cont > 1) return res + 1;
    return res;
}


int main() {
    int n, m; //N, M: CDs owned by Jack and Jill respectively
    while(scanf("%d %d", &n, &m), n || m) {
        Node *root = nullptr;
        int num;
        for(size_t i = 0; i < n + m; i++) {
            scanf("%d", &num);
            if(root == nullptr) {
                root = new Node(num);
                root -> cd.cont++;
            }
            else {
                insert(num, root);
                get(num, root) -> cd.cont++;
            }
        }
        printf("%d\n", ownedByBoth(root));
    }
}