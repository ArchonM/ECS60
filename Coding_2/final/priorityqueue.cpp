
#include<iostream>
#include<stdlib.h>
#include "priorityqueue.h"
#include "json.hpp"

using namespace std;

Queue::Queue() {
	count = 1;
	maxsize = 50;
	QueueData = new int[51];
}

Queue::~Queue() {
	delete[] QueueData;
	QueueData = NULL;
}

void Queue::SetSize(int size) {
	maxsize = size;
	QueueData = new int[size + 1];
}

void Queue::heapifyUp(int index){
	while ((int)(index / 2) > 0 && QueueData[index] > QueueData[(int)(index / 2)]) {
		int temp = QueueData[(int)(index / 2)];
		QueueData[(int)(index / 2)] = QueueData[index];
		QueueData[index] = temp;
		index = (int)(index / 2);
	}
}

void Queue::heapifyDown(int index) {
	if ((2 * index + 1) > count) {
		return;
	}
	else if ((2 * index + 1) == count) {
		if (QueueData[index] < QueueData[2 * index]) {
			int temp = QueueData[index * 2];
			QueueData[index * 2] = QueueData[index];
			QueueData[index] = temp;
			index = index * 2;
			return;
		}
	}
	else {
		if (QueueData[2 * index] > QueueData[2 * index + 1]) {
			//consider 2*index + 1
			if (QueueData[index] < QueueData[2 * index]){
				int temp = QueueData[index * 2];
				QueueData[index * 2] = QueueData[index];
				QueueData[index] = temp;
				index = index * 2;
				heapifyDown(index);
			}
		}
		else {
			if(QueueData[index] < QueueData[2 * index + 1]) {
				int temp = QueueData[index * 2 + 1];
				QueueData[index * 2 + 1] = QueueData[index];
				QueueData[index] = temp;
				index = index * 2 + 1;
				heapifyDown(index);
			}
		}
	}
}

void Queue::insert(int key) {
	if (count > maxsize) {
		cout << "PriorityQueue::insert called on full priority queue" << endl;
		exit(0);
	}
	QueueData[count] = key;
	heapifyUp(count);
	//cout << QueueData[count] << endl;
	count++;
}

void Queue::removeMax() {
	if (count == 1) {
		cout << "PriorityQueue::removeMax called on an empty priority queue" << endl;
		exit(0);
	}
	if (QueueData[1] == 3715) {
		print(1000);
	}
	//for (int i = 1; i < count; i++) {
	//	heapifyUp(i);
	//}
	QueueData[1] = QueueData[count - 1];
	count--;
	heapifyDown(1);
}

void Queue::removeKey(int key) {
	int i = 1;
	for (i = 1; i < count; i++) {
		if (QueueData[i] == key) {
			break;
		}
	}
	if (i == count) {
		cout << "PriorityQueue::removeKey key " << key << " not found" << endl;
		//exit(0);
	}
	else {
		QueueData[i] = QueueData[count - 1];
		count--;
		if (QueueData[i] > QueueData[int(i / 2)]) {
			heapifyUp(i);
		}
		else {
			heapifyDown(i);
		}
	}
}

void Queue::change(int key1, int key2) {
	int i = 1;
	for (i = 1; i < count; i++) {
		if (QueueData[i] == key1) {
			break;
		}
	}
	if (i == count) {
		cout << "PriorityQueue::change key "<< key1 <<" not found" << endl;
		//exit(0);
	}
	else {
		QueueData[i] = key2;
		if (QueueData[i] > QueueData[int(i / 2)]) {
			heapifyUp(i);
		}
		else {
			heapifyDown(i);
		}
	}
}

void Queue::print(int operation) {
	nlohmann::json Result;
	for (int i = 1; i < count; i++) {
		std::string str = std::to_string(i);
		Result[str]["key"] = QueueData[i];
		if ((2 * i) < count) {
			std::string left = std::to_string(2*i);
			Result[str]["leftChild"] = left;
		}
		if ((2 * i + 1) < count) {
			std::string right = std::to_string(2*i+1);
			Result[str]["rightChild"] = right;
		}
		if ((int)(i / 2) > 0) {
			std::string parent = std::to_string((int)(i/2));
			Result[str]["parent"] = parent;
		}
		//cout << QueueData[i] << " ";
	}
	Result["metadata"]["maxHeapSize"] = maxsize;
	Result["metadata"]["max_size"] = maxsize;
	Result["metadata"]["numOperations"] = operation;
	Result["metadata"]["size"] = count - 1;
	std::cout << Result.dump(2) << endl;
}

int Queue::getTop() {
	int result = QueueData[1];
	removeMax();
	return result;
}
