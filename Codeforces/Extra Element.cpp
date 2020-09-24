#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
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
	int n;
	cin >> n;
	vector<ll> a(n), b(n), c(n);
	rep(i, n) cin >> a[i], b[i] = a[i], c[i] = a[i];
	sort(all(a));
	sort(all(c));
	ll d = a[1] - a[0];
	int cnt = 0;
	int ans = -1;
	int f = 0;
	ll sto = 0;
	int fl = 0;
	repn(i, 2, n){
		if(a[i] - a[i - 1] != d){
			if(cnt == 0) ans = i, cnt++, f = 1;
			else{
				fl = 1;
			}
		}
		if(f){
			sto = a[i];
			a[i] = a[i - 1];
			f = 0;
		}
	}
	if(ans == -1){
		cout << find(all(b), c[0]) - b.begin() + 1 << endl;
		return 0;
	}
	int fl2 = 0;
	if(fl == 1){
		ll dist = c[2] - c[1];
		repn(i, 3, n){
			if(c[i] - c[i - 1] != dist){
				fl2 = 1;
			}
		}
		if(fl2 == 0){
			cout << find(all(b), c[0]) - b.begin() + 1 << endl;
			return 0;
		}
	}
	if(fl2){
		ll distance = c[2] - c[0];
		repn(i, 3, n){
			if(c[i] - c[i - 1] != distance){
				cout << -1 << endl;
				return 0;
			}
		}
		cout << find(all(b), c[1]) - b.begin() + 1 << endl;
		return 0;
	}
	cout << (find(all(b), sto) - b.begin()) + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
