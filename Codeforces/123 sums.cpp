#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string sum;
	cin >> sum;
	vector<int> ans;
	for(int i = 0; i < sum.size(); i += 2){
		ans.push_back(int(sum[i]) - 48);
	}
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
		if(i != (ans.size() - 1)){
			cout << "+";
		}
	}
	cout << endl;
	return 0;
}
