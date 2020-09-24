#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	rep(i, n){
		cin >> a[i];
	}
	vector<pi> ans;
	rep(i, n){
		int j = i;
		repn(t, i, n){
			if(a[j] > a[t]) j = t;
		}
		if(i != j) ans.pb(mp(i, j));
		swap(a[i], a[j]);
	}
	cout << ans.size() << endl;
	rep(i, ans.size()){
		cout << ans[i].fi << " " << ans[i].se << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
