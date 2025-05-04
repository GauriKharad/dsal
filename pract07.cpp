// #include <iostream>
// #include <string.h>
// using namespace std;

// class Flight{
//     public :
//         char cityname[10][10];
//         int amt[10][10];
//         Flight(){
//             for(int i = 0 ; i < 10; i++){
//                 strcpy(cityname[i],"XX");
//             }
//             for(int i = 0; i < 10; i++){
//                 for(int j = 0; j < 10; j++){
//                     amt[i][j] = 0;
//                 }
//             }
//         }

//         int create(int citycount){
//             char s[10],d[10],ch;
//             int i,j;
//             int si = 0,di = 0,wt;
//             do{
//             cout<<"Enter the Source : \n";
//             cin>>s;
//             cout<<"Enter the Destination : \n";
//             cin>>d;
//             for(i = 0; i < 10; i++){
//                 if(strcmp(cityname[i],s)==0){
//                 si= i;
//                 break;
//             }
//             }
//             if(si == -1){
//                 strcpy(cityname[citycount],s);
//                 si = citycount;
//                 citycount++;
//             }

//             for(i = 0; i < 10; i++){
//                 if(strcmp(cityname[i],d)==0){
//                 di = i;
//                 break;
//             }
//             }
//             if(di == -1){
//                 strcpy(cityname[citycount],d);
//                 citycount++;
//             }

//             cout<<"Distance Between "<<s<<" and "<<d<<" is : ";
//             cin>>wt;

//            amt[si][di] = wt;
//            cout<<"Do you want to add more?(y/n)\n";
//            cin>>ch;

//            si = di = -1;
//         }while(ch == 'Y' || ch == 'y');
//         return citycount;
//     }

//     void display(int city_count){
//         cout<<"Displaying the Adjacency Matrix : \n";
//         for (int i = 0; i < city_count ; i++){
//             cout<<"\t"<<cityname[i]<<"\n";
//         }
//         for(int i = 0; i < city_count ; i++){
//             cout<<"\t"<<cityname[i]<<"\n";
//             for(int j = 0 ; j < city_count ;j++){
//                 cout<<"\t"<<amt[i][j];
//             }
//             cout<<endl;
//         }
//     }
// };

// int main(){
//     Flight f;
//     int ch;
//     char choice;
//     do{
//     cout<<"--Flight Menu--\n";
//     cout<<"1.Insert.\n";
//     cout<<"2.Display Adjacency Matrix.\n";
//     cout<<"3.Exit.\n";
//     cin>>ch;
//     int citycount = 0;

//     switch(ch){
//         case 1 : 
//             citycount = f.create();
//             break;

//         case 2 :
//             f.display(citycount);
//             break;

//         case 3 : 
//             cout<<"Jaa gharii !!\n";
//             break;

//         default : 
//             cout<<"Invalid Choice.\n";

        
//     }
//     cout<<"Do You Want To Continue ?(y/n)\n";
//     cin>>choice;
// }while(choice == 'Y' || choice == 'y');
// return 0;
// }

#include <iostream>
#include <string.h>
using namespace std;

class Flight {
public:
    char cityname[10][10];
    int amt[10][10];

    Flight() {
        for (int i = 0; i < 10; i++) {
            strcpy(cityname[i], "XX");
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                amt[i][j] = 0;
            }
        }
    }

    int create(int citycount) {
        char s[10], d[10], ch;
        int si = -1, di = -1, wt;

        do {
            cout << "Enter the Source: ";
            cin >> s;
            cout << "Enter the Destination: ";
            cin >> d;

            // Check if source exists
            for (int i = 0; i < citycount; i++) {
                if (strcmp(cityname[i], s) == 0) {
                    si = i;
                    break;
                }
            }
            if (si == -1) {
                strcpy(cityname[citycount], s);
                si = citycount;
                citycount++;
            }

            // Check if destination exists
            for (int i = 0; i < citycount; i++) {
                if (strcmp(cityname[i], d) == 0) {
                    di = i;
                    break;
                }
            }
            if (di == -1) {
                strcpy(cityname[citycount], d);
                di = citycount;
                citycount++;
            }

            cout << "Distance Between " << s << " and " << d << ": ";
            cin >> wt;
            amt[si][di] = wt;

            cout << "Do you want to add more? (y/n): ";
            cin >> ch;

            si = di = -1; // reset indices for next loop
        } while (ch == 'Y' || ch == 'y');

        return citycount;
    }

    void display(int city_count) {
        cout << "\nAdjacency Matrix:\n\t";
        for (int i = 0; i < city_count; i++) {
            cout << cityname[i] << "\t";
        }
        cout << "\n";

        for (int i = 0; i < city_count; i++) {
            cout << cityname[i] << "\t";
            for (int j = 0; j < city_count; j++) {
                cout << amt[i][j] << "\t";
            }
            cout << "\n";
        }
    }
};

int main() {
    Flight f;
    int ch;
    char choice;
    int citycount = 0; // Persist across menu choices

    do {
        cout << "\n-- Flight Menu --\n";
        cout << "1. Insert\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                citycount = f.create(citycount);
                break;

            case 2:
                if (citycount == 0) {
                    cout << "No cities entered yet.\n";
                } else {
                    f.display(citycount);
                }
                break;

            case 3:
                cout << "Jaa gharii !!\n";
                return 0;

            default:
                cout << "Invalid Choice.\n";
        }

        cout << "Do You Want To Continue? (y/n): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
