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

	bool operator!(); // bo� mu dolu mu kontrol eder
	bool operator==(MyVector&); // iki vekt�r e�it mi de�il mi kontrol eder
	bool operator!=(MyVector&); // iki vekt�r e�it mi de�il mi kontrol eder

	int& operator[](int index);
	int operator[](int index) const;

	void setSize(const int size); // boyutu ayarlar
	int getSize() const; // boyutu d�nd�r�r

	MyVector& sort(MyVector&); // vekt�r� s�ralar
	MyVector& push_back(MyVector&, T a); // vekt�r�n sonuna ekler
	MyVector& push_up(MyVector&, T a); // vekt�r�n ba��na ekler

	T& select(MyVector&, int index); // vekt�r� s�ralay�p istenilen indisli de�eri d�nd�r�r.
	T& at(MyVector&, T& a, int index); // istenilen indise ekler
	

private:
	T* vect;
	int size;
};