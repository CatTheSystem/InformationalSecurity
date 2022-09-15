#include <iostream>
#include <fstream>
using namespace std;

string* RecursivePermutation(string Line, int NumberOfPermutations, int From, string* ReturnArray) {
	if (NumberOfPermutations > 0)
	{
		string TempLine = "";
		string character = "";
		for (int i = From; i <= 10 - NumberOfPermutations; i++)
		{
			TempLine = Line;
			character = TempLine[i];
			if (character == "f")
			{
				character = "t";
			}
			else
			{
				character = "f";
			}
			int n = 0;
			while (ReturnArray[n].empty()){
				n++;
			}
			ReturnArray = RecursivePermutation(TempLine.replace(i, 1, character), NumberOfPermutations - 1, i + 1, ReturnArray);
		}
	}
	else
	{
		int n = 0;
		while (!(ReturnArray[n].empty()))
		{
			n++;
		}
		ReturnArray[n] = Line;
		return ReturnArray;
	}
	return ReturnArray;
}

string* CompareArrays(string* FirstArray, string* SecondArray) {
	int n = 0;
	int k = 0;
	int count = 0;
	string tmp1,tmp2;
	while(!(FirstArray[n].empty()))
	{
		tmp1 = FirstArray[n];
		tmp1.pop_back();
		while(!(SecondArray[k].empty()))
		{
			tmp2 = SecondArray[k];
			tmp2.pop_back();
			if (tmp1 == tmp2)
			{
				count++;
			}
			k++;
		}
		k = 0;
		if (count == 0)
		{
			FirstArray[n] = "";
		}
		count = 0;
		n++;
	}
	n = 0;
	while(!(FirstArray[n].empty()))
	{
		n++;
	}
	k = n;
	while(k < 30240){
		while((FirstArray[k].empty()))
		{
			k++;
			if(k == 30240)
			{
				return FirstArray;
			}
		}
		if (!(k == 30240))
		{
			FirstArray[n++] = FirstArray[k];
		}
		k++;
	}
	return FirstArray;
}


int main() {
	int TempInt = 0;
	int n = 0;
	string Line = "";
	string InputArray[100], PermutationMainArray[30240], PermutationTempArray[30240];
	ofstream OutputFile("output.txt");
	ifstream InputFile ("input.txt");
	
	if (InputFile.is_open())
	{
		getline(InputFile, Line);
		while (getline(InputFile,Line))
		{
			InputArray[TempInt++] = Line;
		}
		TempInt = 0;
	}
	else cout << "Unable to open input.txt file";
	
	TempInt = 0;
	RecursivePermutation(InputArray[TempInt], InputArray[TempInt][10] - '0', 0, PermutationMainArray);
	while (!(InputArray[TempInt+1].empty()))
	{
		CompareArrays(PermutationMainArray, RecursivePermutation(InputArray[TempInt+1], InputArray[TempInt + 1][10] - '0', 0, PermutationTempArray));
		while (!(PermutationTempArray[n].empty()))
		{
			PermutationTempArray[n] = "";
			n++;
		}
		TempInt++;
	}
	
	TempInt = 0;
	Line = PermutationMainArray[0];
	while (!(PermutationMainArray[++TempInt].empty()))
	{
		if (PermutationMainArray[TempInt] == Line)
		{
			PermutationMainArray[TempInt] = "";
		}
	}
	
	if (OutputFile.is_open())
	{
		if (PermutationMainArray[1].empty())
		{
			OutputFile << "ONE SOLUTION\n" << Line;
		}
		else
		{
			OutputFile << "POSSIBLE SOLUTION\n" << Line;
		}
	}
	else cout << "Unable to open output.txt file";
	cout << "Tusk executed sucsefully";
    return 0;
}