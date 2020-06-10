#pragma once
#include <iostream>
#include <random>

template <class T>
class MyVector
{
	//template <class T>
	friend std::ostream& operator<<(std::ostream out, const MyVector<T>& other)
	{
		for (auto i = 0; i < other.size; ++i)
			out << other.vect[i] << "-";

		std::cout << std::endl;

		return out;
	}

public:
	MyVector(); // default constuctor
	MyVector(const T* vect, const int size);
	MyVector(int size);

	MyVector(const MyVector&); // copy constuctor
	T& operator=(const MyVector&); //copy assignment operator

	~MyVector(); // destructor

	//MyVector(const MyVector&&); // move constructor
	//MyVector& operator=(MyVector&&); // move assignment operator

	bool operator!(); // boþ mu dolu mu kontrol eder
	bool operator==(MyVector&); // iki vektör eþit mi deðil mi kontrol eder
	bool operator!=(MyVector&); // iki vektör eþit mi deðil mi kontrol eder

	T& operator[](int index);
	T operator[](int index) const;

	void setSize(const int size); // boyutu ayarlar
	int getSize() const; // boyutu döndürür

	MyVector& sort(MyVector&); // vektörü sýralar
	MyVector& push_back(const MyVector&, T a); // vektörün sonuna ekler
	MyVector& push_up(MyVector&, T a); // vektörün baþýna ekler

	T& random_select(MyVector&); // vektörde random bir indis seçer
	T& at(MyVector&, T a, int index); // istenilen indise ekler
	

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
MyVector<T>::MyVector(const T* vect, const int size)
{
	if (size < 0)
		throw std::invalid_argument("index must be bigger than 0");
	
	else if (size == 0)
		MyVector();
	
	else if (size == 1)
	{
		this->vect = new T;
		this->size = size;
		this->vect = vect;
	}
	
	else if (size > 1)
	{
		this->vect = new T[size];
		this->size = size;
		for (auto i = 0; i < size; ++i)
		{
			this->vect[i] = vect[i];
		}
	}
}

template<class T>
inline MyVector<T>::MyVector(int size)
{
	if (size < 0)
		throw std::invalid_argument("index must be bigger than 0");
	else if (size == 0)
		MyVector();
	else if (size == 1)
	{
		vect = new T;
		this->size = size;
	}
	else if (size > 1)
	{
		vect = new T[size];
		this->size = size;
	}
}

template<class T>
inline MyVector<T>::MyVector(const MyVector& other)
{
	size = other.size;
	vect = new T[other.size];
	for (auto i = 0; i < other.size; ++i)
		vect[i] = other.vect[i];
}

template<class T>
inline T& MyVector<T>::operator=(const MyVector& other)
{
	size = other.size;
	vect = new T[other.size];
	for (auto i = 0; i < other.size; ++i)
		vect[i] = other.vect[i];

	return *this;
}

template<class T>
 MyVector<T>::~MyVector()
{
	 if (size == 1)
		 delete vect;
	 else if (size > 1)
		 delete[] vect;
}

 template<class T>
 inline bool MyVector<T>::operator!()
 {
	 if (size == 0)
		 return false;
	 else
		 return true;
 }

 template<class T>
 inline bool MyVector<T>::operator==(MyVector& other)
 {
	 if (size != other.size)
		 return false;
	 else
	 {
		 for (auto i = 0; i < size; ++i)
			 if (vect[i] != other.vect[i])
				 return false;

		 return true;
	 }

	 return true;
 }

 template<class T>
 inline bool MyVector<T>::operator!=(MyVector&)
 {
	 return !*this;
 }

 template<class T>
 inline T& MyVector<T>::operator[](int index)
 {
	 return vect[index];
 }

 template<class T>
 inline T MyVector<T>::operator[](int index) const
 {
	 return vect[index];
 }

 template<class T>
 inline void MyVector<T>::setSize(const int size)
 {
	 if (size < 0)
		 throw std::invalid_argument("index must be bigger than 0");
	 else
		 this->size = size;
 }

 template<class T>
 inline int MyVector<T>::getSize() const
 {
	 return size;
 }

 template<class T>
 inline MyVector<T>& MyVector<T>::sort(MyVector& other)
 {
	 for (auto i = 0; i < other.size; ++i)
	 {
		 for (auto j = i; j < other.size; ++j)
		 {
			 if (other.vect[j + 1] < other.vect[j])
			 {
				 T temp = other.vect[j];
				 other.vect[j] = other.vect[j + 1];
				 other.vect[j + 1] = temp;
			 }
		 }
	 }
 }

 template<class T>
 inline MyVector<T>& MyVector<T>::push_back(const MyVector& other, T a)
 {
	 int temp_size = other.size + 1;
	
	 T* temp = new T[temp_size];
	
	 for (auto i = 0; i < other.size; ++i)
	 {
		 temp[i] = other.vect[i];
	 }
	
	 if (other.size == 1)
		 delete other.vect;
	 else if (other.size > 1)
		 delete[] other.size;

	 temp[temp_size] = a;

	other.vect = new T[temp_size];
	 
	for (auto i = 0; i < temp_size; ++i)
	 {
		 other.vect[i] = temp[i];
	 }
	other.size = temp_size;
	 return *this;
 }

 template<class T>
 inline MyVector<T>& MyVector<T>::push_up(MyVector& other, T a)
 {
	 int temp_size = other.size + 1;
	
	 T* temp = new T[other.size];
	
	 for (auto i = 0; i < other.size; ++i)
		 temp[i] = other.vect[i]; 

	 if (other.size == 1)
		 delete other.vect;
	 else if (other.size > 1)
		 delete[] other.size;

	 other.vect = new T[temp_size];

	 other.vect[0] = a;

	
	 for (auto i = 1; i <= temp_size; ++i)
	 {
		 other.vect[i] = temp[i - 1];
	 }
	 other.size = temp_size;
	 return *this;
 }

 template<class T>
 inline T& MyVector<T>::random_select(MyVector& other)
 {
	 int temp;
	
	 std::random_device rd;
	 std::uniform_real_distribution<double> dist(0.0, 100.0);
	 std::mt19937 mist(rd());
	 temp = dist(mist);

	 return other.vect[temp];
 }

 template<class T>
 inline T& MyVector<T>::at(MyVector& other, T a, int index)
 {
	 int temp_size = other.size + 1;

	 T* temp = new T[other.size];

	 for (auto i = 0; i < other.size; ++i)
		 temp[i] = other.vect[i];

	 if (other.size == 1)
		 delete other.vect;
	 else if (other.size > 1)
		 delete[] other.vect;

	 other.size = new T[temp_size];
	 for (auto i = 0; i < index; ++i)
		 other.vect[i] = temp[i];

	 other.vect[index] = a;

	 for (auto j = index + 1; j < temp_size; ++j)
		 other.vect[j] = temp[j - 1];

 }
