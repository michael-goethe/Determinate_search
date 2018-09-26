#include "stdafx.h"
#include <iostream>

using namespace std;

void Newmatrix(int **newarray, int **array, int x, int j) {
	
	int MoveRight = 0;

	for (int changeW = 0; changeW < x; changeW++) {
		for (int changeS = 0; changeS < x; changeS++) {
			if (changeS == j)
				MoveRight = 1;
			newarray[changeW][changeS] = array[changeW][changeS + MoveRight];
		}
	}


}

int Det(int **mas, int x) {
	int det, y, coef = 1;
	y = x - 1;
	int **Newarray;
	Newarray = new int*[x];
	for (int i = 0; i < x; i++) {
		Newarray[i] = new int(x);
	}

	if (x == 1) {
		det = mas[0][0];
		return det;
	}

	if (x == 2) {
		det = mas[0][0] * mas[1][1] - mas[0][1] * mas[1][0];
		return det;
	}

	if (x > 2) {
		for (int i = 0; i < x; i++) {
            Newmatrix(Newarray, mas, y, i);


			det = mas[0][i] * coef * Det(Newarray, y);
			coef = -coef;
		}
	}
	return det;
}





	int main() {
	int det, x;

	int **ptrarray;
	cout << "type size of matrix" << endl;
	cin >> x;
	ptrarray = new int*[x];

	for (int i = 0; i < x; i++) {
		ptrarray[i] = new int(x);
		for (int j = 0; j < x; j++) {
			cout << "|" << i << "|" << "|" << j << "| = ";
			cin >> ptrarray[i][j];
		}
	}
	

	det = Det(ptrarray, x);

	


	cout << det << endl;
	cin.get();
	cin.get();
    return 0;
}

