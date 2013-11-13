#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

struct mod2counter: public unary_function<int, void> 
{ 
 	int c_odd; 
	int c_even;

 	mod2counter() : c_odd(0), c_even(0) { } 

 	void operator()(int x) { 
		if(x%2 == 1)  ++c_odd; 
		else          ++c_even; 
	} 
}; 

int small_rand(void)
{
	return 1 + rand() % 100;
}

int main()
{
	vector<int> values(100); 

	generate(values.begin(), values.end(), small_rand);

	mod2counter result = for_each(values.begin(), values.end(), mod2counter()); 

	cout << "there are " << values.size() << " numbers in the vector" << endl; 
	cout << "there are " << result.c_odd  << " odd  numbers" << endl; 
	cout << "there are " << result.c_even << " even numbers" << endl; 

	return 0;
}


