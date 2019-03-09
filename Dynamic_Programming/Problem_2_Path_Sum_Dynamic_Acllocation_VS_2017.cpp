/*
   Ardit Shala 
   Compiled with VS2015
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int m;
	cout << "Please tell us the size of your triangle: ";
	cin >> m;

	int** tri = new int*[m];
	for (int i = 0; i < m; ++i)
	{
		tri[i] = new int[m];
	}

	int** cpy = new int*[m];
	for (int i = 0; i < m; ++i)
	{
		cpy[i] = new int[m];
	}

	//making the whole tri matrix entries zero
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tri[i][j] = 0;
		}
	}

	//reading the input from the keyboard
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> tri[i][j];
		}
	}

	//copying everything in tri matrix to cpy matrix
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cpy[i][j] = tri[i][j];
		}
	}


	int val = m; //just to secure the value for the loop iterations

				 //two for loops to find the element
	for (int i = val - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			if (tri[i + 1][j] > tri[i + 1][j + 1]) //check the values of the right/left
			{
				tri[i][j] += tri[i + 1][j]; //if right bigger assign tri[i+1][j] to tri[i][j]
			}
			else
				tri[i][j] += tri[i + 1][j + 1]; //if left bigger assign tri[i+1][j+1] to tri[i][j]
		}
	}

	cout << tri[0][0] << endl; //the overall sum will be stored at tri[0][0] (the very first element of the matrix)

	int p, q, max1; //to find the root

	vector<int> v; //vector to store the indexes values

	for (int i = 0; i<(val - 1); i++)
	{
		max1 = INT_MIN;
		for (int j = 0; j<val; j++)
		{
			if (max1 < tri[i][j])
			{
				p = i;
				q = j;
				max1 = tri[i][j];
			}
		}
		v.push_back(cpy[p][q]);
	}


	int t = max(cpy[p + 1][q], cpy[p + 1][q + 1]); //find the last element

	v.push_back(t); //put that last element into the matrix

	for (unsigned int i = 0; i<v.size(); i++) //print the vector
	{
		cout << v[i] << " ";
	}

	// freeing the memory for matrix tri
	for (int i = 0; i < val; ++i)
		delete[] tri[i];
	delete[] tri;

	// freeing the memory for matrix cpy
	for (int i = 0; i < val; ++i)
		delete[] cpy[i];
	delete[] cpy;

	return 0;
}
