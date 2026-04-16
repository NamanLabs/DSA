#include <iostream>
#include <queue>
using namespace std;

// Define a node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node in the binary tree
Node* insertNode(Node* root, int data) {
    if (!root) {
        return new Node(data); // Create a new root if tree is empty
    }

    queue<Node*> q;
    q.push(root);

    // Level-order traversal to find the first empty spot
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = new Node(data);
            break;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = new Node(data);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

// Function to perform inorder traversal
void inorderTraversal(Node* root) {
    if (!root) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Function to perform preorder traversal
void preorderTraversal(Node* root) {
    if (!root) return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform postorder traversal
void postorderTraversal(Node* root) {
    if (!root) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Function to find and delete the deepest node
void deleteDeepest(Node* root, Node* d_node) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == d_node) {
            temp = nullptr;
            delete d_node;
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = nullptr;
                delete d_node;
                return;
            } else {
                q.push(temp->right);
            }
        }
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = nullptr;
                delete d_node;
                return;
            } else {
                q.push(temp->left);
            }
        }
    }
}

// Function to delete a node
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (!root->left && !root->right) {
        if (root->data == key) {
            delete root;
            return nullptr;
        } else {
            return root;
        }
    }

    queue<Node*> q;
    q.push(root);

    Node* keyNode = nullptr;
    Node* temp;

    // Find the key and the deepest node
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->data == key) {
            keyNode = temp;
        }
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }

    if (keyNode) {
        int x = temp->data;
        deleteDeepest(root, temp);
        keyNode->data = x;
    }

    return root;
}

// Main function
int main() {
    Node* root = nullptr;

    // Insert nodes into the binary tree
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Deleting node 20..." << endl;
    root = deleteNode(root, 20);

    cout << "Inorder traversal after deletion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}