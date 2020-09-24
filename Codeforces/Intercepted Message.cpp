#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi x(n), y(m);
	rep(i, n) cin >> x[i];
	rep(i, m) cin >> y[i];
	int ans = 1;
	int a1 = x[0];
	int i1 = 1;
	int a2 = y[0];
	int i2 = 1;
	while(i1 < n || i2 < m){
		if(a1 == a2){
			ans++;
			if(i1 == n){
				a2 += y[i2];
				i2++;
			}
			else if(i2 == n){
				a1 += x[i1];
				i1++;
			}
			else{
				if(x[i1] < y[i2]){
					a1 += x[i1];
					i1++;
				}
				else{
					a2 += y[i2];
					i2++;
				}
			}
		}
		else if(a1 < a2){
			a1 += x[i1];
			i1++;
		}
		else if(a2 < a1){
			a2 += y[i2];
			i2++;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
