//poly.cpp

//Required only for visual studio

#include "stdafx.h"

#include "targetver.h"

//define the required header file

#include <iomanip>

// access the header file polyO.h

#include "polyO.h"

#include <cassert>

#include <climits>

#include <cmath>

using namespace std;

// using the name sapce main_savitch_3

namespace main_savitch_3

{

       // create an object to access polynomial data

    polynomial::polynomial(double c, unsigned int exponent)

    {

              // clear function

        clear();

              // current _degree exponent

        current_degree = exponent;

              //define the coefecient function

        coef[exponent] = c;

     

    }

       // define the function polynomial

    void polynomial::update_current_degree()

    {

              // loop to compute the capacity

        for(int i = 0; i <= CAPACITY; i++)

        {

                     // check out the condition

            if(coef[i] != 0) current_degree = i;

        }

    }

       // polynomial function   to assign the coefecient

    void polynomial::assign_coef(double coefficient, unsigned int exponent)

    {

              // assert exponent capacity

        assert(exponent <= CAPACITY);

              // coefecient exponent

        coef[exponent] = coefficient;

              // update the _cureent degree function

        update_current_degree();

    }

       // function to add the coefecient

    void polynomial::add_to_coef(double amount, unsigned int exponent)

    {

              // assert the function

        assert(exponent <=CAPACITY);

        coef[exponent] += amount;

        update_current_degree();

    }

       // polynomial clear function

    void polynomial::clear()

    {

              // for loop to compute the coefecient

        for(int i = 0; i <= CAPACITY; i++){

            coef[i] = 0;

        }

              // again call update cureent degree function

        update_current_degree();

    }

       // polynomial function to find the anti derivative

    polynomial polynomial::antiderivative() const

    {

              // check out the capacity with assert

        assert(degree( ) < CAPACITY);

        polynomial anti;

     

              // loop

        for(int i = CAPACITY; i > 0; i--)

        {

                     // anti.assign_coef function

            anti.assign_coef(coef[i-1] / i, i);

        }

              // anti assign_coefecient

        anti.assign_coef(0, 0);

        return anti;

         }

       // polynomial coefecient function

    double polynomial::coefficient(unsigned int exponent) const

    {

              // check out the condition

        if(exponent > CAPACITY)

                     // return zero

                     return 0;

              // return coefecient

        return coef[exponent];

    }

       // polynomial function

    double polynomial::definite_integral(double x0, double x1) const

    {

              // polynomial antiderivative function

        polynomial anti= antiderivative();

        return anti.eval(x1) - anti.eval(x0);

    }

       // find out the polynomial derivative function

    polynomial polynomial::derivative() const

    {

              // polynomial derivative function

        polynomial deriv;

              // for loop to capacity

        for(int i = 0; i < CAPACITY; i++)

        {

                     // drive to assign the coeffecient

            deriv.assign_coef(coef[i+1] * (i + 1), i);

        }

              // return the derive

        return deriv;

     

    }

       // double the polynomial

    double polynomial::eval(double x) const

    {

              // declare the sum is equal to zero

        int sum = 0;

              //loop to capacity

        for(int i = 0; i <= CAPACITY; i++)

        {

                     // sum function

            sum += coef[i] * std::pow(x, i);

        }

              // return the sum

        return sum;

    }

    // polynomial zero

    bool polynomial::is_zero() const

    {

              // loop

        for(int i = 0; i <= CAPACITY; i++)

        {

                     // coefecient

            if (coef[i] != 0) return false;

        }

        return true;

    }

       // polynomial function

    unsigned int polynomial::next_term(unsigned int e) const

    {

              // for loop

        for (unsigned int i = e+1; i <= CAPACITY; i++)

        {

            if(coef[i] != 0) return i;

        }

              // return the zero

        return 0;

    }

// find out the previous term

    unsigned int polynomial::previous_term(unsigned int e) const

