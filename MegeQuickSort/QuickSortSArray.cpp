// QuickSortArray.cpp
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//
// Specifies, implements, and tests a Quick Sort using an array
//

// only one main program can exist at a time when running
// make sure to comment out when done testing

/*//-------------->>DELETE THIS LINE<<----------------
 
#include <iostream>
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
class IntLess {
public:
  bool operator()(const int& x, const int& y) const {
    return x < y;
  }
};

 //----------------------------------------------
 // quickSortStep (function)
 //
 // • Uses recursion to step through
 //   and sort two halves of an array
 //   according to specified pivot
 //
 // Params: a templated array, ints specifying
 //         a particular segment of the array,
 //         a < comparator
 //
 // I/O: none
 // Return: void (nothing)
 //----------------------------------------------
template <typename E, typename C>
void quickSortStep(E S[], int a, int b, const C& less)
{
	// sorting S between indices a and b
	if (a >= b)
    {
	    return;
	}
	
	//E pivot = S[b];   // choose right-most element in range as pivot
	
	// choose a random element from within [a .. b]
	int randIndex = rand() % (b - a + 1) + a;
	E pivot = S[randIndex];        // choose random element in range as pivot
	std::swap(S[randIndex],S[b]);  // put it into S[b]

	E temp;
	
    int l = a;		// where should l start?
    int r = b-1;		// where should r start?
	
	
	while (l <= r)
    {
	   // scan left to right, til we find a larger value than pivot
        while(S[l]<=pivot && l<=r)
        {
            l++;
        }
	   
	   // scan right to left, til we find a smaller value than pivot
        while(S[r]>=pivot && r>=l)
        {
            r--;
        }

	   // swap if necessary	   
        if(l<r)
        {
            std::swap(S[l], S[r]);
        }
	   
	}  // until l and r cross
	
	// move the pivot into its correct position
 
 *///-------------->>DELETE THIS LINE<<----------------

 /////////////optional////////////////
	/*
	temp = S[b];
	S[b] = S[l];
	S[l] = temp;
	*/
//////////////////////////////////////

/*//-------------->>DELETE THIS LINE<<----------------
 
	std::swap(S[l], S[b]);  // pivot value is in it's final position
	
	// Recur
	
	quickSortStep(S, a, l-1, less);   // quick sort the values in the left part
	quickSortStep(S, l+1, b, less);   // quick sort the values in the right part
	
}

 //----------------------------------------------
 // quickSort (function)
 //
 // • Uses recursion via nested function to
 //   sort full array
 //
 // Params: a templated array, int specifying
 //         size of the array, a < comparator
 //
 // I/O: none
 // Return: void (nothing)
 //----------------------------------------------
template <typename E, typename C>
void quickSort(E S[], int size, const C& less)
{
    if (size <= 1) {
        return;
    }
    quickSortStep(S, 0, size-1, less);
}

 *///-------------->>DELETE THIS LINE<<----------------

 //================================================//
 
 // MAIN PROGRAM //
 
 //************************************************//

/*//-------------->>DELETE THIS LINE<<----------------
 
int main()
{
  
  int l[10];    // list in vector format with size 10
  IntLess less;   // comparator object
  int i;

  unsigned int seed;
  cout << "Enter a positive seed number: ";
  cin >> seed;
  srand(seed);   // initialize the random number generator

  for (i = 0; i < 10; i++) {
    l[i] = (rand()%100000);        // larger random numbers (0 .. 99999)
  }

  for (i = 0; i < 10; i++) {           // print out initial ordering
    cout << l[i] << " ";
  }

  cout << "\n quick ... sorting ...\n";
  quickSort(l, 10, less);                  // call the quickSort()

  
  for (i = 0; i < 10; i++) {           // print out sorted ordering
    cout << l[i] << " ";
  }


  cout << endl;

  return 0;
}
 
*///-------------->>DELETE THIS LINE<<----------------
