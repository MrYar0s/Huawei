#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <cmath>
#include <iostream>

struct complex
{
	double re;
	double im;	

	complex();
	complex(double num);
	complex(double real, double imag);
	complex(complex const &num);
	~complex();

	complex operator=(complex const &cmp);
	friend complex operator+(complex const &cmp1, complex const &cmp2);
	friend complex operator-(complex const &cmp1, complex const &cmp2);
	friend complex operator*(complex const &cmp1, complex const &cmp2);
	friend complex operator/(complex const &cmp1, complex const &cmp2);

	complex & operator+=(complex const &cmp);
	complex & operator-=(complex const &cmp);
	complex & operator/=(complex const &cmp);
	complex & operator*=(complex const &cmp);

	complex & operator-();
	complex & operator+();

	bool operator==(complex const &cmp);
	bool operator!=(complex const &cmp);

	complex operator^(double degree) const;
	complex pair() const;

	void print_num();
	double mod();
	double arg();
};
#endif