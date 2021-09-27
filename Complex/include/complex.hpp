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
	complex operator+(complex const &cmp) const;
	complex operator-(complex const &cmp) const;
	complex operator*(complex const &cmp) const;
	complex operator/(complex const &cmp) const;

	complex & operator+=(complex const &cmp);
	complex & operator-=(complex const &cmp);
	complex & operator/=(complex const &cmp);
	complex & operator*=(complex const &cmp);

	complex & operator-();
	complex & operator+();

	complex operator^(double degree) const;
	complex pair() const;

	bool operator==(complex const &cmp);
	bool operator!=(complex const &cmp);

	void print_num();
	double mod();
	double arg();
};
#endif