#include <iostream>
#include <cstring>
using namespace std;

class HashFunction {
public:
    typedef struct hash {
        long phno;
        char name[10];
    } hash;

    hash h[10];

    HashFunction() {
        for (int i = 0; i < 10; i++) {
            h[i].phno = -1;
            strcpy(h[i].name, "");
        }
    }

    int hashFunc(long x) {
        return x % 10;
    }

    int search(long key) {
        for (int i = 0; i < 10; i++) {
            if (h[i].phno == key) {
                return i;
            }
        }
        return -1;
    }

    void Delete(long key) {
        int idx = search(key);
        if (idx == -1) {
            cout << "Phone Number " << key << " not found.\n";
        } else {
            h[idx].phno = -1;
            strcpy(h[idx].name, "");
            cout << "Deleted Successfully.\n";
        }
    }

    // void Insert(long key, char Name[10]) {
    //     int hashval = hashFunc(key);
    //     int originalHash = hashval;
    //     int i = 0;

    //     while (h[hashval].phno != -1 && i < 10) {
    //         hashval = (originalHash + ++i) % 10;
    //     }

    //     if (i == 10) {
    //         cout << "Hash Table is Full.\n";
    //         return;
    //     }

    //     h[hashval].phno = key;
    //     strcpy(h[hashval].name, Name);
    // }

    void Insert(){
        int cnt = 0,i,j,k,l; 
        int flag = 0;
        long key,temp;
        char ans;
        char Name[10],ntemp[10];
        do{
            if(cnt >= 10){
                cout<<"HashTable is Full.\n";
                break;
            }
            cout<<"Enter the telephone No. : \n";
            cin>>key;
            cout<<"Enter the name : \n";
            cin>>Name;

            int hashval = key % 10;
            if(h[hashval].phno == -1){
                h[hashval].phno = key;
                strcpy(h[hashval].name,Name);
            }
            else{
                if(h[hashval].phno % 10 != hashval){
                    temp = h[hashval].phno;
                    strcpy(ntemp,h[hashval].name);
                    h[hashval].phno = key;
                    strcpy(h[hashval].name,Name);
                
                for(i = hashval + 1; i < 10; i++){
                    if(h[i].phno == -1){
                        h[i].phno = temp;
                        strcpy(h[i].name,ntemp);
                        flag = 1;
                        break;
                    }
                }
                for(j = 0; j < hashval && flag ==0; j++){
                    if(h[j].phno == -1){
                        h[j].phno = temp;
                        strcpy(h[j].name,ntemp);
                        break;
                    }
                }
            }
            else{
                for( k = hashval + 1; k < 10; k++){
                    if(h[k].phno == -1){
                        h[k].phno = key;
                        strcpy(h[k].name,Name);
                        flag = 1;
                        break;
                    }
                }
                for( l = 0; l < hashval && flag == 0; l++){
                    if(h[l].phno == -1){
                        h[l].phno = key;
                        strcpy(h[l].name,Name);
                        break;
                    }
                }
            }
        }
        flag = 0;
        cnt++;
            cout<<"Do You Want to Insert More ?(y/n)\n";
            cin>>ans;
        }while(ans == 'y' || ans == 'Y');
    }


    void display() {
        cout << "\n--- Hash Table ---\n";
        for (int i = 0; i < 10; i++) {
            cout << "Index " << i << ": ";
            if (h[i].phno != -1)
                cout << "Phone: " << h[i].phno << ", Name: " << h[i].name << endl;
            else
                cout << "Empty\n";
        }
    }
};

int main() {
    char name[10];
    long phone;
    int choice, index;
    char conti;

    HashFunction fx;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // {cout << "Enter Telephone Number: ";
            // cin >> phone;
            // cout << "Enter Name: ";
            // cin >> name;
            fx.Insert();
            break;
            

        case 2:
            {cout << "Enter Telephone Number to Delete: ";
            cin >> phone;
            fx.Delete(phone);
            break;
            }
        case 3:
            {cout << "Enter Telephone Number to Search: ";
            cin >> phone;
            index = fx.search(phone);
            if (index == -1) {
                cout << "Not Found!\n";
            } else {
                cout << "Found at index " << index << ": " << fx.h[index].name << endl;
            }
            break;
        }
        case 4:
            fx.display();
            break;

        case 5:
            cout << "Thank You!\n";
            return 0;

        default:
            cout << "Invalid Choice!\n";
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> conti;

    } while (conti == 'y' || conti == 'Y');

    return 0;
}
