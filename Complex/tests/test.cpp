#include "test.hpp"
#include "../include/complex.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

bool void_init_test()
{
	complex a;
	if(!is_zero(a.re) || !is_zero(a.im))
	{
		std::cerr<<"void_init_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool init_test()
{
	complex b(br, bi);
	if(!is_zero(b.re-br) || !is_zero(b.im-bi))
	{
		std::cerr<<"init_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool copy_init_test()
{
	complex b(br, bi);
	if(!is_zero(b.re-br) || !is_zero(b.im-bi))
	{
		std::cerr<<"init failed"<<std::endl;
		std::cerr<<"copy_init_test failed"<<std::endl;
		return false;
	}
	complex cp(b);
	if(!is_zero(cp.re-b.re) || !is_zero(cp.im-b.im))
	{
		std::cerr<<"copy_init failed"<<std::endl;
		std::cerr<<"copy_init_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool plus_test()
{
	complex a(ar, ai);
	if(!is_zero(a.re-ar) || !is_zero(a.im-ai))
	{
		std::cerr<<"init failed"<<std::endl;
		std::cerr<<"plus_test failed"<<std::endl;
		return false;
	}
	complex b(br, bi);
	if(!is_zero(b.re-br) || !is_zero(b.im-bi))
	{
		std::cerr<<"init failed"<<std::endl;
		std::cerr<<"plus_test failed"<<std::endl;
		return false;
	}
	complex c = a + b;
	if(!is_zero(c.re-(a.re + b.re)) || !is_zero(c.im-(a.im + b.im)))
	{
		std::cerr<<"complex+complex"<<std::endl;
		std::cerr<<"plus_test failed"<<std::endl;
		return false;
	}
	complex d = 4 + a;
	if(!is_zero(d.re - (4 + a.re)) || !is_zero(d.im - a.im))
	{
		std::cerr<<"num+complex"<<std::endl;
		std::cerr<<"plus_test failed"<<std::endl;
		return false;
	}
	complex e = a + 4;
	if(!is_zero(e.re - (4 + a.re)) || !is_zero(e.im - a.im))
	{
		std::cerr<<"complex+num"<<std::endl;
		std::cerr<<"plus_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool sub_test()
{
	complex a(ar, ai);
	complex b(br, bi);
	complex d = a - b;
	complex c = a - 3;
	complex e = 3 - a;
	if(!is_zero(d.re - (a.re-b.re)) || !is_zero(d.im - (a.im-b.im)))
	{
		std::cerr<<"complex-complex"<<std::endl;
		std::cerr<<"sub_test failed"<<std::endl;
		return false;
	}
	if(!is_zero(c.re - (a.re - 3) || !is_zero(c.im - a.im)))
	{
		std::cerr<<"complex-num"<<std::endl;
		std::cerr<<"sub_test failed"<<std::endl;
		return false;
	}
	if(!is_zero(e.re - (3 - a.re)) || !is_zero(a.im - a.im))
	{
		std::cerr<<"num-complex"<<std::endl;
		std::cerr<<"sub_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool num_init_test()
{
	complex a;
	a = {ar, ai};
	if(!is_zero(a.re - ar) || !is_zero(a.im - ai))
	{
		std::cerr<<"num_init_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool pair_test()
{
	complex a(ar, ai);
	complex b = a.pair();
	if(!is_zero(b.re - a.re) || !is_zero(b.im - a.im*(-1)))
	{
		std::cerr<<"pair_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool mult_test()
{
	complex a(ar, ai);
	complex b(br, bi);
	complex mult = a * b;
	if(!is_zero(a.re*b.re - a.im*b.im - mult.re))
	{
		std::cerr<<"complex*complex real"<<std::endl;
		std::cerr<<"mult_test failed"<<std::endl;
		return false;
	}
	if(!is_zero(a.re*b.im + a.im*b.re - mult.im))
	{
		std::cerr<<"complex*complex imag"<<std::endl;
		std::cerr<<"mult_test failed"<<std::endl;
		return false;
	}
	complex c = 3 * a;
	if(!is_zero(3*a.re - c.re))
	{
		std::cerr<<"num*complex real"<<std::endl;
		std::cerr<<"mult_test failed"<<std::endl;
		return false;
	}
	if(!is_zero(3*a.im - c.im))
	{
		std::cerr<<"num*complex imag"<<std::endl;
		std::cerr<<"mult_test failed"<<std::endl;
		return false;
	}
	complex d = a * 3;
	if(!is_zero(3*a.re - c.re))
	{
		std::cerr<<"complex*num real"<<std::endl;
		std::cerr<<"mult_test failed"<<std::endl;
		return false;
	}
	if(!is_zero(3*a.im - c.im))
	{
		std::cerr<<"complex*num imag"<<std::endl;
		std::cerr<<"mult_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool pow_test()
{
	double degree = 2.0;
	complex mult(ar, ai);
	complex power = mult^degree;
	double r = std::sqrt(mult.re*mult.re + mult.im*mult.im);
	double arg = std::atan(mult.im/mult.re);
	double dr = std::pow(r, degree);
	double cos = std::cos(degree * arg);
	double sin = std::sqrt(1 - cos*cos);
	if(!is_zero((double) (cos*dr) - power.re))
	{
		std::cerr<<"pow_test failed real"<<std::endl;
		return false;
	}
	if(!is_zero((double) (sin*dr) - power.im))
	{
		std::cerr<<"pow_test failed imag"<<std::endl;
		return false;
	}
	return true;
}

bool mod_test()
{
	complex a(ar, ai);
	if(!is_zero(a.mod() - std::sqrt(a.re*a.re+a.im*a.im)))
	{
		std::cerr<<"mod_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool arg_test()
{
	complex a(ar, ai);
	if(!is_zero(a.arg() - std::atan((double)a.im/(double)a.re)))
	{
		std::cerr<<"arg_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool equal_test()
{
	complex a(ar, ai);
	complex c;
	c = a;
	if(!is_zero(c.re - a.re) || !is_zero(c.im - a.im))
	{
		std::cerr<<"equal test failed"<<std::endl;
		return false;
	}
	return true;
}

bool div_test()
{
	complex a(ar, ai);
	complex b(br, bi);

	complex c = a/b;

	complex paired = b.pair();
	complex real = b * paired;
	double denom = real.re;
	complex numer = a * paired;
	if(!is_zero(c.re - numer.re/denom) || !is_zero(c.im - numer.im/denom))
	{
		std::cerr<<"complex/complex"<<std::endl;
		std::cerr<<"div_test failed"<<std::endl;
		return false;
	}

	complex d = 1/b;
	paired = b.pair();
	real = b * paired;
	denom = real.re;
	numer = 1 * paired;
	if(!is_zero(d.re - numer.re/denom) || !is_zero(d.im - numer.im/denom))
	{
		std::cerr<<"num/complex"<<std::endl;
		std::cerr<<"div_test failed"<<std::endl;
		return false;
	}
	complex e = a/5;
	if(!is_zero(e.re - a.re/5) || !is_zero(e.im - a.im/5))
	{
		std::cerr<<"complex/num"<<std::endl;
		std::cerr<<"div_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool plus_eq_test()
{
	complex a(ar, ai);
	complex b(br, bi);
	b += a;
	if(!is_zero(b.re - (a.re + br)) || !is_zero(b.im - (a.im + bi)))
	{
		std::cerr<<"complex+=complex"<<std::endl;
		std::cerr<<"plus_eq_test failed"<<std::endl;
		return false;
	}
	complex c(ar, ai);
	c += 3;
	if(!is_zero(c.re - (ar+3)) || !is_zero(c.im - ai))
	{
		std::cerr<<"complex+=num"<<std::endl;
		std::cerr<<"plus_eq_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool sub_eq_test()
{
	complex a(ar, ai);
	complex b(br, bi);
	b -= a;
	if(!is_zero(b.re - (br - a.re)) || !is_zero(b.im - (bi - a.im)))
	{
		std::cerr<<"complex-=complex"<<std::endl;
		std::cerr<<"sub_eq_test failed"<<std::endl;
		return false;
	}
	complex c(ar, ai);
	c -= 3;
	if(!is_zero(c.re - (ar - 3)) || !is_zero(c.im - ai))
	{
		std::cerr<<"complex-=num"<<std::endl;
		std::cerr<<"sub_eq_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool mult_eq_test()
{
	complex a(ar, ai);
	complex b(br, bi);
	b *= a;
	if(!is_zero(b.re - (a.re*br-a.im*bi)) || !is_zero(b.im - (a.re*bi+br*a.im)))
	{
		std::cerr<<"complex*=complex"<<std::endl;
		std::cerr<<"mult_eq_test failed"<<std::endl;
		return false;
	}
	complex c(ar, ai);
	c *= 3;
	if(!is_zero(c.re - ar * 3) || !is_zero(c.im - ai * 3))
	{
		std::cerr<<"complex*=num"<<std::endl;
		std::cerr<<"mult_eq_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool div_eq_test()
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
	if(!is_zero(b.re - re) || !is_zero(b.im - im))
	{
		std::cerr<<"div_eq_test failed"<<std::endl;
		return false;
	}

	complex c(ar, ai);
	c /= 3;
	if(!is_zero(c.re - ar/3) || !is_zero(c.im - ai/3))
	{
		std::cerr<<"div_eq_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool unar_sub_test()
{
	complex a(ar, ai);
	complex b = -a;
	if(!is_zero(b.re + a.re) || !is_zero(b.im + a.im))
	{
		std::cerr<<"unar_sub_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool is_equal_test()
{
	complex a(ar, ai);
	complex b(ar - 1, ai - 3);
	if(a == b)
	{
		std::cerr<<"complex == complex"<<std::endl;
		std::cerr<<"is_equal_test failed"<<std::endl;
		return false;
	}
	if(b == a)
	{
		std::cerr<<"swaped complex"<<std::endl;
		std::cerr<<"complex == complex"<<std::endl;
		std::cerr<<"is_equal_test failed"<<std::endl;
		return false;
	}
	if(a == ar-3)
	{
		std::cerr<<"complex == num"<<std::endl;
		std::cerr<<"is_equal_test failed"<<std::endl;
		return false;
	}
	if(ar-3 == a)
	{
		std::cerr<<"num == complex"<<std::endl;
		std::cerr<<"is_equal_test failed"<<std::endl;
		return false;
	}
	return true;
}

bool is_not_equal_test()
{
	complex a(ar, ai);
	complex b(ar - 1, ai - 3);
	if(!(a != b))
	{
		std::cerr<<"complex == complex"<<std::endl;
		std::cerr<<"is_equal_test failed"<<std::endl;
		return false;
	}
	if(!(b != a))
	{
		std::cerr<<"swaped complex"<<std::endl;
		std::cerr<<"complex == complex"<<std::endl;
		std::cerr<<"is_equal_test failed"<<std::endl;
		return false;
	}
	if(!(a != ai-2))
	{
		std::cerr<<"complex != num"<<std::endl;
		std::cerr<<"is_equal_test failed"<<std::endl;
		return false;
	}
	if(!(ai-2 != a))
	{
		std::cerr<<"num == complex"<<std::endl;
		std::cerr<<"is_equal_test failed"<<std::endl;
		return false;
	}
	return true;
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
	unar_sub_test();
	is_equal_test();
	is_not_equal_test();
	return 0;
}