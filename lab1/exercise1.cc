#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

int small_rand(void)
{
	return 1 + rand() % 100;
}

int main()
{
	vector<int> values(100); 

	generate(values.begin(), values.end(), small_rand);
	copy(values.begin(), values.end(), ostream_iterator<int>(cout, ", ")); 

	cout << endl;

	return 0;
}
