#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<int> ans;
	int x = 0;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		x = max(0, x - a);
		x += b;
		ans.push_back(x);
	}
	sort(ans.begin(), ans.end());
	cout << ans[n - 1] << endl;
	return 0;
}
