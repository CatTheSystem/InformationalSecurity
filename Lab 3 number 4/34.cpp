#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int levenshtein_distance(const string& s1, const string& s2)
{
	vector<vector<int>> d(s1.length() + 1, vector<int>(s2.length() + 1));

	d[0][0] = 0;
	for(int i = 1; i <= s1.length(); ++i) {
		d[i][0] = i;	
	}
	for(int i = 1; i <= s2.length(); ++i) {
		d[0][i] = i;
	}

	for(int i = 1; i <= s1.length(); ++i) {
		for(int j = 1; j <= s2.length(); ++j) {
			d[i][j] = min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });
		}
	}

	return d[s1.length()][s2.length()];
}

int main(){
	int Index, TempInt,yes, Variable_Var, i = 0;
	string Line, OutLine = "";
	string Dictionary[20000], Verbs[20000], Yep[20000];
	ofstream OutputFile("output.txt");
	ifstream InputFile ("input.txt");
	
	if (InputFile.is_open())
	{
		getline(InputFile, Line);
		Index = Line[0] - '0';
		TempInt = Line[2] - '0';
		for (i = 0; i < Index;i++) getline(InputFile, Dictionary[i]);
		for (i = 0; i < TempInt;i++) getline(InputFile, Verbs[i]);
	}
	else cout << "Unable to open input.txt file";
	
	if (OutputFile.is_open())
	{
	Variable_Var=0;
	for (i = 0; i < TempInt;i++) {
	OutputFile << Verbs[i];
		for (int k = 0; k < Index; k++){
			string TempStr = Verbs[i];
			reverse(TempStr.begin(),TempStr.end());
			if (levenshtein_distance(Verbs[i],Dictionary[k]) <= 1 or levenshtein_distance(TempStr,Dictionary[k]) <=1){
				Variable_Var++;
				Yep[Variable_Var] = Dictionary[k];
			}
		}
	yes = 0;
	OutputFile << " " << Variable_Var;
	if (Variable_Var==1){
		OutputFile << " " << Yep[1];
	}
	OutputFile <<endl;
	Variable_Var = 0;
	}
	}
	else cout << "Unable to open output.txt file";
	cout << "Task executed sucessfuly";
	return 0;	
}