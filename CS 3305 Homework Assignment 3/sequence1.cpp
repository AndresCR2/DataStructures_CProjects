sequence1.cpp

include <iostream>

#include <cstdlib>

#include "sequence1.h"

using namespace std;

int main ( )

{

     sequence bag1;

     bag1.insert(1);

     bag1.insert(2);

     bag1.insert(3);

     bag1.insert(4);

     bag1.insert(5);

     bag1.start( );

     cout << bag1.current( ) << endl;

     system ("pause");

     return 0;

}

sequence_test.cpp

#include <iostream>

#include <cassert>

#include <cstdlib>

#include "sequence1.h"

using namespace std;

//const sequence::size_type sequence::CAPACITY;

sequence::sequence ( )

{

     current_index1 = 0;

     used1 = 0;

}

sequence::size_type sequence::size( ) const
{
     return used1;
}


void sequence::start ( )
{
     current_index1 = 0;
}


sequence::value_type sequence::current( ) const
{
      return data1[current_index1];
}

void sequence::advance ( )
{
     assert (is_item());

     current_index1++;
}


//CONSTANT MEMBER FUNCTIONS

bool sequence::is_item( ) const
{
     return current_index1 < used1;
}

// insert entry before the current item


void sequence::insert (const value_type& entry)

{
     assert( size( ) < CAPACITY);

     for (int i = used1; i > current_index1; i--)
     {

          data1[i] = data1[i-1];

          data1[current_index1] = entry;

          used1++;
     }   
}

    

// insert entry after the current item

void sequence::attach (const value_type& entry)

{
     assert( size( ) < CAPACITY);

     for (int i = used1; i > current_index1; i--)
     {

          data1[i] = data1[i+1];

          data1[current_index1] = entry;

          used1++;
     }   
}


void sequence::remove_current( )
{
     assert (is_item());

     for (int i = current_index1+1; i < used1-1; i++)

     {

          data1[i] = data1[i+1];

          used1--;
     }
}

ostream& operator <<(ostream& outs, const sequence& source)
{
     outs << source.current() << " ";

     return outs;
}

sequence1.h

#ifndef SEQUENCECE_1_H

#define SEQUENCECE_1_H

#include <cstdlib>       // Provides size_t

using namespace std;

class sequence

{

public:

     // TYPEDEFS and MEMBER CONSTANT

     typedef int value_type;

     typedef std::size_t size_type;

     static const size_type CAPACITY = 30;

    

     //CONSTRUCTOR

     sequence ( );

     //MODIFICATION MEMBER FUNCTIONS
     void start ( );

     void advance ( );

     // insert entry before the current item
     void insert (const value_type& entry);
     
     // insert entry after the current item
     void attach (const value_type& entry);

     void remove_current( );



     //CONSTANT MEMBER FUNCTIONS

     size_type size( ) const;

     bool is_item( ) const;

     value_type current( ) const;

private:

     value_type data1[CAPACITY];

     size_type used1;

     size_type current_index1;

};

//NONMEMBER FUNCTIONS for the point class

ostream& operator <<(ostream& outs, const sequence& source);

#endif