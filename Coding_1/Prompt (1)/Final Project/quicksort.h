// Quicksort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include <vector>

void QuickSort(std::vector<int>* numbers, int *num_Cmp, int *num_MemoAccess);
void QuickSortRecurse(std::vector<int>* numbers, int i, int k, int *num_Cmp, int *num_MemoAccess);
int Partition(std::vector<int>* numbers, int i, int k, int *num_Cmp, int *num_MemoAccess);
