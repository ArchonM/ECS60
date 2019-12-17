#include<iostream>
#include<stdlib.h>

using namespace std;

class Queue {
private:
	int count, maxsize;
	int* QueueData;
public:
	Queue();
	~Queue();
	void SetSize(int size);
	void insert(int key);
	void removeMax();
	void removeKey(int key);
	void change(int key1, int key2);
	void heapifyUp(int index);
	void heapifyDown(int index);
	void print(int operation);
	int getTop();
};