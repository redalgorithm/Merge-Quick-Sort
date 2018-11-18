// MergeSortList.h
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//
/*
   Uses STL list<E> and pushes onto two empty lists, S1 and S2
   input is a list of E with comparitor C
   output is a sorted list of E
*/

#ifndef MERGESORTLIST_H
#define MERGESORTLIST_H
#include <list>
using namespace std;

//----------------------------------------------
// mergeS (function)
//
// • Merges two sorted halves of unsorted list
//
// Params: 3 lists and a comparator
// I/O: none
// Return: void (nothing)
//----------------------------------------------
template <typename E, typename C>			            // merge utility
  void mergeS(list<E>& S1, list<E>& S2, list<E>& S, const C& less)
{
  // assumes that S1 and S2 have n/2 elements in sorted order
  //         and that S is empty originally
  // expect that S will have n elements in sorted order
  //         and that S1 and S2 will be empty at the end
  
    typedef typename list<E>::iterator Itor;		    // sequence of elements
    
    Itor p1 = S1.begin();
    Itor p2 = S2.begin();
    
    while(!S1.empty() && !S2.empty())
    {
        // neither is empty
		// find which is smaller, append smaller to S
		//      update iterator of the smaller
        if(less(*p1, *p2))
        {
            S.push_back(*p1++);
            S1.pop_front();
        }
        else
        {
            S.push_back(*p2++);
            S2.pop_front();
        }

    }
    while(!S1.empty())
    {
        // copy rest of S1 to S
        S.push_back(*p1++);
        S1.pop_front();
    }
    while(!S2.empty())
    {
        // copy rest of S2 to S
        S.push_back(*p2++);
        S2.pop_front();
    }
  }
  
//----------------------------------------------
// mergeSortS (function)
//
// • Recursively partitions list then merges
//   the divided list in sorted order
//
// Params: list and < comparator
// I/O: none
// Return: void (nothing)
//----------------------------------------------
template <typename E, typename C>			        // merge-sort S
  void mergeSortS(list<E>& S, const C& less) {
  
    typedef typename list<E>::iterator Itor;		// sequence of elements
    
    int n = S.size();
    if (n <= 1) return;				            	// already sorted
    
    list<E> S1, S2;
    
    Itor p = S.begin();
    
    for (int i = 0; i < n/2; i++) 
        S1.push_back(*p++);                     	// copy first half to S1
        
    for (int i = n/2; i < n; i++) 
        S2.push_back(*p++);                     	// copy second half to S2
        
    S.clear();						                // clear S's contents
      
    mergeSortS(S1, less);			            	// recur on first half
    mergeSortS(S2, less);			            	// recur on second half
    mergeS(S1, S2, S, less);		        		// merge S1 and S2 into S
  }
  


#endif // MERGESORTLIST_H
