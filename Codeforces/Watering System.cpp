#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, A, B;
	cin >> n >> A >> B;
	vector<pi> s(n);
	ll sum = 0;
	int st;
	rep(i, n){
		int x;
		cin >> x;
		if(!i){
			st = x;
		}
		s[i] = mp(x, i);
		sum += x;
	}
	sort(all(s));
	int ind = n - 1;
	int ans = 0;
	while(((st * A) / sum) < B){
		ans++;
		if(!s[ind].se) ind--;
		sum -= s[ind].fi;
		ind--;
		
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
