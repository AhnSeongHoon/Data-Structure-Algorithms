//============================================================================
// Name        : SeonghoonPA1.cpp
// Author      : Ahn SeongHoon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
  string studentName;
  int studentID;
};

class LLnode
{
public:

  LLnode *fwdPtr;
  Student theData;
};
void push_front (LLnode *&llh, Student s) //pass reference, but referece type is pointer, parameter for header is *&
{

  LLnode *newNode  = new LLnode;    //memory allocate for llnode struct
  newNode->theData = s;             //initialize theData from Student s
  newNode->fwdPtr  = llh;           //In this case, llh is original node, original node should be placed after new node. after new node -> original node -> ... -> nullptr
  llh = newNode;


}

void push_back(LLnode *&llh, Student s)
{
	LLnode *lastNode = llh;
	// find the last node
	while(lastNode != nullptr && lastNode ->fwdPtr != nullptr)
	{
		lastNode = lastNode -> fwdPtr;

	}
	// create a new node linked at the last node.
	// if there is no last node, the list is empty, make the new node current header
	LLnode *newNode = new LLnode;
	newNode->fwdPtr = nullptr;
	newNode->theData = s;

	if(lastNode != nullptr)
	{
		lastNode->fwdPtr = newNode; //last node's next pointer point newNode

	}
	else
	{
		llh = newNode; //if no exist node in list

	}

}
int list_length(LLnode *llh)
{
 LLnode *temp = llh;
 int countNode = 0;     //counter variable, every loop it will increase by 1


  while(temp != nullptr)
  {
    temp = temp->fwdPtr; //move to next node
    countNode++;
  }


  return countNode;
}


// displays the data items in each node, producing a report that resembles the following:
//	node 0 address -> 0x776dc0 data -> Willie Makeitt 123456789
//	node 1 address -> 0x776e10 data->Betty Wont 234567890
//	node 2 address -> 0x776e50 data->Mandy Lifeboats 345678901
// If the list is empty, display a message - do no throw an exception.
void display_nodes(LLnode *llh)
{

	LLnode *temp= llh;
	int nodeCounter= 0;

	//If the list is empty, display a message – do not throw an exception.
	if (temp == nullptr) {
		cout << "The list is empty" << endl;
		return;
	}

	while (temp != nullptr) {
		cout << "node " << nodeCounter << " address -> " << temp <<
			" data -> " << temp->theData.studentName << " " << temp->theData.studentID << endl;

		temp = temp->fwdPtr; //access next node pointer
		nodeCounter++;
	}
}

// retrieves the contents of the node at the front. Does not remove the node.
// If the list is empty, throws an exception.
Student retrieve_front(LLnode* llh)
{

	if (llh == nullptr) {
		throw ("linked list is empty");
	}

	return llh->theData;
}
Student retrieve_back(LLnode *llh)
{

	if (llh == nullptr) {

		throw ("linked list is empty");
	}

	// find the last node
	LLnode* lastNode = llh;
	while (lastNode != nullptr && lastNode->fwdPtr != nullptr) {
		lastNode = lastNode->fwdPtr;
	}

	return lastNode->theData;
}

// A user (aka main) defines and initializes linked list processing by defining
// a linked list header for each linked list, for example:
//	LLnode* theLLheader = nullptr;
// Use the main provided for your testing.

int main() {

	LLnode* theLLHeader1 = nullptr;
	Student temp;
	//Check throws well
	//retrieve_front(theLLHeader1); //checked
	//retrieve_back(theLLHeader1); //checked


	temp.studentName = "student1";
	temp.studentID = 11111;
	cout << "Main:  number of nodes in empty list " << list_length(theLLHeader1) << endl;
	cout << "Main:  contents of LL1 nodes" << endl;
	display_nodes(theLLHeader1);
	push_front(theLLHeader1, temp);

	//	push_front (theLLHeader2, {"Charlie",78901});	// not all compilers support this
	cout << "Main:  number of nodes in list after 1 push - " << list_length(theLLHeader1) << endl;
	cout << "Main:  contents of list after 1 push " << endl;
	display_nodes(theLLHeader1);
	temp.studentName = "student2";
	temp.studentID = 22222;
	push_back(theLLHeader1, temp);
	temp.studentName = "student3";
	temp.studentID = 33333;
	push_front(theLLHeader1, temp);
	temp.studentName = "student4";
	temp.studentID = 44444;
	push_back(theLLHeader1, temp);
	cout << "Main:  number of nodes after 4 pushes - " << list_length(theLLHeader1) << endl;
	cout << "Main:  contents of list after 4 pushes " << endl;
	display_nodes(theLLHeader1);
	temp = retrieve_front(theLLHeader1);
	cout << "Main:  retrieve front: " << temp.studentName << " " << temp.studentID << endl;
	temp = retrieve_back(theLLHeader1);
	cout << "Main:  retrieve back: " << temp.studentName << " " << temp.studentID << endl;
	cout << endl;
	LLnode* theLLHeader2 = nullptr;
	temp.studentName = "Adam";
	temp.studentID = 15555;
	push_front(theLLHeader2, temp);
	temp.studentName = "Betty";
	temp.studentID = 25555;
	push_front(theLLHeader2, temp);
	temp.studentName = "Charlie";
	temp.studentID = 35555;
	push_front(theLLHeader2, temp);
	temp.studentName = "Donna";
	temp.studentID = 45555;
	push_back(theLLHeader2, temp);
	temp.studentName = "Earnie";
	temp.studentID = 55555;
	push_back(theLLHeader2, temp);
	temp.studentName = "Felicity";
	temp.studentID = 65555;
	push_back(theLLHeader2, temp);
	cout << "Main:  contents of LL2 nodes" << endl;
	display_nodes(theLLHeader2);

	return 0;
}
