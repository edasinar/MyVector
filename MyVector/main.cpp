#include <iostream>
#include "MyVector.h"

int main()
{
	int a[5] = { 1,2,3,4,5 };
	
	MyVector<int> v1(5);
	
	for (int i = 0; i < 5; ++i)
	{
		v1[i] = a[i];
	}
	v1.print();

	std::cout << std::endl << "###############################" << std::endl;
	v1.push_back(7);
	v1.push_back(19);
	v1.print();
	std::cout << std::endl << "###############################" << std::endl;
	v1.push_up(-3);
	v1.print();
	std::cout << std::endl << "###############################" << std::endl;
	
	/*v1.at(v1, 2, 19);
	v1.print();
	std::cout << std::endl << "###############################" << std::endl;*/

	return 0;
}