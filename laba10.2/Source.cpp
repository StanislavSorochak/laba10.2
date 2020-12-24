#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ReadFile(ifstream& inFile, string& str, string& fileName);
void DeleteSpaceFromSide(string& str);
void ReplaceSpace(string& str);
void WriteToFile(ofstream& inFile, string& str, string& fileName);

int main()
{
	string str;

	ifstream inFile;
	string fileNameFrom = "..\\Files\\Input.txt";

	ofstream outFile;
	string fileNameTo = "..\\Files\\Output.txt";

	ReadFile(inFile, str, fileNameFrom);
	DeleteSpaceFromSide(str);
	ReplaceSpace(str);
	WriteToFile(outFile, str, fileNameTo);

	inFile.close();
	outFile.close();

	return 0;
}


void ReadFile(ifstream& inFile, string& str, string& fileName)
{
	inFile.open(fileName);

	if (!inFile.is_open())   // не удалось открыть файл  
	{
		cout << "Could not open the file " << fileName << endl;
		cout << "Program terminating\n";
		exit(EXIT_FAILURE);  // EXIT_FAILURE - значение аргумента, используемого для взаимодействия программы с операционной системой. Функ exit() завершает программу
	}

	string temp;

	while (!inFile.eof())
	{
		getline(inFile, temp);
		str += temp;
	}

}

void DeleteSpaceFromSide(string& str)
{
	int i = 0;

	while (str[i] == ' ')
	{
		str.erase(i, 1);
	}



	i = str.size() - 1;

	while (str[i] == ' ')
	{
		str.erase(i, 1);
		i--;
	}
}

void ReplaceSpace(string& str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
			{
				str.erase(i, 1);
			}

			str.insert(str.begin() + i, ' ');
		}
	}
}

void WriteToFile(ofstream& outFile, string& str, string& fileName)
{
	outFile.open(fileName);

	outFile << str << endl;
}
