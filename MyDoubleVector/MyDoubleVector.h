#pragma once
#include <cstdlib>

class MyDoubleVector {
public:
	MyDoubleVector(); //default constructor
	MyDoubleVector(size_t capacity);
	MyDoubleVector(const MyDoubleVector& v); //copy constructor for deep copy

	~MyDoubleVector(); //destructor

	//operator
	MyDoubleVector& operator =(const MyDoubleVector& v);
	MyDoubleVector& operator +=(const MyDoubleVector& v);
	double &operator [](size_t i) const;

	//binary operator
	friend MyDoubleVector operator +(const MyDoubleVector& v1, const MyDoubleVector& v2);  
	friend MyDoubleVector operator -(const MyDoubleVector& v1, const MyDoubleVector& v2);
	friend MyDoubleVector operator *(const MyDoubleVector& v1, const MyDoubleVector& v2);
	friend bool operator ==(const MyDoubleVector& v1, const MyDoubleVector& v2);
	
	//Unary operator
	MyDoubleVector& operator -();
	void operator ()(double value);

	void pop_back();//remove last element in the vector
	void push_back(double x); //adds a new element at the end of the vector.
	void reserve(size_t n); //requests that the capacity of the allocated storage sapce
	void clear(); //all the elements of the vector are dropped

	size_t capacity() const; //return the size of the allocated storage space
	size_t size() const; //return s the number of elements in the vector container.
	
	bool empty() const; //returns whether the vector container is empty

private:
	double *data;
	size_t storage;
	size_t used;
};