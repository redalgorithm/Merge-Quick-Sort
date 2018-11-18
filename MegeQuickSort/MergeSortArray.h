// MergeSortArray.h
//
// Created by Shaanan Curtis on 5/27/18.
// Copyright © 2018 SEC. All rights reserved.
//

#ifndef MERGESORTARRAY_H
#define MERGESORTARRAY_H
#include <iostream>
using namespace std;

//----------------------------------------------
// mergeA (function)
//
// • Merges two sorted halves of unsorted array
//
// Params: several ints representing
//         2 halves of an array
// I/O: outputs status of merge
//      lets user know what's
//      going on
// Return: void (nothing)
//----------------------------------------------
void mergeA(int* orig, int* final, int low1, int hi1, int low2, int hi2)
{
    // merge orig[low1 .. hi1] and orig[low2 .. hi2] into final[low1 .. hi2]
    cout << "in merge: (" << low1 << ", " << hi1 << ") and ("
  	   << low2 << ", " << hi2 << ")\n"; 

	// complete the rest of this function
    int i = low1;
    int j = low2;
    int k = low1;
    while(i<=hi1 && j<=hi2)
    {
        if(orig[i]<orig[j])
        {
            final[k++] = orig[i++];
        }
        else
        {
            final[k++] = orig[j++];
        }
    }
    while(i<=hi1)
    {
        final[k++] = orig[i++];
    }
    while(j<=hi2)
    {
        final[k++] = orig[j++];
    }
	  
}

//----------------------------------------------
// mergeSortA (function)
//
// • Recursively partitions array then merges
//   the divided array in sorted order
//
// Params: ints representing two arrays and specified half
// I/O: outputs status of mergesort
//      lets user know what's
//      going on
// Return: void (nothing)
//----------------------------------------------
void mergeSortA (int* orig, int* final, int low, int hi)
{
  // mergeSort the values in orig[low] .. orig[hi] into sorted order 
  cout << "in mergeSort: (" << low << ", " << hi << ")\n"; 
 
  int n = hi - low + 1;
  if (n <= 1)
  {
    // base case for recursion
     return;
  }
  
  // switchArrays so that at every next level down the recursive call
  //       tree, the merging will go into orig, then into final, then
  //       into orig, and so on.  In this way, we don't need to keep
  //       re-allocating sub-arrays and copying data.
  //------------------
    int* temp;
    temp = orig;
    orig = final;
    final = temp;
  
  int half = (low + hi) / 2; 
  
  // 1) mergeSort the first half from orig into final
  mergeSortA(orig, final, low, half);
    
  // 2) mergeSort the second half from orig into final
  mergeSortA(orig, final, half+1, hi);

  // 3) merge the two halves of final back into orig
  mergeA(final, orig, low, half, half+1, hi);
}

#endif
