#include<iostream>
using namespace std;
class bank_accounthw
{
private:
double balance;
string owner;
public:
// Creating new Bank account.
bank_accounthw(string owner_name,double starting)
{
balance = starting;
owner = owner_name;
}
  
// Deposites money from bank account.
void deposite(double money)
{
balance = balance + money;
}
  
// Withdraws money from bank account.
void withdraw(double money)
{
balance = balance - money;
}
  
// Function to change the owner.
void change_owner(string new_owner)
{
owner = new_owner;
}
  
// Function to find current balance.
double find_balance()
{
return balance;
}
  
// Function to find current owner.
string find_owner()
{
return owner;
}
};
int main()
{
// Implementation of the class.
bank_accounthw acc("Andres",1000);
cout<<"Current Owner : "<<acc.find_owner()<<endl;
cout<<"Current Bank Balance : "<<acc.find_balance()<<endl;
  
// Deposite 500
acc.deposite(500);
  
// Withdraw 300
acc.withdraw(300);
  
// Change owner_name to David.
acc.change_owner("Roy");
  
cout<<"Current Owner : "<<acc.find_owner()<<endl;
cout<<"Current Bank Balance : "<<acc.find_balance()<<endl;
return 0;
}