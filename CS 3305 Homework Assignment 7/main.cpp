/// g++ -g -Wall -o deque main.cpp
#include "deque.h"

using namespace main_savitch_6B;
using namespace std;

int main(int argc, char** argv)
{
   deque<int> d1;
   assert(d1.size() == 0);
   assert(d1.empty());
   d1.push_front(0);
   assert(d1.size() == 1);
   assert(!d1.empty());
   d1.push_back(1);
   assert(d1.front() == 0);
   assert(d1.back() == 1);
   deque<int> d2;
   d2.push_back(1);
   d2.push_front(0);
   assert(d1==d2);
  
   cout << "d1: " << d1 << endl;
   cout << "d2: " << d2 << endl;
  
   d1.push_front(0);
   d1.push_back(1);
   d1.push_front(2);
   d1.push_back(3);
   d1.push_front(4);
   d1.push_back(5);
   d1.push_front(6);
   d1.push_back(7);
   d1.push_front(8);
  
   cout << "d1: " << d1 << endl;
  
   d1.pop_back();
   d1.pop_back();
   d1.pop_back();
   d1.pop_back();
   d1.pop_front();
   d1.pop_front();
   d1.pop_front();
   d1.pop_front();
   d1.pop_front();
  
   cout << "d1: " << d1 << endl;
  
   d2.push_back(1);
   d2.push_back(2);
   d2.push_back(3);
   d2.push_back(5);
   d2.push_back(8);
   d2.push_back(13);
   d2.push_back(21);
   d2.push_back(34);
   d2.push_back(55);
   d2.push_back(89);
   d2.push_back(144);
   d2.push_back(233);
  
   cout << "d2: " << d2 << endl;
  
   for (int i = 0; i < 12; i++)
   {
       int pre1 = d1.back();
       d1.pop_back();
       int pre2 = d1.back();
       d1.push_back(pre1);
       d1.push_back(pre1+pre2);
   }
  
   cout << "d1: " << d1 << endl;
   assert(d1==d2);
   cout << "Everything Works!" << endl;
  
   return 0;
}