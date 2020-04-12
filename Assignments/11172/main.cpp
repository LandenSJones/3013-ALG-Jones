#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int x, count = 1;
	cin >> x;
	while (x != 0)
	{
		cout << "Case " << count++ << ": " <<  x / 2 << endl;
		cin >> x;
	}
	return 0;
}
