//============================================================================
// Name        : AhnPA6.cpp
// Author      : Ahn SeongHoon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include "LL.hpp"
using namespace std;

//first hash function I tried
//int hashFunction(string str)
//{
//    int hash = 5381;        // magic number for prime number
//    int c;
//    for(char s : str)      //for-each, so, c contains every single letter of str
//    {
//        c = s;
//        hash += (hash * abs(c)) % 163; // Biggest prime number  160 = 163
//    }
//
//    return hash % 163;
//}
//second hash Function I tried
//long long hashFunction(string str)
//{
//	long long hash = 5381; // magic number for prime number
//	int strSize = str.length();
//	//cout << "strSize is : " << strSize << endl;
//	int key = 1;
//	for(int i = 0; i < strSize; i++)
//	   {
//	    //key *= static_cast<int>(str[i]); //every single letter in the string change into int type then store into key
//	     key  *= abs(str[i]);
//	     hash += key;                     //assign the key into hash
//	   }
//        hash = abs(hash);
//	    return hash % 163;                 //hashing by module as class discussed the prime number nearest 160 == 163
//}
long long int hashFunction(string str)   //prevent overflow
{
    //Hashing method from class
	long long int hash = 5381; 				//magic number for prime number
	char a,b,c,d,e,f,g,h,i;                 //employee ID -- 9 characters: three alpha followed by six numeric

	    a = str[0];
	    b = str[1];
	    c = str[2];
	    d = str[3];
	    e = str[4];
	    f = str[5];
	    g = str[6];
	    h = str[7];
	    i = str[8];
	    //int j = str[9];
	    int key = 7717; // magic number for prime
	    key = hash * abs(a*b*c*d*e*f*g*h*i); //even I use abs value, but I want to hash lager number
	    hash = abs(key * 163 + hash);
        hash = (hash << 3);  //try for bitwise operator by prime number
        //cout << hash << endl;

    return hash % 163;                 //hashing by module as class discussed the prime number nearest 160 == 163
}

int main()
{
	cout << "************ part 1 ***********" << endl;
    int table[163];      //array for hash table and collision occur
    for(int i=0; i<163; i++)
    {
    	table[i] = 0;    //fill zero for all index
    }

    ifstream readFile;

    readFile.open("a6data F22.txt");
    if(!readFile.is_open())
    {
    	cout << "open error file, please check text file directory " << endl;
    	return 4;
    }
    if(readFile.is_open())
    {
        while(!readFile.eof())
        {
            string line;
            getline(readFile, line); //read by line
            if(line != "")
            {
            	int hash = hashFunction(line.substr(0,9)); //pass the Employee ID of every line of text file
            	table[hash]++; //add by 1 for every collision occur for specific index
            }

        }
        readFile.close();
    }

//    for(int i = 0; i < 163; i++)
//    {
//		cout << "Hash entry " << i << " number of hash " << table[i] << endl;
//
//    }

//    //variables for part1
    float chainSize = 0.0;
    float chainHashCount = 0.0;
    int hashCount = 0;
    int emptyHashCount = 0;

    for(int i=0; i<163; i++)
    {
        if(table[i] == 1) //hash index occur
        {
            hashCount++;
        }
        else if(table[i] > 1) //collision occur
        {
            chainHashCount++;
            chainSize += table[i]; // for number of chain at the specific hash index
        }
        else if(table[i] == 0)    //array not filled
        {
            emptyHashCount++;
        }
    }
   //cout << "The chain size : " << chainSize << endl;
    float average = chainSize / chainHashCount;   //average chain size of hash table
    cout << "number of elements with 0 hashes                 " << emptyHashCount << endl;
    cout << "number of elements with 1 hash                   " << hashCount << endl;
    cout << "number of elements with >1 hash                  " << chainHashCount << endl;
    cout << "average chain size for elements with >1 hash     " << average << endl;
    //part 1 pass

    cout << "*************** part 2 ***********" << endl;
    hashTableEntry hashTable[163]; //hashEntry size is nearest prime number of 160
    for(int i=0; i<163; i++)
    {
    	//initialize member variable of hashTable with 0 and null string
        hashTable[i].info.ID = "0";
        hashTable[i].info.name = "";
    }

    readFile.open("a6data F22.txt");
    if(readFile.is_open())
    {
        while(!readFile.eof())
        {   //read file again
            string str;
            getline(readFile, str); // read file line by line

            if(str != "") // the last line of the text file is null string so that condition for break
            {
                int hash = hashFunction(str.substr(0,9));

                Employee newEmployee; //data from text file into new employee
                newEmployee.ID = str.substr(0,9); //data for ID
                newEmployee.name = str.substr(9); //data for name

                if(hashTable[hash].info.ID == "0")  //If the ID has 0, the hash index has no data
                {
                    hashTable[hash].info = newEmployee; //fill the array at hash index with newEmployee
                }
                //If hash index of array has data more then one, add data not hash entry, hashEntry's linked list
                else
                {
                    hashTable[hash].llEmployee.push_front(newEmployee);
                }
            }
        }
        //close file
        readFile.close();
    }

    LL<Employee> *ll = new LL<Employee>; //allocate memory for ll pointer
    for(int i=0; i<163; i++)
    {
        //ll points hashTable linked list address, I don't have to that because I have llEmployee to access member function of LL
    	//I tried make sure my linked list connected properly
        ll = &hashTable[i].llEmployee;
        //employee get data every loop from current employee info from hash table
        Employee employee = hashTable[i].info;
        cout << "hash table entry " << i;
        //if ID 0, current index has no data in hash table
        if(employee.ID == "0")
        {
            cout << "    no data" << endl;
        }
        // if current index has data, print employee data
        else
        {
            cout << "    employee    " << employee.ID << "  name  " << employee.name << endl;
        }

        // if current index has data, but no linked list(chain)
        if(ll->list_length() == 0) //or hashTable[i].llEmployee.list_length == 0
        {
            cout << "      there is no chain from this entry" << endl;
        }
        //if list->length() is not zero means there is collision by chaining(linked list exist)
        else
        {
        	   ll->display_list();
        	   //I can also use
        	   //hashTable[i].llEmployee.display_list();
         }
    }
    Employee temp;
    while(true)   //loop until input is 0
    {

    	string input;
    	cout << "Please enter ID for employee " << endl;
    	getline(cin,input);

    	if(input == "0")  //break loop condition
    	{
    		cout << "Thanks and have a good day " << endl;
    		return 0;
    	}
    	else
    	{
            //hash user input string
    	    int hash = hashFunction(input);
            //after get hash index, figure out data exist in the hash index
            if (hashTable[hash].info.ID == "0")
            {
            	//if no data in the hash index, print not found
                cout << "employee not found" << endl;
            }
            //if hash index has matched with inputID print print out employee data
            //in this case no need to use search function, since employee already found
            else
            {
                if (hashTable[hash].info.ID == input)
                {
                    cout << hashTable[hash].info.ID << " " << hashTable[hash].info.name << endl;
                }
                else
                {
                	//search ID using LL class member
                	temp = hashTable[hash].llEmployee.search_list(input);
                	cout << temp.ID << " " << temp.name << endl;

                }
            }
       }

    }
 //pass part2


}
