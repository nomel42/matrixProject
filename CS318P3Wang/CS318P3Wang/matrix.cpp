#ifndef MATRIX_CPP
#define MATRIX_CPP
#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdlib.h> 
using namespace std;

template<typename T>
matrix<T>  matrix<T>::t() const
{
	// You write code
	return matrix<T>(); //dummy return statement needs to be replaced
}

template <typename T>
const matrix<T> & matrix<T>::operator=(const matrix<T> & rhs)
{
	assert(this->numrows() == rhs.numrows() && this->numcols() == rhs.numcols());
	// You write code
	return matrix<T>(1, 1); //dummy return statement needs to be replaced
}

template<typename T>
const matrix<T> matrix<T>::operator+=(const matrix<T> & rhs) {
	assert(this->numrows() == rhs.numrows() && this->numcols() == rhs.numcols());
	// You write code
	return matrix<T>(1, 1); //dummy return statement needs to be replaced 
}

template<typename T>
const matrix<T> matrix<T>::operator+ (const matrix<T> & rhs) const {

	assert(this->numrows() == rhs.numrows() && this->numcols() == rhs.numcols());

	// You write code
	return matrix<T>(1, 1); //dummy return statement needs to be replaced 
}

template<typename T>
const matrix<T> matrix<T>::operator*= (const  T &c) {
	// You write code
	return matrix<T>(); //dummy return
}

template<typename T>
const matrix<T>  matrix<T>::operator* (const  T &c) const {
	// You write code
	return matrix(); //dummy return
}

template<typename T>
const matrix<T> matrix<T>::operator* (const matrix<T> & rhs)const {

	// You write code
	return matrix<T>(); //dummy return
}

template<typename T>
vector<T> matrix<T>::row(int k) const {
	// You write code
	return vector<T>(); //dummy return
}

template<typename T>
vector<T> matrix<T>::col(int k) const {
	// You write code
	return vector<T>(); //dummy return
}

template<typename T>
matrix<T> matrix<T>::deleteRow(int k) const {
	// You write code
	return matrix<T>(); //dummy return
}

template<typename T>
matrix<T> matrix<T>::deleteCol(int k) const {
	// You write code
	return matrix<T>(); //dummy return
}

template <typename T>
T matrix<T>::det_aux() {
	T sum;
	if (this->numrows() == 0)
		return 0;
	else if (this->numrows() == 1)
		return this->arr[0][0];
	else if (this->numrows() == 2)
		return this->arr[0][0] * this->arr[1][1]
		- this->arr[1][0] * this->arr[0][1];
	else {
		sum = T();
		for (int k = 0; k < this->numcols(); k++) {
			// You write code
		}
	}
	return sum;
}

template <typename T>
T matrix<T>::det()
{
	assert(this->numrows() == this->numcols());
	return this->det_aux();
}

template<typename T>
void matrix<T>::read(istream & in = cin) {

	int totalElements = numrows()*numcols();
	for (int i = 0; i < numrows(); i++)
		for (int j = 0; j < numcols(); j++)
			this->arr[i][j] = T();

	if (this->numrows() == 0) return;

	int numberOfElements = 0;
	while (numberOfElements < totalElements && in >> ws && !in.eof()) {
		T element;
		numberOfElements++;
		in >> element;
		this->arr[(numberOfElements - 1) / numcols()][(numberOfElements - 1) % numcols()] = element;
	}
}

template<typename T>
void matrix<T>::print(ostream & out = cout) const {
	for (int i = 0; i < numrows(); i++) {
		cout << this->arr[i][0];
		for (int j = 1; j < numcols(); j++)
			cout << " " << this->arr[i][j];
		cout << endl;
	}
}

template<typename T>
istream& operator >> (istream &  in, matrix<T> & rhs) {
	rhs.read(in);
	return in;
}

template<typename T>
ostream& operator<<(ostream & out, const  matrix<T> & rhs) {
	rhs.print(out);
	return out;
}

template<typename T>
T dot(const vector<T> & lvec, const vector<T> & rvec) {
	// You write code
	return T(); //dummy return
}

template<typename T>
matrix<T> eye(int n) {
	// You write code
	return matrix<T>(); //dummy return
}

template<typename T>
matrix<T> zeroes(int rows, int cols) {
	matrix<T> zeroesMat(rows, cols);
	// You write code
	return zeroesMat;
}

template<typename T>
matrix<T> ones(int rows, int cols) {
	matrix<T> onesMat(rows, cols);
	// You write code
	return onesMat;
}

#endif