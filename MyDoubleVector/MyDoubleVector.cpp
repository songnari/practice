#include "MyDoubleVector.h"
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

MyDoubleVector::MyDoubleVector() : storage(20), used(0) {
	//Postcondition: The MyDoubleVector has been initialized and it is empty
	data = new double[storage];
}

MyDoubleVector::MyDoubleVector(size_t storage) : storage(storage), used(0) {
	//Postcondition: The MyDoubleVector has been initialized and it is empty
	data = new double[storage];
}

MyDoubleVector::MyDoubleVector(const MyDoubleVector& v) : storage(v.storage), used(v.used) {
	//Postcondition: The MyDoubleVector has been initialized and it is filled with v
	data = new double[v.storage];
	copy(v.data, v.data + v.used, data);
}

MyDoubleVector::~MyDoubleVector() {
	if (data != nullptr) {
		delete[] data;
	}
}

MyDoubleVector & MyDoubleVector::operator=(const MyDoubleVector &v) {
	//Postcondition : Copy RHS object to LHS object.
	double *temp;

	if (this == &v) {
		return *this;
	}
	if (storage != v.storage) {
		temp = new double[v.storage];
		delete[] data;
		data = temp;
		storage = v.storage;
	}
	used = v.used;
	copy(v.data, v.data + v.used, data);
	return *this;
}

MyDoubleVector & MyDoubleVector::operator+=(const MyDoubleVector & v) {
	//Postconditon : Appends RHS object to LHS one.
	if (storage < used + v.used) {
		reserve(used + v.used);
	}

	copy(v.data, v.data + v.used, data + used);
	used += v.used;
	return *this;
}

double & MyDoubleVector::operator[](size_t i) const {
	//Postcondition : Returns a reference to the element at the requested position in the vector container.
	assert(i < used);

	return data[i];
}


MyDoubleVector operator+(const MyDoubleVector & v1, const MyDoubleVector & v2) {
	//Precondition : the sizes of the two operands is the same.
	//Postcondition : Returns a object that is a vector-sum of the two operand objects.
	assert(v1.used == v2.used);

	MyDoubleVector temp(v1.used);
	temp.used = v1.used;

	for (size_t i = 0; i < v1.used; i++)
		temp.data[i] = v1.data[i] + v2.data[i];

	return temp;
}

MyDoubleVector operator-(const MyDoubleVector & v1, const MyDoubleVector & v2) {
	//Precondition : the sizes of the two operands is the same.
	//Postcondition : Returns a object that is a vector-difference of the two operand objects.
	assert(v1.storage == v2.storage);
	MyDoubleVector temp(v1.used);
	temp.used = v1.used;

	for (size_t i = 0; i < v1.used; i++)
		temp.data[i] = v1.data[i] - v2.data[i];

	return temp;
}

MyDoubleVector operator*(const MyDoubleVector & v1, const MyDoubleVector & v2) {
	//Precondition : the sizes of the two operands is the same.
	//Postcondition : Returns the scalar product value of the two operand objects.
	assert(v1.storage == v2.storage);

	MyDoubleVector temp(v1.used);
	temp.used = v1.used;

	for (size_t i = 0; i < v1.used; i++)
		temp.data[i] = v1.data[i] * v2.data[i];

	return temp;
}

bool operator==(const MyDoubleVector & v1, const MyDoubleVector & v2) {
	//Postcondition : Returns whether or not the two operand vectors are the same.
	assert(v1.storage == v2.storage);
	assert(v1.used == v2.used);

	for (size_t i = 0; i < v1.used; i++) {
		if (v1.data[i] != v2.data[i])
			return false;
	}
	return true;
}

MyDoubleVector & MyDoubleVector::operator-() {
	//Postconditon : Returns a object of which each element is the negarive element.
	for (int i = 0; i < used; i++) {
		data[i] = data[i] * (-1);
	}

	return *this;
}

void MyDoubleVector::operator()(double value) {
	//Postcondition : Makes every element of this object be the vlaue of the real-valued operand.
	for (int i = 0; i < used; i++) {
		data[i] = value;
	}
}

void MyDoubleVector::pop_back() {
	//Precondition: The MyDoubleVector is not empty
	//Postcondition: Removes the last element in the vector
	if (used > 0) {
		--used;
	}
}

void MyDoubleVector::push_back(double x) {
	//Precondition:The vector is now full.
	//Postcondition: Adds a new element at the end of the vector, after its current last element
	if (used == storage) {
		cout << "push back Ferror : storage is full " << endl;
	}
	else if (used < storage) {
		data[used++] = x;
	}
}

void MyDoubleVector::reserve(size_t n) {
	//Precondition:n is positive number
	//Postcondition: Resize storage at least enough to hold n elements.
	double *temp;

	if (storage == n) {
		return;
	}
	if (n < used) {
		n = used;
	}

	temp = new double[n];
	copy(data, data + used, temp);
	delete[] data;
	data = temp;
	storage = n;
}

void MyDoubleVector::clear() {
	//Postconditon : All the elements of the vector are dropped
	delete[] data;
	data = nullptr;
	used = 0;
}

size_t MyDoubleVector::capacity() const {
	//Postcondition: Returns the size of the allocated storage space
	return storage;
}

size_t MyDoubleVector::size() const {
	//Postcondition: Returns the number of elements in the vector container
	return used;
}

bool MyDoubleVector::empty() const {
	//Postcondition : Returns whether the vector container is empty
	if (used == 0) {
		return true;
	}
	else {
		return false;
	}
}