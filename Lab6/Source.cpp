#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

bool FileCheck(ifstream& inFile);
//Precondition: An input stream variable has been declared.
//Postcondition: Input stream has been varified to be either valid or invalid.

string ReadInBinary(ifstream& inFile);
//Precondition: Function is passed a non-failed input stream
//Postcondition: Function returns a string that is a binary number.

int BinaryToDecimal(int binaryForm);
//Precondition: A identifier pointing to a int variable contains a binary number.
//Postcondition: Function returns the decimal version of a binary number.

void FormatOutput(int binaryForm, int decimalForm);

int main()
{
	ifstream inFile;
	int binaryForm;
	int decimalForm;

	if (!FileCheck(inFile)) //If input file fails to open,
		return 1; //then terminate program.

	binaryForm = stoi(ReadInBinary(inFile)); //ReadInBinary returns a string and this needs to be converted to an integer. stoi (string to integer) is used to convert the string to an integer and store into int id.  
	decimalForm = BinaryToDecimal(binaryForm); //BinaryToDecimal takes the integer decimal number returned and stores it into decimalForm

	FormatOutput(binaryForm, decimalForm);

	return 0;
}

bool FileCheck(ifstream& inFile)
{
	inFile.open("test.txt");

	if (!inFile)
	{
		cout << "The input file failed to open";
		return false;
	}

	return true;
}

string ReadInBinary(ifstream& inFile)
{
	char input;
	string block = "";

	inFile.get(input);

	while (inFile)
	{
		if (input == '1' || input == '0')
			block = block + input;
		else
		{
			inFile.clear();
			inFile.ignore(100000);
		}

		inFile.get(input);
	}

	inFile.close();

	return block;
}

int BinaryToDecimal(int binaryForm)
{
	int decimalForm = 0;
	int powerOfTwo = 1; //Starts at 2^0 for the right most bit.

	while (binaryForm != 0) //Sums values of binary left to right
	{
		int lastBit = binaryForm % 10; //Checks to see if the last bit is either a 1 or 0 (Is a zero if divisible by 10)
		binaryForm = binaryForm / 10; //Moves one bit location to the right for loop control
		decimalForm += lastBit * powerOfTwo; //Multiplies current power of two by either a 1 or a zero (if zero, then that power is not included in the final decimal form b/c any number multiplied by zero is zero)
		powerOfTwo = powerOfTwo * 2; //Increments power of two.
	}

	return decimalForm;
}

void FormatOutput(int binaryForm, int decimalForm)
{
	cout << "\tBinary Number:" << "\t\tDecimal Equivalent:\n";
	cout << "\t" << setw(8) << binaryForm << "\t\t" << setw(9) << decimalForm;
}