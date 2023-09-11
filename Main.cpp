#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

class Bank{
    private:
    int total;
    int id;
    struct person{
        int AccNo;
        string name, AccType;
        int contact, money;
    }
    person[100];
    public:
    Bank(){
        total = 0;
    }
    void choice();
    void perData();
    void show();
    void update();
    void search();
    void transactions();
    void del();


};

void Bank::choice(){
    char ch;
    while(1){
        cout<<"\n\nPress..!!"<<endl;
    cout<<"1. Create New Account"<<endl;
    cout<<"2. View Customers List"<<endl;
    cout<<"3. Update Information of existing account"<<endl;
    cout<<"4. Check the details of an existing account"<<endl;
    cout<<"5. For Transactions"<<endl;
    cout<<"6. Remove Existing account"<<endl;
    cout<<"7. Exit"<<endl;
    ch = getch();
    switch(ch){
        case '1':
        Bank::perData();
        break;

        case '2':
        Bank::show();
        break;

        case '3':
        Bank::update();
        break;

        case '4':
        Bank::search();
        break;

        case '5':
        Bank::transactions();

        case '6':
        Bank::del();
    }
    }
}

void Bank::perData(){
    cout<<"Enter data of person"<<total+1<<endl;
    cout<<"Enter Name: ";
    cin>>person[total].name;
    cout<<"Enter AccNo: "<<endl;
    cin>>person[total].AccNo;
    cout<<"Enter Account Type: "<<endl;
    cin>>person[total].AccType;
    cout<<"Enter Contact No: "<<endl;
    cin>>total[person].contact;
    cout<<"Enter Money to Deposit: "<<endl;
    cin>>person[total].money;


    total++;
}

void Bank::show(){
    for(int i = 0; i<total; i++){
        cout<<"Data of Person "<<i+1<<endl;
        cout<<"Name: "<<person[i].name<<endl;
        cout<<"Account No: "<<person[i].AccNo<<endl;
        cout<<"Account Type: "<<person[i].AccType<<endl;
        cout<<"Contact: "<<person[i].contact<<endl;
        cout<<"Money to Deposit: "<<person[i].money<<endl;
        break;

        if(i == total-1){
        cout<<"No such customers found"<<endl;
    }
    }
    
}

void Bank::update(){
    cout<<"Enter the customer id to change the data"<<endl;
    cin>>id;
    for(int i = 0; i<total; i++){
        if(id == person[i].AccNo){
            cout<<"Enter Previous Data";
            cout<<"Data of Person "<<i+1<<endl;
            cout<<"Name: "<<person[i].name<<endl;
            cout<<"Account No: "<<person[i].AccNo<<endl;
            cout<<"Account Type: "<<person[i].AccType<<endl;
            cout<<"Contact: "<<person[i].contact<<endl;
            cout<<"Money to Deposit: "<<person[i].money<<endl;
            cout<<"\nEnter New Data"<<endl;
            cout<<"Enter Name: ";
            cout<<"Enter data of person"<<total+1<<endl;
            cout<<"Enter Name: ";
            cin>>person[total].name;
            cout<<"Enter AccNo: "<<endl;
            cin>>person[total].AccNo;
            cout<<"Enter Account Type: "<<endl;
            cin>>person[total].AccType;
            cout<<"Enter Contact No: "<<endl;
            cin>>total[person].contact;
            cout<<"Enter Money to Deposit: "<<endl;
            cin>>person[total].money;
            break;


        }
        if(i == total-1){
        cout<<"No such customers found"<<endl;
    }
    
    }
}

void Bank::search(){
     cout<<"Enter the customer id to search the data"<<endl;
     cin>>id;
     for(int i = 0; i<total; i++){
        if(id == person[i].AccNo){
            cout<<"Data of Person "<<i+1<<endl;
            cout<<"Name: "<<person[i].name<<endl;
            cout<<"Account No: "<<person[i].AccNo<<endl;
            cout<<"Account Type: "<<person[i].AccType<<endl;
            cout<<"Contact: "<<person[i].contact<<endl;
            cout<<"Money to Deposit: "<<person[i].money<<endl;
            break;


        }
        if(i == total-1){
        cout<<"No such customers found"<<endl;
     }
     
    }

}

void Bank::transactions(){
    
    char ch;
    int amount;
    cout<<"Enter the customer id to perform transaction"<<endl;
    cin>>id;
    for(int i = 0; i<total; i++){
        if(id == person[i].AccNo){
            cout<<"Name: "<<person[i].name<<endl;
            cout<<"Account Type: "<<person[i].AccType<<endl;
            cout<<"Contact: "<<person[i].contact<<endl;
            cout<<"\nExisting Money "<<person[i].money<<endl;
            cout<<"Press 1 to Deposit"<<endl;
            cout<<"Press 2 to withdraw"<<endl;
            ch = getch();

            switch(ch){
                
                case '1':
                cout<<"How much amount you want to deposit?"<<endl;
                cin>>amount;
                person[i].money += amount;
                cout<<"Your new total money is "<<person[i].money<<endl;
                break;

                case '2':
                back:
                cout<<"How much amount you want to withdraw?"<<endl;
                cin>>amount;
                if(amount>person[i].money){
                    cout<<"Your existing cash is just "<<person[i].money<<endl;
                    Sleep(3000);
                    goto back;
                }
                person[i].money -= amount;
                cout<<"Your new total money is "<<person[i].money<<endl;
                break;

                default:
                cout<<"Invalid input"<<endl;
                break;


            }
            break;
        }
        if(i==total-1){
            cout<<"No such record found"<<endl;
        }
    }


}

void Bank::del(){
    char ch;
    cout<<"Press 1 to remove specific record"<<endl;
    cout<<"Press 2 to remove full record"<<endl;
    ch = getch();
    switch(ch){
        case '1':
        for(int i = 0; i<total; i++){
            if(id == person[i].AccNo){
                for(int j = i; j<total; j++){
                    person[j].name = person[j+1].name;
                    person[j].AccNo = person[j+1].AccNo;
                    person[j].AccType = person[j+1].AccType;
                    person[j].contact = person[j+1].contact;
                    person[j].money = person[j+1].money;
                    total--;
                    break;

                }
                
            }
            if(i == total){
                cout<<"No such record found"<<endl;
            }
        }
        break;
        case '2':
        total = 0;
        cout<<"All record is deleted"<<endl;
        break;

        default:
        cout<<"Invalid input"<<endl;
        break;
    }
} 






int main(){

    Bank obj;
    obj.choice();
    return 0;
}