#include <iostream>
#include <fstream>
#include <regex>
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
	
	Line = regex_replace(Line,regex("[^a-zA-Z]"),"");
	Line = regex_replace(Line,regex("([a-zA-Z])\\1{1}"),"");
	while(i<Line.length()){
		if(Line[i]==Line[i+1]){
			Line.replace(i,i+1,"");
			i=0;
		}else{
			i++;
		}
	}
	
	if (OutputFile.is_open())
	{
		OutputFile << Line <<endl;
	}
	else cout << "Unable to open output.txt file";
	cout << "Task executed sucessfuly";
	return 0;	
}