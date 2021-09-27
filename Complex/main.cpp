#include <cassert>
#include <iostream>

#include "complex.hpp"

int main(int argc, char const *argv[])
{
	///////////////////////////////////////////
	double ar, br, ai, bi;
	std::cin >> ar >> ai >> br >> bi;
	assert(std::cin.good());
	///////////////////////////////////////////
	//Initializer with 0
	complex a;
	assert(a.re == 0.0 && a.im == 0.0);
	//Initializer with 2 numbers
	complex b(br, bi);
	///////////////////////////////////////////
	//Print both
	a.print_num();
	b.print_num();
	///////////////////////////////////////////
	//Copy complex
	complex copy(b);
	assert(copy.re == b.re && copy.im == b.im);
	///////////////////////////////////////////
	//Plus complex
	complex c = a + b;
	assert(c.re == a.re+b.re && c.im == a.im+b.im);
	//Mines complex
	complex d = a - b;
	assert(d.re == a.re-b.re && d.im == a.im-b.im);
	///////////////////////////////////////////
	//Initialisation
	a = {ar, ai};
	assert(a.re == ar && a.im == ai);
	//Pairing
	a.pair();
	assert(a.re == ar && a.im == ai*(-1));
	//Multiplication
	complex mult = a * b;
	assert(a.re*b.re - a.im*b.im == mult.re);
	assert(a.re*b.im + a.im*b.re == mult.im);
	mult.print_num();
	//Power
	complex power = mult^2.0;
	power.print_num();
	//Mod and Arg
	printf("mod = %lg\n", b.mod());
	printf("arg = %lg\n", b.arg());
	//Equal check
	c = a;
	assert(c.re == a.re && c.im == a.im);

	return 0;
}