// Merge Sort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include <vector>

void MergeSort(std::vector<int>* numbers, int *num_Cmp, int *num_MemoAccess);
void MergeSortRecurse(std::vector<int>* numbers, int i, int k, int *num_Cmp, int *num_MemoAccess);
void Merge(std::vector<int>* numbers, int i, int j, int k, int *num_Cmp, int *num_MemoAccess);
