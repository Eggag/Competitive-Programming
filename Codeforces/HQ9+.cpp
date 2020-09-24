#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string ans;
	cin >> ans;
	for(int i = 0; i < ans.size(); i++){
		if(ans[i] == 'H' || ans[i] == 'Q' || ans[i] == '9'){
			cout << "YES" << endl;
			return 0;
		}
	}	
	cout << "NO" << endl;
	return 0;
}
