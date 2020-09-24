#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	int q;
	cin >> q;
	vi type(q), p(q), x1(q);
	rep(i, q){
		cin >> type[i];
		if(type[i] == 1){
			cin >> p[i];
			p[i]--;
		}
		cin >> x1[i];
	}
	int x = 0;
	vi v(n, 0);
	for(int i = q - 1; i >= 0; i--){
		if(type[i] == 1){
			if(v[p[i]]) continue;
			v[p[i]] = 1;
			a[p[i]] = max(x, x1[i]);
		}
		else{
			x = max(x, x1[i]);
		}
	}
	rep(i, n){
		if(v[i]){
			cout << a[i] << " ";
		}
		else{
			cout << max(a[i], x) << " ";
		}
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
