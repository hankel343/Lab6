/*
* Hankel Haldin
* Lab 6: Program reads in characters representing binary and prints them and their decimal equivalent to a table in the console.
* Due: 11/16/2020
*
* Program uses an EOF while loop to read individual characters from an input file. These characters are then evaluated against -
* several conditions within the while loop that determine what to do with the character. The table these values are output to are -
* controled by two switch statements in the void function PrintTable which determine the binary place value as well as the decimal -
* place value for output spacing.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/************
* Prototypes*
*************/

void FileCheck(ifstream& inFile);
//Pre: The function is passed a input stream variable
//Post: The function will verify the state of the input file when it is first opened (either opens successfully or terminates main because the input file failed to open).

void PrintTable(int total, string binaryNum);
//Pre: The main function has successfully read in a series of binary numbers, stored them to a string called binaryNum and converted the binary to a decimal number
//Post: The function will output a table with the binary number that has been read in with its decimal equivalent

int DecimalPlaceValue(int total);
//Pre: The main function has successfully calculated a decimal number called total which is passed to the function by value
//Post: Function returns the number of place values in the decimal number

void ResetCounters(int& total, int& position, string& binaryNum);
//Pre: The while loop has either encountered the end of a line or an error in the input stream
//Post: Function resets the values of counters that are used during program execution.

int main()
{
	ifstream inFile;

	FileCheck(inFile);

	cout << setw(22) << "Binary Number:" << setw(24) << "Decimal Equivalent:" << endl; //Heading for output

	char input; //Reads the character from the input file
	int total = 0; //Stores the decimal equivalent of input.
	int position = 0; //Counter that keeps track of input cursor position (detects spaces in binary numbers)
	string binaryNum = ""; //Empty string to store input chars for binary number as they're read from input file.

	while (inFile.get(input) || (total != 0)) { //While the input stream is valid OR there is a running total for a decimal number

		if (input == '0' && position == 0) { //If a 0 is read on the first space of a line

			bool isOne = false;
			bool isBadData = false;

			while (!isOne && !isBadData) { //While input is NOT a one AND is NOT bad data

				position++; //Increment the file cursor (detects spaces in binary numbers)
				inFile.get(input);

				if (input == '1')
					isOne = true; //First one of binary number found

				if ((int(input) < '0' || int(input) > '1') && (input != ' ') || (input == ' ' && position > 0)) { //If anything other than a 1 or a 0 is read AND input is not a space in the middle of a binary number
					isBadData = true; //Bad data found
				}
			}
		}

		if ((input == '\n' && position > 0) || (!inFile)) { //If file input cursor has read a new line where the position is atleast one OR reached end of file (a complete line of binary)

			//Prints output to table in the console.
			PrintTable(total, binaryNum);

			//Resets counters for the next line of input
			ResetCounters(total, position, binaryNum);
		}
		else if (input == '1') { //If input char is a '1'

			binaryNum += input; //Use string concatenation to add the input 1 or 0 to a string 
			total = (total * 2) + 1; //Multiply the total by 2 to account for the next highest place value and add 1
			position++; //Increment the file cursor
		}
		else if (input == '0') {

			binaryNum += input; //Use string concatenation to add the input 1 or 0 to a string
			total = (total * 2) + 0; //Multiply the total by 2 to account for the next highest place value and add 0 (adding zero leaves the total unchanged)
			position++; //Increment the file cursor
		}
		else if (input == '\n' && position == 0) { //If the cursor reads a newline character on the first spot for a character (Finds a blank line)
			continue; //Re-evaluate logic from beginning of the loop with a new character.
		}
		else if ((int(input) < '0' || int(input) > '1') && (input != ' ') || (input == ' ' && position > 0)) { //If the ASCII code for input is less than '0' or greater than '1' AND NOT space (32 is ASCII code for ' ') OR there is a space in a binary number

			//Print error message to the console
			cout << setw(24) << "Bad data on input\n";

			//Resets counters for the line.
			ResetCounters(total, position, binaryNum);

			//Ignores all data on the input line with bad data
			inFile.ignore(1000, '\n');
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

		if (total < 4) {
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
		else if (total >= 4096 && total < 10000) {
			cout << setw(15) << total << endl;
		}
		break;

	case 5:
		if (total >= 10000 && total < 16384) {
			cout << setw(16) << total << endl;
		}
		else if (total >= 16384 && total <= 32768) {
			cout << setw(15) << total << endl;
		}
		else if (total > 32768 && total <= 65535) {
			cout << setw(15) << total << endl;
		}
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