#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    Node *nodes[26];
    for (int i = 0; i < 26; ++i) nodes[i] = nullptr;

    for (int i = 0; i < N; ++i) {
        char x, y, z;
        cin >> x >> y >> z;
        int idx = x - 'A';
        if (!nodes[idx]) nodes[idx] = createNode(x);
        if (y != '.') {
            nodes[y - 'A'] = createNode(y);
            nodes[idx]->left = nodes[y - 'A'];
        }
        if (z != '.') {
            nodes[z - 'A'] = createNode(z);
            nodes[idx]->right = nodes[z - 'A'];
        }
    }
    Node *root = nodes[0];

    preorder(root);
    cout<<"\n";
    inorder(root);
    cout<<"\n";
    postorder(root);
    return 0;
}

void inorder(Node *root)
{
    if (root == nullptr) return;
    inorder(root->left);
    cout << (char)root->data;
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == nullptr) return;
    cout << (char)root->data;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << (char)root->data;
}