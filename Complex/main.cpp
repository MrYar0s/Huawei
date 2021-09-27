#include <cassert>
#include "complex.hpp"

const double ai = 7.3;
const double ar = -4.5;
const double br = -0.6;
const double bi = 11.3;

void void_init_test()
{
	complex a;
	assert(a.re == 0.0 && a.im == 0.0);
}

void init_test()
{
	complex b(br, bi);
	assert(b.re == br && b.im == bi);
}

void copy_init_test()
{
	complex b(br, bi);
	assert(b.re == br && b.im == bi);
	complex cp(b);
	assert(cp.re == b.re && cp.im == b.im);
}

void plus_test()
{
	complex a(ar, ai);
	complex b(br, bi);
	complex c = a + b;
	assert(c.re == a.re+b.re && c.im == a.im+b.im);
	assert(a.re == ar && a.im == ai);
	assert(b.re == br && b.im == bi);
}

void plus_test_num()
{
	complex a(ar, ai);
	complex c = a + 4;
	assert(c.re == a.re+4);
}

void sub_test()
{
	complex a(ar, ai);
	complex b(br, bi);
	complex d = a - b;
	assert(d.re == a.re-b.re && d.im == a.im-b.im);
}

void num_init_test()
{
	complex a;
	a = {ar, ai};
	assert(a.re == ar && a.im == ai);
}

void pair_test()
{
	complex a(ar, ai);
	complex b = a.pair();
	assert(b.re == a.re && b.im == a.im*(-1));
}

void mult_test()
{
	complex a(ar, ai);
	complex b(br, bi);
	complex mult = a * b;
	assert(a.re*b.re - a.im*b.im == mult.re);
	assert(a.re*b.im + a.im*b.re == mult.im);
}

void pow_test()
{
	double degree = 2.0;
	complex mult(ar, ai);
	complex power = mult^degree;
	double r = std::sqrt(mult.re*mult.re + mult.im*mult.im);
	double arg = std::atan(mult.im/mult.re);
	double dr = std::pow(r, degree);
	double cos = std::cos(degree * arg);
	double sin = std::sqrt(1 - cos*cos);
	assert((double) (cos*dr) == power.re);
	assert((double) (sin*dr) == power.im);
}

void mod_test()
{
	complex a(ar, ai);
	assert(a.mod() == std::sqrt(a.re*a.re+a.im*a.im));
}

void arg_test()
{
	complex a(ar, ai);
	assert(a.arg() == std::atan((double)a.im/(double)a.re));
}

void equal_test()
{
	complex a(ar, ai);
	complex c;
	c = a;
	assert(c.re == a.re && c.im == a.im);
}

void div_test()
{
	complex a(ar, ai);
	complex b(br, bi);

	complex c = a/b;

	complex paired = b.pair();
	complex real = b * paired;
	double denom = real.re;
	complex numer = a * paired;
	assert(c.re == numer.re/denom);
	assert(c.im == numer.im/denom);
}

void plus_eq_test()
{
	complex a(ar, ai);
	complex b(br, bi);
	b += a;
	assert(b.re == a.re + br && b.im == a.im + bi);
}

void sub_eq_test()
{
	complex a(ar, ai);
	complex b(br, bi);
	b -= a;
	assert(b.re == br - a.re && b.im == bi - a.im);
}

void mult_eq_test()
{
	complex a(ar, ai);
	complex b(br, bi);
	b *= a;
	assert(b.re == a.re*br-a.im*bi && b.im == a.re*bi+br*a.im);
}

void div_eq_test()
{
	complex a(ar, ai);
	complex b(br, bi);

	complex paired = a.pair();
	complex real = a * paired;
	double denom = real.re;
	complex numer = b * paired;
	double re = numer.re/denom;
	double im = numer.im/denom;
	
	b /= a;
	assert(b.re == re && b.im == im);
}

void unar_sub()
{
	complex a(ar, ai);
	a = -a;
	assert(a.re == -ar && a.im == -ai);
}

void unar_plus()
{
	complex a(ar, ai);
	a = +a;
	assert(a.re == ar && a.im == ai);
}

int main(int argc, char const *argv[])
{
	void_init_test();
	init_test();
	copy_init_test();
	plus_test();
	sub_test();
	num_init_test();
	pair_test();
	mult_test();
	pow_test();
	mod_test();
	arg_test();
	equal_test();
	div_test();
	plus_eq_test();
	sub_eq_test();
	mult_eq_test();
	div_eq_test();
	unar_sub();
	unar_plus();
	return 0;
}