#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> v;
	int n;
	unsigned int k;

	cout << "How many elements you want to put in: "; 
	cin >> n;
	cout << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "How many letters are these words going to have: ";
	cin >> k;
	cout << "-------------------------------------------------------" << endl;

	string s;

	cout << "Enter the words with the k length" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s.length() > k || s.length() < k)
			cout << "The length is exeeced, please write words with " << k << " letters" << endl;
		else
			v.push_back(s);
	}

	std::sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}
