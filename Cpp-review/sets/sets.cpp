/* Review of sets in C++. */

#include<iostream>
using namespace std;
#include <set>
#include<vector>

/*TODO: compute the intersection of two sets: E.g., intersection of {2,3,4,5,6,7,} and {1,2,4,7,11,44} is {2,4,7}*/

set<int> intersect(const set<int>& s1, const set<int>& s2) 
{
	set<int> intersection;
	
	for(set<int>::iterator i = s1.begin(); i!= s1.end(); ++i)
	{
		for(set<int>::iterator j = s2.begin(); j!=s2.end(); ++j)
		{
			if (*i == *j)
			{
				intersection.insert(*i);
			}
		}
	}


	return intersection;
}

/* TODO: write a function that returns the union of two sets */
set<int> Union(const set<int>& s1, const set<int>& s2) 
{
	set<int> uni;

	for(set<int>::iterator i = s1.begin(); i!=s1.end(); ++i)
	{
		uni.insert(*i);
	}

	for(set<int>::iterator j = s2.begin(); j!=s2.end(); ++j)
	{
		uni.insert(*j);
	}
	
	return uni;
}

/* TODO: emulate the insert function for the set, but for a vector.
 * That is, write a function that takes a vector (say of integers)
 * and a single integer x, and adds x to the vector *only if it was
 * not already present*. You can return a boolean indicating whether
 * or not x insertion took place. */

bool vector_insert(vector<int> V, int n)
{
	/*we can search the vector and see if the element is already there.
	 * If there, return false. If not, insert into vector and return true*/
	//bool found = false;

	for (int i = 0; i < V.size(); ++i)
		{
			if(V[i] == n)
				return false;
		}
	V.push_back(n);

	return true;
}

void print_set(const set<int>& s) 
{
	cout<<"{ ";
	for(set<int>::iterator i = s.begin(); i != s.end(); ++i)
	{
		cout<<*i<<" ";
	}
	cout<<"} ";
	cout<<endl;
}

int main()
{
	set<int> s1 = {2,3,4,5,6,7};
	set<int> s2 = {1,2,4,7,11,44};
	set<int> s3 = intersect(s1,s2);
	set<int> s4 = Union(s1,s2);
	print_set(s3);
	print_set(s4);

	vector<int> V = {1,2,3,4};
	int n = 6;

	cout<<vector_insert(V,n)<<endl;
	return 0;
}
