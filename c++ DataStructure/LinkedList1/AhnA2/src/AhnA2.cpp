//============================================================================
// Name        : AhnA2.cpp
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
	//Step2 pass
	LL <Student> ll1;
	cout << "main: length of empty list - " << ll1.list_length() << endl;
	ll1.display_list();
	Student temp;
	temp.data = "aaaaa";
	temp.key = 12345;
	ll1.push_front(temp);
	temp.data = "bbbbb";
	temp.key = 23456;
	ll1.push_back(temp);
	temp.data = "before aaaaa";
	temp.key = 34567;
	ll1.push_front(temp);
	temp.data = "after bbbbb";
	temp.key = 45678;
	ll1.push_back(temp);

	cout << "main: length of list after 4 pushes - " << ll1.list_length() << endl;
	ll1.display_list();
	cout << endl;
//	//check destroy function
 //   ll1.destroy_list(); //destroy work!
 //   ll1.display_list();
//  ll1.destroy_list(); //pass all condition for destroy
//
    temp = ll1.search_list (23456);
    //debug point
    //cout << temp.key << endl;
       if (temp.key != 0)
    		cout << "main: node with key 23456 found" << endl;
    	else
    		cout << "main: node with key 23456 not found - that's an error" << endl;

       temp = ll1.search_list (23457);
       	if (temp.key != 0)
       		cout << "main: node with key 23457 found - that's an error" << endl;
       	else
       		cout << "main: node with key 23457 not found" << endl;
       	//pass search_list all case

       	bool b;
       		b = ll1.delete_node (23456);
       		//cout << "delete_node function ended" << endl;
       		if (b)
       			cout << "main: node with key 23456 deleted" << endl;
       		else
       			cout << "main: node with key 23456 not deleted - that's an error" << endl;

       		cout << "main: length of list after delete - " << ll1.list_length() << endl;
       		cout << "main: display of list after delete" << endl;
       		ll1.display_list();

       		ll1.destroy_list();
       		cout << "main: length of list after destroy - " << ll1.list_length() << endl;
       		cout << "main: display of list after destroy" << endl;
       		ll1.display_list();
       		cout << endl;
       		//To check after Destroy, when header is nullptr push_back function works well
//       	Student temp2;
//       	temp2.key = 1444;
//       	temp2.data = "alalalfoelfl";
//       	ll1.push_back(temp2);
//       	temp2.key = 55555;
//       	temp2.data = "alalalfoelfl222";
//       	ll1.push_back(temp2);
//       	ll1.display_list();


       		return 0;
       	}

