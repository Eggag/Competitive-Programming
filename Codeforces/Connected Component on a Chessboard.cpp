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
	int q;
	cin >> q;
	while(q--){
		int b, w;
		cin >> b >> w;
		int sum = b + w;
		int ind = 3;
		if(b < w) ind = 2;
		int cntw = 0, cntb = 0;
		vector<pi> op;
		int mb = 0, mw = 0;
		while((!(ind % 2) && w) || (ind & 1 && b)){
			op.pb({2, ind});
			if(!(ind & 1)) w--, cntw++, mw = ind;
			else b--, cntb++, mb = ind;
			ind++;
		}
		if(!b && !w){
			cout << "YES" << endl;
			rep(i, op.size()) cout << op[i].fi << " " << op[i].se << endl;
			continue;
		}
		if(!b){
			if(w > (cntb * 2)){
				cout << "NO" << endl;
				continue;
			}
			int ind1 = 3;
			int cntb1 = cntb;
			while(w && cntb1 && ind1 <= mb){
				op.pb({1, ind1});
				ind1 += 2;
				w--;
				cntb1--;
			}
			ind1 = 3;
			while(w && cntb){
				op.pb({3, ind1});
				ind1 += 2;
				w--;
				cntb--;
			}
		}
		if(!w){
			if(b > (cntw * 2)){
				cout << "NO" << endl;
				continue;
			}
			int ind1 = 4;
			int cntw1 = cntb;
			while(b && cntw1 && ind1 <= mw){
				op.pb({1, ind1});
				ind1 += 2;
				b--;
				cntw1--;
			}
			ind1 = 4;
			while(b && cntw){
				op.pb({3, ind1});
				ind1 += 2;
				b--;
				cntw--;
			}
		}
		cout << "YES" << endl;
		assert((int)(op.size()) == sum);
		rep(i, op.size()) cout << op[i].fi << " " << op[i].se << endl;
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
