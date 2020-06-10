#include <iostream>
#include "MyVector.h"

int main()
{
	int a[5] = { 1,2,3,4,5 };
	
	MyVector<int> v1(a, 5);

	std::cout << v1;

	

	return 0;
}