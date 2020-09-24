#include <bits/stdc++.h>
using namespace std;

int main(){
	string name;
	cin >> name;
	vector<char> letters;
	int num = 0;
	for(int i = 0; i < name.size(); i++){
		if(find(letters.begin(), letters.end(), name[i]) == letters.end()){
			num++;
			letters.push_back(name[i]);	
		}
	}
	if(num % 2 == 0){
		cout << "CHAT WITH HER!" << endl;
	}
	else{
		cout << "IGNORE HIM!" << endl;
	}
	return 0 ;
}
