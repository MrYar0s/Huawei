#include "../include/complex.hpp"

complex::complex() :
	re(0), im(0) {}

complex::complex (double num) :
	re(num), im(0) {}

complex::complex(double real, double imag) :
	re(real), im(imag) {}


complex::complex(complex const &num) :
	re(num.re), im(num.im) {}

complex::~complex()
{
	re = 0;
	im = 0;
}

complex complex::operator=(complex const &cmp)
{
	re = cmp.re;
	im = cmp.im;
	return *this;
}

complex operator+(complex const &cmp1, complex const &cmp2)
{
	complex z;
	z.re = cmp1.re + cmp2.re;
	z.im = cmp1.im + cmp2.im;
	return z;
}

complex operator-(complex const &cmp1, complex const &cmp2)
{
	complex z;
	z.re = cmp1.re - cmp2.re;
	z.im = cmp1.im - cmp2.im;
	return z;
}

complex operator*(complex const &cmp1, complex const &cmp2)
{
	complex z;
	z.re = cmp1.re*cmp2.re - cmp1.im*cmp2.im;
	z.im = cmp1.re*cmp2.im + cmp1.im*cmp2.re;
	return z;
}

complex operator/(complex const &cmp1, complex const &cmp2)
{
	complex z;
	complex paired = cmp2.pair();
	complex real = cmp2 * paired;
	double denom = real.re;
	complex numer = cmp1 * paired;
	z.re = numer.re/denom;
	z.im = numer.im/denom;
	return z;
}

complex & complex::operator+=(complex const &cmp)
{
	re += cmp.re;
	im += cmp.im;
	return *this;
}

complex & complex::operator-=(complex const &cmp)
{
	re -= cmp.re;
	im -= cmp.im;
	return *this;
}

complex & complex::operator/=(complex const &cmp)
{
	complex paired = cmp.pair();
	complex real = cmp * paired;
	double denom = real.re;
	complex numer = *this * paired;
	re = numer.re/denom;
	im = numer.im/denom;
	return *this;
}

complex & complex::operator*=(complex const &cmp)
{
	double real = re;
	double imag = im;
	re = real*cmp.re - imag*cmp.im;
	im = real*cmp.im + imag*cmp.re;
	return *this;
}

complex & complex::operator-()
{
	re = -re;
	im = -im;
	return *this;
}

complex & complex::operator+()
{
	return *this;
}


bool complex::operator==(complex const &cmp) const
{
	if(re == cmp.re && im == cmp.im)
		return true;
	return false;
}

bool complex::operator!=(complex const &cmp) const
{
	if(re != cmp.re || im != cmp.im)
		return true;
	return false;
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

complex complex::operator^(double degree)
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

double complex::mod()
{
	return std::sqrt(re*re+im*im);
}

double complex::arg()
{
	return std::atan((double)im/(double)re);
}