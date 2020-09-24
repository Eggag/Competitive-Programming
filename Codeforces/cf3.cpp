#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	string ans[t];
	for(int i = 0; i < t; i++){
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		if(str[0] == str[str.size() - 1]){
			ans[i] = "-1";
		}
		else{
			ans[i] = str;
		}
	}
	for(int i = 0; i < t; i++){
		cout << ans[i] << endl;
	}
	return 0;
}
