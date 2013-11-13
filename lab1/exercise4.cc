#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <ext/functional>

using namespace std;
using namespace __gnu_cxx;

int main()
{
	vector<int> v;

      	v.push_back(1);
     	v.push_back(4);
     	v.push_back(2);
      	v.push_back(8);
      	v.push_back(5);
      	v.push_back(7);

      	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
      	cout << endl;

	// compose1(x) = ((x % 2) == 0) 
      	vector<int>::iterator new_end = 
              remove_if(v.begin(), v.end(), 
                        compose1(bind2nd(equal_to<int>(), 0),   // x == 0
                                 bind2nd( modulus<int>(), 2))); // x % 2

	// the code used :v.end() insted of :new_end
	// thats why it printed all the vector and not just the range we wanted
      	copy(v.begin(), new_end , ostream_iterator<int>(cout, " "));
      	cout << endl;

	return 0;
}
