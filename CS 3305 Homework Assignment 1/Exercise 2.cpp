//Roy Andres Corrales Ramirez
//Exercise 2
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   int num,num1;
  
cout<<"Enter a number :";
cin>>num;

for(int i=num;num>=0;num-=2)
{
   num1=num;
for(int j=num1;num1>=0;num1-=2)
   {

       cout<<num1<<" ";
   }
   cout<<endl;
}
return 0;
}