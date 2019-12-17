// Insertion Sort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks
#include <ctime>
#include <iostream>
#include <cstdio>

#include "insertionsort.h"


void InsertionSort(std::vector<int>* numbers, int *num_Cmp, int *num_MemoAccess, unsigned long long *start, unsigned long long *end) {
    *start = clock();
    std::cout<<std::endl<<"start is:"<<*start<<std::endl;
   int i = 0;
   int j = 0;
   int temp = 0;  // Temporary variable for swap

   for (long long count = 0; count < 1000000000000000000; count++)
   {}
   for (i = 1; i < numbers->size(); ++i) {
      j = i;
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && (*numbers)[j] < (*numbers)[j - 1]) {
         *num_Cmp += 1;
         *num_MemoAccess+=2;
         // Swap numbers[j] and numbers[j - 1]
         temp = (*numbers)[j];
         (*numbers)[j] = (*numbers)[j - 1];
         (*numbers)[j - 1] = temp;
         *num_MemoAccess += 4;
         --j;
      }
      *num_Cmp += 1;
      *num_MemoAccess += 2;

   }
   *end = clock();
   std::cout<<std::endl<<"end is:"<<*end<<std::endl;
   return;
}
