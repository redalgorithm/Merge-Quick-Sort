// QuickSortSequence.cpp
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//
// Test program for the quickSort implementation using sequences
// using stl::list as sequence since main functions are present
//
// only one main program can exist at a time when running
// make sure to comment out when done testing

/*//-------------->>DELETE THIS LINE<<----------------
 
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>        
using namespace std;

//-----------------------------------------------------------
// IntLess (class)
//
//  comparator class (<)
//
// Private members: no
// Protected members: no
// Public members: yes
// Constructors: no
//-----------------------------------------------------------
class IntLess
{
public:
  bool operator()(const int& x, const int& y) const
    {
        return x < y;
    }
};

//----------------------------------------------
// quickSortSeq (function)
//
// • Uses recursion to partition original sequence
//   and sort according to specified pivot
//
// Params: a templated list & < comparator
//         passed by reference
// I/O: none
// Return: void (nothing)
//----------------------------------------------
template <typename E, typename C>
void quickSortSeq(std::list<E>& S, const C& less)
{
    // base case
    int numElem = S.size();
	if (numElem <= 1)
    {
	    return;
	}
	
	//E pivot = S.back();   // choose last element as pivot
	
	// choose a random index from within the list  // could be O(n)
	int randIndex = rand() % numElem;
    // find the pivot value at index randIndex
    typename std::list<E>::iterator iter;
    iter = S.begin();
    for (int k = 0; k < randIndex; k++) {
        ++iter;
    }
    E pivot = *iter;

    // based upon pivot, partition into three lists:  Lesser, Equal, Greater
    std::list<E> Lesser;
    std::list<E> Equal;
    std::list<E> Greater;
    

    while (!S.empty())
    {
            // get next element and remove from S
            if(S.front()<pivot)
            {
                Lesser.push_back(S.front());
                S.pop_front();
            }
            else if(S.front()>pivot)
            {
                Greater.push_back(S.front());
                S.pop_front();
            }
            else
            {
                Equal.push_back(S.front());
                S.pop_front();
            }
        
        	  // add it to Lesser if appropriate
        
              // add it to Greater if appropriate
       
              // add it to Equal if apprproate
        
    }
    // S should now be empty
    	
	quickSortSeq(Lesser, less);    // quick sort the values in the Lesser list
	quickSortSeq(Greater, less);   // quick sort the values in the Greater list
	
	// Conquer -- reassemble back into S
	
	
    while (!Lesser.empty()) {
        S.push_back(Lesser.front());
        Lesser.pop_front();
    }
    while (!Equal.empty()) {
        S.push_back(Equal.front());
        Equal.pop_front();
    }
    while (!Greater.empty()) {
        S.push_back(Greater.front());
        Greater.pop_front();
    }
	    
	
}

*///-------------->>DELETE THIS LINE<<----------------

//=========================================//

// MAIN PROGRAM //

//*****************************************//

/*//-------------->>DELETE THIS LINE<<----------------
 
int main()
{
  
  list<int> l;                                           // list in vector format with size 10
  IntLess less;                                          // comparator object
  int i;

  unsigned int seed;
  cout << "Enter a positive seed number: ";
  cin >> seed;
  srand(seed);                                           // initialize the random number generator

  for (i = 0; i < 10; i++) {
    l.push_back(rand()%100000);                          // larger random numbers (0 .. 99999)
  }

  std::list<int>::iterator iter;
  
  for (iter = l.begin(); iter != l.end(); ++iter) {     // print out initial ordering
    cout << *iter << " ";
  }

  cout << "\n quick ... sorting ...\n";
  quickSortSeq(l, less);                                // call the quickSortSeq()

  
  for (iter = l.begin(); iter != l.end(); ++iter) {     // print out sorted ordering
    cout << *iter << " ";
  }


  cout << endl;

  return 0;
}

*///-------------->>DELETE THIS LINE<<----------------

