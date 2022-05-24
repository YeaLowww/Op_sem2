#include"Header.h"
void output_param(vector <Tetra>& arr) {

	for (int i = 0; i < arr.size(); i++)
	{
		cout << "Tetraid: " << i + 1 << endl;
		cout << "cordinates of point A: " << arr[i].Ax << ", " << arr[i].Ay << ", " << arr[i].Az << endl;
		cout << "cordinates of point B: " << arr[i].Bx << ", " << arr[i].By << ", " << arr[i].Bz << endl;
		cout << "cordinates of point C: " << arr[i].Cx << ", " << arr[i].Cy << ", " << arr[i].Cz << endl;
		cout << "cordinates of point D: " << arr[i].Dx << ", " << arr[i].Dy << ", " << arr[i].Dz << endl;
	}

}
void input_param(vector <Tetra>& arr, int& n) {

	Tetra a;
	cout << "Input count of Tetraids " << endl;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "Tetraid: " << i + 1 << endl;
		cout << "Input cordinates of point A(x, y, z): " << endl;
		cin >> a.Ax;
		cin >> a.Ay;
		cin >> a.Az;
		cout << "Input cordinates of point B(x, y, z): " << endl;
		cin >> a.Bx;
		cin >> a.By;
		cin >> a.Bz;
		cout << "Input cordinates of point C(x, y, z): " << endl;
		cin >> a.Cx;
		cin >> a.Cy;
		cin >> a.Cz;
		cout << "Input cordinates of point D(x, y, z): " << endl;
		cin >> a.Dx;
		cin >> a.Dy;
		cin >> a.Dz;
		arr.push_back(a);
	}


}
void find_V(vector <Tetra>& arr, int n) {
	double ABx, ABy, ABz;
	double ACx, ACy, ACz;
	double ADx, ADy, ADz;
	double V, maxV = 0, counter = 0;
	double* arrV = new double[n];
	for (int i = 0; i < arr.size(); i++)
	{
		ABx = arr[i].Bx - arr[i].Ax;
		ABy = arr[i].By - arr[i].Ay;
		ABz = arr[i].Bz - arr[i].Az;

		ACx = arr[i].Cx - arr[i].Ax;
		ACy = arr[i].Cy - arr[i].Ay;
		ACz = arr[i].Cz - arr[i].Az;

		ADx = arr[i].Dx - arr[i].Ax;
		ADy = arr[i].Dy - arr[i].Ay;
		ADz = arr[i].Dz - arr[i].Az;

		arrV[i] = abs(((ABx * ACy * ADz) + (ABy * ACz * ADx) + (ABz * ACx * ADy) - (ABz * ACy * ADx) - (ABy * ACx * ADz) - (ABx * ACz * ADy)) / 6);
		if (arrV[i] > maxV) {
			maxV = arrV[i];
			counter = i + 1;
		}
	}
	cout << "max V = " << maxV << " tetraid number = " << counter << endl;
	delete[] arrV;
}