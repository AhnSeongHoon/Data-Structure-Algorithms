/*
 * BSTree.hpp
 *
 *  Created on: Nov 1, 2022
 *      Author: Ahn SeongHoon
 */

#ifndef BSTREE_HPP_
#define BSTREE_HPP_


#include <iostream>
#include <cmath>
using namespace std;

template <class T>
struct Tnode
{
	T nodeValue;
	Tnode <T> *Lchild;
	Tnode <T> *Rchild;
	T balance;
};

template <class T>
class BSTree
{
	public:
     //all public member function required from PA7, height function is going to be used for printRohit
	 void insert (T & input); //replaced
	 bool search (T & input); //replaced
     void printRohit ();      //replaced
     void printRohitWithBF();
     int height();
     void inOrderTraversal();
     void preOrderTraversal();
     void postOrderTraversal();
     void udelete(T input);

     //new function for PA8
     void insertR(T input); //Replace insert function into recursive
     bool searchR(T input); //Replace search function into recursive
     void setallBF();
     int getLargestBF();
	private:
     //all private memeber function required from PA7
	Tnode <T>*tRoot = nullptr;

	void printRohitLevel(Tnode<T>* node, int x, int level, int height, string& print, const int WIDTH);
	//void printRohitWithBFLevel(Tnode<T>* node, int x, int level, int height, string& print, const int WIDTH);
	int  heightInternal(Tnode<T>* tRoot);
	void udeleteInternal (Tnode<T> * &);
	void inOrderTraversalInternal(Tnode  <T>*);
	void preOrderTraversalInternal(Tnode <T>*);
	void postOrderTraversalInternal(Tnode <T>*);

	//new functions for PA8
	Tnode<T> *insertRInternal(Tnode<T>*, T);
	bool searchRInternal(Tnode<T>*, T);
	void setallBFInternal(Tnode <T>*);
	int  getLargestBFInternal(Tnode <T>*);
	void printRohitWithBFLevel(Tnode<T>* node, int x, int level, int height, string& print, const int WIDTH);
};
template <class T>
void BSTree<T>::insertR(T input)
{
	if(tRoot == nullptr)   //if the tree is empty, the root node become newNode
	{

		       Tnode<T> *newNode = new Tnode<T>; //Allocate memory for newNode
				//input value can't not have child node until user call insert function
				newNode->nodeValue = input; //assign node value in the newNode
				newNode->Lchild = nullptr;
				newNode->Rchild = nullptr;
				tRoot = newNode;            //tRoot points newNode
				return;
	}
	else
	{
		tRoot = insertRInternal(tRoot, input);  //If tree is not empty, call recursive insert function
	}



}
template <class T>
Tnode<T>* BSTree<T>::insertRInternal(Tnode <T>*current, T input)
{
	if(current->nodeValue > input)           //new node is going to be left child
	{
		if(current->Lchild == nullptr)       //When find place for new Node
		{
			Tnode <T>*newNode = new Tnode<T>;	//allocate memory for new node
			current->Lchild = newNode;          //current's left child is new Node
			newNode->nodeValue = input;         //assign node value in newNode
			//since it is new node, it has no child until other new node inserted
			newNode->Lchild = nullptr;
			newNode->Rchild = nullptr;

		}
		else
		{
			current->Lchild = insertRInternal(current->Lchild, input); // since current's node value is larger, go to left subtree of current
		}
	}
	else if(current->nodeValue < input)   //new node is going to be right child
	{
		if(current->Rchild == nullptr)  //when find place for new Node
		{
			Tnode <T>*newNode = new Tnode<T>; //allocate memory for new node
			current->Rchild = newNode;        //current's right child new node
			newNode->nodeValue = input;       //assign input value into new node
			//since it is new node, it has no child until other new node inserted
			newNode->Lchild = nullptr;
			newNode->Rchild = nullptr;
		}
		else
		{
			current->Rchild = insertRInternal(current->Rchild, input); //recursive call sending current's right child
		}
	}
	else
	{
		//when input value already exist in the BSTree
		cout << "The BSTree can not have duplicated value " << endl;


	}

	return current;   //return pointer
}
template <class T>
void BSTree<T>::setallBF()
{
	setallBFInternal(tRoot);   //call internal recursive function
}
template <class T>
void BSTree<T>::setallBFInternal(Tnode <T> *current)
{

	if(current != nullptr)
	{
		int lh = heightInternal(current->Lchild); //get left height by edge
		int rh = heightInternal(current->Rchild); //get right height by edge
		current->balance = rh - lh;               //In our class, balance factor = right - left
		setallBFInternal(current->Lchild);        //set all balance factor for left child
		setallBFInternal(current->Rchild);        //set all balance factor for right child

	}
	return;
}
template <class T>
int BSTree<T>::getLargestBF()
{
	return getLargestBFInternal(tRoot);
}
template <class T>
int BSTree<T>::getLargestBFInternal(Tnode <T>*current)
{
	if(current != nullptr)
	{
		int Llarge = getLargestBFInternal(current->Lchild);
		int Rlarge = getLargestBFInternal(current->Rchild);
		if((abs(current->balance)) > abs(Llarge))       // Set Llarge
		{
			Llarge = current->balance;
		}
		else if((abs(current->balance)) > abs(Rlarge)) // Set Rlarge
		{
			Rlarge = current->balance;
		}
		if(abs(Llarge) > abs(Rlarge))   //return larger value
		{
			return Llarge;
		}
		else
		{
			return Rlarge;
		}
	}
	else
		return 0;

}

