/*
 * LL.hpp
 *
 *  Created on: Sep 14, 2022
 *      Author: seong
 */

#ifndef LL_HPP_
#define LL_HPP_

#include <iostream>
#include "Student.hpp"
#include <string>

template <class T>
struct LLnode
{
      LLnode *fwdPtr;
      Student theData;
};

template <class T>
class LL
{
    private:
    LLnode<T> *header; //header node

    public:
    LL(); //constructor
    void push_front (T student);
    void push_back(T student);
    int  list_length();
    void display_list();
    Student retrieve_front();
    Student retrieve_back();
    void destroy_list();
    T search_list(int key);
    bool delete_node(int key);

    //new functions
    void push_backRecursive(LLnode<T> *lastNode, LLnode<T>*temp); //helper function
    int  list_lengthRecursive(LLnode<T> *temp, int countNode); //helper function
    void destory_listRecursive(LLnode<T> *current); //helper function
    bool delete_nodeRecursive(LLnode<T> *current, LLnode<T> *previous,int key); //helper function
    //void display_listRecursive(LLnode<T> *temp, int nodeCounter); //helper function
};
template <class T>
LL<T>::LL() //constructor
    {
         header = nullptr;                //when object created, header initialized with nullptr
    }

template <class T>
void LL<T>::push_front (T student)          //pass Student object by reference
   {
        LLnode<T> *newNode = new LLnode<T>;  //allocate memory for newNode
        newNode->theData = student;                //initialize theData from Student data
        newNode->fwdPtr  = header;           //In this case, llh is original node, original node should be placed after new node. after new node -> original node -> ... -> nullptr
        header = newNode;

    }

