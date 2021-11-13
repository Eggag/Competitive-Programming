#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
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
	vector<pi> od, ev;
	repn(i, 1, n + 1) repn(j, 1, n + 1){
		if((i + j) & 1) od.pb(mp(i, j));
		else ev.pb(mp(i, j));
	}
	while((int)(od.size()) && (int)(ev.size())){
		int a;
		cin >> a;
		a--;
		if(a == 0){
			pi ls = ev.back();
			cout << 2 << " " << ls.fi << " " << ls.se << endl;
			ev.pop_back();
		}
		else{
			pi ls = od.back();
			cout << 1 << " " << ls.fi << " " << ls.se << endl;
			od.pop_back();
		}
	}
	if((int)(od.size())){
		while((int)(od.size())){
			int a;
			cin >> a;
			a--;
			if(a == 0){
				pi ls = od.back();
				cout << 3 << " " << ls.fi << " " << ls.se << endl;
				od.pop_back();
			}
			else{
				pi ls = od.back();
				cout << 1 << " " << ls.fi << " " << ls.se << endl;
				od.pop_back();
			}
		}
	}
	else{
		while((int)(ev.size())){
			int a;
			cin >> a;
			a--;
			if(a == 1){
				pi ls = ev.back();
				cout << 3 << " " << ls.fi << " " << ls.se << endl;
				ev.pop_back();
			}
			else{
				pi ls = ev.back();
				cout << 2 << " " << ls.fi << " " << ls.se << endl;
				ev.pop_back();
			}
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
