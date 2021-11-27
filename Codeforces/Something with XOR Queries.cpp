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

int ask(int a, int b){
	cout << "? " << a << " " << b << endl;
	int res;
	cin >> res;
	return res;
}

int main(){
	int n;
	cin >> n;
	vi cnt(20, 0), cnt1(20, 0), hm(n);
	rep(i, n) rep(j, 15) if(i & (1 << j)) cnt[j]++;
	rep(i, n){
		int cr = ask(0, i);
		hm[i] = cr;
		rep(j, 15) if(cr & (1 << j)) cnt1[j]++;
	}
	int ans = 0;
	vi pos;
	rep(i, 20) if(cnt[i]){
		if(cnt1[i] != cnt[i]) ans |= (1 << i);
		else{
			if(cnt[i] == (n / 2)){
				pos.pb(i);
			}
		}
	}
	vi owo;
	rep(i, (1 << (int)(pos.size()))){
		int uwu = ans;
		rep(j, pos.size()) if(i & (1 << j)) uwu |= (1 << pos[j]);
		if(uwu < n) owo.pb(uwu);
	}
	int orz = ask(0, 0), res = 0;
	vi r(n);
	repn(i, 1, n) r[i] = ask(i, 0);
	vi ez;
	rep(i, owo.size()){
		int ok = 1;
		vi b(n);
		rep(j, n){
			b[j] = (owo[i] ^ hm[j]);
			if(b[j] < 0 || b[j] > n) ok = 0;
		}
		if(!ok) continue;
		int fr = (owo[i] ^ orz);
		vi p(n, -1), vis(n, 0);
		p[0] = owo[i];
		vis[p[0]] = 1;
		repn(j, 1, n){
			p[j] = (r[j] ^ fr);
			if(p[j] < 0 || p[j] >= n || vis[p[j]]){
				ok = 0;
				break;
			}
			vis[p[j]] = 1;
		}
		rep(j, n) if(p[b[j]] != j) ok = 0;
		res += ok;
		if(ok && !ez.size()) ez = p;
	}
	cout << "!" << endl;
	cout << res << endl;
	rep(i, n) cout << ez[i] << ' ';
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
