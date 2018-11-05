#include"ClassList.h"

List::List() :head(NULL), tail(NULL) {}
List::~List() {
	Node *delNode = head;
	while (delNode->prev != NULL) {
		head = delNode->prev;
		delete[] delNode;
		delNode = head;
	}
}

void List::addHead(int data) {
	Node *tempNode = new Node;
	tempNode->data = data;
	tempNode->prev = head;

	if (head != NULL){
		head->next = tempNode;
	}

	if (count == 0){
		head = tail = tempNode;
	}
	else {
		head = tempNode;
	}
	count++;
}

void List::addTail(int data) {
	Node *tempNode = new Node;
	tempNode->data = data;
	tempNode->next = tail;

	if (tail != NULL) {
		tail->prev = tempNode;
	}

	if (count == 0) {
		head = tail = tempNode;
	}
	else {
		tail = tempNode;
	}
	count++;
}

void List::ShowAll() {
	int c(0);
	Node *viewNode = head;
	while (viewNode != NULL) {
		c++;
		cout << "Elem " << c << " = " << viewNode->data << endl;
		viewNode = viewNode->prev;
	}
	cout << endl;
}

int List::getCountOfElem() {
	return this->count;
}

int List::findDataByElem(int elem) {
	Node *viewNode;
	if (elem < (this->count / 2)) {
		viewNode = head;
		for (int temp(1); temp != elem; temp++) {
			viewNode = viewNode->prev;
		}
	}
	else {
		viewNode = tail;
		for (int temp = count; temp != elem; temp--) {
			viewNode = viewNode->next;
		}
	}
	return viewNode->data;
}

int List::findElemByData(int data) {
	Node *viewNode = head;
	int elem(1);
	while (viewNode->data != data) {
		if (viewNode->prev == NULL) {
			cout << endl << "The List doesn't have this DATA!!!  ";
			return 0;
		}
		else {
			viewNode = viewNode->prev;
			elem++;
		}
	}
	return elem;
}

void List::deleteByDefiniteElem(int elem) {
	Node *delCurrendNode = head;
	for (int temp(1); temp != elem; temp++) {
		delCurrendNode = delCurrendNode->prev;
	}
	Node *tempNodeNext, *tempNodePrev;
	tempNodeNext = delCurrendNode->next;
	tempNodePrev = delCurrendNode->prev;
	delete[] delCurrendNode;

	if (tempNodeNext != NULL && tempNodePrev != NULL) {
		tempNodeNext->prev = tempNodePrev;
		tempNodePrev->next = tempNodeNext;
	}
	else if (tempNodePrev == NULL) {
		tail = tempNodeNext;
		tempNodeNext->prev = NULL;
	}
	else if (tempNodeNext == NULL) {
		head = tempNodePrev;
		tempNodePrev->next = NULL;
	}
}

void List::deleteByDefiniteData(int data) {
	Node *delCurrendNode = head;
	int elem(1);
	while (delCurrendNode->data != data) {
		if (delCurrendNode->prev == NULL) {
			cout << endl << "The List doesn't have this DATA!!!  ";
		}
		else {
			delCurrendNode = delCurrendNode->prev;
			elem++;
		}
	}
	Node *tempNodeNext, *tempNodePrev;
	tempNodeNext = delCurrendNode->next;
	tempNodePrev = delCurrendNode->prev;
	delete[] delCurrendNode;

	if (tempNodeNext != NULL && tempNodePrev != NULL) {
		tempNodeNext->prev = tempNodePrev;
		tempNodePrev->next = tempNodeNext;
	}
	else if (tempNodePrev == NULL) {
		tail = tempNodeNext;
		tempNodeNext->prev = NULL;
	}
	else if (tempNodeNext == NULL) {
		head = tempNodePrev;
		tempNodePrev->next = NULL;
	}
	cout << "Elem " << elem << " has been deleted by data - "<< data << endl << endl;
}