    {

              // loop

        for(int i = e-1; i >=0; i--)

        {// check out the condition

            if(coef[i] != 0) return i;

        }

              // return the UINT_MAX

        return UINT_MAX;

    }

       // polynomial plus opertor

    polynomial operator+ (const polynomial &p1, const polynomial &p2)

    {

              //polynomial sum

        polynomial sum;

              // loop

        for (int i = 0; i <= polynomial::CAPACITY; i++)

        {

                     // add the coefecient of P1 and P2

            sum.add_to_coef(p1.coefficient(i), i);

            sum.add_to_coef(p2.coefficient(i), i);

        }

              // return the sum

        return sum;

    }

       // the minus opertor function

    polynomial operator- (const polynomial &p1, const polynomial &p2)

    {

              // the difference

        polynomial dif;

              // loop to

        for (int i = 0; i <= polynomial::CAPACITY; i++)

        {

                     // difference between the P1 and P2

            dif.add_to_coef(p1.coefficient(i), i);

            dif.add_to_coef(-p2.coefficient(i), i);

        }

              // return the difference

        return dif;

    }

       // the multiplication opertor

    polynomial operator* (const polynomial &p1, const polynomial &p2)

    {

              // assert the function P1 and p2 degree coefecient

        assert(p1.degree() + p2.degree() <= polynomial::CAPACITY);

        polynomial product;

     

              // loop to execute the function P1

        for(int i = 0; i <= p1.degree(); i++)

        {

                     // loop for P2

            for(int j = 0; j <= p2.degree(); j++)

            {

                           // find out the multpliction

                product.add_to_coef(p1.coefficient(i) * p2.coefficient(j), i+j);

            }

        }

              // return the multiplication product

        return product;

    }

       // ostream opreator

    ostream& operator<< (ostream& cout, const polynomial &p)

    {

              // initliaze the counter

        int count = 0;

              // some variable declared

        unsigned int i = p.previous_term(polynomial::CAPACITY+1);

   ios_base::fmtflags flags = cout.flags();        

  

   // precesion the polynomial

   int prec = cout.precision();

   cout<<setiosflags(ios::fixed);

   cout.precision(1);

   // when p is zero

   if(p.is_zero())

   {

          // display the zero

      cout << "0";

       return cout;

   }

   //when i is greater than 1

   if(i > 1)

   {

          // increment the counter

       ++count;

     

          // display the coefecient

           cout << p.coefficient(i) << "x^" << i;

        }

   // store into i the previous term

   i = p.previous_term(i);

   // the while loop check to the condition

   while (i != UINT_MAX && i > 1)

        {

              // increment the counter

       ++count;

          // coefecient is greater than zero

            if(p.coefficient(i) > 0)

            {

                           // display the plus opertor

                cout << " + ";

            }

                     //otherwise

            else

            {

                           // display the - opertore

                cout << " - ";

            }

                     // display the polynomial equation

            cout <<abs(p.coefficient(i)) << "x^" << i;

            i = p.previous_term(i);

        }

     

        //when i is equal to one

        if(i == 1)

        {

       // increment the counter

       ++count;

          // coefecient function

       if(p.coefficient(i) > 0)

               {

                              // display the cout

                     cout << " + ";

               }

                   // else cout the -

               else

               {

                     cout << " - ";

               }

        // display the equation

         cout <<abs(p.coefficient(i)) << "x";

   i = p.previous_term(i);

         

   }

              // when i is equal to zero

        if(i == 0)

        {

       // count is not equal to zero

       if(count != 0)

       {

                 // when p coefecient is greater than zero

                   if(p.coefficient(i) > 0)

                   {

                                     //display the plus

                    cout << " + ";

                   }

                   else

                   {

                                     // otherwise display the minu

                      cout << " - ";

                   }

       }

          // display the equation

               cout <<abs(p.coefficient(i));

        }

              // display the precison

   cout.precision(prec);

   cout <<resetiosflags(flags);

   // return the cout

        return cout;

     

    }

}