#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void PrintBinaryValues(string binaryNum);
void PrintDecimalValues(int total);
int DecimalPlaceValue(int total);

int main()
{
	ifstream inFile;
	char input;


	cout << "Binary Number:" << setw(25) << "Decimal Equivalent:" << endl;

	inFile.open("test.txt");

	inFile.get(input);

	int total = 0;
	int position = 0;
	string binaryNum = "";
	while (inFile) {

		
		if (input == '1') {

			binaryNum += input;
			total = (total * 2) + 1;
			position++;
		}
		else if (input == '0') {

			binaryNum += input;
			total = (total * 2) + 0;
			position++;
		}
		else if (input == '\n' && position == 0) { //If the cursor reads a newline character on the first line for a character
			inFile.get(input);
			continue; //Re-evaluate logic from beginning of the loop with the new character.
		}
		else if ((int(input) < '0' || int(input) > '1') && (input != ' ') || (input == ' ' && position > 0)) { //If the ASCII code is less than '0' or greater than '1' AND NOT space (32 ASCII code) OR there is a space in a binary number

			cout << "Bad data on input\n"; //Print error message to the console

			//Resets counters for the next line of input
			position = 0;
			total = 0;
			binaryNum = "";

			//Ignores all data on the input line with bad data
			inFile.ignore(1000, '\n');
		}

		inFile.get(input);

		if ((input == '\n' && position > 0) || (!inFile)) { //If file input cursor has read a new line where the position is atleast one OR reached end of file

			if (total <= 2047) {
				PrintBinaryValues(binaryNum);
				PrintDecimalValues(total);
			}
			

			//Resets counters for the next line of input
			position = 0;
			total = 0;
			binaryNum = "";
		}
		
	}




	return 0;
}

void PrintBinaryValues(string binaryNum) {

	switch (binaryNum.length()) {

		case 1:
			cout << setw(binaryNum.length() + 6) << binaryNum;
			break;

		case 2:
			cout << setw(binaryNum.length() + 5) << binaryNum;
			break;

		case 3:
			cout << setw(binaryNum.length() + 4) << binaryNum;
			break;

		case 4:
			cout << setw(binaryNum.length() + 4) << binaryNum;
			break;

		case 5:
			cout << setw(binaryNum.length() + 3) << binaryNum;
			break;

		case 6:
			cout << setw(binaryNum.length() + 2) << binaryNum;
			break;

		case 7:
			cout << setw(binaryNum.length() + 3) << binaryNum;
			break;

		case 8:
			cout << setw(binaryNum.length() + 2) << binaryNum;
			break;

		case 9:
			cout << setw(binaryNum.length() + 1) << binaryNum;
			break;

		case 10:
			cout << setw(binaryNum.length() + 1) << binaryNum;
			break;

		case 11:
			cout << setw(binaryNum.length()) << binaryNum;
			break;

		default:
			cout << "Out of range\n";
	}

}

void PrintDecimalValues(int total) {

	switch (DecimalPlaceValue(total)) {

		case 1:
			cout << setw(21) << total << endl;
			break;

		case 2:
			cout << setw(20) << total << endl;
			break;

		case 3:
			cout << setw(19) << total << endl;
			break;

		case 4:
			cout << setw(18) << total << endl;
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