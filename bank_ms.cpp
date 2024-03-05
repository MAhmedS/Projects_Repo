#include <iostream>
using namespace std;

int choice = 0;
bool u_login=0;

class Bank{
private:
    string email[20];
    string pass[20];
    string uname[20];
    int next_ind = 0;
    int wallet = 0;
public:
    void home(){
        string options[] = {". New Account",". Login",". View Balance",". Exit",". Add Balance"};
        cout<<"---------AHMED BANK---------"<<endl;
        int i;
        for(i=0;i<5;i++){
            cout<<i+1<<options[i]<<endl;
        }
        cin>>choice;
    }
    void new_account(){
        cout<<"Enter New Email: "<<endl;
        cin>>email[next_ind];
        cout<<"Enter New Username: "<<endl;
        cin>>uname[next_ind];
        cout<<"Enter New Password: "<<endl;
        cin>>pass[next_ind];
        ++next_ind;
        cout<<"Your Record Are:"<<endl;
        int i;
        for(i=0;i<1;i++){
            cout<<"Email: "<<email[next_ind-1]<<endl;
            cout<<"Username: "<<uname[next_ind-1]<<endl;
            cout<<"Password: "<<pass[next_ind-1]<<endl;
        }
        this->home_return();
    }
    void home_return(){
        char home_choice;
        cout<<"Press h to go to Home-Page"<<endl;
        cin>>home_choice;
        if(home_choice=='h'){
            choice = 0;
            this->home();
        }
        else{
            cout<<"Invalid Choice"<<endl;
        }
    }
    void login(){
        string test_email;
        string test_uname;
        string test_pw;
        if(u_login==0){
            cout<<"Enter Email address"<<endl;
            cin>>test_email;
            cout<<"Enter Username"<<endl;
            cin>>test_uname;
            cout<<"Enter Password"<<endl;
            cin>>test_pw;
            int i;
            for(i=0;i<1;i++){
                if(email[i]==test_email and pass[i]==test_pw and uname[i]==test_uname){
                    cout<<"Logged in Successfully"<<endl;
                    u_login = 1;
                }
                else{
                    cout<<"Invalid Credentials"<<endl;
                    continue;
                }
            }
        }
        else{
            cout<<"Already Logged in"<<endl;
        }
        this -> home_return();
    }
    void view_balance(){
        if(u_login==1){
            cout<<"The Balance is: "<<wallet<<endl;
        }
        else{
            cout<<"You must login first"<<endl;
        }
    }
    void add_balance(){
        if(u_login!=1){
            cout<<"You must Login First"<<endl;
            this->home_return();
        }
        else{
            int amount = 0;
            cout<<"Your Initial Balance is: "<<wallet<<endl;
            cout<<"Enter Amount to be added: "<<endl;
            cin>>amount;
            wallet += amount;
            cout<<"Your current balance is: "<<wallet<<endl;

        }
    }
};

int main() {
    Bank AhmedBank;
    while (true) {
        AhmedBank.home();
        if(choice==1){
            AhmedBank.new_account();
        }
        else if(choice==2){
            AhmedBank.login();
        }
        else if(choice==3){
            AhmedBank.view_balance();
        }
        else if(choice==5){
            AhmedBank.add_balance();
        }
        else{
            cout<<"Thanks for using our app"<<endl;
            exit(0);
        }
    }
    return 0;
}
