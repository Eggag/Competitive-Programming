#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string word;
	cin >> word;
	string match = "hello";
	int j = 0;
	for(int i = 0; i < word.size(); i++){
		if(word[i] == match[j]){
			j++;
		}	
	}
	if(j == 5){
		cout << "YES" << endl;	
	}
	else{
		cout << "NO" << endl;
	}
}
