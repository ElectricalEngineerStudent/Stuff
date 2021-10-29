//============================================================================
// Name        : Matrix_solver.cpp
// Author      : Ba Nam Nguyen
// Version     :
// Copyright   : Your copyright notice
// Description : 3 by 3 matrix determinant solver
//============================================================================

#include <iostream>

using namespace std;

void InputData();
void Solver();
void PrintResult();

double dMatrix[3][3];
double dVector[3];
double dResult[3];

int main () {
	InputData();
	Solver();
	PrintResult();

/*	int numbers[3][3];
	cout << "Enter numbers: " << endl;

	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			cin >> numbers[i][j];
		}
	}
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			cout << "["<<i<<"]["<<j<<"]:" << numbers[i][j] << endl;
		}
	}

*/
}

void InputData() {
	int i, j;
	int confirm = 1;

	while (confirm == 1) {
		// This part for input the matrix
		for (i=0; i < 3; ++i) {
			for (j=0; j < 3; ++j) {
				cout << "Enter matrix item " << i << ","  << j << " :" ;
				cin >> dMatrix[i][j];

				// validate input data
				if (cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "\nPlease enter numbers." << endl << endl;
					for (i=0; i<3; ++i){
						for (j=0; j<3; ++j){
						cout << "Enter matrix item " << i << ","  << j << " :" ;
						cin >> dMatrix[i][j];
						}
					}

				}

				cout << endl;
				}
			}
		cout << "Please review the matrix "	<< endl;
		for (i=0; i < 3; ++i) {
			cout << dMatrix[i][0] << " "<< dMatrix[i][1] <<" "<< dMatrix[i][2] << endl;
			}
		cout << "Everything OK? Enter 1 for re-enter: ";
		cin >> confirm;

		// This part for input the vector

		for (i=0; i < 3; ++i){
			for (j=0; j<1; ++j){
			cout << "Enter vector: " << i << "," << j << " :";
			cin >> dVector[i];
			}
		}

	}

}

void Solver() {
	int i,j;
	cout << "I'm solving now using Cramer's Rule\n" << endl;

	double q = dMatrix[0][0]*dMatrix[1][1]*dMatrix[2][2];
	double w = dMatrix[0][1]*dMatrix[1][2]*dMatrix[2][0];
	double h = dMatrix[0][2]*dMatrix[1][0]*dMatrix[2][1];
	double r = dMatrix[2][0]*dMatrix[1][1]*dMatrix[0][2];
	double t = dMatrix[2][1]*dMatrix[1][2]*dMatrix[0][0];
	double y = dMatrix[2][2]*dMatrix[1][0]*dMatrix[0][1];

	double detA = (q + w + h) - (r + t + y);

	cout << "Determinant of Matrix A: " << detA << endl;

	cout << "Matrix A1: " << endl;
	for (i=0; i<3; ++i){
		for (j=0; j<1; ++j){
		cout << dVector[i] << " " << dMatrix [i][1] << " " << dMatrix [i][2]<<endl;
		}
	}

	double A = dVector[0]*dMatrix[1][1]*dMatrix[2][2];
	double B = dMatrix[0][1]*dMatrix[1][2]*dVector[0];
	double C = dMatrix[0][2]*dVector[0]*dMatrix[2][1];
	double D = dVector[0]*dMatrix[1][1]*dMatrix[0][2];
	double E = dMatrix[2][1]*dMatrix[1][2]*dVector[0];
	double F = dMatrix[2][2]*dVector[0]*dMatrix[0][1];

	double detA1 = (A + B + C) - (D + E + F);
	cout << "Determinant of A1: " << detA1 << endl;


	cout << "Matrix A2: " << endl;
	for (i=0; i<3; ++i){
		for (j=0; j<1; ++j){
		cout << dMatrix [i][j] << " " << dVector[i] << " " << dMatrix [i][2]<<endl;
		}
	}

	double a = dMatrix[0][0]*dVector[0]*dMatrix[2][2];
	double b = dVector[0]*dMatrix[1][2]*dMatrix[2][0];
	double c = dMatrix[0][2]*dMatrix[1][0]*dVector[0];
	double d = dMatrix[2][0]*dVector[0]*dMatrix[0][2];
	double e = dVector[0]*dMatrix[1][2]*dMatrix[0][0];
	double f = dMatrix[2][2]*dMatrix[1][0]*dVector[0];

	double detA2 = (a + b + c) - (d + e + f);
	cout << "Determinant of A2: " << detA2 << endl;

	cout << "Matrix A3: " << endl;
	for (i=0; i<3; ++i){
		for (j=0; j<1; ++j){
		cout << dMatrix [i][j] << " " << dMatrix [i][1] << " " << dVector[i]<<endl;
		}
	}

	double a1 = dMatrix[0][0]*dMatrix[1][1]*dVector[0];
	double b1 = dMatrix[0][1]*dVector[0]*dMatrix[2][0];
	double c1 = dVector[0]*dMatrix[1][0]*dMatrix[2][1];
	double d1 = dMatrix[2][0]*dMatrix[1][1]*dVector[0];
	double e1 = dMatrix[2][1]*dVector[0]*dMatrix[0][0];
	double f1 = dVector[0]*dMatrix[1][0]*dMatrix[0][1];

	double detA3 = (a1 + b1 + c1) - (d1 + e1 + f1);
	cout << "Determinant of A3: " << detA3 << endl;



	double x1 = (detA1) / (detA);
	double x2 = (detA2) / (detA);
	double x3 = (detA3) / (detA);

	cout << "The answer is: X1 = " << x1 << ", " << "X2 = " << x2 << ", " << "X3 = " << x3 << endl;

}

void PrintResult() {
	int i;
	cout << "There... " << endl;
	cout << "Thank you."

}






