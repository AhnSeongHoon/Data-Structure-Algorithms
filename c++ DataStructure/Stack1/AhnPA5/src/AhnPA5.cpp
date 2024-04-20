//============================================================================
// Name        : AhnPA5.cpp
// Author      : Ahn Seonghoon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Stack.hpp"
#include <string>
using namespace std;

int main() {

	Stack s(5);
	int i;
	bool b;
	cout << "main: start of part 1" << endl;
	s.push(11);
	b = s.top(i);
	cout << "main: top after one push ->" << i << endl;
	s.push(22);
	s.push(33);
	s.push(44);
	s.push(55);
	b = s.top(i);
	cout << "main: top after five pushes ->" << i << endl;
	b = s.pop();
	b = s.pop();
	b = s.top(i);
	cout << "main: top after two pops->" << i << endl;
	b = s.pop();
	b = s.pop();
	b = s.pop();
	b = s.top(i);
	if (b)
	{
		cout << "main: error, after five pushes and pops, top should have failed" << endl;
	}
	else
	{
		cout << "main: top correctly returned false after five pushes and pops" << endl;
	}
	cout << "main: attempting sixth pop" << endl;
	b = s.pop();
	if (b)
	{
		cout << "main: after sixth pop, stack non-empty when it should be empty";
	}
	else
	{
		cout << "main: after sixth pop, stack correctly empty" << endl;
	}

	cout << endl << "main: start of part 2" << endl;
	s.push(21);	// 1st element 1st array
	s.push(22);
	s.push(23);
	s.push(24);
	s.push(25);
	s.push(26);	// 1st element 2nd array
	s.push(27);
	s.push(28);
	s.push(29);
	s.push(30);
	s.push(31);	// 1st element 3rd array

	cout << "main: before loop " << endl;
	b = s.top(i);
	while (b)
	{
		cout << "main: element of stack retrieved via top " << i << endl;
		b=s.pop();
		b=s.top(i);
	}
	cout << "main: after while loop, should have seen elements 31 thru 21" << endl;
	s.push(21);	// 1st element 1st array
	s.push(22);
	s.push(23);
	s.push(24);
	s.push(25);
	s.push(26);	// 1st element 2nd array
	s.push(27);
	s.push(28);
	s.push(29);
	s.push(30);
	s.push(31);	// 1st element 3rd array
	cout << "main: before destroy"<< endl;
	s.destroy();
	b = s.top(i);
	if (b)
	{
		cout << "main: error, stack not empty after destroy"<< endl;
	}
	else
	{
		cout << "main: stack correctly empty after destroy"<< endl;
	}

	cout << endl << "main: start of part 3" << endl;
	s.push(41);
	b=s.top(i);
	cout << "main: new top of stack " << i << endl;
	s.destroy();
	cout << "main: ending" << endl;

	return 0;
}




