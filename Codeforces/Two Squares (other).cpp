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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<pi> a(4), b(4);

bool insq(int x, int y){
	return (y >= a[0].se && y <= a[1].se && x >= a[0].fi && x <= a[2].fi);
}

bool insq1(int x, int y){
	if(!(y >= a[0].se && y <= a[1].se && x >= a[0].fi && x <= a[2].fi)) return 0;
	int cur = 0;
	//check the / and \ lines
	if(y <= (b[0].se + (x - b[0].fi))) cur++;
	if(y >= (b[1].se + (b[1].fi - x))) cur++;
	if(y <= (b[3].se + (b[3].fi - x))) cur++;
	if(y >= (b[1].se + (x - b[1].fi))) cur++;
	if(cur == 4) return 1;
	else return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	rep(i, 4) cin >> a[i].fi >> a[i].se;
	rep(i, 4) cin >> b[i].fi >> b[i].se;
	sort(all(a));
	sort(all(b));
	repn(i, -200, 201){
		repn(j, -200, 201) if(insq(i, j) && insq1(i, j)){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
