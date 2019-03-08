#include <iostream>
#include <vector>
using namespace std;

void radixSort(vector<int>& toSort)
{
	int radix = 10;
	vector<vector<int> > bucket(radix);
	bool stop = false;
	int tmp = -1;
	int placement = 1;
	while (stop == false)
	{
		stop = true;
		for (size_t i = 0; i < toSort.size(); ++i)
		{
			tmp = toSort[i] / placement;
			bucket[tmp % radix].push_back(toSort[i]);
			if (stop == true && tmp > 0)
				stop = false;
		}
		int counter = 0;
		for (int i = 0; i < radix; ++i)
		{
			for (size_t j = 0; j < bucket[i].size(); ++j)
			{
				toSort[counter] = bucket[i][j];
				counter++;
			}
			bucket[i].clear();
		}
		placement *= radix;
	}
}

int main()
{
	int myints[] = { (int)'a' ,15,26,29,5 };
	vector<int> vec(myints, myints + sizeof(myints) / sizeof(int));
	cout << "The contents of vec are:";
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
	cout << "Apply Radix sort: " << endl;
	radixSort(vec);
	cout << "The contents of sorted vec are:";
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	return 0;
}
