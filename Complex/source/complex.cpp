#include "../include/complex.hpp"
#include <cmath>
#include <iostream>

#define ACCURACY 10e-6
bool is_zero(const double num)
{
	if(num >= -ACCURACY && num <= ACCURACY)
		return true;
	return false;
}

complex::complex() :
	re(0), im(0) {}
complex::complex(double real, double imag) :
	re(real), im(imag) {}
complex::complex(const complex &num) :
	re(num.re), im(num.im) {}
complex::~complex()
{
	re = 0;
	im = 0;
}

complex & complex::operator=(const complex &cmp)
{
	re = cmp.re;
	im = cmp.im;
	return *this;
}
complex & complex::operator=(double num)
{
	re = num;
	im = 0;
	return *this;
}

complex complex::operator+(const complex &cmp) const
{
	complex z;
	z.re = re + cmp.re;
	z.im = im + cmp.im;
	return z;
}
complex complex::operator-(const complex &cmp) const
{
	complex z;
	z.re = re - cmp.re;
	z.im = im - cmp.im;
	return z;
}
complex complex::operator*(const complex &cmp) const
{
	complex z;
	z.re = re*cmp.re - im*cmp.im;
	z.im = re*cmp.im + im*cmp.re;
	return z;
}
complex complex::operator/(const complex &cmp) const
{
	complex z = *this;
	double real = cmp.re;
	double imag = cmp.im;
	z *= cmp.pair()/(real*real+imag*imag);
	return z;
}

complex complex::operator+(double num) const
{
	complex z;
	z.re = num + re;
	z.im = im;
	return z;
}
complex complex::operator-(double num) const
{
	complex z;
	z.re = re - num;
	z.im = im;
	return z;
}
complex complex::operator*(double num) const
{
	complex z;
	z.re = num*re;
	z.im = num*im;
	return z;
}
complex complex::operator/(double num) const
{
	complex z;
	z.re = re/num;
	z.im = im/num;
	return z;
}

complex & complex::operator+=(const complex &cmp)
{
	re += cmp.re;
	im += cmp.im;
	return *this;
}
complex & complex::operator-=(const complex &cmp)
{
	re -= cmp.re;
	im -= cmp.im;
	return *this;
}
complex & complex::operator*=(const complex &cmp)
{
	double real = re;
	double imag = im;
	re = real*cmp.re - imag*cmp.im;
	im = real*cmp.im + imag*cmp.re;
	return *this;
}
complex & complex::operator/=(const complex &cmp)
{
	double real = cmp.re;
	double imag = cmp.im;
	*this *= cmp.pair()/(real*real + imag*imag);
	return *this;
}

complex & complex::operator+=(double num)
{
	re += num;
	return *this;
}
complex & complex::operator-=(double num)
{
	re -= num;
	return *this;
}
complex & complex::operator*=(double num)
{
	double real = re;
	double imag = im;
	re = num*real;
	im = num*imag;
	return *this;
}
complex & complex::operator/=(double num)
{
	re = re/num;
	im = im/num;
	return *this;
}

complex complex::operator-() const
{
	complex z;
	z.re = (-1)*re;
	z.im = (-1)*im;
	return z;
}

bool complex::operator==(const complex &cmp) const
{
	if(is_zero(re - cmp.re) && is_zero(im - cmp.im))
		return true;
	return false;
}
bool complex::operator!=(const complex &cmp) const
{
	if(!is_zero(re - cmp.re) || !is_zero(im - cmp.im))
		return true;
	return false;
}

bool complex::operator==(double num) const
{
	if(is_zero(re - num) && is_zero(im))
		return true;
	return false;
}
bool complex::operator!=(double num) const
{
	if(!is_zero(re - num) || !is_zero(im))
		return true;
	return false;
}

complex complex::operator^(double degree) const
{
	complex z;
	double r = std::sqrt(re*re + im*im);
	double arg = std::atan(im/re);
	double dr = std::pow(r, degree);
	double cos = std::cos(degree * arg);
	double sin = std::sqrt(1 - cos*cos);
	z.re = (double) (cos*dr);
	z.im = (double) (sin*dr);
	return z;
}
complex complex::pair() const
{
	complex z;
	z.im = im * (-1);
	z.re = re;
	return z;
}

void complex::info() const
{
	if(im < 0)
		std::cout << re << " - " << im*(-1) << 'i';
	else if(im > 0)
		std::cout << re << " + " << im << 'i';
	else
		std::cout << re;
	std::cout << '\n';
}
double complex::mod() const
{
	return std::sqrt(re*re+im*im);
}
double complex::arg() const
{
	return std::atan((double)im/(double)re);
}

complex operator+(double num, const complex &cmp)
{
	complex z;
	z.re = num + cmp.re;
	z.im = cmp.im;
	return z;
}
complex operator-(double num, const complex &cmp)
{
	complex z;
	z.re = num - cmp.re;
	z.im = -cmp.im;
	return z;
}
complex operator*(double num, const complex &cmp)
{
	complex z;
	z.re = num*cmp.re;
	z.im = num*cmp.im;
	return z;
}
complex operator/(double num, const complex &cmp)
{
	complex z{num, 0};
	z /= cmp;
	return z;
}

bool operator==(double num, const complex &cmp)
{
	if(is_zero(num - cmp.re) && is_zero(cmp.im))
		return true;
	return false;
}
bool operator!=(double num, const complex &cmp)
{
	if(!is_zero(num - cmp.re) || !is_zero(cmp.im))
		return true;
	return false;
}