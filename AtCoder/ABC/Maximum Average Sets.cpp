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

ll C[55][55];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	rep(i, 55){
		C[i][0] = C[i][i] = 1LL;
		repn(j, 1, i){
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
		}
	}
	int n, a, b;
	cin >> n >> a >> b;
	vector<ld> v(n);
	rep(i, n) cin >> v[i];
	sort(all(v));
	reverse(all(v));
	ld sum = 0;
	rep(i, a) sum += v[i];
	sum /= (ld)(a);
	cout << fixed << setprecision(10) << sum << endl;
	int ind = a - 1;
	int cnt = 1;
	int l = 0;
	while(ind < n && v[ind] == v[a - 1]) ind++, cnt++;
	ind = a - 1;
	while(ind >= 0 && v[ind] == v[a - 1]) ind--, cnt++, l++;
	cnt -= 2;
	if(ind == -1){
		ll ans = 0;
		repn(i, a, min(b + 1, cnt + 1)) ans += C[cnt][i];
		cout << ans << endl;
	}
	else{
		cout << C[cnt][l] << endl;
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
