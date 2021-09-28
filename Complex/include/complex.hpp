#ifndef COMPLEX_INCLUDE_COMPLEX_HPP
#define COMPLEX_INCLUDE_COMPLEX_HPP

bool is_zero(const double num);

struct complex
{
	double re;
	double im;	

	complex();
	complex(double real, double imag);
	complex(const complex &num);
	~complex();

	complex & operator=(const complex &cmp);
	complex & operator=(double num);

	complex operator+(const complex &cmp) const;
	complex operator-(const complex &cmp) const;
	complex operator*(const complex &cmp) const;
	complex operator/(const complex &cmp) const;

	complex operator+(double num) const;
	complex operator-(double num) const;
	complex operator*(double num) const;
	complex operator/(double num) const;

	complex & operator+=(const complex &cmp);
	complex & operator-=(const complex &cmp);
	complex & operator*=(const complex &cmp);
	complex & operator/=(const complex &cmp);

	complex & operator+=(double num);
	complex & operator-=(double num);
	complex & operator*=(double num);
	complex & operator/=(double num);

	complex operator-() const;

	bool operator==(const complex &cmp) const;
	bool operator!=(const complex &cmp) const;

	bool operator==(double num) const;
	bool operator!=(double num) const;

	complex operator^(double degree) const;
	complex pair() const;

	void info() const;
	double mod() const;
	double arg() const;
};

complex operator+(double num, const complex &cmp);
complex operator-(double num, const complex &cmp);
complex operator*(double num, const complex &cmp);
complex operator/(double num, const complex &cmp);

bool operator==(double num, const complex &cmp);
bool operator!=(double num, const complex &cmp);

#endif	//COMPLEX_INCLUDE_COMPLEX_HPP