/** Task 0: Write a program to print the numbers between 1 and 1-, along with an indication of whether each is even or odd. **/

#include <iostream>
using namespace std;

void print_numbers(int a[])
{
	for (int i = 0; i < 10; ++i)
	{
		cout<<a[i]<<" "<<"\n";
	}
}

void get_even(int a[])
{
	for (int i = 0; i < 10; ++i)
	{
		if (a[i]%2 == 0)
			cout<<a[i]<<" ";
	}
	cout<<endl;
}

void get_odd(int a[])
{
	for (int i = 0; i < 10; ++i)
		{
			if (a[i]%2 != 0)
				cout<<a[i]<<" ";
		}
	cout<<endl;
}




int main()
{
	int a[10] = {1, 2, 3, 5, 6, 7, 8, 9, 10};
	//cout<<a<<endl;
	int n;
	
	/*for (int i = 0; i < 10; ++i)
	{
		cin>>n;
		a[i] = n;
	}*/
	
	//print_numbers(a);
	cout<<"Even: ";
	get_even(a);
	cout<<endl;

	cout<<"Odd: ";
	get_odd(a);
	cout<<endl;

	return 0;

}