template<class T>
bool BSTree<T>::searchR(T input)
{
	if (tRoot == nullptr) //when tree is empty, display error message
	{
		cout << "Error, binary search tree is empty" << endl;
		return false;	//return false
	}
	return searchRInternal(tRoot, input);
}
template<class T>
bool BSTree<T>::searchRInternal(Tnode<T>* current, T input)
{
	if (current == nullptr) //base case, when traversal all node in the tree, but not found
	{
		//cout << "Not found " << endl;
		return false;
	}
	else if (current->nodeValue == input)//base case, when found target node
	{
		//cout << "Found " << endl;
		return true;
	}
	else //recursion case
	{
			if (current->nodeValue < input) //if input is larger then current's node value,
			{
				return searchRInternal(current->Rchild, input); //then send right child
			}
			else //if not,
			{

				return searchRInternal(current->Lchild, input); //then send left child
			}
	}

}

template <class T>
bool BSTree<T>::search(T &input)
{
	bool found = false;
	if(tRoot == nullptr) //if tree is empty when root point nullptr
	{
		cout << "The tree is empty" << endl;
		return found;    //return false
	}
	else
	{
		Tnode <T>*current = tRoot;  //current points root of the tree
		while(current != nullptr && found == false) //Either tree traversal all or found the target node then stop loop
		{
			if(current->nodeValue == input)   //if currentNode matches with target value, return true
			{
				found = true;

			}
			//like binary search algorithm
			else if(current->nodeValue > input) //if current value is lager, cut the right subtree(no need to search)
			{
				current = current->Lchild;
			}
			else
			{
				current = current->Rchild;     //if current value is smaller, cut the left subtree(no need to search)
			}
		}
	}

	return found; //return true;
}
template <class T>
void BSTree<T>::insert(T &input)
{

	Tnode<T> *newNode = new Tnode<T>;
	//input value can't not have child node until user call insert function
	newNode->nodeValue = input;
	newNode->Lchild = nullptr;
	newNode->Rchild = nullptr;

	if(tRoot == nullptr)   //if the tree is empty, the root node become newNode
	{

		tRoot = newNode;
		return;

	}
	else				 //if the tree is not empty
	{

		Tnode <T>*current = tRoot; //current points to root node
		Tnode <T>*trailing = nullptr;  //trailing node acts like parent node(above current node)
		while(current != nullptr)   //find the place for new node
		{
			trailing = current;
			if(current->nodeValue == input) //property of the binary search tree == do not have same node value
			{
				cout << "Error, binary search tree can't have dupliacte value in the tree" << endl;
				return;
			}
			// like search algorithm, if current's node value is lager then new node, go to left of current
			else if(current->nodeValue > input)
			{
				current = current->Lchild;
			}
			else
			{
				current = current->Rchild; //if current's node value is smaller then new node value, go to right of current
			}
		}
		//end while
		//trailing point is parent of newNode;
		if(trailing->nodeValue > input)
		{
			trailing->Lchild = newNode; //newNode value is smaller then parent node
		}
		else
		{
			trailing->Rchild = newNode; //newNode value is lager then parent node
		}
	}
	return; //end func
}
template <class T>
int BSTree<T>::height()
{

	return heightInternal (tRoot);//height function called helper function for recursive calling
}

