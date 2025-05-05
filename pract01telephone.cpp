#include<iostream>
using namespace std;

struct Node {
    long long data;
    Node * next;
};

class Hashing {
    private :
        Node *HashTable[10];
    public :
        Hashing(){
            for(int i = 0; i < 10; i++){
                HashTable[i] = NULL;
            }
        }    

        ~Hashing() {
            // Destructor to free all allocated nodes
            for(int i = 0; i < 10; i++) {
                Node* current = HashTable[i];
                while(current != NULL) {
                    Node* nextNode = current->next;
                    delete current;
                    current = nextNode;
                }
                HashTable[i] = NULL;
            }
        }
        
        int hashfx( long long key){
            return(key % 10);
        }
        
        Node *create_node(long long value){
            Node *temp = new Node;
            temp -> data = value;
            temp -> next = NULL;
            return temp;
        }
        
        Node * insert_node(long long value){
            int hashval = hashfx(value);
            Node *head = create_node(value);
            
            if(HashTable[hashval] == NULL){
                HashTable[hashval] = head;
            } else {
                Node *temp = HashTable[hashval];
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = head;
            }
            return head;
        }
        
        void delete_node(long long value){
            int hashval = hashfx(value);
            Node *temp = HashTable[hashval];
            Node *prev = NULL;

            while(temp != NULL && temp->data != value){
                prev = temp;
                temp = temp->next;
            }

            if(temp == NULL){
                cout << "Telephone number not found\n";
                return;
            }

            if(prev == NULL){
                // Deleting the first node in the list
                HashTable[hashval] = temp->next;
            } else {
                prev->next = temp->next;
            }

            delete temp;
            cout << "Deletion Successful!\n";
        }
        
        void display(){
            for(int i = 0; i < 10; i++){
                cout << "a[" << i << "]";
                Node* temp = HashTable[i];
                if(temp == NULL){
                    cout << " -> NULL";
                } else {
                    while(temp){
                        cout << " -> " << temp->data;
                        temp = temp->next;
                    }
                }
                cout << endl;
            }
        }
        
        int search(long long key){
            
            for(int i = 0; i < 10; i++){
                if(HashTable[i] != nullptr && HashTable[i] -> data == key){
                    return i;
                }
                
            }
            return -1;
        }

        void searchvalue(){
            long long key;
            cout<<"Enter the Telephone No. To Search.\n";
            cin>>key;
            int flag = search(key);
            if(flag == -1){
                cout<<"OOPS not present in the table.\n";
            }
            else{
                cout<<"YEAhh found at index "<<flag<<".\n";
            }
        }
};

int main(){
    long long insertdata , deletevalue;
    Hashing h;
    Node *root = nullptr;
    int choice;
    do{
        cout<<"Enter Your Choice :\n";
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.Display\n";
        cout<<"4.Search.\n";
        cout<<"5.Exit\n";
        cin>>choice;
        
        switch(choice){
            case 1 : cout<<"Enter Telephone No. to Insert :";
                     cin>>insertdata;
                     h.insert_node(insertdata);
                     cout<<"Insertion Successful !\n";
                     break;
                     
            case 2 : cout<<"Enter Telephone No. to Delete :";
                     cin>>deletevalue;
                     h.delete_node(deletevalue);
                     // Removed redundant "Deletion Successful!" print here
                     break;
                     
            case 3 : cout<<"Displaying ...\n";
                     h.display();
                     break;

            case 4 : h.searchvalue();
                     break;
                     
            case 5 : cout<<"Exiting... !!\n";
                     break;
                     
            default : cout<<"Invalid Choice !\n"; 
            
        }
    }while(choice != 5);
    
    return 0;
}
