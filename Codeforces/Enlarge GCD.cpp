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
const int MAXN = 15000000;

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<bool> prime;
int p[(MAXN + 1)];

void sieve(ll n){
	prime.assign(n + 1, 1);
	prime[1] = 0;
	for(ll i = 2; i <= n; i++){
		if(prime[i]){
			for(ll j = i * 2; j <= n; j += i){
				prime[j] = 0;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	rep(i, n) cin >> a[i];
	int g = a[0];
	repn(i, 1, n) g = gcd(g, a[i]);
	rep(i, n) a[i] /= g;
	memset(p, 0, sizeof(p));
	rep(i, n) p[a[i]]++;
	sieve(MAXN);
	int mx = 0;
	repn(i, 2, MAXN + 1) if(prime[i]){
		int cnt = 0;
		for(int j = i; j <= MAXN; j += i) cnt += p[j];
		mx = max(mx, cnt);
	}
	if(!mx) cout << "-1" << endl;
	else cout << n - mx << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
