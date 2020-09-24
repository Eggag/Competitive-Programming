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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi f(n);
	vi v(200005, 0);
	vi pos(200005, 1);
	rep(i, n){
		cin >> f[i], v[f[i]] = 1;
		if(f[i]) pos[i] = 0;
	}
	vi c;
	repn(i, 1, n + 1) if(!v[i]) c.pb(i);
	rep(i, n){
		if(!f[i]){
			f[i] = c[(int)c.size() - 1];
			c.pop_back();
		}
	}
	vi b;
	rep(i, n){
		if(f[i] == (i + 1)) b.pb(i);	
	}
	for(int i = 1; i < (int)b.size(); i += 2){
		swap(f[b[i]], f[b[i + 1]]);
	}
	if(b.size() & 1){
		//one more to take care of
		rep(i, n) if(i != b[0] && pos[i]){
			swap(f[i], f[b[0]]);
			break;
		}
	}
	rep(i, n){
		assert(f[i] != (i + 1));
		cout << f[i] << " ";
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
