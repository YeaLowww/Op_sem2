#include "Header.h"
TVector2::TVector2(double x, double y)
{
	this->x = x;
	this->y = y;
}
double TVector2::get_coord(char coord)
{
	switch (coord)
	{
	case 'x':
		return x;
		break;
	case 'y':
		return y;
		break;
	}
}
double TVector2::get_length()
{
	return sqrt(x * x + y * y);
}
double TVector2::scalar(TVector& t)
{
	return x * t.get_coord('x') + y * t.get_coord('y');
}

TVector3::TVector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
double TVector3::get_coord(char coord)
{
	switch (coord)
	{
	case 'x':
		return x;
		break;
	case 'y':
		return y;
		break;
	case 'z':
		return z;
		break;
	}
}
double TVector3::get_length()
{
	return sqrt(x * x + y * y + z * z);
}
double TVector3::scalar(TVector& t)
{
	return x * t.get_coord('x') + y * t.get_coord('y') + z * t.get_coord('z');
}