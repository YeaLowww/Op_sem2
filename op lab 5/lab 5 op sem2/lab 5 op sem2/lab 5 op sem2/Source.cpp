#include "Header.h"

int main()
{
	setlocale(LC_ALL, "");
	double x1, y1, z1, x2, y2, z2, x3, y3, x4, y4, res;

	cout << "����i�� 3 ���������� ������� �: ";
	cin >> x1 >> y1 >> z1;
	TVector3 A(x1, y1, z1);

	cout << "����i�� 3 ���������� ������� B: ";
	cin >> x2 >> y2 >> z2;
	TVector3 B(x2, y2, z2);

	cout << "����i�� 2 ���������� ������� C: ";
	cin >> x3 >> y3;
	TVector2 C(x3, y3);

	cout << "����i�� 2 ���������� ������� D: ";
	cin >> x4 >> y4;
	TVector2 D(x4, y4);

	res = A.scalar(B) + C.scalar(D) + A.get_length();
	cout<<"S = (A,B) + (C,D) + |A| = "<< res;
}