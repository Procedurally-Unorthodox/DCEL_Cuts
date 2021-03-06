#include "Ratio.h"


int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

rto::rto()
{
	n = 0;
	d = 1;
}

rto::rto(int num)
{
	n = num;
	d = 1;
}

rto::rto(int num, int den)
{
	n = num;
	d = den;
}

rto::rto(rto && target)
{
	n = target.n;
	d = target.d;
}

rto::rto(rto const & target) {
	n = target.n;
	d = target.d;
}

rto & rto::operator=(int const & target)
{
	n = target;
	d = 1;
	return *this;
}

rto & rto::operator=(rto const & target)
{
	n = target.n;
	d = target.d;

	return *this;
}

rto rto::operator-() const
{
	return rto(-n,d);
}

rto rto::operator+(int factor) const
{
	int x = n + factor * d;
	int y = d;

	int z = gcd(x, y);

	if (y / z < 0) {
		z *= -1;
	}

	return rto(x / z, y / z);
}

rto rto::operator+(const rto & target) const
{
	int g = gcd(target.d, d);

	int x = n * (target.d / g) + target.n * (d / g);
	int y = d * (target.d / g);

	int z = gcd(x, y);

	if (y / z < 0) {
		z *= -1;
	}

	return rto(x / z, y / z);
}

rto rto::operator-(int factor) const
{
	int x = n - factor * d;
	int y = d;

	int z = gcd(x, y);

	if (y / z < 0) {
		z *= -1;
	}

	return rto(x / z, y / z);
}

rto rto::operator-(const rto & target) const
{
	int g = gcd(target.d, d);

	int x = n * (target.d / g) - target.n * (d / g);
	int y = d * (target.d / g);

	int z = gcd(x, y);

	if (y / z < 0) {
		z *= -1;
	}

	return rto(x / z, y / z);
}

rto rto::operator*(int factor) const
{
	int x = n * factor;
	int y = d;

	int z = gcd(x, y);

	if (y / z < 0) {
		z *= -1;
	}

	return rto(x / z, y / z);
}

rto rto::operator*(const rto & target) const
{
	int x = n * target.n;
	int y = d * target.d;

	int z = gcd(x, y);

	if (y / z < 0) {
		z *= -1;
	}

	return rto(x / z, y / z);
}

rto rto::operator/(int factor) const
{
	int x = n;
	int y = d * factor;

	int z = gcd(x, y);

	if (y / z < 0) {
		z *= -1;
	}

	return rto(x / z, y / z);
}

rto rto::operator/(const rto & target) const
{
	int x = n * target.d;
	int y = d * target.n;

	int z = gcd(x, y);

	if (y / z < 0) {
		z *= -1;
	}

	return rto(x / z, y / z);
}

rto & rto::operator+=(int factor)
{
	int x = n + factor * d;
	int y = d;

	int z = gcd(x, y);

	n = x / z;
	d = y / z;

	if (d < 0) {
		n *= -1;
		d *= -1;
	}

	return *this;
}

rto & rto::operator+=(const rto & target)
{
	int g = gcd(target.d, d);

	int x = n * (target.d/g) + target.n * (d/g);
	int y = d * (target.d/g);

	int z = gcd(x, y);

	n = x / z;
	d = y / z;

	if (d < 0) {
		n *= -1;
		d *= -1;
	}

	return *this;
}

rto & rto::operator-=(int factor)
{
	int x = n - factor * d;
	int y = d;

	int z = gcd(x, y);

	n = x / z;
	d = y / z;

	if (d < 0) {
		n *= -1;
		d *= -1;
	}

	return *this;
}

rto & rto::operator-=(const rto & target)
{
	int g = gcd(target.d, d);

	int x = n * (target.d / g) - target.n * (d / g);
	int y = d * (target.d / g);

	int z = gcd(x, y);

	n = x / z;
	d = y / z;

	if (d < 0) {
		n *= -1;
		d *= -1;
	}

	return *this;
}

rto & rto::operator*=(int factor)
{
	int x = n * factor;
	int y = d;

	int z = gcd(x, y);

	n = x / z;
	d = y / z;

	if (d < 0) {
		n *= -1;
		d *= -1;
	}

	return *this;
}

rto & rto::operator*=(const rto & target)
{
	int x = n * target.n;
	int y = d * target.d;

	int z = gcd(x, y);

	n = x / z;
	d = y / z;

	if (d < 0) {
		n *= -1;
		d *= -1;
	}

	return *this;
}

rto & rto::operator/=(int factor)
{
	int x = n;
	int y = d * factor;

	int z = gcd(x, y);

	n = x / z;
	d = y / z;

	if (d < 0) {
		n *= -1;
		d *= -1;
	}

	return *this;
}

rto & rto::operator/=(const rto & target)
{
	int x = n * target.d;
	int y = d * target.n;

	int z = gcd(x, y);

	n = x / z;
	d = y / z;

	if (d < 0) {
		n *= -1;
		d *= -1;
	}

	return *this;
}

bool rto::operator==(const int & test) const
{
	return (n == test && d == 1);
}

bool rto::operator==(const rto & target) const
{
	return (n == target.n && d == target.d);
}

bool rto::operator!=(const int & test) const
{
	return (n != test || d != 1);
}

bool rto::operator!=(const rto & target) const
{
	return (n != target.n || d != target.d);
}

bool rto::operator>(const int & test) const
{
	return n > test * d;
}

bool rto::operator>(const rto & test) const
{
	return n * test.d > test.n * d;
}

bool rto::operator<(const int & test) const
{
	return n < test * d;
}

bool rto::operator<(const rto & test) const
{
	return n * test.d < test.n * d;
}

bool rto::operator>=(const int & test) const
{
	return n >= test * d;
}

bool rto::operator>=(const rto & test) const
{
	return n * test.d >= test.n * d;
}

bool rto::operator<=(const int & test) const
{
	return n <= test * d;
}

bool rto::operator<=(const rto & test) const
{
	return n * test.d <= test.n * d;
}

float rto::toFloat() const
{
	return (float)n / (float)d;
}
