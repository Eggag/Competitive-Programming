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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ld> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	sort(all(a));
	sort(all(b));
	reverse(all(a));
	reverse(all(b));
	ld mn = 0.0;
	int ind = 0, ind1 = 0;
	ld sm = 0.0, sm1 = 0.0;
	rep(i, 2 * n){
		if(ind < n && ind1 < n){
			if(sm < sm1){
				sm += a[ind];
				ind++;
			}
			else{
				sm1 += b[ind1];
				ind1++;
			}
		}
		else if(ind < n){
			sm += a[ind];
			ind++;
		}
		else if(ind1 < n){
			sm1 += b[ind1];
			ind1++;
		}
		mn = max(mn, min((ld)(sm - (i + 1)), (ld)(sm1 - (i + 1))));
	}
	cout << fixed << setprecision(4) << mn << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
