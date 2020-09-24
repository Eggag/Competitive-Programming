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
	int n, r;
	cin >> n >> r;
	vi x(n);
	rep(i, n) cin >> x[i];
	vector<ld> h(5000, 0); //height of an x column
	vector<ld> res(n);
	rep(i, n){
		ld ans = r;
		if(!h[x[i]]) ans = r;
		else ans = h[x[i]] + (2 * r);
		repn(j, max(0, (x[i] - (2 * r))), (x[i] + (2 * r)) + 1) if(h[j] && j != x[i]){
			//look at all columns that might be touching the current disk
			ld one = (ld)((abs(x[i] - j)) * (abs(x[i] - j))); //the base
			ld two = (ld)((r * 2) * (r * 2)); //the diagonal
			ld cur = (ld)(sqrt(two - one));
			if(((cur + h[j]) > ans)) ans = cur + h[j];
		}
		h[x[i]] = ans; //update height
		res[i] = ans;
	}
	cout << fixed << setprecision(15);
	rep(i, n) cout << res[i] << " ";
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