template <class T>
int BSTree<T>::heightInternal(Tnode <T>*tRoot)
{

	 Tnode <T>*temp = tRoot; //temp points the root node

	 if(temp == nullptr) //if the tree is empty
	 {
		 return -1; //As professor's algorithms, there is no certain way to indicate empty tree
	 }
	 else
	 {
		 int lh = heightInternal(temp->Lchild);  //get the height of the left subtree
		 int rh = heightInternal(temp->Rchild);  //get the height of the right subtree

		 //figure out which side of the subtree has more edges
		 //return height + 1 need, we skipped count for first edge for root node
		 	 if(lh > rh)
		 	 {
		 		 return lh + 1;
		 	 }
		 	 else
		 	 {
		 		 return rh + 1;
		 	 }
	 }
	 return -1;

}
template <class T>
void BSTree<T>::udelete(T input)
{
	bool found = false;
	Tnode <T>*current = tRoot;
	Tnode <T>*trailing = nullptr;
	if(tRoot == nullptr)
	{
		cout << "Nothing to delete, the tree is empty" << endl;
		return;
	}
	while(current != nullptr && found != true)
	{
		if(current->nodeValue == input)
		{
			found = true; //if found true(the node to be deleted is found) stop loop
		}
		else
		{
			trailing = current; //again trailing act like parent node for current
			if(current->nodeValue > input)
			{
				current = current->Lchild;  //traversal only left tree
			}
			else
			{
				current = current->Rchild; //traversal only right tree
			}
		}
	}
	if(found == true)
	{

		cout << "Found key to delete " << input << endl; //debug part for search node to delete

	}
	if(current == nullptr) //this if case for there is no value we are looking for
	{
		cout << "After traversal, there is not " << input << "exist in the tree" << endl;
		return;
	}

		//The reason why we take parameter pass by reference is when we delete node in the udeleteInternal function
	    //we can de-allocate memory using delete keyword, but the tree have to be connected except deleted node
	    //And we don't declare parent's node for every node, so deleteInternal not only delete node, also modify tree structure
	else
	{
		//send node to delete into udeleteInternal function as reference
		if(current == tRoot)
		{
			udeleteInternal(tRoot);

		}
		else if(trailing->nodeValue > input)
		{

			udeleteInternal(trailing->Lchild);
		}
		else
		{
			udeleteInternal(trailing->Rchild);
		}
	}
}


template<class T>
void BSTree<T>::udeleteInternal(Tnode<T> *&current) {

	//cout << current->nodeValue << endl;
	//the node to delete is leaf node(has any child)
	if (current->Lchild == nullptr && current->Rchild == nullptr)
	{
		delete current;     //delete current memory
		current = nullptr;  //points null
		return;
	}
	    // 2 case and 3 case. current has one child node(not leaf node)
		// Delete current and connect node
	    // store child node into temp, after deleting assign temp into current

	if (current->Lchild != nullptr && current->Rchild == nullptr)
	{
		Tnode<T> *temp = current->Lchild; //when it has left child
		delete current;
		current = temp;
		return;
	}
	if (current->Lchild == nullptr && current->Rchild != nullptr)
	{
		Tnode<T> *temp = current->Rchild; //when it has right child
		delete current;
		current = temp;
		return;
	}

	//case 4 : When the node to be deleted has both left child and right child
	//Find predecessor(the maximum value of the right subtree)
	//To access predecessor, one down to left then down all the way to right
	Tnode <T>*predecessor = current->Lchild; // one left (since it has both child, it has left subtree)
	Tnode <T>*trailPredecessor = current;    // trailing predecessor(current)

	while(predecessor->Rchild != nullptr)   //find where is predecessor
	{
		trailPredecessor = predecessor;     //keep trailing previous of predecessor
		predecessor = predecessor->Rchild;  //down all the way to right

	}

	current->nodeValue = predecessor->nodeValue;
//	      5									4(current)
//	3          6             ->     3			           6
//		4(predecessor)					  4(predecessor)

	//As professor shows using white board, I have to care about left subtree of predecessor, but no need to right subtree(predecessor don't have)
	//cout << trailPredecessor << " " << current << endl;
	if(trailPredecessor == current) //when predecessor is just current's left node(no right subtree), trailingPredecessor is still current
	{

		current->Lchild = predecessor->Lchild;
	}
	else
	{
		//cout << "Is here? " << endl;
		trailPredecessor->Rchild = predecessor->Lchild; //when the predecessor has left subtree(It always lager then trailPredecessor)
	}



	delete predecessor;  //after all connected well, delete predecessor node
	//	      4(current)					            4(current)
	//	3                  6             ->     3			           6
	//		4(predecessor)

}


