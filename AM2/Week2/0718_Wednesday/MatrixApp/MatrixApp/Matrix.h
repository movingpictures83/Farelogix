#pragma once

#include <vector>
#include <iostream>
using std::vector;
using std::ostream;
using std::cout;
using std::endl;

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
	data = new T*[r];
	for (int i = 0; i < r; i++)
		data[i] = new T[c];
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
	return data[i][j];
}

template<class T>
const T& Matrix<T>::operator()(const int i, const int j) const {
	cout << "READ ONLY VERSION" << endl;
	return data[i][j];
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const {
	Matrix<T> retval(rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			retval.data[i][j] = data[i][j] + rhs.data[i][j];

	return retval;
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