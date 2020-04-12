//Landen Jones
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
#define endl "\n"
using namespace std;
struct MyNode
{
	bool visited = 0;
	vector<int> vec;

	void PrintVec()
	{
		for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << " ";
	}
	void AddToVec(int num)
	{
		bool alreadyHave = false;
		for (int i = 0; i < vec.size(); i++)
		{
			if (num == vec[i])
				alreadyHave = true;
		}
		if (!alreadyHave)
			vec.push_back(num);
	}
	MyNode()
	{
		visited = false;
	}
};
void FillList(MyNode* List);
int GetNumRows();
int GetFirstChar(string str);
int GetSecondChar(string str);
int CalculateSubgraphs(MyNode* List, int rows);
int NextUnvisitedNode(MyNode* List, int rows);
bool VisitNodes(MyNode* List, vector<int>& nodesT);
bool AllVisited(MyNode* List, int rows);

int main()
{
	int iterations;						//variable used for 
	string str;
	cin >> iterations;				//gets number of times to run
	getline(cin, str);				//gets remaining line after iterations
	for (int i = 0; i < iterations; i++)
	{
		int rows = GetNumRows();	//returns number of characters in graph
		MyNode* List = new MyNode[rows];
		FillList(List);
		cout << CalculateSubgraphs(List, rows);
		if (i == iterations - 1)
		{
			cout << endl;
		}
		else
			cout << endl << endl;
	}
	return 0;
}
int CalculateSubgraphs(MyNode* List, int rows)
{
	vector<int> nodesToTraverse;
	int result = 0, nextU;
	bool change = false;
	//While not all nodes have been visited
	while (!AllVisited(List, rows))
	{
		change = false;
		result++;
		nextU = NextUnvisitedNode(List, rows);
		nodesToTraverse.push_back(nextU);
		while (!change)
		{
			change = VisitNodes(List, nodesToTraverse);
		}
	}
	return result;
}
bool VisitNodes(MyNode* List, vector<int>& nodesT)
{
	bool Visited = false;
	//traverse through nodesToTraverse
	for (int i = 0; i < nodesT.size(); i++)
	{	//if node isn't visited
		if (List[nodesT[i]].visited == false)
		{	//change to visited
			List[nodesT[i]].visited = true;
			Visited = true;
			//take their nodes and add to list to traverse
			for (int j = 0; j < List[nodesT[i]].vec.size(); j++)
			{
				nodesT.push_back(List[nodesT[i]].vec[j]);
			}
		}
	}
	return Visited;
}
bool AllVisited(MyNode* List, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		if (List[i].visited == false)
			return false;
	}
	return true;
}
void FillList(MyNode* List)
{
	string temp;
	getline(cin, temp);				//gets first data set of v1 to v2
	while (temp != "")					//
	{
		List[GetFirstChar(temp)].AddToVec(GetSecondChar(temp));
		List[GetSecondChar(temp)].AddToVec(GetFirstChar(temp));
		temp = "";						//resets string after data is used
		getline(cin, temp);
	}

}
int GetFirstChar(string str)
{
	if (str.length() == 2)
	{
		return str[0] - 65;
	}
	else
		cout << "Error, length is not equal to 2";
	return '?';
}
int GetSecondChar(string str)
{
	if (str.length() == 2)
	{
		return str[1] - 65;
	}
	else
		cout << "Error, length is not equal to 2";
	return '*';
}
int GetNumRows()
{
	string garbage;
	char start;
	cin >> start;
	getline(cin, garbage);			//gets rid of the remaining space after the character
	int numV = start - 64;				//64 here bc rows start at 1
	return numV;
}
int NextUnvisitedNode(MyNode* List, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		if (List[i].visited == false)
			return i;
	}
}
