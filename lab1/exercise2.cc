#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

string abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

string rand_string(void)
{
	string str = "";

	int size = abc.length();
	int len  = 5 + rand() % 10;

	while ((len--) > 0) str += abc[rand() % size];

	return str;
}

int main()
{
	vector<string> values(100); 

	generate(values.begin(), values.end(), rand_string);

	// using default comparison (operator <)
	sort (values.begin(), values.end());

	copy(values.begin(), values.end(), ostream_iterator<string>(cout, ", ")); 

	cout << endl;

	return 0;
}



