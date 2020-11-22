// polyO.h

//pragma once define to execute this file first

#pragma once

// required only in Visual studio

#include "stdafx.h"

#include "targetver.h"

// define the header file

#ifndef POLYO_H

#define POLYO_H

#include <iostream> // Provides ostream

using namespace std;

// define the name space main_savitch_3

namespace main_savitch_3

{

       // define the class polynomial

    class polynomial

    {

        // function which is helpful to identify the degree

        void update_current_degree();

    public:

       // CONSTANTS

       static const unsigned int CAPACITY = 30;

        // CONSTRUCTOR

       polynomial(double c = 0.0, unsigned int exponent = 0);

       // MODIFICATION MEMBER FUNCTIONS

       void assign_coef(double coefficient, unsigned int exponent);

        void add_to_coef(double amount, unsigned int exponent);

       void clear( );

      // CONSTANT MEMBER FUNCTIONS

        polynomial antiderivative( ) const;

       double coefficient(unsigned int exponent) const;

        double definite_integral(double x0, double x1) const;

       unsigned int degree( ) const { return current_degree; }

       polynomial derivative( ) const;

       double eval(double x) const;

        bool is_zero( ) const;

       unsigned int next_term(unsigned int e) const;

       unsigned int previous_term(unsigned int e) const;

       // CONSTANT OPERATORS

       double operator( ) (double x) const { return eval(x); }

    private:

        double coef[CAPACITY+1];

        unsigned int current_degree;

              void compute_degree();

    };

    // NON-MEMBER BINARY OPERATORS

    polynomial operator +(const polynomial& p1, const polynomial& p2);

    polynomial operator -(const polynomial& p1, const polynomial& p2);

    polynomial operator *(const polynomial& p1, const polynomial& p2);

    // NON-MEMBER OUTPUT FUNCTIONS

    std::ostream& operator << (std::ostream& cout, const polynomial& p);

}

#endif