#include <bits/stdc++.h>
using namespace std;

int main(){
	string dword;
	cin >> dword;
	string word;
	int it;
	if(dword.size() % 2 != 0){
		word.push_back(dword[dword.size()/2]);
		it = dword.size()/2;
	}
	else{
		word.push_back(dword[(dword.size()/2) - 1]);
		it = (dword.size()/2) - 1;
	}
	int a = 1;
	int b = 1;
	for(int i = 1; i < dword.size(); i++){
		if(i % 2 != 0){
			word.push_back(dword[it + a]);
			a++;
		}
		else{
			word.push_back(dword[it - b]);
			b++;
		}
	}
	cout << word << endl;
	return 0;
}
