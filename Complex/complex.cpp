#include "complex.hpp"
#include <cmath>
#include <iostream>

complex::complex() : re(0), im(0) {}
complex::complex (double num) : re(num), im(0) {}
complex::complex(double real, double imag) :
	re(real), im(imag) {}
complex::complex(complex const &num) :
	re(num.re), im(num.im) {}

complex complex::operator=(complex const &num)
{
	re = num.re;
	im = num.im;
	return *this;
}

complex complex::operator+(complex &cmp)
{
	complex z;
	z.re = re + cmp.re;
	z.im = im + cmp.im;
	return z;
}

complex complex::operator-(complex &cmp)
{
	complex z;
	z.re = re - cmp.re;
	z.im = im - cmp.im;
	return z;
}

complex complex::operator*(complex &cmp)
{
	return {re*cmp.re - im*cmp.im, re*cmp.im + im*cmp.re};
}

complex complex::operator^(double degree)
{
	complex z;
	double r = std::sqrt(re*re + im*im);
	double arg = std::atan(im/re);
	double dr = std::pow(r, degree);
	double cos = std::cos(degree * arg);
	double sin = std::sin(degree * arg);
	z.re = (double) (cos*dr);
	z.im = (double) (sin*dr);
	return z;
}

void complex::print_num()
{
	if(im < 0)
		std::cout << re << " - " << im*(-1) << 'i';
	else if(im > 0)
		std::cout << re << " + " << im << 'i';
	else
		std::cout << im;
	std::cout << '\n';
}

void complex::pair()
{
	im = im * (-1);
}

double complex::mod()
{
	return std::sqrt(re*re+im*im);
}

double complex::arg()
{
	return std::atan((double)im/(double)re);
}