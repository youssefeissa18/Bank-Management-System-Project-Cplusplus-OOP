//  1. Create New Account 
//  2. Show All Account    
//  3. Search Account or Find Account      
//  4. Deposit Money       
//  5. Withdraw Money       
//  6. Balance Inquiry      
//  7. Exit

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

class BankManage{
private:
    vector<BankAccount> bankAccount;
public:
    BankManage(){}
    void addAccount(string name, int accountNum, double balance){
        bankAccount.push_back(BankAccount(name,accountNum,balance));
    }

    void showAllAccount(){
        cout << "The Accounts : " << endl;
        for (int i = 0; i < bankAccount.size(); i++)
        {
            cout << "\t\tName : " << bankAccount[i].getName() << "\t\tAccount Number : " << bankAccount[i].getAccountNum() << "\t\tBalance  : " << bankAccount[i].getBalance() << endl;
        }
    }
    void searchAccount(int accountNum){
        int flag = 0;
        for (int i = 0; i < bankAccount.size(); i++)
        {
            if (bankAccount[i].getAccountNum() == accountNum)
            {
                flag = 1;
                cout << "\t\tName : " << bankAccount[i].getName() << "\t\tAccount Number : " << bankAccount[i].getAccountNum() << "\t\tBalance  : " << bankAccount[i].getBalance() << endl;
            }
            
        }
        if (flag == 0)
        {
            cout << "Not Founded" << endl;
        }  
    }
    BankAccount* findAccount(int accountNum){
			for(int i = 0; i< bankAccount.size();i++){
				if(bankAccount[i].getAccountNum() == accountNum){
					return &bankAccount[i];
				}
			}
		}

};

char op;
int choice;
int main(){
    cout << "================================================Bank-Management-System-Project============================================" << endl;
    cout<<"Do You Want to Countinue or Exit [Y/N] ??";
    cin >> op;
    while (op == 'Y' || op == 'y')
    {
        cout << "1- Create New Account" << "\n2- Show All Account" << "\n3- Search Account"<< "\n4- Deposit Money" <<  "\n5- Withdraw Money"<< "\n6- Balance Inquiry"<< "\n7- Exit" << endl;
        cout << "Your Choice is";
        cin >> choice;
        switch (choice)
        {
        case 1:
            {
                string name;
                cout << "Enter Name : " ;
                getline(cin , name);
                int accountNum;
                cout << "\n Enter Account Number : ";
                cin >> accountNum;
                int balance;
                cout << "\n Enter Balance : ";
                cin >> balance;
                BankManage Bank;
                Bank.addAccount(name,accountNum,balance);
                cout << "Your Account Create Successfully" << endl;
            }
            break;
        case 2:
            {
                cout << "====================================================" << endl;
                BankManage Bank;
                Bank.showAllAccount();
                cout << "====================================================" << endl;
            }
            break;
        case 3:
            {
                cout << "====================================================" << endl;
                BankManage Bank;
                int accountNum;
                cout << "Enter Account Number You Want : ";
                cin >> accountNum;
                cout << endl; 
                Bank.searchAccount(accountNum);
                cout << "====================================================" << endl;
            }
            break;
        case 4:
            {
                cout << "====================================================" << endl;
                double amount;
                BankManage Bank1;
                int accountNum;
                cout << "Enter Account Number You Want : ";
                cin >> accountNum;
                cout << endl; 
                BankAccount *Bank = Bank1.findAccount(accountNum);
                if (Bank != NULL)
                {
                    cout << "Enter The Amount : ";
                    cin >> amount;
                    cout << endl; 
                    Bank->deposit(amount);
                    cout<< amount <<" Deposit Successfully ...."<<endl;
                }
                else
                {
                    cout << "Your Account not Found" << endl;
                }
                
                cout << "====================================================" << endl;
            }
            break;
        case 5:
            {
                cout << "====================================================" << endl;
                double amount;
                BankManage Bank1;
                int accountNum;
                cout << "Enter Account Number You Want : ";
                cin >> accountNum;
                cout << endl; 
                BankAccount *Bank = Bank1.findAccount(accountNum);
                if (Bank != NULL)
                {
                    cout << "Enter The Amount : ";
                    cin >> amount;
                    cout << endl; 
                    Bank->withDraw(amount);
                    cout<< amount <<" Withdraw Successfully ...."<<endl;
                }
                else
                {
                    cout << "Your Account not Found" << endl;
                }
                cout << "====================================================" << endl;
            }
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalide Choice try Again " << endl;
            break;
        }
        cout<<"Do You Want to Countinue or Exit [Y/N] ??";
    	cin>>op;
    }
    

    return 0;
}