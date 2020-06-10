#pragma once
#include <iostream>
template <class T>
class MyVector
{
	friend std::ostream& operator<<(std::ostream out, const MyVector& vect);
	//friend std::istream& operator>>(std::istream in, MyVector& vect);

public:
	MyVector(); // default constuctor
	MyVector(const T& vect, const int size);
	MyVector(int size);

	MyVector(const MyVector&); // copy constuctor
	MyVector& operator=(MyVector&); //copy assignment operator

	~MyVector(); // destructor

	MyVector(const MyVector&&); // move constructor
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

template<class T>
inline MyVector<T>::MyVector()
{
	size = 0;
}

template<class T>
MyVector<T>::MyVector(T& vect, const int size)
{
	if (size < 0)
		throw std::invalid_argument("index must be bigger than 0");
	
	else if (size == 0)
		MyVector();
	
	else if (size == 1)
	{
		this->vect = new T[2];
		this->size = size;
		this->vect[0] = vect;
		this->vect[1] = '\0';
	}
	
	else if (size > 1)
	{

	}
}

template<class T>
inline MyVector<T>::MyVector(int size)
{
}


