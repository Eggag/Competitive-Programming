#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

void solve(){
	int l, r;
	cin >> l >> r;
	int ans = 0;
	if(l % 2 == 0){
		ans -= (r - l + 1) / 2;
		if((r - l + 1) % 2 != 0){
			if(r % 2 == 0) ans += r;
			else ans -= r;	
		}
	}
	else{
		ans += (r - l + 1) / 2;
		if((r - l + 1) % 2 != 0){
			if(r % 2 == 0) ans += r;
			else ans -= r;	
		}
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
