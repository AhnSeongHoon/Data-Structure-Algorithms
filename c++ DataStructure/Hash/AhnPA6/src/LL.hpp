/*
 * LL.hpp
 *
 *  Created on: Aug 31, 2022
 *      Author: Seonghoon
 */

#ifndef LL_HPP_
#define LL_HPP_

#include <iostream>
#include "Employee.hpp"
#include <string>


template <class T>
struct LLnode
{
      LLnode *fwdPtr;
      T theData;
};

template <class T>
class LL
{
    private:
    LLnode<T> *header; //header node

    public:
    LL(); //constructor
    void push_front (T employee);
    void push_back(T employee);
    int  list_length();
    void display_list();
    T retrieve_front();
    T retrieve_back();
    void    destroy_list();
    //T search_list(int key);
    bool delete_node(int key);
    //bool delete_node(string key);
    T search_list(string key);
};
template <class T>
LL<T>::LL()
    {
         header = nullptr;  //when object created, header initialized with nullptr
    }

template <class T>
void LL<T>::push_front(T employee) //pass Employee object by reference
{
        LLnode<T> *newNode = new LLnode<T>; //allocate memory for newNode
        newNode->theData = employee;        //initialize theData from Employee data
        newNode->fwdPtr  = header;          ////In this case, llh is original node, original node should be placed after new node. after new node -> original node -> ... -> nullptr
        header = newNode;

}
template <class T>
void LL<T>::push_back(T employee)
{

	LLnode<T> *lastNode = new LLnode<T>;  //allocate memory for lastNode
	lastNode ->fwdPtr = nullptr;          //lastNode is going to be placed at the last of linked list, so it points null as fwdPtr
	lastNode ->theData = employee;		  //add employee key and data


	LLnode<T> *temp = new LLnode<T>;    //Don't wanna modify headerNode, so make new LLnode as temp
	temp = header;                      //temp points header
    if(temp == nullptr)                 //if linked list is empty
    {
    	header = lastNode; //header points lastNode
    	return;            //end function
    }

	while(temp->fwdPtr != nullptr)   //traversal(linear search) until fwdPtr points nullptr
	{
		temp = temp->fwdPtr;         //last node's next pointer point tempNode

	}
	 //when tempNode->next access nullptr, it means newNode access at the position
	 //lastNode placed after newNode address

	temp->fwdPtr = lastNode;     //In original head -> node1 -> node2-> ...-> tempNode ->nullptr
                                 //it became head->node1->node2->....->tempNode->lastNode->nullptr
}

template <class T>
int  LL<T>::list_length()
{
 LLnode<T> *temp = header; //temp points to header
 int countNode = 0;        //counter variable, every loop it will increase by 1


  while(temp != nullptr)   //traverse(linear search) until nullptr
  {
    temp = temp->fwdPtr;   //move to next node
    countNode++;           //increase by 1 every iterate
  }


  return countNode;
}
template <class T>
void LL<T>::display_list() //modified
{

	LLnode<T> *temp= header; //temp points header node
	int nodeCounter= 0;     //it likes index of the linked list


	if (temp == nullptr) //when list empty
	{
//		cout << "The list is empty" << endl;
		return;
	}

	while (temp != nullptr) //traversal linked list
	{
//		cout << "node " << nodeCounter << " address -> " << temp <<
//			" data -> " << temp->theData.ID << " " << temp->theData.name << endl;
//        temp = temp->fwdPtr;
        cout <<  "      chain - employee " << temp->theData.ID << " name " <<  temp->theData.name << endl;
		temp = temp->fwdPtr; //access next node pointer
		nodeCounter++;
	}
}
template <class T>
T LL<T>::retrieve_front()
{

	if (header == nullptr)
		{
			throw ("linked list is empty"); //throw and end program
		}

		return header->theData;  //if linked list has node, return the first data of node list
}
template <class T>
T LL<T>::retrieve_back()
{
	if (header == nullptr) //if linked list is empty
	{

		throw ("linked list is empty"); //throw and end program
	}


	LLnode<T>* lastNode = header; // find the last node of header
	while (lastNode->fwdPtr != nullptr) //traversal list before nullptr
	{
		lastNode = lastNode->fwdPtr; //move node to its fwdNode
	}

	return lastNode->theData;      //when the condition node->fwdPtr = nullptr, return student data in the node
}
template <class T>
void LL<T>::destroy_list() {

	LLnode<T>* current = new LLnode<T>; //Allocate memory for current
	LLnode<T>* previous = new LLnode<T>; //Allocate memory for current

	current = header;      // current points to header Node
	previous = nullptr;
	if(header == nullptr)  //if list is empty
	{
		cout << "There is nothing to destroy list" << endl;
	}
	//int debuggCounter = 0;
	// iterate every node deleting memory allocated for each node
	while (current != nullptr)
	{
		//cout << debuggCounter << endl;
		//debuggCounter++;
		previous = current;				// save pointer to current node before moving to the next node
		current = current->fwdPtr;		// move to the next node
		delete previous;				// delete the saved node
										// delete current;  will not delete the appropriate node, since current already moves to its fwdPtr
	}

	header = nullptr;                  //since we destroy all node in the list, header points to node
}


