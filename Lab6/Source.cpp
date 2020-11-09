#include <iostream>
#include <fstream>


using namespace std;

void ReadFile(ifstream& inFile);

int main()
{
    ifstream inFile;


    ReadFile(inFile);


    return 0;
}

void ReadFile(ifstream& inFile) {

    char input;
    int total = 0, num = 0;
    string binaryNum = "";

    inFile.open("test.txt");

    if (!inFile) { //If input file fails to open
        cout << "The input file failed to open\n";
    }



    while (inFile.get(input)) {

        if (input == '1') { //Checks to see if input is a 1
            binaryNum += input; //Adds the '1' to the binaryNum string
            total = (total * 2) + 1; // Multiplying by two accounts for the next highest place value in binary
            num++; //Reads place value in binary
        }
        else if (input == '0') { //Checks to see if input is a 0
            binaryNum += input; //Adds a '0' to the binaryNum string
            total = (total * 2) + 0; //Multiplying by two accounts for the next hightest place value in binary, and the current value isn't added because it is a 0.
            num++;
        }
        else if ((isalpha(input)) || (input == ' ' && num > 0)) { //if (input(is a letter)) OR there is a space between binary values)
            binaryNum = "";
            total = 0;
            num = 0;
            cout << "Bad data on input" << endl;
            inFile.ignore(1000, '\n');
        }
        else if (input == '\n' && num == 0) {
            continue;
        }

        if (input == '\n' && num > 0) {
            cout << binaryNum << ' ' << total << endl;
            total = 0;
            num = 0;
            binaryNum = "";
        }

    }

}