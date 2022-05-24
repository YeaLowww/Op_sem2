#include <iostream>
#include<math.h>
using namespace std;

class TVector
{
public:
	virtual double get_length() = 0;
	virtual double get_coord(char) = 0;
	virtual double scalar(TVector&) = 0;
};

class TVector2 : public TVector
{
	double x, y;
public:
	TVector2(double x, double y);
	double get_coord(char) override;
	double get_length() override;
	double scalar(TVector&) override;
};
class TVector3 : public TVector
{
	double x, y, z;
public:
	TVector3(double x, double y, double z);
	double get_coord(char) override;
	double get_length() override;
	double scalar(TVector&) override;
};