// testMergeSortArray.cpp
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//
// Tests MergeSortArray
//

// only one main program can exist at a time when running
// make sure to comment out when done testing

/*//-------------->>DELETE THIS LINE<<----------------
 
#include <iostream>
#include <iomanip>
#include "MergeSortArray.h"
using namespace std;

int main()
{

  // create array
  int size;
  int* array;
  int* extra;
  
  srand(time(NULL));
  
  cout << "Enter number of values to sort:";
  cin >> size;
  
  array = new int [size];
  extra = new int [size];
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 1000;  // three-digit values
    extra[i] = array[i];       // extra will contain a copy of the array
  }
  
  cout << "\nOrig:\n______________\n";
  for (int i = 0; i < size; i++) {
    cout << setw(4) << array[i];
  }
  cout << "\n_______________\n\n";
  
  mergeSortA(array, extra, 0, size-1);
  
  cout << "\nSorted:\n______________\n";
  for (int i = 0; i < size; i++) {
    cout << setw(4) << extra[i];
  }
  cout << "\n_______________\n\n";
  
  // deallocate arrays
  delete [] array;
  delete [] extra;
  
  return 0;
}
 
*///-------------->>DELETE THIS LINE<<----------------

