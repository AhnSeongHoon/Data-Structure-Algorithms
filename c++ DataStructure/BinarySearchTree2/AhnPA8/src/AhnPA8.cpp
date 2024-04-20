//============================================================================
// Name        : AhnPA8.cpp
// Author      : Ahn SeongHoon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "BSTree.hpp"
using namespace std;

int main()
{
	BSTree <int> myDtree;
	cout << "--------------------------------------------------------------" << endl;
	myDtree.insertR(10);
	myDtree.setallBF();
	myDtree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	myDtree.insertR(11);
	myDtree.setallBF();
	myDtree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	myDtree.insertR(14);
	myDtree.setallBF();
	myDtree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	myDtree.insertR(17);
	myDtree.setallBF();
	myDtree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	myDtree.insertR(18);
	myDtree.setallBF();
	myDtree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	myDtree.insertR(12);
	myDtree.setallBF();
	myDtree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	myDtree.insertR(13);
	myDtree.setallBF();
	myDtree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	myDtree.insertR(16);
	myDtree.setallBF();
	myDtree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	myDtree.insertR(5);
	myDtree.setallBF();
	myDtree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	cout << "***deleting 16" << endl;
	myDtree.udelete(16);
	myDtree.setallBF();
	myDtree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	cout << "***deleting 17" << endl;
	myDtree.udelete(17);
	myDtree.setallBF();
	myDtree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	cout << "***deleting 14" << endl;
	myDtree.udelete(14);
	myDtree.setallBF();
	myDtree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	cout << "***deleting 10" << endl;
	myDtree.udelete(10);
	myDtree.setallBF();
	myDtree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------" << endl;

	BSTree<int> mytree;
	cout << "--------------------------------------------------------------" << endl;
	cout << "inserting 5" << endl;
	mytree.insertR(5);
	mytree.setallBF();
	mytree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	cout << "inserting 3" << endl;
	mytree.insertR(3);
	mytree.setallBF();
	mytree.printRohitWithBF();
	cout << "max BF " << mytree.getLargestBF() << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "inserting 8" << endl;
	mytree.insertR(8);
	mytree.setallBF();
	mytree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	cout << "inserting 12" << endl;
	mytree.insertR(12);
	mytree.setallBF();
	mytree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	cout << "inserting 9" << endl;
	mytree.insertR(9);
	mytree.setallBF();
	mytree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	cout << "inserting 1" << endl;
	mytree.insertR(1);
	mytree.setallBF();
	mytree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	cout << "inserting 2" << endl;
	mytree.insertR(2);
	mytree.setallBF();
	mytree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	cout << "inserting 10" << endl;
	mytree.insertR(10);
	mytree.setallBF();
	mytree.printRohitWithBF();
	cout << "--------------------------------------------------------------" << endl;
	cout << "inserting 11" << endl;
	mytree.insertR(11);
	mytree.setallBF();
	mytree.printRohitWithBF();
	cout << "max BF " << mytree.getLargestBF() << endl;

	//Check whether the searchR function works well. It works
//	bool b = mytree.searchR(11);
//			if(b)
//			{
//				cout << "found " << endl;
//			}
//			else
//			{
//				cout << "Not found" << endl;
//			}
	return 0;
}