template <class T>
void BSTree<T>::inOrderTraversal()
{
   inOrderTraversalInternal(tRoot);
}
template <class T>
void BSTree<T>::inOrderTraversalInternal(Tnode <T>*temp) //print ascending order
{
	if (temp != nullptr) //base case
	{
		 inOrderTraversalInternal(temp->Lchild); //down to left subtree
	     cout << temp->nodeValue << endl;        //visit node
	     inOrderTraversalInternal(temp->Rchild); //its right subtree
	}

}
template <class T>
void BSTree<T>::preOrderTraversal() //print level of each node left to right
{
	preOrderTraversalInternal(tRoot);
}
template <class T>
void BSTree<T>::preOrderTraversalInternal(Tnode <T>*temp) //it printed node like actual tree structure
{

	if(temp != nullptr)
	{
		cout << temp->nodeValue << endl;        //root node printed first
		preOrderTraversalInternal(temp->Lchild); //down to left subtree
		preOrderTraversalInternal(temp->Rchild); //its  right subtree
	}
}
template <class T>
void BSTree<T>::postOrderTraversal()
{
	postOrderTraversalInternal(tRoot);
}

template <class T>
void BSTree<T>::postOrderTraversalInternal(Tnode <T>*temp) //print order for node it should be deleted
{
	if(temp != nullptr)
	{
		postOrderTraversalInternal(temp->Lchild); //down left of root node
		postOrderTraversalInternal(temp->Rchild); //down right of root node
		cout << temp->nodeValue << endl; 		 //visit node
	}
}
//printRohit and printRohitLevel functions given by professor's previous student
//I just change some name of variable and type of object to fit in PA7
template <class T>
void BSTree<T>::printRohit()
{
	const int WIDTH = 3;		//must be greater than the max characters printed per node; for example, if printing 2 digit numbers, WIDTH should be >= 3
	const int GAP = 5;			//gap between each node
	int height = this->height();
	//cout << height << endl; // check number of edges using height function
	string lines[height+1];

	//generates a string for each level of the tree
	for(int i=1; i<=height+1; i++){
		string line;
		printRohitLevel(tRoot, i, i, height, line, WIDTH);
		lines[i-1] = line;
	}

	//removes the unnecessary spaces from the lines
	int space = 0;
	bool allSpace;
	for(unsigned int i=0; i<lines[0].length(); i++){
		allSpace = true;
		for(string line: lines){
			if(line.at(i) != ' '){
				allSpace = false;
			}
		}
		if(allSpace){		//every line has a space at this index
			space += 1;
		}
		else{
			if(space > GAP){		//the space is too long and must be reduced to GAP
				for(string& line: lines){
					line.erase(i-space, space-GAP);
				}
				i-= (space-GAP);
			}
			else if(space < GAP && space>0){		//the space is too small and must be expanded to GAP
				string spaces;
				for(int j=0; j< (GAP-space); j++){
					spaces += " ";
				}
				for(string& line: lines){
					line.insert(i-space, spaces);
				}
				i += (GAP-space);
			}
			space = 0;
		}
	}

	//prints out each line
	for(string line: lines){
		cout << line << endl << endl << endl;
	}
}
template <class T>
void BSTree<T>::printRohitLevel(Tnode<T>* node, int x, int level, int height, string& print, const int WIDTH)
{
	if(node == nullptr){		//this node is empty so generates enough spaces based on which level the node is located on in relation to the level that must be printed and the height of the tree
		for(int i=0; i< WIDTH*pow(2,height+1-level+x); i++)
			print+= " ";
	}
	else if(x == 1){		//the node is on the right level
		for(int i=0; i< WIDTH*(pow(2,height+1-level)); i++)		//space to print before node
			print+= " ";
		int val = node->nodeValue;
		string value = to_string(val);
		print+= value;
		for(unsigned int i=0; i< (WIDTH-value.length()); i++)		//if the width of the node is less than WIDTH, prints spaces
			print+= " ";
		for(int i=0; i< WIDTH*(pow(2,height+1-level)-1); i++)		//space to print after node
			print+= " ";
	}
	else{
		printRohitLevel(node->Lchild, x-1, level, height, print, WIDTH);
		printRohitLevel(node->Rchild, x-1, level, height, print, WIDTH);
	}
}
template <class T>
	void BSTree<T>::printRohitWithBF(){		// pjh orig width=3 gap=5
	const int WIDTH = 7;		//must be greater than the max characters printed per node; for example, if printing 2 digit numbers, WIDTH should be >= 3
	const int GAP = 4;			//gap between each node
	int height = this->height();
	string lines[height+1];

	//generates a string for each level of the tree
	for(int i=1; i<=height+1; i++){
		string line;
		printRohitWithBFLevel(tRoot, i, i, height, line, WIDTH);
		lines[i-1] = line;
	}

	//removes the unnecessary spaces from the lines
	int space = 0;
	bool allSpace;
	for(unsigned int i=0; i<lines[0].length()-1; i++){	// pjh mod goes until length()-1 from length()
		allSpace = true;
		for(string line: lines){
			if(line.at(i) != ' '){
				allSpace = false;
			}
		}
		if(allSpace){		//every line has a space at this index
			space += 1;
		}
		else{
			if(space > GAP){		//the space is too long and must be reduced to GAP
				for(string& line: lines){
					line.erase(i-space, space-GAP);
				}
				i-= (space-GAP);
			}
			else if(space < GAP && space>0){		//the space is too small and must be expanded to GAP
				string spaces;
				for(int j=0; j< (GAP-space); j++){
					spaces += " ";
				}
				for(string& line: lines){
					line.insert(i-space, spaces);
				}
				i += (GAP-space);
			}
			space = 0;
		}
	}

	//prints out each line
	for(string line: lines){
		cout << line << endl << endl << endl;
	}
}
template <class T>
void BSTree<T>::printRohitWithBFLevel(Tnode<T>* node, int x, int level, int height, string& print, const int WIDTH)
{

	if(node == nullptr){		//this node is empty so generates enough spaces based on which level the node is located on in relation to the level that must be printed and the height of the tree
		for(int i=0; i< WIDTH*pow(2,height+1-level+x); i++)
			print+= " ";
	}
	else if(x == 1){		//the node is on the right level
		for(int i=0; i< WIDTH*(pow(2,height+1-level)); i++)		//space to print before node
			print+= " ";
		int val = node->nodeValue;
		string value = to_string(val);
		print+= value;
		int bal = node->balance;				// start pjh mods
		string baln = to_string (bal);
		print+= "(";
		print+= baln;
		print+= ")";							// end pjh mods
		for(unsigned int i=0; i< (WIDTH-value.length()); i++)		//if the width of the node is less than WIDTH, prints spaces
			print+= " ";
		for(int i=0; i< WIDTH*(pow(2,height+1-level)-1); i++)		//space to print after node
			print+= " ";
	}
	else{
		printRohitWithBFLevel(node->Lchild, x-1, level, height, print, WIDTH);
		printRohitWithBFLevel(node->Rchild, x-1, level, height, print, WIDTH);

	}
}




#endif /* BSTREE_HPP_ */
