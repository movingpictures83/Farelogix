#pragma once

#include <vector>
#include <iostream>
#include <exception>
#include <string>
using std::vector;
using std::ostream;
using std::cout;
using std::endl;
using std::out_of_range;
using std::logic_error;
using std::to_string;

#include "InvalidDimensionException.h"

template<class T>
class Matrix {
private:
	T** data;
	int rows, cols;
public:
	Matrix(const int r, const int c);
	Matrix(const Matrix<T>& rhs);
	~Matrix();
	T& operator()(const int i, const int j);
	const T& operator()(const int i, const int j) const;
	Matrix<T> operator+(const Matrix<T>& rhs) const;
	Matrix<T>& operator=(const Matrix<T>& rhs);
	
	template<class U>
	friend ostream& operator<<(ostream& this2, const Matrix<U>& rhs);
};

template<class T>
Matrix<T>::Matrix(const int r, const int c) : rows(r), cols(c) {
	try {
		data = new T*[r];
		for (int i = 0; i < r; i++)
			data[i] = new T[c];
	}
	catch (std::bad_array_new_length e) {
		cout << "[Matrix] Matrix(): Cannot initialize array with negative size" << endl;
		exit(1);
	}
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& rhs) {
	rows = rhs.rows;
	cols = rhs.cols;
	data = new T*[rows];
	for (int i = 0; i < rows; i++)
		data[i] = new T[cols];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			data[i][j] = rhs.data[i][j];
}

template<class T>
Matrix<T>::~Matrix() {
	for (int i = 0; i < rows; i++)
		delete data[i];
	delete data;
}

template<class T>
T& Matrix<T>::operator()(const int i, const int j) {
	cout << "READ/WRITE" << endl;
	try {
		if (i < 0 || j < 0 || i >= rows || j >= cols)
			throw out_of_range("[Matrix] operator(): Index " + to_string(i) + "," + to_string(j) + " out of range.");
		return data[i][j];
	}
	catch (out_of_range e) {
		cout << e.what() << endl;
		exit(1); // Exits the program, error code 1
	}
}

template<class T>
const T& Matrix<T>::operator()(const int i, const int j) const {
	cout << "READ ONLY VERSION" << endl;

	try {
		if (i < 0 || j < 0)
			throw out_of_range("[Matrix] operator(): Index " + to_string(i) + "," + to_string(j) + " out of range.");
		else if (i >= rows || j >= cols)
			throw logic_error("[Matrix] operator(): Index " + to_string(i) + "," + to_string(j) + " out of range.");
		return data[i][j];
	}
    // From most specific to least specific
	catch (out_of_range e) {
		cout << e.what() << endl;
		exit(1); // Exits the program, error code 1
	}
	catch (logic_error e) {
		cout << e.what() << endl;
		return T();
	}
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const {
	try {
		if (rhs.rows != rows || rhs.cols != cols)
			throw InvalidDimensionException("Matrix", "+", rows, cols, rhs.rows, rhs.cols);
		Matrix<T> retval(rows, cols);

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				retval.data[i][j] = data[i][j] + rhs.data[i][j];

		return retval;
	}
	catch (InvalidDimensionException e) {
		cout << e.what() << endl;
		exit(1);
	}
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
	rows = rhs.rows;
	cols = rhs.cols;
	data = new T*[rows];
	for (int i = 0; i < rows; i++)
		data[i] = new T[cols];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			data[i][j] = rhs.data[i][j];
	return *this;
}

template<class U>
ostream& operator<<(ostream& this2, const Matrix<U>& rhs) {
	for (int i = 0; i < rhs.rows; i++) {
		this2 << "|";
		for (int j = 0; j < rhs.cols; j++)
			this2 << rhs.data[i][j] << " ";
		this2 << "|" << endl;
	}
	return this2;
}