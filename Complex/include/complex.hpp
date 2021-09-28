#ifndef COMPLEX_INCLUDE_COMPLEX_HPP
#define COMPLEX_INCLUDE_COMPLEX_HPP

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

	complex & operator+=(complex const &cmp);
	complex & operator-=(complex const &cmp);
	complex & operator/=(complex const &cmp);
	complex & operator*=(complex const &cmp);

	complex & operator-();
	complex & operator+();

	bool operator==(complex const &cmp) const;
	bool operator!=(complex const &cmp) const;

	complex operator^(double degree);
	complex pair() const;

	void print_num();
	double mod();
	double arg();
};

complex operator+(complex const &cmp1, complex const &cmp2);
complex operator-(complex const &cmp1, complex const &cmp2);
complex operator*(complex const &cmp1, complex const &cmp2);
complex operator/(complex const &cmp1, complex const &cmp2);
#endif