#include <iostream>
#include <fstream>


using namespace std;

int main()
{
	ifstream inFile;
	char input;

	cout << "Binary Number:" << "\t\tDecimal Equivalent:" << endl;

	inFile.open("test.txt");

	inFile.get(input);

	int decimalNum = 0;
	int position = 0;
	string binaryNum = "";
	while (inFile) {

		
		if (input == '1') {

			binaryNum += input;
			decimalNum = (decimalNum * 2) + 1;
			position++;
		}
		else if (input == '0') {

			binaryNum += input;
			decimalNum = (decimalNum * 2) + 0;
			position++;
		}
		else if (input == '\n' && position == 0) { //If the cursor reads a newline character on the first line for a character
			inFile.get(input);
			continue; //Re-evaluate logic from beginning of the loop with the new character.
		}
		else if ((int(input) < '0' || int(input) > '1') && (input != ' ') || (input == ' ' && position > 0)) { //If the ASCII code is less than '0' or greater than '1' AND NOT space (32 ASCII code)

			cout << "Bad data on input\n"; //Print error message to the console

			//Resets counters for the next line of input
			position = 0;
			decimalNum = 0;
			binaryNum = "";

			//Ignores all data on the input line with bad data
			inFile.ignore(1000, '\n');
		}

		inFile.get(input);

		if ((input == '\n' && position > 0) || (!inFile)) { //If file input cursor has read a new line where the position is atleast one OR reached end of file

			cout << binaryNum << ' ' << decimalNum << endl; //Display the current binary number and decimal number computed for the line

			//Resets counters for the next line of input
			position = 0;
			decimalNum = 0;
			binaryNum = "";
		}
		
	}




	return 0;
}