//template <class T>
//T LL<T>::search_list(int key)
//{
//	LLnode<T>* node = header;
//	//Student object for return
//	Student temp;
//	temp.key = 0;
//	temp.data = "";  // null string
//
//	// iterate every node and check if there is any node whose key matches with the parameter key
//	while (node != nullptr)
//	{
//
//		if (node->theData.key == key) // if there is exist match theData with Student key, return the data
//		{
//			//initialize temp with theData of node
//			temp.key = node->theData.key;
//			temp.data = node->theData.data;
//			//debug point
//			//cout << node->theData.key << " "<< endl;
//			//cout << temp.key << " " << temp.data << endl;
//			return temp;
//		}
//		node = node->fwdPtr; //node moves to fwdNode for every traversal
//	}
//
//	// if no match found, return an empty data
//	//cout << node->theData.key << " "<< endl;
//	return temp;
//}
template <class T>
T LL<T>::search_list(string key)
{
	LLnode<T>* node = header;

	Employee temp; //create employee object
	//initialization with zero and null
	temp.ID = "0";
	temp.name = "";


	while (node != nullptr)
	{

		if (node->theData.ID == key) // if there is exist match theData with Student key
		{

			temp.ID = node->theData.ID;
			temp.name = node->theData.name;


			return temp;     // return the data
		}
		node = node->fwdPtr;
	}
	//if employee not found(if the object data still zero and null string)
//    if(temp.ID == "0" && temp.name == "")
//    {
//    	cout << "Employee not found " << endl;
//    }
	cout << "Employee not found " << endl;
	return temp;
}

template <class T>
bool LL<T>::delete_node(int key)
{
	//Allocate memory for current, previous, and next pointers
	LLnode<T>* current = new LLnode<T>;
    current = header;
	LLnode<T>* previous =  new LLnode<T>;
	previous = nullptr;
	LLnode<T>* next = new LLnode<T>;
    next = nullptr;
	//if linked list empty, so there is nothing to search
	if(current == nullptr)
	{
		cout << "Linked list is empty" << endl;
		return false; //return false
	}
	// iterate every node and check if there is any node whose key matches with the argument
	while (current != nullptr) //traversal current that points header
	{
		next = current->fwdPtr; //next points to current's fwdPtr;

			if (current->theData.key == key) // if there is any match to delete, delete the node from list and delete its memory
		{
			// to remove the node from list, alter the link of previous node from current node to next node
			if (previous != nullptr)
			{
				previous->fwdPtr = next; //previous->current->next become previous->next(current gone)
			}
			else
			{
				header = next; // in case removing header node from list, just make the next node a new header
			}
			// delete memory of matched node and return true
			delete current;
			return true;
		}

		previous = current;
		current = current->fwdPtr;
	}

	// if no match found, return false
	return false;
}
//template <class T>
//bool LL<T>::delete_node(string key)
//{
//
//	LLnode<T>* current = new LLnode<T>;
//    current = header;
//	LLnode<T>* previous =  new LLnode<T>;
//	previous = nullptr;
//	LLnode<T>* next = new LLnode<T>;
//    next = nullptr;
//
//	if(current == nullptr)
//	{
//		cout << "Linked list is empty" << endl;
//		return false;
//	}
//
//	while (current != nullptr)
//	{
//		next = current->fwdPtr;
//
//			if (current->theData.ID == key)
//		{
//
//			if (previous != nullptr)
//			{
//				previous->fwdPtr = next;
//			}
//			else
//			{
//				header = next;
//			}
//
//			delete current;
//			return true;
//		}
//
//		previous = current;
//		current = current->fwdPtr;
//	}
//
//
//	return false;
//}
//Hash entry struct for array entry
struct hashTableEntry
{
    Employee info;
    LL<Employee> llEmployee;
};

#endif /* LL_HPP_ */
