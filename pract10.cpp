#include <iostream>
using namespace std;

#define max 20
class HeapArrangement{
    private :
    int array[max];
    public:
        
    HeapArrangement(){
        for(int i = 0; i < max ;i++){
            array[i] = 0;
        }
    }
        void heapShell(int total){
            int i,j,temp;
            char ch;
            do{
            for(i = 1; i <= total; i++){
                cout<<"Enter the marks of "<<i<<" :";
                cin>>array[i];
                cout<<endl;
                j = i;
                int par = j/2;

                while(array[j] <= array[par] && j!=0){
                    temp = array[j];
                    array[j] = array[par];
                    array[par] = temp;
                    j = par;
                    par = j/2;
                }
            }
            cout<<"Insert More ?(1 for continue)\n";
            cin>>ch;
        }while(ch == 1);
    }
        int maxMarks(int total){
            int Max = array[1];
            for(int i = 1; i < max;i++){
                if(Max < array[i]){
                    Max = array[i];
                }
            } 
            return Max;
        }

        void minMarks(){
            cout<<"Minimum Marks In the Class :"<<array[1];
        }
        // not necessary to display it as heap you canjust print it also
        
        void displayheap(int total){
            int i=1, space = 6;
            
            while(i <= total){
               if(i==1 || i==2 || i==4 || i==8 || i==16)
                    {
                    cout<<endl<<endl;
                    for(int j=0;j<space;j++)
                         cout<<" ";
                    space-=2;   
                    }
                   cout<<" "<<array[i];i++;
                cout<<endl<<endl;
            }
};

int main(){
    HeapArrangement h;
    int ch,total,MaxMarks;
    string choice;
    do{
        cout<<"--Heap Menu--\n";
        cout<<"1.Insert The Marks.\n";
        cout<<"2.Display The Marks.\n";
        cout<<"3.Maximum Marks In The Class.\n";
        cout<<"4.Minimum Marks In The Class.\n";
        cout<<"5.Exit.\n";
        cin>>ch;
        switch(ch){
            case 1 :
                cout<<"How Many Marks you Want to Insert?\n";
                cin>>total;
                h.heapShell(total);
                break;

            case 2 :
                cout<<"Displaying :\n";
                h.displayheap(total);
                break;

            case 3 :
                cout<<"Maximum Marks In The Class : ";
                cout<<h.maxMarks(total);
                break;

            case 4 : 
                // cout<<"Minimum Marks In The Class : ";
                h.minMarks();
                break;

            case 5 : 
                cout<<"Thank Youhh !! Nigh Chal \n";
                break;

            default :
            cout<<"Invalid Choice.\n";
        }
        cout<<endl;
        cout<<"Chalu Thevaychay Ka ?(ho ki nahi).\n";
        cin>>choice;
    }while(choice == "ho" || choice == "HO");

    return 0;

}
