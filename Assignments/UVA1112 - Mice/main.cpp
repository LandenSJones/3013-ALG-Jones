#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int** Make2dArray(ifstream&, int);
void Fill2dArray(int**, ifstream&, int);
void Print2dArray(int, int**);
void printSolution(int**, int);
void FloydWarshall(int**, int, int, int);
#define INF 99999
int main()
{
	ifstream infile; infile.open("input.txt");
	int iterations;
	cin >> iterations;				//gets number of times to run
	while(iterations-- > 1)
	{
		int rows, exit, timer, traversals;
		cin >> rows >> exit >> timer >> traversals;
		exit--;
		int** graph = Make2dArray(infile, rows);
		Fill2dArray(graph, infile, traversals);
		FloydWarshall(graph, rows, exit, timer);
		cout << '\n';
	}
	int rows, exit, timer, traversals;
	cin >> rows >> exit >> timer >> traversals;
	exit--;
	int** graph = Make2dArray(infile, rows);
	Fill2dArray(graph, infile, traversals);
	FloydWarshall(graph, rows, exit, timer);
	return 0;
}
//Prints the array, values of -1 are undefined
void Print2dArray(int rows, int** Array)
{
	cout << "Here is the Array\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (Array[i][j] == INF)
				cout << setw(10) << "INF";
			else
				cout << setw(10) << Array[i][j];
		}
		cout << endl;
	}
}
//Creates 2D array and assigns all values to -1, initially
int** Make2dArray(ifstream& infile, int size)
{
	int** graph;
	graph = new int* [size];
	//Creates 2D array
	for (int i = 0; i < size; i++) 
	{
		graph[i] = new int[size];
	}
	//Initializes values initially to "-1"
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			graph[i][j] = INF;
	}
	for (int i = 0; i < size; i++)
	{
		graph[i][i] = 0;
	}
	return graph;
}
//Fills the Arrays with the values in the traversals
void Fill2dArray(int** graph, ifstream& infile, int traversals)
{
	int x, y, d;
	for (int i = 0; i < traversals; i++)
	{
		cin >> x >> y >> d;
		x--;
		y--;
		graph[x][y] = d;
	}
}
void printSolution(int** graph, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (graph[i][j] == INF)
				cout << setw(10) << "INF";
			else
				cout << setw(10) << graph[i][j];
		}
		cout << endl;
	}
}
void FloydWarshall(int** graph, int rows, int exit, int timer)
{
	int** dist = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		dist[i] = new int[rows];
	}
	int i, j, k;


	for (i = 0; i < rows; i++)
		for (j = 0; j < rows; j++)
			dist[i][j] = graph[i][j];

	for (k = 0; k < rows; k++)
	{
		// Pick all vertices as source one by one  
		for (i = 0; i < rows; i++)
		{
			// Pick all vertices as destination for the  
			// above picked source  
			for (j = 0; j < rows; j++)
			{
				// If vertex k is on the shortest path from  
				// i to j, then update the value of dist[i][j]  
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	int result = 0;
	//cout << "Number of rows is " << rows << '\n';
	//cout << "Exit is " << exit << '\n';
	//cout << "Timer is " << timer << '\n';
	for (int i = 0; i < rows; i++)
	{
		if (dist[i][exit] <= timer)
			result++;
	}
	//for (int i = 0; i < rows; i++)
	//	cout << "Spot[" << i << "][exit] is : " << dist[i][exit] << endl;
	cout << result << "\n";
	//printSolution(dist, rows);
}
