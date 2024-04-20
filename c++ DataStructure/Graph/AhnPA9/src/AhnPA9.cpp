//============================================================================
// Name        : AhnPA9.cpp
// Author      : Ahn SeongHoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct Vertex
{
    int vertexValue;
    list<int> neighbors;
};
int size;
bool* visit; //visitation table

vector<string> split(string str, char delimiter)
{
	//int i;
    vector<string> vertexInfro;
    int pos = str.find(delimiter); // find function going to return 1(position of the first blank after vertex)
    //cout << pos << endl;
    while ((pos = str.find(delimiter)) != -1) //If the find function does not find delimeter, it will return -1
    {

    	vertexInfro.push_back(str.substr(0, pos)); //push back vetrex and its neighbors

        str.erase(0, pos + 1);  //remove delimiter with the number I read until str remain -1(indicates end of neighbor)
        //cout << str << endl;
        //i++;
    }
//    cout << endl;
//    for(int i = 0; i < vertexInfro.size(); i++)
//    {
//    	cout << vertexInfro[i] << " ";
//    }
//    cout << endl;
    return vertexInfro;
}

void dftInternal(int **adjMatrix, int vertex)
{
    cout << vertex << " "; //visit vertex
    visit[vertex] = true;  //mark as visited
    int current = 0; //position at first neighbor
    while(current < size) //while there are more neighbors
    {
    	//if neighbor is not visited and neighbor is exist
        if(adjMatrix[vertex][current] && !visit[current])
        {
            dftInternal(adjMatrix, current); //call dftInternal recursively

        }
        current++; //position at next neighbor
    }
}

void dft(int **adjMatrix)
{
	for(int i = 0; i < size; i++) //set all vertices as unvisited
	{
		visit[i] = false;
	}
    int current = 0; //position at first vertex
    //since our vertex is ascending order,
    while(current < size)  //it can be determined vertex number whether it has more vertex in the graph
    {
        if(!visit[current])
        {
        	//if vertex is not visited
            dftInternal(adjMatrix, current); // call helper function

        }
        current++;//position at next vertex
    }
}

void bft(vector<Vertex> vertices)
{
    bool visit[size];
    for(int i = 0; i < size; i ++) // set all vertices as unvisited
    {
    	visit[i] = false;
    }
    queue<int> toVisit; //create queue

    int startVertex = 0;
    while(startVertex < size) //move vertices in graph
    {
        if (!visit[startVertex]) //if vertex is not visited
        {
            toVisit.push(startVertex); // push vertex onto queue
            visit[startVertex] = true; // mark vertex as visited
            while(!toVisit.empty()) //queue not empty
            {
                int current = toVisit.front(); // get vertex to look up neighbor
                toVisit.pop(); //pop queue
                cout << current << " "; // visited popped vertex
                for(int element : vertices[current].neighbors) //check neighbor
                    if (!visit[element]) //if neighbor is not visited
                    {
                        toVisit.push(element); //push onto queue
                        visit[element] = true; // mark visited
                    }
            }
        }
        startVertex++; //go to at next vertex
    }
}

int main()
{
	//read input vertex number first
	ifstream inFile;
	string input;
    // Step 1-1. Read total vertices count
	inFile.open ("A9 F2022.ini"); //ini file can be read by same way with txt file
    if (!inFile.is_open())                //If file is not opened
    {
    	cout << "Open File Error" << endl;
        return 4;
    }
    getline (inFile, input); //get number of vertexes from the ini file
    size = stoi(input);      //since input is string data, using stoi make string to int
    visit = new bool[size];  //dynamically allocate visitation table, I will use bool type
    inFile.close();          //after read parameter file close the file properly


    vector<Vertex> vertices;     // initialize adjacency list

     // Initialize adjacency matrix 2d array
    int **matrix;
    matrix = new int * [size]; //creates an array of int pointers
    for (int i=0; i<size; i++)
    {

    	matrix[i] = new int [size]; //allocate array of size from ini file. Since the 2d array is n*n
    }

    // Initialize matrix with zero
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
        	matrix[i][j] = 0; //insert 0 into all of index

        }
    }

    //  Read graph information
	inFile.open ("A9data688g3 F2022.txt"); //if file is not open,
	if (!inFile.is_open())
	{
		cout << "File open error" << endl; //display error
        return 4;
	}

    getline (inFile, input); //read vertex information as string type
    while (!inFile.eof())    //read until end of the text file
    {
        vector<string> getData = split(input, ' '); //split by delimiter(space)
        //cout << "In while " << parsed[0] << endl; To check, get data properly
        // First input of line is src vertex
        int vertex = stoi(getData[0]); //take vertex
        Vertex temp;
        temp.vertexValue = vertex; //take vertex value for struct member variable

        ////size() function returns unsigned int, so compare with unsigned int i
        for(unsigned int i=1; i<getData.size(); i++) // i starts with 1, since it is loop for neighbors
        {

            int neighbor = stoi(getData[i]);
            // If adjacency matrix's neighbor is exist, it represented by 1
            matrix[vertex][neighbor] = 1;
            // adjacency list
            temp.neighbors.push_back(neighbor); //insert to neighbor into temp vector
        }
        vertices.push_back(temp); //push back data into adjacency list

        getline (inFile, input);
    }
    inFile.close();

    //step to print out adjacency list
    cout << "Populated adjacency list:" <<  endl;
    for(unsigned int i=0; i<vertices.size(); i++) //size() function returns unsigned int, so compare with unsigned int i
    {
    	//display vertex
        cout << "vertex number " << i << " value " << vertices[i].vertexValue << " neighbors-> ";
        for(int element: vertices[i].neighbors)
        {
				cout << element << " "; //display all neighbors
        }
        cout << endl;
    }
    cout << endl;

    // Step to print out adjacency matrix
    cout << "Populated adjacency matrix:" << endl;
    for(int i=0; i<size; i++)
    {
        cout << "vertex number " << i << " value " << vertices[i].vertexValue << " neighbors-> ";
        //or cout << "vertex number " << i << " value " << i << " neighbors-> ";
        for(int j=0; j<size; j++)
        {
            if (matrix[i][j] != 0) //If neighbor exist in the matrix
            {
                cout << j << " ";  //display neighbor
            }

        }
        cout << endl;
    }
    cout << endl;
//    cout << "To check original form of adjacency matrix" << endl;
//    for(int i = 0; i < size; i++)
//    {
//    	for(int j = 0; j < size; j++)
//    	{
//    		cout << matrix[i][j];
//    	}
//    	cout << endl;
//    }
//    cout << endl; it printed well

    //Traverse the graph using dft and Adjacency matrix
    cout << "Depth-first traversal:" << endl;
    dft(matrix);
    cout << endl;

    //Traverse the graph using bft and Adjacency list
    cout << "Breadth-first traversal:" << endl;
    bft(vertices);
    cout << endl;

    //delete memory for matrix
    for(int i = 0; i < size; i++)
    {
    	delete [] matrix[i];
    }
    cout << "Have a great day!!" << endl;
	return 0;
}
