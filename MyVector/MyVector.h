#pragma once
#include <iostream>
template <class T>
class MyVector
{
	friend std::ostream& operator<<(std::ostream out, MyVector& vect);
	//friend std::istream& operator>>(std::istream in, MyVector& vect);

public:
	MyVector(); // default constuctor
	MyVector(T& vect, int size);

	MyVector(MyVector&); // copy constuctor
	MyVector& operator=(MyVector&); //copy assignment operator

	~MyVector(); // destructor

	MyVector(MyVector&&); // move constructor
	MyVector& operator=(MyVector&&); // move assignment operator

	bool operator!(); // boþ mu dolu mu kontrol eder
	bool operator==(MyVector&); // iki vektör eþit mi deðil mi kontrol eder
	bool operator!=(MyVector&); // iki vektör eþit mi deðil mi kontrol eder

	int& operator[](int index);
	int operator[](int index) const;

	void setSize(const int size); // boyutu ayarlar
	int getSize() const; // boyutu döndürür

	MyVector& sort(MyVector&); // vektörü sýralar
	MyVector& push_back(MyVector&, T a); // vektörün sonuna ekler
	MyVector& push_up(MyVector&, T a); // vektörün baþýna ekler

	T& select(MyVector&, int index); // vektörü sýralayýp istenilen indisli deðeri döndürür.
	T& at(MyVector&, T& a, int index); // istenilen indise ekler
	

private:
	T* vect;
	int size;
};