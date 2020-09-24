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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ld n;
	ld w;
	cin >> n >> w;
	cout << fixed << setprecision(15);
	vector<ld> a(2 * n);
	rep(i, (2 * n)) cin >> a[i];
	sort(all(a));
	ld cur = w / n;
	cur /= 1.50000;
	if(cur <= a[n] && (ld)(cur / 2) <= a[0]){
		cout << (ld)(n * (cur + (ld)(cur / 2))) << endl;
	}
	else{
		if(cur <= a[n] && (ld)(cur / 2) >= a[0]){
			cout << (ld)(n * (a[0] * 3)) << endl;
		}
		else if(cur >= a[n] && (ld)(cur / 2) <= a[0]){
			cout << (ld)(n * (a[n] + (ld)(a[n] / 2))) << endl;
		}
		else{
			ld ans = 0;
			if(a[n] >= (a[0] * 2)) ans = (ld)(n * (a[0] * 3));
			else ans = (ld)(n * (a[n] + (ld)(a[n] / 2)));
			cout << ans << endl;
		}
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
