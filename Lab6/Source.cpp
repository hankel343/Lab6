#include <iostream>
#include <fstream>

using namespace std;

int ReadFile(ifstream& inFile);

int main()
{
	ifstream inFile;

	ReadFile(inFile);

	return 0;
}

int ReadFile(ifstream& inFile) {

	char input;
	int powerOfTwo = 0;
	int sum = 0;

	inFile.open("test.txt");

	if (!inFile) {
		cout << "Input file failed to open.";
		return 1;
	}

	inFile.get(input);

	int bitPosition = 0;
	while (inFile) {

		if (bitPosition == 0)
			powerOfTwo += 1;
		else
			powerOfTwo = (powerOfTwo * 2);

		sum += powerOfTwo;

		cout << sum << endl;

		bitPosition++;
		inFile.get(input);
	}

	inFile.close();

}