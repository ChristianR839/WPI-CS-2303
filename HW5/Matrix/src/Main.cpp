#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string removeSpaces(string str) {
	string newStr = "";

	for (int i = 0; str[i]; i++) {
		if (str[i] != ' ') {
			newStr = newStr + str[i];
		}
	}

	return newStr;
}

int lineWidth(string str) {
	string newStr = removeSpaces(str);
	return newStr.length();
}

int dataIndex(int row, int col, int width) {
	int val = (row * width) + col;
	// cout << "DataIndex(" << row << ", " << col << "): " << val << endl;
	return val;
}

int main(int argc, char* argv[]) {

	ifstream inputFile("input.txt");

	string input;
	string allData;

	int width = 0;
	int height = 0;

	if (inputFile.is_open()) {
		while(getline(inputFile, input)) {
			width = lineWidth(input);
			height++;
			allData = allData + removeSpaces(input);
		}
		inputFile.close();
	}

	int bLeftMat[height][width];

	for (int k = 0; k < height; k++) {
		for (int l = 0; l < width; l++) {
			bLeftMat[k][l] = allData[dataIndex(k, l, width)] - 48; // ascii
		}
	}

	// cout << "allData at index 3: " << allData[3] << endl;
	// cout << "1, 2: " << bLeftMat[1][2] << endl << endl;

	cout << "Input Matrix:" << endl << endl;

	for (int s = 0; s < height; s++) {
		for (int t = 0; t < width; t++) {
			cout << bLeftMat[s][t] << " ";
		}
		cout << endl;
	}

	cout << endl;

	int leftMat[height*2][width];

	for (int m = ((height * 2) - 1); m >= 0; m--) {
		for (int n = (width - 1); n >= 0; n--) {
			if (m >= height) {
				leftMat[m][n] = bLeftMat[m - height][n];
			} else {
				leftMat[m][n] = bLeftMat[height - m - 1][n];
			}
		}
	}

	int rghtMat[height*2][width*2];

	for (int o = ((height * 2) - 1); o >= 0; o--) {
		for (int p = ((width * 2) - 1); p >= 0; p--) {
			if (p < width) {
				rghtMat[o][p] = leftMat[o][p];
			} else {
				rghtMat[o][p] = leftMat[o][(width * 2) - p - 1];
			}
		}
	}

	cout << "Final Matrix:" << endl << endl;

	for (int q = 0; q < (height * 2); q++) {
		for (int r = 0; r < width*2; r++) {
			cout << rghtMat[q][r] << " ";
		}
		cout << endl;
	}

	ofstream newFile("output.txt");

	for (int y = 0; y < (height * 2); y++) {
		for (int z = 0; z < width*2; z++) {
			newFile << rghtMat[y][z] << " ";
		}
		newFile << endl;
	}

	newFile.close();

	// cout << allData << endl;
	// cout << width << " width" << endl;
	// cout << height << " height" << endl;

	/*
	 * Steps:
	 * 1.) Read the input of a file (done)
	 * 2.) Use the input to determine the size of the array (done)
	 * 3.) Process the data, mirroring it throughout the full array
	 * 4.) Output full array
	 */
}
