#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x),left(NULL),right (NULL){};
};


class Traversal{
    public:
Node *createNode(int value){
    Node *temp = new Node(value);
    return temp;
}


int longestPath(Node *root){
    if(root == NULL){
        return 0;
    }
    else{
        int leftpath = longestPath(root -> left);
        int rightpath = longestPath(root -> right);
        return max(leftpath,rightpath) + 1;
    }
}

int minValue(Node *root){
    if(root == NULL){
        cout<<"Tree Is Empty\n";
        return 0;
    }
    else{
        if(root -> left){
            root = root -> left;
        }
        return root -> data;
    }
    
}

Node *swapTree(Node *root){
   
    if(root){
        swap(root -> left, root -> right);
        swapTree(root -> left);
        swapTree(root -> right);
    }
    return root;
}

Node *insertNode(Node *root, int data){
    Node * temp = new Node(data);
    if(root == NULL){
        root = temp;
    }
    else{
        if(root -> data < data){
            root -> right = insertNode(root -> right,data);
        }
        else{
            root -> left = insertNode(root -> left, data);
        }
    }
    return root;
}

Node *findMin(Node *root){
    while(root -> left != NULL){
        root = root -> left;
    }
    return root;
}

Node *Delete(Node *root,int key){
    
    if(root == NULL){
        cout<<"Empty.\n";
    }
    if(key > root -> data){
        return Delete(root -> right , key);
    }
    else if(key < root -> data){
        return Delete(root -> left , key);
    }
    else{

        // no child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
        }
        //single child
        else if(root -> left == NULL){
            Node *temp = root -> right;//right child is present.
            delete root;
            return temp;
        }
        else if(root -> right == NULL){
            Node * temp = root -> left;//left child is present.
            delete root;
            return temp;
        }

        else{
            Node * successor = findMin(root -> right);
            root -> data = successor -> data;
            return Delete(root -> right , successor -> data);
            
        }
    }
    return root;
}

void inorder(Node * root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(Node *root){
    if(root){
        cout<<root -> data <<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
    
void postorder(Node *root){
    if(root){
        postorder(root-> left);
        postorder(root -> right);
        cout<<root -> data<<" ";
    }
}

void BFS(Node * root){
    if(root == NULL){
        cout<<"Can't perform BFS.\n";
    }
    else{
        queue<Node *> q;
        q.push(root);
        while(!q.empty())
        {
            Node * temp = q.front();
            q.pop();

            cout<<temp -> data <<" ";

            if(temp -> left)q.push(temp->left);
            if(temp -> right)q.push(temp -> right);
        }    
    }
}

int search(Node *root, int value){
    if(root == NULL){
        return 0;

    }
    else{
        if(root -> data == value){
            return 1;
        }
        else if(root -> data > value){
            return search(root -> left,value);
        }
        else{
            return search(root -> right,value);
        }
    }
}

void display(node *ptr, int level){
    if (ptr != NULL) {
        display(ptr->right, level + 1);
        cout << endl;
        for (int i = 0; i < level; i++)
            cout << "       ";
        cout << ptr->data;
        display(ptr->left, level + 1);
    }
}

node *deletenode(node *root, int key){
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) return root->right;
        else if (!root->right) return root->left;
        root->data = min(root->right);
        root->right = deleteNode(root->right, root->info);
    }
    return root;
}


};


int main(){
    Traversal t;
    Node *root = nullptr;
    Node *another = nullptr;
    Node *temp = nullptr;
    int key;
    int values[] = {21,27,25,1,28,76,11};
    for(int value : values){
        root = t.insertNode(root,value);
    }
    int ch,dt,sch,it,find;
    
    do{
        cout<<"Menu :\n";
        cout<<"1.Insert a new node.\n";
        cout<<"2.Longest Path.\n";
        cout<<"3.Minimum Value.\n";
        cout<<"4.Swap the BST.\n";
        cout<<"5.Search A Value.\n";
        cout<<"6.Inorder Traversal.\n";
        cout<<"7.Preorder Traversal.\n";
        cout<<"8.Postorder Traversal.\n";
        cout<<"9.BFS.\n";
        cout<<"10.Exit.\n";
        cout<<"11.Display.\n";
        cout<<"12.Delete a node.\n";
        cin>>ch;

        switch(ch){
            case 1 :
                cout<<"Enter the Data to Insert : ";
                cin>>dt;
                t.insertNode(root,dt);
                cout<<endl;
                break;

            case 2 :
                cout<<"Longest Path is : "<<t.longestPath(root);
                cout<<endl;
                break;

            case 3 :
                cout<<"The Minimum value In BST is : "<<t.minValue(root);
                cout<<endl;
                break;

            case 4 :
                another = t.swapTree(root);
                cout<<"Swapped tree is : ";
                t.inorder(another);
                cout<<endl;
                break;

            case 5 :
                {cout<<"Enter the data to Search : ";
                cin>>sch;
                find = t.search(root,sch);
                if(find == 0){
                    cout<<"Data is absent.\n";
                }
                else{
                    cout<<"Data is present.\n";
                }
                break;
            }

            case 6 :
                cout<<"Inorder Traversal : ";
                t.inorder(root);
                cout<<endl;
                break;

            case 7 :
                cout<<"Preorder Traversal : ";
                t.preorder(root);
                cout<<endl;
                break;

            case 8 : 
                cout<<"Postorder Traversal : ";
                t.postorder(root);
                cout<<endl;
                break;

            case 9 :
                cout<<"BFS : ";
                t.BFS(root);
                cout<<endl;
                break;

            case 10 :
                cout<<"Thank You !\n";
                break;

            case 11 :
                cout<<"BST Traversal.\n";
                t.display();
                break;

            case 12 :
                {
                    cout<<"Enter a Node to delete :";
                    cin>>key;
                cout<<"Deleting a node.\n";
                temp = t.deletenode(root,key);
                    break;
                }
            
            default : 
            cout<<"Invalid Choice, Try Again !!!\n";

        }

        cout<<"Do You Want To Continue ?(1/0)\n";
        cin>>it;
    }while(it == 1);

    return 0;
}
