// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using std::cout;
using std::endl;

template<class T>
void addCheck(T& result, T op1, T op2) {
	int tmp = op1 + op2;
	int overflow = ~(op1^op2) & (tmp^op1);
	if (overflow < 0) cout << "WARNING: OVERFLOW DETECTED, RESULT UNCHANGED" << endl;
	else result = tmp;
}

bool sameSign(int a, int b) {
	return ((a^b) >= 0);
}

bool isOdd(int a) {
	return (a & 1);
}

// Euclid's Algorithm, Recursive
// gcd(a, b) = a    (if b=0 or a=b)
//             b    (if a=0)
//             gcd(a/2, b/2)  (if a and b are even)
//             gcd(a/2, b)    (if a is even and b is odd)
//             gcd(a, b/2)    (if a is odd and b is even)
//             gcd(a-b, b)    (if a and b are odd and a > b)
//             gcd(a, b-a)    (if a and b are odd and a <= b)
int gcd(int a, int b)
{
	if (!b || !(a^b)) return a;
	else if (!a) return b;
	else if ((!(a & 1)) && (!(b & 1))) return gcd(a >> 1, b >> 1) << 1;
	else if ((!(a & 1)) && (b & 1)) return gcd(a >> 1, b);
	else if ((a & 1) && (!(b & 1))) return gcd(a, b >> 1);
	else if (a > b) return gcd(a - b, b);
	else return gcd(a, b - a);
}


bool cmpNoCase(const char* s1, const char* s2) {
	while (*s1 && *s2) {
		if ((*s1++ ^ *s2++) & ~32) return false;
	}
	return true;
}

void toLower(char* t, const char* s) {
	while (*s) {
		*t = *s++ | 32;
		t++;
	}
	*t = '\0';
}

void toUpper(char* t, const char* s) {
	while (*s) {
		*t = *s++ & ~32;
		t++;
	}
	*t = '\0';
}

// These functions save if statements
// if statements can be costly (non-strictly sequential execution)
template<class T>  T min(T x, T y) {
	T tmp = x - y;
	return y + (tmp & (tmp >> (8 * sizeof(T) - 1)));
}

template<class T> T abs(T val) {
	int mask = val >> (sizeof(T) * 8 - 1);
	// If positive, add zero and XOR with zeroes (stays the same)
	// If negative, subtract one and XOR with ones (flips the bits)
	return ((val + mask) ^ mask); 
}



int main()
{
	// Optimization: Multiplication By Constant
	int x = 8;
	int y = (x << 2) + x; // y = x * 5, a little faster
	int z = (x << 3) + x; // y = x * 9
	cout << x << " " << y << " " << z << endl;


	// Check for overflow
	//int w = x + y; // Should not be too large
	//int overflow = ~(x^y) & (w^x);
	int w;
	addCheck(w, x, y); // w = x + y
	cout << "W SHOULD BE 48: " << w << endl;
	x = 1 << 30;
	y = 1 << 30;
	addCheck(w, x, y);
	cout << "W SHOULD STILL BE 48: " << w << endl;
	x = 1 << 31;
	y = 1 << 31;
	addCheck(w, x, y);
	cout << "W SHOULD STILL BE 48: " << w << endl;


	// Same signs
	w = 5;
	x = 8;
	y = -3;
	cout << "5 AND 8 SAME SIGN: " << sameSign(w, x) << endl;
	cout << "8 AND -3 SAME SIGN: " << sameSign(x, y) << endl;
	cout << "5 IS ODD:" << isOdd(w) << endl;
	cout << "8 IS ODD:" << isOdd(x) << endl;
	cout << "GCD OF 8 and 12:" << gcd(8, 12) << endl;

	// Swap two values
	// Minorly slower but saves one memory spot
	w = w ^ x;
	x = w ^ x;
	w = w ^ x;
	cout << "W: " << w << " X: " << x << endl;
	
	// Compare two strings, case insensitive
	cout << "COMPARE Trevor and Trevor: " << cmpNoCase("Trevor", "Trevor") << endl;
	cout << "COMPARE Trevor and treVor: " << cmpNoCase("Trevor", "treVor") << endl;
	cout << "COMPARE Trevor and Michel: " << cmpNoCase("Trevor", "Michel") << endl;

	// To upper and to lower case
	const char* name = "Trevor";
	char name2[7];
	char name3[7];
	toUpper(name2, name);
	cout << "Name in Uppercase: " << name2 << endl;
	toLower(name3, name);
	cout << "Name in Lowercase: " << name3 << endl;

	// Minimum element.  Note shift right must use arithmetic and not logical shift
	cout << "Min of 8 and 5: " << min(w, x) << endl;
	cout << "Absolute Value of -4: " << abs(-4) << endl;
	cout << "Absolute Value of +4: " << abs(4) << endl;

    return 0;
}

