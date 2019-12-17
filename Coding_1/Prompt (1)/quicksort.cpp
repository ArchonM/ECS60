// Quicksort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "quicksort.h"


void QuickSort(std::vector<int>* numbers, int *num_Cmp, int *num_MemoAccess) {
   QuickSortRecurse(numbers, 0, numbers->size() - 1, num_Cmp, num_MemoAccess);
}

void QuickSortRecurse(std::vector<int>* numbers, int i, int k, int *num_Cmp, int *num_MemoAccess) {
   int j = 0;

   /* Base case: If there are 1 or zero elements to sort,
    partition is already sorted */
   if (i >= k) {
      return;
   }

   /* Partition the data within the array. Value j returned
    from partitioning is location of last element in low partition. */
   j = Partition(numbers, i, k, num_Cmp, num_MemoAccess);

   /* Recursively sort low partition (i to j) and
    high partition (j + 1 to k) */
   QuickSortRecurse(numbers, i, j, num_Cmp, num_MemoAccess);
   QuickSortRecurse(numbers, j + 1, k, num_Cmp, num_MemoAccess);

   return;
}

int Partition(std::vector<int>* numbers, int i, int k, int *num_Cmp, int *num_MemoAccess) {
   int l = 0;
   int h = 0;
   int midpoint = 0;
   int pivot = 0;
   int temp = 0;
   bool done = false;

   /* Pick middle element as pivot */
   midpoint = i + (k - i) / 2;
   pivot = (*numbers)[midpoint];
   *num_MemoAccess += 1;

   l = i;
   h = k;

   while (!done) {

      /* Increment l while numbers[l] < pivot */
      while ((*numbers)[l] < pivot) {
         *num_Cmp += 1;
         *num_MemoAccess += 1;

         ++l;
      }
      *num_Cmp += 1;
      *num_MemoAccess += 1;

      /* Decrement h while pivot < numbers[h] */
      while (pivot < (*numbers)[h]) {
          *num_Cmp += 1;
          *num_MemoAccess += 1;
         --h;
      }
      *num_Cmp += 1;
      *num_MemoAccess += 1;

      /* If there are zero or one elements remaining,
       all numbers are partitioned. Return h */
      if (l >= h) {
         done = true;
      }
      else {
         /* Swap numbers[l] and numbers[h],
          update l and h */
         temp = (*numbers)[l];
         (*numbers)[l] = (*numbers)[h];
         (*numbers)[h] = temp;
         *num_MemoAccess += 4;
         ++l;
         --h;
      }
   }

   return h;
}
