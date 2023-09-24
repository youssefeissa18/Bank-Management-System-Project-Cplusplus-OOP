#include <bits/stdc++.h>

using namespace std;
class BankAccount{
private:
    string name;
    int accountNum;
    double balance;
public:
    BankAccount(){
        name = "";
        accountNum = 0;
        balance = 0;
    }
    BankAccount(string name, int accountNum, double balance){
        this->name = name;
        this->accountNum = accountNum;
        this->balance = balance;
    }
    string getName(){
        return name;
    }
    int getAccountNum(){
        return accountNum;
    }
    double getBalance(){
        return balance;
    }
    void deposit(double balance){
        this->balance += balance;
        cout<<"Deposit Successfully..."<<endl;
    }
    void withDraw(double balance){
        if (balance < this->balance)
        {
            this->balance -= balance;
            cout<<"Withdraw Successfully..."<<endl;            
        }
        else
        {
            cout << "Your Balance is not have enough money" << endl;
        }
    }



};

//  1. Create New Account   BA Done
//  2. Show All Account     BM
//  3. Search Account       Bm
//  4. Deposit Money        BA Done
//  5. Withdraw Money       BA Done
//  6. Balance Inquiry      BA Done
//  7. Exit
int main(){
    BankAccount B1("Youssef",12,4512);
    cout << B1.getBalance() << endl;
    cout << B1.getAccountNum() << endl;
    B1.deposit(1000);
    cout << B1.getBalance() << endl;
    B1.withDraw(10000);
    cout << B1.getBalance() << endl;
    cout << "Hello World" << endl;

    return 0;
}