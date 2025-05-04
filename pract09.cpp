#include<iostream>
using namespace std;

struct Node{
    int key;
    string meaning;
    Node *left, *right = nullptr;
};

class AVL{
    public :
    Node *root= NULL;
        void create_node(){
            char ans;
            do{
            Node *temp = new Node;
            cout<<"Enter the Key : \n";
            cin>>temp -> key;
            cout<<"Enter the Meaning : \n";
            cin.ignore();
            getline(cin,temp -> meaning);
            // temp -> left = temp -> right = nullptr;
                root = insert_node(root,temp);
            // return temp;
            cout<<"Do you want to Insert more?(y/n)\n";
            cin>>ans;
        }while(ans == 'y' || ans == 'Y');
    }

        Node *insert_node(Node *root, Node *temp){
            // Node *temp = create_node(key,mean);
            if(root == NULL){
                return temp;
            }
            else{
                if(temp -> key < root -> key){
                    root -> left = insert_node(root -> left, temp);
                    root = balance(root);
                }
                else{
                    root -> right = insert_node(root -> right, temp);
                    root = balance(root);
                }
            }
            return root;
        }

        Node *balance(Node *cur){
            int var = dif(cur);
            if(var >= 2){
                if(dif(cur -> left) < 0)
                    cur = (LR(cur));
                else{
                    cur = (LL(cur));
                }
            }
            else if(var <= -2){
                if(dif(cur -> right) < 0)
                    cur = RR(cur);
                else{
                    cur = RL(cur);
                }
            }
            return cur;
        }

        int dif(Node *cur){
            int l = height(cur -> left);
            int r = height(cur -> right);
            return l-r;
        }

        int height(Node *cur){
            if (cur == NULL){
                return 0;
            }
                int left = height(cur -> left);
                int right = height(cur -> right);
                return max(left,right) + 1;
        }

        Node *LL(Node *parent){
            Node *temp1,*temp2;
            temp1 = parent -> left;
            temp2 = temp1 -> right;
            temp1 -> right = parent;
            parent -> left = temp2;
            return temp1;
        }

        Node *LR(Node *cur){
            cur -> left = RR(cur -> left);
            return (LL(cur));
        }

        Node *RR(Node *parent){
            Node *temp1,*temp2;
            temp1 = parent -> right;
            temp2 = temp1 -> left;
            temp1 -> left = parent;
            parent ->right = temp2;
            return temp1; 
        }

        Node *RL(Node *cur){
            cur -> right = LL(cur -> right);
            return (RR(cur));
        }

        void ascending(Node *root){
            if(root == NULL){
                return ;
                // cout<<"Nothing in AVL.\n";
            }
            ascending(root -> left);
            cout<<root -> key<<" "<<root -> meaning<<" ";
            cout<<endl;
            ascending(root -> right);
            // return root;
        }

        void descending(Node *root){
            if(root == NULL){
                return ;
                // cout<<"Nothing in AVl.\n";
            }
            descending(root -> right);
            cout<<root -> key<<" "<<root -> meaning<<" ";
            cout<<endl;
            descending(root -> left);
            // return root;
        }

        void displayad(){
            cout<<"The Ascending Order is : ";
            ascending(root);
            cout<<endl;
            cout<<"The Descending Order is : ";
            descending(root);
            cout<<endl;
        }

        bool search(Node *root,int key){
            if(root == NULL){
                return false;
            }
            else{
                if(root -> key == key){
                    return true;
                }
                else if(root -> key < key){
                    return search(root -> right,key);
                }
                else{
                    return search(root -> left,key);
                }
            }
            return false;
        }

        void searchvalue(){
            bool flag = true;
            int key;
            cout<<"Enter the Key to search : \n";
            cin>>key;
            flag = search(root,key);
            if(flag == false){
                cout<<"The Key Not Found.\n";
            }
            else{
                cout<<"The Key Found.\n";
            }
        }

        Node *deleten(Node *root, int key){
            if(root == NULL){
                return root;
            }
            else if(root -> key > key){
                root -> left = deleten(root -> left,key);
            }
            else if(root -> key < key){
                root -> right = deleten(root -> right, key);
            }
            else{
                Node *l = root ->left;
                Node *r = root -> right;
                delete root;

                if(!r) return l;
                    Node *m = r;
                    while(m -> left) m = m -> left;
                    m -> right = Min(r);
                    m -> left = l;
                    return balance(m);
            }
            return balance(root);
        }

        void deletenode(){
            int key;
            cout<<"Enter the Key to delete : \n";
            cin>>key;
            root = deleten(root,key);
        }

        Node *Min(Node *root){
            if(!root -> left) return root -> right;
                Node *temp = root -> left;
                while(temp -> left){
                    temp = temp -> left;
                }
            return temp;
        }
};

int main(){
    AVL tree;
    int ch,val;
    bool flag = 0;
    do{
        cout<<"-- Menu --\n";
        cout<<"1.Insert.\n";
        cout<<"2.Display The Ascending Order and Descending Order Of Key.\n";
        cout<<"3.Search.\n";
        cout<<"4.Delete.\n";
        cin>>ch;

        switch(ch){
            case 1 :
                tree.create_node();
                break;

            case 2 :
                tree.displayad();
                break;

            case 3 : 
                tree.searchvalue();
                break;

            case 4 : 
                tree.deletenode();
                break;

            default :
                cout<<"Invalid Choice.\n";

        }
        cout<<"Do you Want to Continue ? (1 for continue)\n";
        cin>>val;
    }while(val == 1);

    return 0;
}