//============================================================================
// Name        : AhnPA3.cpp
// Author      : Ahn Seonghoon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int fibb(int n)
{

	// print out changing n value of every function call
	cout << "\t fibb("<< n <<") -> ";
		if(n == 1) //the first fibonacci is 0
		{

			return 0;
		}
		if(n == 2) //the second fibonacci is 1
		{

			return 1;

		}
		//To get nth fibonacci, need fibonacci(n - 1), fibonacci(n - 2). So that base case has 2 cases
		//fibbonacci nth = fibonacci(n - 1) + fibonacci(n - 2)
        return fibb(n-1) + fibb(n-2);

}
int pow(int x, int y) // x is baseNum, y is powerNum
{
	//you may assume that both x and y are integers, and greater than zero.
	if(y == 0)
	{
		cout << "powerNum can not be zero in this case " << endl;
		return 1; // since every number to the power zero is 1;
	}
	if(x == 0) //since base 0 to the any power is zero
	{
		cout << "baseNum can not be zero in this case " << endl;
		return 0;
	}
	if(y == 1) //base case, if powerNum is 1 return baseNum to function
	{
		return x;
	}
	//power problem break into baseNum * baseNum * baseNum .... * baseNum
	//powerNum determines how many baseNum multiplied it self.
	return x * pow(x, y-1); // powerNum decrease by 1 every recursion call
}

int sum(int *array, int size)
{

	// sum of array is always the value of the element
	// for example, sum of array = { 3 }; is 3
	// its going to be base case for recursive
	if (size == 1) {
		return array[0];
	}

	//sum of array equals to (last element) + (sum of sub-array whose length is 1 shorter)
	// for example, sum of { 1, 2, 3 } equals to 3 + { 1, 2 }
	return array[size - 1] + sum(array, size - 1); // write resursion code for return
}
int countOccurrences(string s)
{
	int lastVowelCount = 0;	// 1 if last letter of string has vowel, if don't 0
	// there is no vowel in string, ex) an empty string
	if (s.empty()) {
		return 0;
	}
    char lastChar = s[s.length()-1]; //lastChar will contain the last index letter of string
	if (lastChar == 'a' || lastChar == 'e' || lastChar == 'i' || lastChar == 'o' || lastChar == 'u' || lastChar == 'y')
	{
		lastVowelCount = 1;
	}
	else
		lastVowelCount = 0;
	//vowel occurences of string equals to (if the last element is vowel) + (occurences of substring whose length is 1 letter short then original)
    //for example, vowel occurences of 'apple' is 1 + countOccurrences('appl') [because last char 'e' is a vowel]
	return lastVowelCount + countOccurrences(s.substr(0, s.length() - 1));
}
string reverseString(string s)
{

	//reverse of string has one letter is the same of orginal string
	//ex) reverseString('G') is just 'G'
	if (s.length() == 1)
	{
		return s;
	}

    char lastLetter = s[s.length()-1]; //lastLetter contain last letter of string array
	//reverse of string equals to (last character) + (reverse of substring whose length is 1 char shorter)
	//ex) reverse of 'home' equals to 'e' + reverseString('hom'), which is string that without lastLetter
	return lastLetter + reverseString(s.substr(0, s.length() - 1));
}

int main() {

	//test1
	cout << "********** first 10 fibonacci numbers **********" << endl;
	for (int i=1; i<=10; i++)
	{
	// to print clean result
    cout <<setw(6) << fibb(i) << " is " << i << "th fibbonacci " << endl;
	}
	cout << endl << "********** end of fibonacci test **********" <<
	endl;
	cout << endl << endl;

	//test2
	cout << "3 to the 4th is " << pow (3, 4) << endl;
	cout << "5 to the 1st is " << pow (5, 1) << endl;
	//test for if baseNum or powerNum has zero value
	//cout << "7 to the 3rd is " << pow(7,3) << endl;
	//case for if user want to zero power or base
	//cout << "0 to the 1 is " << pow(0,1) << endl;
	//cout << "1 to the 0 is " << pow(1,0) << endl;
	cout << endl << endl;

	//test3
	int array[5] = {5,4,3,2,1};
	cout << "sum of entire array is " << sum (array, 5) << endl;
	cout << "sum of first element only is " << sum (array, 1) << endl;
	cout << "sum of first three elements is " << sum (array, 3) << endl;
	cout << endl << endl;

	//test4
	string s = "now is the time for each good person";
	//cout << s[s.length()-1] << endl;

	cout << "number of vowels is " << countOccurrences (s) << endl;
	s = "aeiouy";
	cout << "number of vowels is " << countOccurrences (s) << endl;
	s = "bcd";
	cout << "number of vowels is " << countOccurrences (s) << endl;
	cout << endl << endl;

	cout << "reverse of " << s << " is " << reverseString (s) << endl;
	s = "abcd";
	cout << "reverse of " << s << " is " << reverseString (s) << endl;
//	s = "Ahn Seonghoon";
//	cout << "reverse of " << s << " is " << reverseString(s) << endl;
	return 0;

}
