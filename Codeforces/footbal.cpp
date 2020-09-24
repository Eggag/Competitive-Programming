#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string situation;
	cin >> situation;
	int cur = 0;
	for(int i = 0; i < situation.size(); i++){
		if(i == 0){
			cur++;
		}
		else{
			if(situation[i] == situation[i - 1] || cur == 0){
				cur++;
			}
			else{
				cur = 1;
			}
		}
		if(cur == 7){
			cout << "YES" << endl;
			break;
		}
		if(i == situation.size() - 1){
			if(cur < 7){
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
