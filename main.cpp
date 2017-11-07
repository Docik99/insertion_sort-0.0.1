#include <iostream>
#include <sstream>

using namespace std;

bool rn(int & n, int * array)
{
	string string;
	getline(cin, string);
	istringstream stream(string);
	bool such = true;
	for (int i = 0; i < n; ++i)
	{
		if (!(stream >> array[i]))
		{
			such = false;
			break;
		}
	}
	return such;
}

int main()
{
	int n = 5;
	int * array = new int [n];
    string str;
	getline(cin, str);
	istringstream stream(str);
	if (stream >> n)
	{
		if (rn(n, array))
		{
			int a, j;
			for (int i = 1; i < n; i++)
			{
				a = array[i];
				j = i - 1;
				while (array[j] > a && j >= 0)
				{
					array[j + 1] = array[j];
					array[j] = a;
					j--;
				}
			}

			for (int i = 0; i < n; i++)
			{
				cout << array[i] << " ";
			}
		}
		else
		{
			cout << "An error has occured while reading input data.";
		}
	}
	return 0;
}
