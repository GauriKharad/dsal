#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Record {
    public:
        int roll;
        char dob[8],name[20],phno[20],bg[5],adr[20];
        //string dob,name,phno,bg,adr;

        void accept(){
            cout<<"Enter Your Roll No. : \n";
            cin>>roll;
            cin.ignore();
            cout<<"Enter Your Name : \n";
            cin.getline(name,10);
            // getline(cin,name);
            // cout<<"Enter Your DOB : \n";
            // cin>>dob;
            cout<<"Enter Your Phone Number : \n";
            
            cin.getline(phno,20);
            // getline(cin,phno);
            cout<<"Enter Your Blood Group : \n";
            
            cin.getline(bg,5);
            // getline(cin,bg);
            // cout<<"Enter Your Home Address : \n";
            // cin>>adr;
        }

        void display(){
            cout<<"Roll No. : "<<roll<<" Name : "<<name<<" Phone Number : "<<phno<<" Blood Group : "<<bg<<endl;
        }
};


void addstudent(){

    Record r;
    ofstream outfile("std.txt", ios::binary | ios::app);
    int ans;
    do{
    r.accept();
    outfile.write((char *)&r, sizeof(r));
    
    cout<<"Student Record Added.\n";
    cout<<"Do You Want To Insert More?(1 for continue).\n";
    cin>>ans;
    cin.ignore();
    }while(ans == 1);
    outfile.close();
}

void dispstud(){
    Record r;
    ifstream infile("std.txt", ios::binary);
    if(!infile){
        cout<<"No record found.\n";
        return;
    }
    cout<<"\n----All Student Details----\n";
    while(infile.read((char*)&r,sizeof(r))){
        r.display();
        cout<<"--------------------\n";
    }
    infile.close();
}

void searchStud(int roll){
    Record r;
    ifstream infile("std.txt", ios::binary);
    bool found = false;

    while(infile.read((char*)&r, sizeof(r))){
        if(r.roll == roll){
            r.display();
            found = true;
            break;
        }
    }
    if(!found){
        cout<<"Student with Roll No. "<<roll<<" not Found.\n";
    }
    infile.close();
}

void deletestud(int roll){
    Record r;
    ifstream infile("std.txt",ios::binary);
    ofstream outfile("deletion.txt",ios::binary | ios::app);
    bool flag = false;

    while(infile.read((char*)&r,sizeof(r))){
        if(r.roll == roll){
            flag = true;
            continue;
        }
        outfile.write((char*)&r, sizeof(r));
    }

    infile.close();
    outfile.close();

    remove("std.txt");
    rename("deletion.txt","std.txt");

    if(flag){
        cout<<"Student Record Deleted.\n";
    }
    else{
        cout<<"Student With Roll No. "<<roll<<" is not Present.\n";
    }
}

int main(){
    int ans,choice,roll1,roll2;
    do{
        cout<<"\n-----Menu-----\n";
        cout<<"1.Insert the Student Record.\n";
        cout<<"2.Display the Student Record.\n";
        cout<<"3.Delete the Student Record.\n";
        cout<<"4.Search the Student Record.\n";
        cin>>choice;

        switch(choice){
            case 1 : 
                addstudent();
                break;

            case 2 :
                dispstud();
                break;

            case 3 :
                {
                    cout<<"Enter the Roll No. of Student To Delete the record : ";
                    cin>>roll1;
                    cout<<endl;
                    deletestud(roll1);
                    break;
                }

            case 4 :
                {
                    cout<<"Enter the Roll No. of Student To Search the record : ";
                    cin>>roll2;
                    cout<<endl;
                    searchStud(roll2);
                    break;
                }

            default :
            cout<<"Invalid Choice.\n";
        }
        cout<<"Press 1 for Continue.\n";
        cin>>ans;
    }while(ans == 1);

    return 0;
}
