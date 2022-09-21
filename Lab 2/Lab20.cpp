#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int Index, TempInt, i = 0;
	string Line, OutLine = "";
	string InputArray[100], OutputArray[10001];
	ofstream OutputFile("output.txt");
	ifstream InputFile ("input.txt");
	
	if (InputFile.is_open())
	{
		getline(InputFile, Line);
	}
	else cout << "Unable to open input.txt file";
	
	TempInt = 1;
	for (i = 0; i < Line.length() ; i++){
		if (Line[i] != Line[i+1]){
			if (TempInt != 1){
				OutputArray[Index++] = to_string(TempInt) + Line[i];
			} else {
				OutputArray[Index++] = Line[i];
			}
			TempInt = 1;
		} else {
			TempInt++;
		}
	}
	
	for (i = 0; i < Line.length() and OutputArray[i] != ""; i++){
		OutLine += OutputArray[i];		
	}
	
	if (OutputFile.is_open())
	{
		OutputFile << OutLine <<endl;
	}
	else cout << "Unable to open output.txt file";
	cout << "Task executed sucessfuly";
	return 0;	
}