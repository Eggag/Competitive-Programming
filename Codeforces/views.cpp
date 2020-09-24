#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	ll m;
	cin >> n >> m;
	ll a[n];
	ll ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	ll need = a[n - 1];
	ll cur = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > 1){
			ans += a[i] - 1;	
		}
		if(a[i] > cur){
			cur++;
		}
	}
	ans -= need - cur;
	cout << ans << endl;
	return 0;
}
