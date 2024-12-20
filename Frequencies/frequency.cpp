#include "frequency.h"

void frequency::getF()
{
	getData();
	setP();
	h = 0;
	l = 1;
	b = 0;
	for (int i = 1; i < 9387; i++)
	{
		f = asin((y[i + 1] - c) / -a) / i;
		b += f;
		if (h < f) {
			h = f;
		}
		if (l > f) {
			l = f;
		}
	}
	d = 1;
	f = -asin((y[2] - c) / -a) / 1;
	b = -.21451409;
	e = .000011;
	g = .003812;
	int n = 0;
	for (int i = 1; i < 9387; i++)
	{
		k = exp(e * -i - d) + b;
		f = asin((y[i + 1] - c) / -a) / i;
		if (k == f)
			n = i;
		cout << f << " " << k << '\n';
	}
	f = -asin((y[2] - c) / -a) / 1;
	k = g - d * n;
	b = f;
	cout << f << " " << k << " " << n << '\n';
}

void frequency::getData()
{
	ifstream input;
	input.open("frequencies.txt");
	if (!input.is_open())
	{
		cout << "File isn't open.";
	}
	else
	{
		double n;
		h = 0;
		l = 10;
		for (int i = 0; i < 9388; i++)
		{
			n = 0;
			input >> n;
			if (h < n) {
				h = n;
			}
			if (l > n) {
				l = n;
			}
			y[i] = n;
		}
		f = 1;
		a = (h - l) / 2;
		c = (h + l) / 2;
		cout << a << " " << c << '\n';
	}
	input.close();
}

void frequency::gradient()
{
	r = .01;
	setP();
	double z;
	double e;
	e = Error();
	z = 0;
	z = deriv();
	f -= r * e * z;
	cout << f << '\n';
}

double frequency::Error()
{
	double e = 0;
	for (int t = 0; t < 9387; t++)
	{
		k = b - (1 / exp(e * -t));
		e += abs(y[t] - k);
	}
	e = e / 9389;
	return e;
}

double frequency::deriv()
{
	double m = 0;
	for (int t = 0; t < 9387; t++)
	{
		m += -exp(e * t + 1);
	}
	m = m / 9387;
	return m;
}

void frequency::setP()
{
	for (int i = 0; i < 9389; i++)
	{
		p[i] = -a * sin(f * i) + c;
	}
}

void frequency::aGradient()
{
	setP();
	double z = 0;
	double e = Error();
	z = deriv();
	a -= r * e * z;
	cout << a << '\n';
}

void frequency::bGradient()
{
	setP();
	double z = 0;
	double e = Error();
	z = deriv();
	b -= r * e * z;
	cout << b << '\n';
}

void frequency::cGradient()
{
	setP();
	double z = 0;
	double e = Error();
	z = deriv();
	c -= r * e * z;
	cout << c << '\n';
}

void frequency::dGradient()
{
	k = -b * sin(e) - d + g;
	double z = 0;
	double e = p[1] - k;
	z = -e * b * cos(e) - d;
	d -= r * e * z;
}

void frequency::gGradient()
{
	r = .01;
	double z = 0;
	double x = Error();
	z = deriv();
	e -= r * x * z;
	cout << e << '\n';
}

void frequency::setK()
{
	for (int i = 0; i <9387; i++)
	{
		o[i] = b - (1 / exp(e * -i));
	}
}