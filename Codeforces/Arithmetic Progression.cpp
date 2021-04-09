#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int a[mxN];
int q = 60;

mt19937 rng((ll)std::chrono::steady_clock::now().time_since_epoch().count());

int qry(int t, int x){
	q--;
	if(t == 1){
		cout << "? " << x << endl;
		int ret;
		cin >> ret;
		return a[x] = ret;
	}
	else{
		cout << "> " << x << endl;
		int ret;
		cin >> ret;
		return ret;
	}
}

int n;
vi p;

void check(int d, int mx){
	if((mx - (d * (n - 1))) < 0) return;
	if((mx - p[0]) % d != 0) return;
	if((mx - p[0]) / d >= n) return;
	cout << "! " << mx - (d * (n - 1)) << " " << d << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	memset(a, -1, sizeof(a));
	int l = 0, r = 1e9 + 1;
	while(l < r){
		int mid = (l + r) / 2;
		if(!qry(2, mid)) r = mid;
		else l = mid + 1;
	}
	int nm = 0;
	while(q && nm != n){
		int i = (int)(rng() % n) + 1;
		if(!~a[i]) qry(1, i), nm++;
		p.pb(a[i]);
	}
	int g = 0;
	sort(all(p));
	rep(i, p.size()) repn(j, i + 1, p.size()) g = gcd(g, p[j] - p[i]);
	for(int i = 1; (i * i) <= g; i++){
		check(i, l);
		check(g / i, l);
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
