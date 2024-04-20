//============================================================================
// Name        : AhnPA4.cpp
// Author      : Ahn Seonghoon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "LL.hpp"
#include <string>
using namespace std;

int main() {

	LL <Student> ll1;
	cout << "main: length of empty list - " << ll1.list_length() << endl;
	ll1.display_list();

	Student temp;
	temp.data = "aaaaa";
	temp.key = 12345;
	ll1.push_front(temp);
	temp.data = "bbbbb";
	temp.key = 23456;
	ll1.push_back(temp);       //recursive pass
	temp.data = "before aaaaa";
	temp.key = 34567;
	ll1.push_front(temp);
	temp.data = "after bbbbb";
	temp.key = 45678;
	ll1.push_back(temp);
	cout << "main: length of list after 4 pushes - " << ll1.list_length() << endl; //recursive pass
	ll1.display_list();	//recursive practice pass
	cout << endl;

	temp = ll1.search_list (23456);
	if (temp.key != 0)
		cout << "main: node with key 23456 found" << endl;
	else
		cout << "main: node with key 23456 not found - that's an error" << endl;

	temp = ll1.search_list (23457);
	if (temp.key != 0)
		cout << "main: node with key 23457 found - that's an error" << endl;
	else
		cout << "main: node with key 23457 not found" << endl;

	bool b;
	cout << endl;
	b = ll1.delete_node (11111);				// delete case 4
	//cout << b << endl;				debugg
	if (b)
		cout << "main: node with key 11111 deleted - that's an error" << endl;
	else
		cout << "main: node with key 11111 not found, not deleted" << endl;

	cout << "main: length of list after delete - " << ll1.list_length() << endl;
	cout << "main: display of list after delete" << endl;
	ll1.display_list();
	cout << endl;

	b = ll1.delete_node (23456);				// delete case 3
	if (b)
		cout << "main: node with key 23456 deleted" << endl;
	else
		cout << "main: node with key 23456 not deleted - that's an error" << endl;

	cout << "main: length of list after delete - " << ll1.list_length() << endl;
	cout << "main: display of list after delete" << endl;
	ll1.display_list();
	cout << endl;

	b = ll1.delete_node (34567);				// delete case 2
	if (b)
		cout << "main: node with key 34567 deleted" << endl;
	else
		cout << "main: node with key 34567 not deleted - that's an error" << endl;

	cout << "main: length of list after delete - " << ll1.list_length() << endl;
	cout << "main: display of list after delete" << endl;
	ll1.display_list();
	cout << endl;

	ll1.destroy_list();		//pass recursive
	cout << "main: length of list after destroy - " << ll1.list_length() << endl;
	cout << "main: display of list after destroy" << endl;
	ll1.display_list();
	cout << endl;
	//check push_back works well after destroy all node in the list
//	Student temp5;
//	temp5.key = 1235124;
//	temp5.data = "Ahnn";
//	ll1.push_back(temp5);
//	ll1.display_list();

	return 0;
}
