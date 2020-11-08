#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int BinaryToDecimal(ifstream& inFile);

int main()
{
	ifstream inFile;

	cout << BinaryToDecimal(inFile) << endl;
	

	return 0;
}

int BinaryToDecimal(ifstream& inFile) {

	char input;
	int total = 0;
	string binaryNum = "";

	inFile.open("test.txt");

	if (!inFile) {
		cout << "The input file failed to open\n";
		return 1;
	}

	inFile.get(input);

	cout << "Binary Number: " << "\t\tDecimal Equivalent:\n";

	while (inFile) {
		

		if (input == '1')
			binaryNum += input;
		else if (input == '0')
			binaryNum += input;

		if (input == '1') {
			total = (total * 2) + 1;
		}
		else if (input == '0') {
			total = (total * 2) + 0;
		}

		inFile.get(input);

		if (input == '\n')
		{
			cout << setw(8) << binaryNum << "\t\t\t" << total << endl;
			total = 0;
			binaryNum = "";
		}
	}

	return total;

	inFile.close();

}