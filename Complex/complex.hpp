struct complex
{
	double re;
	double im;	

	complex();
	complex(double num);
	complex(double real, double imag);
	complex(complex const &num);

	complex operator=(complex const &num);
	complex operator+(complex &cmp);
	complex operator-(complex &cmp);
	complex operator*(complex &cmp);
	complex operator^(double degree);

	void print_num();
	void pair();
	double mod();
	double arg();
};