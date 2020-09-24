#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	string stones;
	int ans = 0;
	cin >> stones;
	for(int i = 1; i < n; i++){
		if(stones[i] == stones[i - 1]){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
