/*Write a program to compute factorial of numbers between 1 and 10 using the following recursive function: n! = 1 if n = 0; (n-1)! * n if n >0 **/

#include <iostream>
using namespace std;

int fact(int n)
{
	if (n == 0)
		return 1;
	else {
		//cout<<n*(n-1)<<endl;
		return fact(n - 1)*n;
			
	}
}


int main()
{
	for (int i = 1; i < 11; ++i)
		cout<<fact(i)<<endl;


	return 0;
}

