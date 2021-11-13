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

int n;

bool cmp(array<int, 4> a, array<int, 4> b){
	if(a[0] != b[0]) return a[0] < b[0];
	return a[3] > b[3];
}

bool check(vi sa, vi ea, vi sb, vi eb){
	multiset<int> a, b;
	vector<array<int, 4>> p;
	rep(i, n){
		p.pb(array<int, 4>{sa[i], sb[i], eb[i], 1});
		p.pb(array<int, 4>{ea[i], sb[i], eb[i], 0});
	}
	sort(all(p), cmp);
	rep(i, 2 * n){
		if(p[i][3]){
			if(a.size()){
				if(p[i][1] > *b.begin()) return false;
				if(p[i][2] < *a.rbegin()) return false;
			}
			a.insert(p[i][1]);
			b.insert(p[i][2]);
		}
		else{
			a.erase(a.find(p[i][1]));
			b.erase(b.find(p[i][2]));
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	vi sa(n), ea(n), sb(n), eb(n);
	rep(i, n) cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
	if(check(sa, ea, sb, eb) && check(sb, eb, sa, ea)) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
