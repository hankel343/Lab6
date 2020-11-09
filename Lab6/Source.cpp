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
		
		//Conditions create a string of 1's and 0's to represent the binary number in output
		if (input == '1')
			binaryNum += input;
		else if (input == '0')
			binaryNum += input;

		//Calculates from binary to decimal
		if (input == '1') {
			total = (total * 2) + 1;
		}
		else if (input == '0') {
			total = (total * 2) + 0;
		}

		inFile.get(input);

		//Goes to new line
		if (input == '\n')
		{
			cout << setw(binaryNum.length() + 7) << binaryNum << "\t\t\t" << total << endl;
			total = 0;
			binaryNum = "";
		}
	}

	return total;

	inFile.close();

}