#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

template <typename BidirectionalIterator>
void my_reverse(BidirectionalIterator first, BidirectionalIterator last) 
{
	--last;

	while(distance(first,last) > 0)
	{
		swap(*first, *last);

		++first;
		--last;
	}
}

int small_rand(void)
{
	return 1 + rand() % 100;
}

void test(int size)
{
	cout << "size : " << size << endl;
	if(size < 1) return;

	vector<int> values(size); 
	generate(values.begin(), values.end(), small_rand);

	copy(values.begin(), values.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	my_reverse(values.begin(), values.end());
	
	copy(values.begin(), values.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	test(0);
	test(1);
	test(17);
	test(20);

	return 0;
}



