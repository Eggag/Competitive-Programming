#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string ans[n];
	for(int i = 0; i < n; i++){
		string word;
		string str = "";
		cin >> word;
		if(word.size() <= 10){
			ans[i] = word;
		}
		else{
			int s = word.size() - 2;
			str.push_back(word[0]);
			str += to_string(s);
			str.push_back(word[word.size() - 1]);
			ans[i] = str;
		}
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << endl;
	}
	return 0;
}
