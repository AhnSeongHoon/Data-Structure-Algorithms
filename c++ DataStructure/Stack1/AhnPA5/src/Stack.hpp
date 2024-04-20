/*
 * Stack.hpp
 *
 *  Created on: 2022. 9. 22.
 *      Author: Ahn seonghoon
 */

#ifndef STACK_HPP_
#define STACK_HPP_
#include <iostream>
#include <list>

using namespace std;

class Stack
{
private:
    int arraySize;		//size of array by user input
    int topElement;		//indicate top position
    list <int*> LLlist; //linked list definition, it contains dynamic allocated stack array as a node

public:
    Stack(int size);
    Stack();
    void push(int key);
    bool top(int& i);
    bool pop();
    void destroy();

};

Stack::Stack() //default constructor
{
	//if user does not specify size of stack array, the size is going to be 16
    topElement = 0;
    arraySize = 16;
    int* stackArray = new int[arraySize]; //create dynamic allocate memory size with user input
    LLlist.push_front(stackArray);
}

Stack::Stack(int size) //constructor
{
    topElement = 0;
    arraySize = size;
    int* stackArray = new int[arraySize]; //create dynamic allocate memory size with user input
    LLlist.push_front(stackArray);
}

void Stack::push(int key)
{

    if (LLlist.empty())
    {
    	//As professor mentioned in class, we can't call constructor after we create object,
    	//So copy code for constructor
    	//if user call the pop function more than data in stack array, it will generate
        topElement = 0;
        int* stackArray = new int[arraySize];
        LLlist.push_front(stackArray);
    }
    if (topElement == arraySize)   // if the current array is full
    {
        // create a new array
        int* stackArray = new int[arraySize]; // dynamic allocated array with same size

        // add a pointer node for stack array in the linked list
        LLlist.push_back(stackArray);
        LLlist.back()[0] = key;   // move the data to index [0] in the new array
        topElement = 1; //I fill the one element, so topElement is 1
    }
    else //it means the current array has place for the element
    {

        LLlist.back()[topElement] = key; // add data to the array at position [topElement]
        topElement++; //increament topElement by 1
    }
}

bool Stack::pop()
{
    //if there are no arrays in the list, or if there is one array and it is empty
    if (LLlist.empty() || (LLlist.size() == 1 && topElement == 0)) //it means there is nothing to pop
    {  //return false
        return false;
    }
    else
    {
    	if (topElement == 1)  //if the array has only one used element(list exists)
        {

            if (LLlist.size() != 1) //and if there is one more array
            {
                // delete current array
                delete[] LLlist.back(); // 5(full)->1(top) delete back 5(full)->nothing
            }
            LLlist.pop_back(); //remove linked list  for array
            topElement = arraySize;// set topElement = array size
            return true;
        }
        else
        {
            // topElement--
            topElement--;
        }
        // return true
        return true;
    }

}

bool Stack::top(int& i)
{
    // if there are no arrays in the list, or if there is one array and it is empty
    if (LLlist.empty() || (LLlist.size() == 1 && topElement == 0))
    {
//    	cout << "There is nothing in top position, I will return -1 in case for garbage value " << endl;
//    	i  = -1;
    	return false;
    }

    else
    {
    	//cout << "The top is " << LLlist.back()[topElement-1];
    	i = LLlist.back()[topElement - 1]; //retrieve data for user(element topElement - 1), back() means the last element of array(top)
        //return true
        return true;
    }
}
/// basic iteration through an STL container using an STL iterator
//// think of the iterator as a pointer
// list<string>::iterator cantaloupe;
//// .begin returns a pointer to the first element
//// .end returns a pointer to an imaginary element which is
//// just past the last element
//// we iterate starting at .begin and ending when we're at that
//// imaginary element
// for (cantaloupe = l.begin(); cantaloupe != l.end(); cantaloupe++)
// {
//// defererence the iterator to get at the contents it points to
//  cout << "list element " << *cantaloupe << endl;
// }
// return;
void Stack::destroy()
{
//	int *tempArray = new int[arraySize];
//	tempArray = LLlist.back();
//int count = 0;
    while (!LLlist.empty())
    {
    	//cout << count << endl;
    	//cout << tempArray << endl;
    	//delete [] tempArray;
    	delete[] LLlist.back();
        LLlist.pop_back();   // remove linked list nodes
       //tempArray = LLlist.back();
        //count++;
    }

    topElement = 0; //after all node(stack array) destroyed, top position should be 0
}




#endif /* STACK_HPP_ */
