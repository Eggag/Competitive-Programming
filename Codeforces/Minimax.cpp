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

void solve(){
	string s1;
	cin >> s1;
	int n = (int)(s1.size());
	vi cnt(30, 0);
	int nm = 0, mx = 0;
	rep(i, n){
		int cr = (int)(s1[i] - 'a');
		if(!cnt[cr]) nm++;
		cnt[cr]++;
		mx = max(mx, cnt[cr]);
	}
	int mn = 1e9;
	rep(i, 30) if(cnt[i] > 0) mn = min(mn, cnt[i]);
	if(nm == 1){
		cout << s1 << '\n';
		return;
	}
	if(mx == 1){
		sort(all(s1));
		cout << s1 << '\n';
		return;
	}
	if(mn == 1){
		rep(i, 30) if(cnt[i] == 1){
			cout << (char)('a' + i);
			cnt[i]--;
			break;
		}
		rep(j, 30) if(cnt[j]){
			char nw = (char)('a' + j);
			rep(l, cnt[j]) cout << nw;
		}
		cout << '\n';
		return;
	}
	if(nm == 2){
		char a = '.', b = '.';
		int a1 = -1, b1 = -1;
		vi cnt2 = cnt;
		rep(i, 26) if(cnt[i]){
			if(a == '.') a = (char)('a' + i), a1 = i;
			else b = (char)('a' + i), b1 = i;
		}
		string s = "";
		if(cnt[a1] <= (cnt[b1] + 2)){
			string s1 = "";
			s1 += a;
			rep(i, cnt2[b1]) s1 += b;
			rep(i, cnt2[a1] - 1) s1 += a;
			if(cnt[a1] <= 2){
				rep(i, cnt[a1]) s += a;
				rep(i, cnt[b1]) s += b;
				cout << min(s1, s) << '\n';
				return;
			}
			rep(i, 2) s += a;
			cnt[a1] -= 2;
			while(cnt[a1]--){
				s += b;
				s += a;
				cnt[b1]--;
			}
			rep(i, cnt[b1]) s += b;
			cout << min(s1, s) << '\n';
		}
		else{
			string s1 = "";
			s1 += a;
			rep(i, cnt2[b1]) s1 += b;
			rep(i, cnt2[a1] - 1) s1 += a;
			if(cnt[b1] <= 2){
				rep(i, cnt[b1]) s += b;
				rep(i, cnt[a1]) s += a;
				cout << min(s1, s) << '\n';
				return;
			}
			rep(i, 2) s += b;
			cnt[b1] -= 2;
			while(cnt[b1]--){
				s += a;
				s += b;
				cnt[a1]--;
			}
			rep(i, cnt[a1]) s += a;
			cout << min(s1, s) << '\n';
		}
		return;
	}
	rep(i, 26) rep(j, 26){
		vi cnt1 = cnt;
		int ff = 1;
		cnt1[i]--;
		cnt1[j]--;
		if(cnt1[i] < 0 || cnt1[j] < 0) continue;
		string cr = "";
		char a = (char)('a' + i);
		char b = (char)('a' + j);
		cr += a;
		cr += b;
		if(i == j){
			rep(k, 30) if(cnt1[k]){
				if(k == i){
					int f = 0;
					repn(l, k + 1, 30) if(cnt1[l]){
						cr += (char)('a' + l);
						cnt1[l]--;
						f = 1;
						break;
					}
					if(!f) goto bd;
				}
				break;
			}
		}
		rep(k, min(i, j)){
			char nw = (char)('a' + k);
			rep(l, cnt1[k]) cr += nw;
		}
		repn(k, min(i, j) + 1, max(i, j)) if(cnt1[k]) ff = 0;
		if(i == j){
			string de = "";
			repn(k, i + 1, 30){
				char nw = (char)('a' + k);
				rep(l, cnt1[k]) de += nw;
			}
			if(cnt1[i]){
				rep(k, cnt1[i]){
					if(k != cnt1[i] - 1 && k == (int)(de.size())) goto bd;
					cr += a;
					if(k != cnt1[i] - 1){
						cr += de[k];
						cnt1[de[k] - 'a']--;
					}
				}
			}
			repn(k, i + 1, 30){
				char nw = (char)('a' + k);
				rep(l, cnt1[k]) cr += nw;
			}
		}
		else if(ff){
			if(cnt1[i] && !cnt1[j]){
				rep(l, cnt1[i]) cr += a;
			}
			else if(!cnt1[i] && cnt1[j]){
				rep(l, cnt1[j]) cr += b;
			}
			else{
				int f2 = 0;
				char ch = '.';
				repn(k, j + 1, 30) if(cnt1[k]){
					ch = (char)('a' + k);
					cnt1[k]--;
					f2 = 1;
					break;
				}
				if(!f2) goto bd;
				rep(l, cnt1[i]) cr += a;
				cr += ch;
				rep(l, cnt1[j]) cr += b;
			}
			repn(k, j + 1, 30){
				char nw = (char)('a' + k);
				rep(l, cnt1[k]) cr += nw;
			}
		}
		else{
			repn(k, min(i, j), 30){
				char nw = (char)('a' + k);
				rep(l, cnt1[k]) cr += nw;
			}
		}
		cout << cr << '\n';
		return;
		bd:;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
