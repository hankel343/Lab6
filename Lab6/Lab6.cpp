#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//void PrintBinaryValues(string binaryNum);
//void PrintDecimalValues(int total);

void FileCheck(ifstream& inFile);
void PrintTable(int total, string binaryNum);
int DecimalPlaceValue(int total);
void ResetCounters(int& total, int& position, string& binaryNum);

int main()
{
	ifstream inFile;
	char input;


	cout << setw(22) << "Binary Number:" << setw(24) << "Decimal Equivalent:" << endl;

	FileCheck(inFile);

	//Priming read for file input loop.
	inFile.get(input);

	int total = 0; //Stores the decimal equivalent of input.
	int position = 0; //Counter that keeps track of input position
	string binaryNum = ""; //Empty string to store input chars as they're read from input file.
	while (inFile) {
		
		if (input == '1') { //If input char is a '1'

			binaryNum += input; //Use string concatenation to add the input to a string 
			total = (total * 2) + 1; //Multiply the total by 2 to account for the next highest place value and add 1
			position++; //Increment the position counter
		}
		else if (input == '0') {

			binaryNum += input; //Use string concatenation to add the input to a string
			total = (total * 2) + 0; //Multiply the total by 2 to account for the next highest place value and add 0 (adding zero leaves the total unchanged except for increasing place value)
			position++; //Increment the position counter
		}
		else if (input == '\n' && position == 0) { //If the cursor reads a newline character on the first line for a character
			inFile.get(input);
			continue; //Re-evaluate logic from beginning of the loop with the new character.
		}
		else if ((int(input) < '0' || int(input) > '1') && (input != ' ') || (input == ' ' && position > 0)) { //If the ASCII code is less than '0' or greater than '1' AND NOT space (32 ASCII code) OR there is a space in a binary number

			//Print error message to the console
			cout << setw(24) << "Bad data on input\n"; 

			//Resets counters for the line.
			ResetCounters(total, position, binaryNum);

			//Ignores all data on the input line with bad data
			inFile.ignore(1000, '\n');
		}

		inFile.get(input);

		if ((input == '\n' && position > 0) || (!inFile)) { //If file input cursor has read a new line where the position is atleast one OR reached end of file

			//Prints output to table in the console.
			PrintTable(total, binaryNum);

			//Resets counters for the next line of input
			ResetCounters(total, position, binaryNum);
		}
	}

	inFile.close();
	return 0;
}

void FileCheck(ifstream& inFile) {
	inFile.open("BinaryIn.dat");

	if (!inFile) {
		cout << "The input file failed to open.\n";
	}
}

void ResetCounters(int& total, int& position, string& binaryNum) {
	//Resets counters for the next line of input
	position = 0;
	total = 0;
	binaryNum = "";
}

void PrintTable(int total, string binaryNum) {


	//Prints binary values according to the number of place values 
	switch (binaryNum.length()) {

	case 1:
		cout << setw(binaryNum.length() + 14) << binaryNum;
		break;

	case 2:
		cout << setw(binaryNum.length() + 13) << binaryNum;
		break;

	case 3:
		cout << setw(binaryNum.length() + 13) << binaryNum;
		break;

	case 4:
		cout << setw(binaryNum.length() + 12) << binaryNum;
		break;

	case 5:
		cout << setw(binaryNum.length() + 12) << binaryNum;
		break;

	case 6:
		cout << setw(binaryNum.length() + 11) << binaryNum;
		break;

	case 7:
		cout << setw(binaryNum.length() + 11) << binaryNum;
		break;

	case 8:
		cout << setw(binaryNum.length() + 10) << binaryNum;
		break;

	case 9:
		cout << setw(binaryNum.length() + 10) << binaryNum;
		break;

	case 10:
		cout << setw(binaryNum.length() + 9) << binaryNum;
		break;

	case 11:
		cout << setw(binaryNum.length() + 9) << binaryNum;
		break;

	case 12:
		cout << setw(binaryNum.length() + 8) << binaryNum;
		break;

	case 13:
		cout << setw(binaryNum.length() + 8) << binaryNum;
		break;

	case 14:
		cout << setw(binaryNum.length() + 7) << binaryNum;
		break;

	case 15:
		cout << setw(binaryNum.length() + 7) << binaryNum;
		break;

	case 16:
		cout << setw(binaryNum.length() + 6) << binaryNum;
		break;

	default:
		cout << setw(22) << "16-bit limit\n";
		break;
	}


	//Prints decimal values
	switch (DecimalPlaceValue(total)) { //Switches off of the decimal place value to determine spacing in output

	case 1:

		if (total < 6) {
			cout << setw(20) << total << endl;
		}
		else 
			cout << setw(19) << total << endl;
		break;

	case 2:
		if (total <= 15) {
			cout << setw(19) << total << endl;
		}
		else if (total <= 32) {
			cout << setw(18) << total << endl;
		}
		else if (total > 32 && total <= 63) {
			cout << setw(18) << total << endl;
		}
		else
			cout << setw(17) << total << endl;
		break;

	case 3:
		if (total < 256) {
			cout << setw(18) << total << endl;
		}
		else
			cout << setw(17) << total << endl;
		break;

	case 4:
		if (total >= 1000 && total < 1024) {
			cout << setw(17) << total << endl;
		}
		else if (total >= 1024 && total < 2048) {
			cout << setw(16) << total << endl;
		}
		else if (total >= 2048 && total <= 4095) {
			cout << setw(16) << total << endl;
		}
		else if (total >= 4096 && total < 10000)
			cout << setw(15) << total << endl;
		break;

	case 5:
		if (total >= 10000 && total < 16384)
			cout << setw(16) << total << endl;
		else if (total >= 16384 && total <= 32768)
			cout << setw(15) << total << endl;
		else if (total > 32768 && total <= 65535)
			cout << setw(15) << total << endl;
		break;
	}
}

int DecimalPlaceValue(int total) {

	int placeValue = 0;

	while (total != 0) {
		total /= 10;
		placeValue++;
	}

	return placeValue;
}