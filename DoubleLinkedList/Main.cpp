#include"ClassList.h"

int main() {
	List myList;

	myList.addHead(150);//7
	myList.addHead(486);//6
	myList.addHead(7953);//5
	myList.addHead(134);//4
	myList.addHead(145);//3
	myList.addHead(1747);//2
	myList.addHead(1123);//1
	myList.addTail(5523);//8
	myList.addTail(553);//9
	myList.addTail(576);//10
	myList.addTail(214);//11
	myList.addTail(145);//12
	myList.addTail(12342);//13

	myList.ShowAll();
	cout << endl << "Data - " << myList.findDataByElem(3) << endl;
	cout <<"Elem - "<< myList.findElemByData(214) << endl;
	cout <<"Elem - "<< myList.findElemByData(45637) << endl << endl;

	myList.deleteByDefiniteElem(13);
	myList.ShowAll();
	myList.deleteByDefiniteElem(1);
	myList.ShowAll();
	myList.deleteByDefiniteElem(4);
	myList.ShowAll();
	myList.deleteByDefiniteData(553);
	myList.ShowAll();

	system("pause");

	return 0;
}