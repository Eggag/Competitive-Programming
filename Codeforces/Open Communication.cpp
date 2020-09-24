#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
 
int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
bool oneq(pi a, pi b){
	if(a.fi == b.fi){
		if(a.se == b.se) return 0;
		else return 1;
	}
	if(a.fi == b.se){
		if(a.se == b.fi) return 0;
		else return 1;
	}
	if(a.se == b.fi){
		if(a.fi == b.se) return 0;
		else return 1;
	}
	if(a.se == b.se){
		if(a.fi == b.fi) return 0;
		else return 1;
	}
	return 0;
}
 
bool twoeq(pi a, pi b){
	if(min(a.fi, a.se) == min(b.fi, b.se) && max(a.fi, a.se) == max(b.fi, b.se)){
		return 1;
	}
	return 0;
}

int checksame(pi a, pi b){
	if(a.fi == b.fi) return a.fi;
	if(a.fi == b.se) return a.fi;
	if(a.se == b.fi) return a.se;
	if(a.se == b.se) return a.se;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pi> v1, v2;
	rep(i, n){
		int a, b;
		cin >> a >> b;
		v1.pb(mp(a, b));
	}
	rep(i, m){
		int a, b;
		cin >> a >> b;
		v2.pb(mp(a, b));
	}
	int ans = 0;
	set<int> pos;
	rep(i, n){
		int g;
		set<int> cur;
		rep(j, m){
			if(oneq(v1[i], v2[j]) && !twoeq(v1[i], v2[j])){
				g = checksame(v1[i], v2[j]);
				pos.insert(g);
				cur.insert(g);
			}
		}
		if(cur.size() > 1){
			cout << -1 << endl;
			return 0;
		}
	}
	rep(i, m){
		int g;
		set<int> cur;
		rep(j, n){
			if(oneq(v2[i], v1[j]) && !twoeq(v2[i], v1[j])){
				g = checksame(v2[i], v1[j]);
				pos.insert(g);
				cur.insert(g);
			}
		}
		if(cur.size() > 1){
			cout << -1 << endl;
			return 0;
		}
	}
	if(pos.size() == 1){
		cout << *pos.begin() << endl;
	}
	else{
		cout << 0 << endl;
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