template <class T>
void LL<T>::push_back(T student)
{

	LLnode<T> *lastNode = new LLnode<T>;  //allocate memory for lastNode
	lastNode ->fwdPtr = nullptr;          //lastNode is going to be placed at the last of linked list, so it points null as fwdPtr
	lastNode ->theData = student;		  //add student key and data


	LLnode<T> *temp = new LLnode<T>;    //Don't wanna modify headerNode, so make new LLnode as temp
	temp = header;                      //temp points header
	if(temp == nullptr)
		{
			header = lastNode; //header points lastNode
	    	return;            //end function
		}

	push_backRecursive(lastNode, temp);
	return;
}
template <class T>
void LL<T>::push_backRecursive(LLnode<T> *lastNode, LLnode<T> *temp)
{

	if(temp->fwdPtr == nullptr) //base case, if next node of temp points nullptr(at the last of the list), end recursion
	{
		temp->fwdPtr = lastNode;        //In original head -> node1 -> node2-> ...-> tempNode ->nullptr
		                                //it became head->node1->node2->....->tempNode->lastNode->nullptr
		return;
	}
	//temp = temp->fwdPtr;    //temp points next pointer of tempNode
	 //temp = temp->fwdPtr
	//I can pass paramter temp->fwdPtr instead
	push_backRecursive(lastNode, temp->fwdPtr); //recursive call

}
template <class T>
int  LL<T>::list_length()
{
	//cout << "In list_length function header : " << header << endl;
	LLnode<T> *temp = header; //temp points to header
	int countNode = 0;        //counter variable, every loop it will increase by 1
	if(header == nullptr)
	{
		return 0;
	}

	return list_lengthRecursive(temp, countNode);

}
template <class T>
//helper function
int LL<T>::list_lengthRecursive(LLnode<T> *temp, int countNode) //parameter temp pointer moves to its fwdPtr every recursive calling
{
	//To debugg if the header position changed
	//cout << "Header : " << header << "\tTemp : " << temp << endl;
//	int countNode;
//	countNode = 0;
	if(temp == nullptr) //base case of recursion, it will recursive until temp is nullptr
	{
		return 0;
	}

    //Debugging Point
	countNode++;          //increase by 1 every recursive
	temp = temp->fwdPtr;  //move to next node
    //when base case returns 0, then return 1+0 -> 1+1 -> 1 + 2.... to list_length function
	return  1+list_lengthRecursive(temp, countNode);
}
template <class T>
void LL<T>::display_list()
{
	int nodeCounter = 0; //it likes index of the linked list
	if(header == nullptr) //when list is empty
	{
		cout << "The list is empty" << endl;
		return; //end function
	}
	LLnode<T> *temp = new LLnode<T>; //allocate memory for temp pointer
	temp = header;					 //temp points to header
	while(temp != nullptr)
	{
		cout << "node " << nodeCounter << " address-> " << temp << " data -> "
		<< temp->theData.data << " " << temp->theData.key << endl;
		temp = temp->fwdPtr;
		nodeCounter++;
	}

    return; // end Function
	//display_listRecursive(temp, nodeCounter); //call helper function
    //when helperfunction end, end function
}
//practice
//template <class T>
//void LL<T>::display_listRecursive(LLnode<T> *temp, int nodeCounter)
//{
//	if(temp == nullptr) //base case for recursive, temp access next node every recursion generates
//	{
//		return;
//	}
//	//it is recursion, so I don't need to use while loop(temp != nullptr) to traversal
//	cout << "node " << nodeCounter << " address -> " << temp <<
//		" data -> " << temp->theData.data << " " << temp->theData.key << endl;
//
//	temp = temp->fwdPtr; //access next node pointer
//	nodeCounter++;       //increase by 1 linked list index for printing
//	display_listRecursive(temp, nodeCounter); //recursive parameters are next node of temp and nodeIndex
//}
template <class T>
Student LL<T>::retrieve_front()
{

	if (header == nullptr)
	{
		throw ("linked list is empty"); //throw and end program
	}

	return header->theData;  //if linked list has node, return the first data of node list
}
template <class T>
Student LL<T>::retrieve_back()
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
	//LLnode<T>* previous = new LLnode<T>; //Allocate memory for current

	current = header;      // current points to header Node
	//previous = nullptr;
	if(header == nullptr)  //if list is empty
	{
		cout << "There is nothing to destroy list" << endl;
	}
	//int debuggCounter = 0;
	// iterate every node deleting memory allocated for each node
	destory_listRecursive(current);
	//header = nullptr;
}
template <class T>
void LL<T>::destory_listRecursive(LLnode<T> *current)
{
	LLnode<T>* previous = new LLnode<T>; //Allocate memory for current
	if(current == nullptr) //base case, it will reach when all node destoryed in the list
	{
		header = nullptr;    //since we destroy all node, header points to nullptr
		return;				 //end recursive call
	}

	previous = current;           // save pointer to current node before moving to the next node
	current = current->fwdPtr;    // move to the next node
	delete previous;             // delete the saved node
								// delete current;  will not delete the appropriate node, since current already moves to its fwdPtr
	destory_listRecursive(current); // call the function recursively
}
template <class T>
T LL<T>::search_list(int key)
{
	LLnode<T>* node = header;
	//Student object for return
	Student temp;
	temp.key = 0;
	temp.data = "";  // null string

	// iterate every node and check if there is any node whose key matches with the parameter key
	while (node != nullptr)
	{

		if (node->theData.key == key) // if there is exist match theData with Student key, return the data
		{
			//initialize temp with theData of node
			temp.key = node->theData.key;
			temp.data = node->theData.data;
			//debug point
			//cout << node->theData.key << " "<< endl;
			//cout << temp.key << " " << temp.data << endl;
			return temp;
		}
		node = node->fwdPtr; //node moves to fwdNode for every traversal
	}

	// if no match found, return an empty data
	//cout << node->theData.key << " "<< endl;
	return temp;
}
template <class T>
bool LL<T>::delete_nodeRecursive(LLnode<T> *current, LLnode<T> *previous, int key)
{
	LLnode<T>* next = new LLnode<T>; //allocate memory for next pointer
	next = nullptr;
	if(current == nullptr)      //base case, it means I traversal all node, but didn't find any match node
	{
		return false;
	}
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

			previous = current;        //for the next recursive, previous points current
			current = current->fwdPtr;  //current moves next node
			return delete_nodeRecursive(current, previous, key); //recursive call
}
template <class T>
bool LL<T>::delete_node(int key)
{
	//Allocate memory for current, previous pointers
	LLnode<T>* current = new LLnode<T>;
    current = header;
	LLnode<T>* previous =  new LLnode<T>;
	previous = nullptr;
   // int keyData = key;
	//if linked list empty, so there is nothing to search
	if(current == nullptr)
	{
		cout << "Linked list is empty" << endl;
		return false; //return false
	}

	return delete_nodeRecursive(current, previous, key);
	// iterate every node and check if there is any node whose key matches with the argument
//	while (current != nullptr) //traversal current that points header
//	{
//		next = current->fwdPtr; //next points to current's fwdPtr;
//
//			if (current->theData.key == key) // if there is any match to delete, delete the node from list and delete its memory
//		{
//			// to remove the node from list, alter the link of previous node from current node to next node
//			if (previous != nullptr)
//			{
//				previous->fwdPtr = next; //previous->current->next become previous->next(current gone)
//			}
//			else
//			{
//				header = next; // in case removing header node from list, just make the next node a new header
//			}
//			// delete memory of matched node and return true
//			delete current;
//			return true;
//		}
//
//		previous = current;
//		current = current->fwdPtr;
	}

	// if no match found, return false
	//return false;


#endif /* LL_HPP_ */

