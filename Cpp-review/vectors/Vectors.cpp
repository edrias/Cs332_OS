#include <iostream>
using namespace std;
#include <vector>

/* TODO: write a *binary search* on a sorted vector.  The idea is to
 * kind of emulate the process you use to find a particular page in a book:
 * 1. open the book to some page in the middle.
 * 2. if the page number was too high, open to the middle of the pages to the
 *    left; if it was too low, open to the middle of the pages to the right
 * 3. continue as above until you found the right page.
 *
 */

bool binary_search(const vector<int>& V, int n) {
	
	int mid = V.size()/2;
	
	vector<int> tmp;

	if (V[mid] == n)
		return true;
	
	if (mid == 1) 
		return false;

	else if (n > V[mid]){
		for (int i = mid + 1; i < V.size(); ++i)
			tmp.push_back(V[i]);

		return binary_search(tmp,n);
	}
	else {
		for (int i = 0; i < mid; ++i) {
			tmp.push_back(V[i]);
		}
		return binary_search(tmp,n);
	}
	return false;
}



/* TODO: write a function that takes a vector and places the elements
 * in sorted order.*/

void sort_vector(const vector<int>& V) {
	
}

void print_vect(vector<int> V) {
	for (int i = 0; i < V.size(); ++i)
	{
		cout<<V[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	vector<int> V;
	
	for (int i = 0; i < 2; ++i)
	{
		V.push_back(i);
	}
	print_vect(V);
	
	cout<<binary_search(V,2)<<endl;
	


	return 0;
}
