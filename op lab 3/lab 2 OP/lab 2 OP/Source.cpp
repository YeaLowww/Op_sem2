#include"Header.h"
int main() {

	vector<Tetra> parameters;
	int n;
	input_param(parameters, n);
	cout << endl;
	output_param(parameters);
	find_V(parameters, n);
}
