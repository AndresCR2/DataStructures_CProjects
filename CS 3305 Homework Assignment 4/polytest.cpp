//polytest.cpp

// required only in visual studio

#include "stdafx.h"

#include "targetver.h"

// declare the required header files

#include "polyO.h"

#include <iostream>// Provides ostream

using namespace std;

// define the name space main_savitch_3

using namespace main_savitch_3;

// declare the main function of the program

int main()

{

   //p1 and P2 polynomial eqution

   polynomial p1(5, 1);

   polynomial p2(5, 1);

   // p1 assigned coefecient

   p1.assign_coef(2, 0);

   //p2 assigned coefecient

   p2.assign_coef(2, 0);

   p2.add_to_coef(9.11, 2);

   p2.add_to_coef(-6.3, 4);

   p2.add_to_coef(-4, 15);

   // p1 add the coeffecient

   p1.add_to_coef(2.8, 1);

   p1.add_to_coef(-1.22, 2);

   p1.add_to_coef(3.3365, 4);

   // for loop

   for(int i = 0; i <=12; i++)

   {

          // P1 add the coefecient

       p1.add_to_coef(i/10., i);

   }

   // display the output of Antiderivative

   cout << p2 << std::endl;

   cout << "Anti_derivative" <<endl << p2.antiderivative() <<endl;

   // display the define Integral

   cout << "Integration_defination" <<endl << p2.definite_integral(0, 1) <<endl;

   // define the derivative

   cout << "Derivative_of Polynomial" <<endl << p2.derivative() <<endl;

// evaluvate the

   cout << "Evaluvation at 1: " << p2.eval(1) <<endl <<endl <<endl;

   cout << p2 <<endl;

   cout << p1 <<endl;

   // add both the polynomial

   cout <<endl << p1 + p2 <<endl;

   //difference between P1 and P2

   cout << p1 - p2 << endl;

   cout << p2 - p1 << endl;

   // P1 clear function call

   p1.clear();

   //p2 clear function call

   p2.clear();

   // loop to execute the

   for(int i = 0; i < 2; i++)

   {

          // assign the coefecient

       p1.assign_coef(1, i);

       p2.assign_coef(1, i);

   }

   //display the p1 and P2

   cout << p1 <<endl << p2 <<endl;

   // display the product of p1 and p2

   cout << p1 * p2 << endl;

   // call the polynomial object

   polynomial p;

   // loop

   for(int i = 0; i <=29; i++)

   {

          // assign the coefecient

       p.assign_coef(i%2==1 ? i / 1.2 : -i/17.0, i);

      // display the p

          cout << p <<endl;

   }

   // for hold the console screen

   system("pause");

}