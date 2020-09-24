#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool check(int c, int m, int x, int num){
	int add = x;
	int cnt = 0;
	if(c >= num) add += c - num, cnt++;
	if(m >= num) add += m - num, cnt++;
	if(cnt != 2) return 0;
	if(add >= num) return 1;
	else return 0;
}

void solve(){
	int c, m, x;
	cin >> c >> m >> x;
	int l = 0, r = ((c + m + x) / 3);
	while(l < r){
		int mid = (r + l + 1) / 2;
		if(check(c, m, x, mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
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
