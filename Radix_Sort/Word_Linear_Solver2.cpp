/*
	ADS - Spring 2018
	Ardit Shala / 30001420
	Sort Strings in Linear Time
	I used Radix Sort to do that
*/

#include <cstdio>
#include <iostream>
#include <string>
using std::string;
using namespace std;

size_t getMax(string arr[], int n) {
	size_t max = arr[0].size();
	for (int i = 1; i < n; i++)
	{
		if (arr[i].size()>max)
			max = arr[i].size();
	}
	return max;
}

void countSort(string a[], int size, size_t k) {
	string *b = NULL; int *c = NULL;
	b = new string[size];
	c = new int[257];



	for (int i = 0; i <257; i++)
	{
		c[i] = 0;
	}
	for (int j = 0; j <size; j++)
	{
		c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;           																		 
	}

	for (int f = 1; f <257; f++) 
	{
		c[f] += c[f - 1];
	}

	for (int r = size - 1; r >= 0; r--) 
	{
		b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
		c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
	}

	for (int l = 0; l < size; l++)
	{
		a[l] = b[l];
	}
	delete[] b;
	delete[] c;
}


void radixSort(string b[], int r) {
	size_t max = getMax(b, r);
	for (size_t digit = max; digit > 0; digit--) { 
		countSort(b, r, digit - 1);
	}

}

int main(void) {

	unsigned int k;
	int n;
	cout << "How many elements you want to put in: ";
	cin >> n;
	cout << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "How many letters are these words going to have: ";
	cin >> k;
	cout << "-------------------------------------------------------" << endl;

	string data[256];
	cout << "Enter the words with the k length" << endl;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s.length() > k || s.length() < k)
			cout << "The length is exeeced, please write words with " << k << " letters" << endl;
		else
			data[i] = s;
	}

	radixSort(data, (int)(sizeof(data) / sizeof(data[0])));
	cout << "After Sorting: " << endl;
	for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		printf("    %s\n", data[i].c_str());
	}

	char end;
	fillimi:
	cout << "Type 'x' to close the terminal" << endl;
	cin >> end;

	if (end == 'x' || end == 'X')
		exit(1);
	else
		goto fillimi;

	int c;
	cin >> c;
	cout << c;
	return 0;
}