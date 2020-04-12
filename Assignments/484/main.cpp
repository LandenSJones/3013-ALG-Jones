//Landen Jones
#include <iostream>
#include <vector>
#include <fstream>
#define endl "\n"
using namespace std;
struct MyVec
{
	vector<int> num;
	vector<int> occ;

	//checks to see if value is in the vector
	bool InVector(int x)
	{
		for (int i = 0; i < num.size(); i++)
		{
			if (x == num[i])
				return true;
		}
		return false;
	}


	//takes a value and adds if in vector, returns true
	void AddOcc(int x)
	{
		for (int i = 0; i < num.size(); i++)
		{
			if (x == num[i])
			{
				occ[i] += 1;
			}
		}
	}

};

int main()
{
	MyVec Data;
	//ifstream infile;
	//infile.open("input.txt");
	int num;
	while (cin>> num)
	{
		if (Data.InVector(num))
			Data.AddOcc(num);
		else
		{
			Data.num.push_back(num);
			Data.occ.push_back(1);
		}

	}
	for (int i = 0; i < Data.num.size(); i++)
	{
		cout << Data.num[i] << ' ' << Data.occ[i] << '\n';
	}
}
