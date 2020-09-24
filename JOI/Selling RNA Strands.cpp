#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
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
const int mxN = 1e5 + 5;
const int MOD = 12277039;
const int MOD2 = 112111211;
 
template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

struct HASH{
	size_t operator () (const pair<int, int> &x) const {
		return hash<long long>()(((long long)(x.first)) ^ (((long long)(x.second)) << 32));
	}
};

int n, m;
string s[mxN];
pair<pair<string, string>, int> p[mxN];
gp_hash_table<pi, int, HASH> hshs;
vector<pi> haS[mxN];
vector<pi> haS1[mxN];
vector<pi> haP[mxN];
pi h[mxN];

bool cmp(pair<pair<string, string>, int> a, pair<pair<string, string>, int> b){
	return a.fi.fi < b.fi.fi;
}
 
void add(int ind){
	//adds all the suffix hashes of s[ind]
	rep(i, s[ind].size()) hshs[haS1[ind][i]]++;
}

void del(int ind){
	//deletes all the suffix hashes of s[ind]
	rep(i, s[ind].size()) hshs[haS1[ind][i]]--;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> s[i];
	sort(s, s + n);
	rep(i, n){
		int hsh = 1, hsh1 = 1;
		for(int j = 1; j <= (int)s[i].size(); j++){
			hsh = (hsh * 31) + (s[i][j - 1] - 'a') + 1;
			hsh1 = (hsh1 * 37) + (s[i][j - 1] - 'a') + 1;
			hsh %= MOD;
			hsh1 %= MOD2;
			haS[i].pb(mp(hsh, hsh1));
		}
	}
	rep(i, n){
		int hsh = 1, hsh1 = 1;
		for(int j = (int)s[i].size(); j >= 1; j--){
			hsh = (hsh * 31) + (s[i][j - 1] - 'a') + 1;
			hsh1 = (hsh1 * 37) + (s[i][j - 1] - 'a') + 1;
			hsh %= MOD;
			hsh1 %= MOD2;
			haS1[i].pb(mp(hsh, hsh1));
		}
	}
	rep(i, m){
		cin >> p[i].fi.fi >> p[i].fi.se;
		p[i].se = i;
	}
	sort(p, p + m, cmp);
	rep(i, m){
		int hsh = 1, hsh1 = 1;
		for(int j = (int)p[i].fi.se.size(); j >= 1; j--){
			hsh = (hsh * 31) + (p[i].fi.se[j - 1] - 'a') + 1;
			hsh1 = (hsh1 * 37) + (p[i].fi.se[j - 1] - 'a') + 1;
			hsh %= MOD;
			hsh1 %= MOD2;
		}
		h[i] = mp(hsh, hsh1);
	}
	rep(i, m){
		int hsh = 1, hsh1 = 1;
		for(int j = 1; j <= (int)p[i].fi.fi.size(); j++){
			hsh = (hsh * 31) + (p[i].fi.fi[j - 1] - 'a') + 1;
			hsh1 = (hsh1 * 37) + (p[i].fi.fi[j - 1] - 'a') + 1;
			hsh %= MOD;
			hsh1 %= MOD2;
			haP[i].pb(mp(hsh, hsh1));
		}
	}
	vi ext(m, 0), ans(m, 0);
	repn(i, 1, m){
		if(p[i].fi.fi.size() >= p[i - 1].fi.fi.size()){
			int f = 1;
			rep(j, p[i - 1].fi.fi.size()){
				if(p[i].fi.fi[j] != p[i - 1].fi.fi[j]){
					f = 0;
					break;
				}
			}
			ext[i] = f;
		}
	}
	int l = 1e9, r = 0;
	int hii = 0;
	rep(i, m){
		if(ext[i]){
			//we would always narrow the [l, r] range
			if(l == 1e9){
				ans[p[i].se] = 0;
				continue;
			}
			//modify the range
			repn(j, l, r + 1){
				if(s[j].size() < p[i].fi.fi.size()){
					del(j);
					l++;
					continue;
				}
				if(haS[j][(int)p[i].fi.fi.size() - 1] == haP[i][(int)p[i].fi.fi.size() - 1]) break;
				del(j);
				l++;
			}
			for(int j = r; j >= l; j--){
				if(s[j].size() < p[i].fi.fi.size()){
					del(j);
					r--;
					continue;
				}
				if(haS[j][(int)p[i].fi.fi.size() - 1] == haP[i][(int)p[i].fi.fi.size() - 1]) break;
				del(j);
				r--;
			}
			if(l > r) l = 1e9;
		}
		else{
			l = 1e9, r = 0;
			hshs.clear();
			int lo = hii, hi = n - 1;
			while(lo < hi){
				int mid = (lo + hi + 1) / 2;
				if(s[mid] < p[i].fi.fi) lo = mid;
				else hi = mid - 1;
			}
			hii = max(hii, lo);
			if(lo == 0 && s[lo] >= p[i].fi.fi) lo = -1;
			int nm = 0;
			repn(j, lo + 1, n){
				if(s[j].size() < p[i].fi.fi.size()) break;
				if(haS[j][(int)p[i].fi.fi.size() - 1] != haP[i][(int)p[i].fi.fi.size() - 1]) break;
				add(j);
				nm += s[j].size();
				l = min(l, j), r = max(r, j);
			}
		}
		ans[p[i].se] = hshs[h[i]];
	}
	rep(i, m) cout << ans[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
