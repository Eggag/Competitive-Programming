#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int ans = INT_MAX;
	for(int i = 1; i < k; i++){
		if(n % i == 0){
			ans = min(ans, n/i * k + i);
		}
	}
	cout << ans << endl;
	return 0;
}
