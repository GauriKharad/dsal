#include<iostream>
#include<queue>
using namespace std;

struct node {
    int data;
    node *left, *right;
    node(int val) : data(val), left(nullptr), right(nullptr) {} 
};

class BST {
public:
    node* root = nullptr;

    void insert(int val) { 
        node* newnode = new node(val); 
        if (root == nullptr) {
            root = newnode;
            cout << "Root Node Inserted.\n";
            return;
        }

        node* current = root;
        while (true) { 
            if (val == current->data) {
                cout << "Element Already Present.\n";
                delete newnode; 
                return;
            } else if (val < current->data) {
                if (current->left == nullptr) {
                    current->left = newnode;
                    cout << "Node Added to Left Side.\n";
                    return;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = newnode;
                    cout << "Node Added to Right Side.\n";
                    return;
                }
                current = current->right;
            }
        }
    }

    void display(node* temp, int depth = 0) {
        if (!temp) return; 
        display(temp->right, depth + 1);
        for (int i = 0; i < depth; i++) cout << "     ";
        cout << temp->data << "\n";
        display(temp->left, depth + 1);
    }

    node* Delete(node* root, int key) {
        if (root == nullptr) return root;
        if (key < root->data) {
            root->left = Delete(root->left, key);
        } else if (key > root->data) {
            root->right = Delete(root->right, key);
        } else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->left) {
                node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                node* temp = root->left;
                delete root;
                return temp;
            } else {
                node* successor = findMin(root->right); 
                root->data = successor->data;
                root->right = Delete(root->right, successor->data); 
            }
        }
        return root;
    }

    int findpath(node* root) {
        if (!root) return 0;
        int left = findpath(root->left);
        int right = findpath(root->right);
        return max(left, right) + 1;
    }

    node* findMin(node* root) {
        while (root && root->left) {
            root = root->left;
        }
        return root; 
    }

    void inorder(node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(node* root) {
        if (!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    node* swaptree(node* temp) {
        if (!temp) return temp;
        swap(temp->left, temp->right);
        swaptree(temp->left);
        swaptree(temp->right);
        return temp;
    }

    void BFS(node* root) {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }

        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

   
    node* getRoot() { return root; }//use this function instead of root because it can update the value
    void setRoot(node* newRoot) { root = newRoot; }//will not require to assign separately just call this fx.
};

int main() {
    int ans, key, choice;
    BST b;

    do {
        cout << "\n-----Menu-----\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Delete\n";
        cout << "4. Longest Path\n";
        cout << "5. Minimum Value\n";
        cout << "6. Inorder\n";
        cout << "7. Preorder\n";
        cout << "8. Postorder\n";
        cout << "9. BFS\n";
        cout << "10. Swap Tree\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                b.insert(key); 
                break;

            case 2:
                cout << "BST Display:\n";
                b.display(b.getRoot());
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                b.setRoot(b.Delete(b.getRoot(), key));
                break;

            case 4:
                cout << "Longest Path: " << b.findpath(b.getRoot()) << "\n";
                break;

            case 5: {
                node* minNode = b.findMin(b.getRoot());
                if (minNode)
                    cout << "Minimum Value: " << minNode->data << "\n";
                else
                    cout << "Tree is empty.\n";
                break;
            }

            case 6:
                cout << "Inorder Traversal:\n";
                b.inorder(b.getRoot());
                cout << "\n";
                break;

            case 7:
                cout << "Preorder Traversal:\n";
                b.preorder(b.getRoot());
                cout << "\n";
                break;

            case 8:
                cout << "Postorder Traversal:\n";
                b.postorder(b.getRoot());
                cout << "\n";
                break;

            case 9:
                cout << "BFS Traversal:\n";
                b.BFS(b.getRoot());
                cout << "\n";
                break;

            case 10: {
                node* newRoot = b.swaptree(b.getRoot());
                cout << "Swapped Tree Display:\n";
                b.display(newRoot);
                break;
            }

            default:
                cout << "Invalid choice!\n";
        }

        cout << "\nPress 1 to continue: ";
        cin >> ans;

    } while (ans == 1);

    return 0;
}
