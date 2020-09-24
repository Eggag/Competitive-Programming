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

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

pi ask(int num){
	cout << "? " << num << endl;
	int a, b;
	cin >> a >> b;
	return mp(a, b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, start, x;
	cin >> n >> start >> x;
	pi cur = ask(start);
	if(cur.fi >= x){
		cout << "! " << cur.fi << endl;
		return 0;
	}
	int mx = cur.fi;
	int best = cur.se;
	rep(i, 999){
		int ind = (rng() % n) + 1;
		pi nw = ask(ind);
		if(nw.fi == x){
			cout << "! " << nw.fi << endl;
			return 0;
		}
		if(nw.fi < x && nw.fi >= mx){
			mx = nw.fi;
			best = nw.se;
		}
	}
	if(mx == x){
		cout << "! " << mx << endl;
		return 0;
	}
	int ind1 = best;
	rep(i, 999){
		if(ind1 == -1){
			cout << "! -1" << endl;
			return 0;
		}
		pi tmp = ask(ind1);
		ind1 = tmp.se;
		if(tmp.fi >= x){
			cout << "! " << tmp.fi << endl;
			return 0;
		}
	}
	cout << "! -1" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
