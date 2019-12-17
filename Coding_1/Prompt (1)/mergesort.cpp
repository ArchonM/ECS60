// Merge Sort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "mergesort.h"

void MergeSort(std::vector<int>* numbers, int *num_Cmp, int *num_MemoAccess) {
   MergeSortRecurse(numbers, 0, numbers->size() - 1, num_Cmp, num_MemoAccess);
   return;
}


void MergeSortRecurse(std::vector<int>* numbers, int i, int k, int *num_Cmp, int *num_MemoAccess) {
   int j = 0;

   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition

      // Recursively sort left and right partitions
      MergeSortRecurse(numbers, i, j, num_Cmp, num_MemoAccess);
      MergeSortRecurse(numbers, j + 1, k, num_Cmp, num_MemoAccess);

      // Merge left and right partition in sorted order
      Merge(numbers, i, j, k, num_Cmp, num_MemoAccess);
   }
}

void Merge(std::vector<int>* numbers, int i, int j, int k, int *num_Cmp, int *num_MemoAccess) {
   int mergedSize = k - i + 1;                // Size of merged partition
   int mergePos = 0;                          // Position to insert merged number
   int leftPos = 0;                           // Position of elements in left partition
   int rightPos = 0;                          // Position of elements in right partition
   std::vector<int> mergedNumbers;
   mergedNumbers.resize(mergedSize);          // Dynamically allocates temporary array
                                              // for merged numbers

   leftPos = i;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position

   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {

      if ((*numbers)[leftPos] < (*numbers)[rightPos]) {
         *num_Cmp += 1;
         *num_MemoAccess += 2;
         mergedNumbers[mergePos] = (*numbers)[leftPos];
         *num_MemoAccess += 2;
         ++leftPos;
      }
      else {
         *num_Cmp += 1;
         *num_MemoAccess += 2;
         mergedNumbers[mergePos] = (*numbers)[rightPos];
         *num_MemoAccess += 2;
         ++rightPos;

      }
      ++mergePos;
   }

   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = (*numbers)[leftPos];
      *num_MemoAccess += 2;
      ++leftPos;
      ++mergePos;
   }

   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = (*numbers)[rightPos];
      *num_MemoAccess += 2;
      ++rightPos;
      ++mergePos;
   }

   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      (*numbers)[i + mergePos] = mergedNumbers[mergePos];
      *num_MemoAccess += 2;
   }
}
