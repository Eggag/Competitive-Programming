#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, k;
	cin >> t;
	vector<string> answers;
	for(int i = 0; i < t; i++){
		cin >> n >> k;
		string ans;
		for(int a = 0; a < k; a++){
			char l = (char)('a' + a);
		        ans.push_back(l);
		}
		for(int i = k; i < n; i++){
			ans.push_back(ans[i - k]);
		}
		answers.push_back(ans);
	}
	for(int i = 0; i < t; i++){
		cout << answers[i] << endl;
	}
}
