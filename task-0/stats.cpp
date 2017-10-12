/** Write a program that will prompt the user to input 10 integer values. The program will then identify and display the smallest, largest, most occuring number (with the count), and the average of 10 integers. **/

#include <iostream>
using namespace std;

void print_array(int array[])
{
	for (int i = 0; i < 10; ++i)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}


int get_min(int numbers[])
{
	int min = numbers[0];

	for (int i = 0; i < 10; ++i)
	{
		if (numbers[i] < min)
			min = numbers[i];
	}

	return min;
}

int get_max(int numbers[])
{
	int max = numbers[0];
	
	for (int i = 0; i < 10; ++i)
	{
		if (numbers[i] > max)
			max = numbers[i];
	}

	return max;
}

int get_max_index(int numbers[])
{
	int max = numbers[0];
	int max_index;
	for (int i = 0; i < 10; ++i)
	{
		if (numbers[i] > max)
			max = numbers[i];
			max_index = i;
	}

	return max_index;
}
	
int search_index(int numbers[], int n)
{
	for (int i = 0; i < 10; ++i)
	{
		if (numbers[i] == n) 
			return i;
	}
	return -1;
}


int most_occuring(int numbers[])
{
	int counter[10];

	for (int i = 0; i < 10; ++i)
		counter[i] = 0;

	for (int j = 0; j < 10; ++j)
	{
		//cout<<search_index(numbers,numbers[j])<<endl;

		++counter[search_index(numbers, numbers[j])];
	}

	//print_array(counter);

	return numbers[get_max_index(counter)];
}

int count_most_occuring(int numbers[], int n)
{
	int count = 0;

	for (int i = 0; i < 10; ++i)
	{
		if (numbers[i] == n)
			++count;
	}
	return count;
}
		

double get_average(int numbers[])
{
	double sum = 0;

	for (int i = 0; i < 10; ++i)
	{
		sum+= numbers[i];
	}
	return sum/10.0;

}
int main()
{
	int numbers[10] = {1,2,1,3,4,3,5,6,9,1};

	cout<<"Max: "<<get_max(numbers)<<endl;
	cout<<"Min: "<<get_min(numbers)<<endl;
	
	int most_occurings = most_occuring(numbers);
	cout<<"Most Occuring: "<<most_occuring(numbers)<<" |count: "<<count_most_occuring(numbers,most_occurings)<<endl;
	
	cout<<"Average: "<<get_average(numbers)<<endl;
	
	return 0;
}
