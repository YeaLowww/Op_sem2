
#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Tetra {
public:
	int Ax, Ay, Az;
	int Bx, By, Bz;
	int Cx, Cy, Cz;
	int Dx, Dy, Dz;

};
void input_param(vector <Tetra>&, int& n);
void output_param(vector <Tetra>&);
void find_V(vector <Tetra>&, int n);
