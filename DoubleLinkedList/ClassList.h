#pragma once
#include <iostream>

using namespace std;

class List {
private:
	struct Node {
		int data;
		Node *next = NULL;
		Node *prev = NULL;
	};
	Node *head;
	Node *tail;
	int count = 0;
public:
	List();
	~List();
	void addHead(int);
	void addTail(int);
	void ShowAll();
	int getCountOfElem();
	int findDataByElem(int);
	int findElemByData(int);
	void deleteByDefiniteElem(int);
	void deleteByDefiniteData(int);
};
