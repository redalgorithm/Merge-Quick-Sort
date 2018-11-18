// testMergeSortList.cpp
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//
// Tests MergeSortList
//

// only one main program can exist at a time when running
// make sure to comment out when done testing

/*//-------------->>DELETE THIS LINE<<----------------
 
#include <iostream>
#include <iomanip>
#include <list>
#include "MergeSortList.h"
#include "IntLess.h"
using namespace std;

int main() {

  // test routine for merge sort using lists
  // with element type int
  // with comparator IntLess

  // create list
  int size, x;
  list<int> listS;
  list<int>::iterator iter; // iterator for list
  
  // create comparator
  IntLess intComp;
  
  // fill list
  srand(time(NULL));
  
  cout << "Enter number of values to sort:";
  cin >> size;
  
  for (int i = 0; i < size; i++) {
    x = rand() % 1000;  // three-digit values
    listS.push_back(x); // put at end of listS
  }
  
  // print original list contents
  cout << "\nOrig:\n______________\n";
  for (iter = listS.begin(); iter != listS.end(); ++iter) {
    cout << setw(4) << *iter;
  }
  cout << "\n_______________\n\n";
  
  // call the merge sort with a list
  mergeSortS(listS, intComp);
  
  // print sorted list contents
  cout << "\nSorted:\n______________\n";
  for (iter = listS.begin(); iter != listS.end(); ++iter) {
    cout << setw(4) << *iter;
  }
  cout << "\n_______________\n\n";
  

  return 0;
}
*///-------------->>DELETE THIS LINE<<----------------
