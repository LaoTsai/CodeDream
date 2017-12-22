#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T>
void print_item(T item)
{
	cout << item << " ";
}

void (*pout)(int) = print_item;

int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	list<int> ilist(a, a+7);

	for_each(ilist.begin(), ilist.end(), pout);
	cout << endl;

	ilist.push_back(8);
	ilist.push_back(9);

	for_each(ilist.begin(), ilist.end(), pout);
	cout << endl;

	ilist.remove_if(bind2nd(modulus<int>(), 2));
	ilist.remove_if(bind2nd(modulus<int>(), 2));

	for_each(ilist.begin(), ilist.end(), pout);
	cout << endl;

	return 0;
}
