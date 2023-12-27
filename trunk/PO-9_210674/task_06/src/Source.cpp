#include "Header.h"
#include <iostream>
using namespace std;
int main() {
	//char word[255] = "sad";
	char word[255];
	cout << "Enter word:" << endl;
	cin >> word;
	cout << endl;
	double v = sortAscendingg(word);

	cout << v << endl;

	return 0;
}