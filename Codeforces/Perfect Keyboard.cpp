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

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	int nm[30][30];
	memset(nm, 0, sizeof(nm));
	vi num(30, 0);
	rep(j, 26){
		rep(i, n){
			if(s[i] == (char)('a' + j)){
				if(i > 0){
					if(!nm[s[i] - 'a'][s[i - 1] - 'a']){
						nm[s[i] - 'a'][s[i - 1] - 'a'] = 1;
						num[s[i] - 'a']++;
						if(num[s[i] - 'a'] > 2){
							cout << "NO" << endl;
							return;
						}
					}
				}
				if(i != (n - 1)){
					if(!nm[s[i] - 'a'][s[i + 1] - 'a']){
						nm[s[i] - 'a'][s[i + 1] - 'a'] = 1;
						num[s[i] - 'a']++;
						if(num[s[i] - 'a'] > 2){
							cout << "NO" << endl;
							return;
						}
					}
				}
			}
		}
	}
	int on = 0;
	rep(i, 26) if(num[i] <= 1) on++;
	if(on < 2){
		//nothing to put on the ends
		cout << "NO" << endl;
		return;
	}
	vi vis(30, 0);
	vector<string> comps;
	rep(i, 26) if(!vis[i]){
		string ans = "";
		ans += (char)('a' + i);
		vis[i] = 1;
		while(true){
			int nw = ans.size();
			if(ans.size() == 1){
				int prev = -1;
				rep(j, 26) if(nm[ans[0] - 'a'][j] && !vis[j]){
					vis[j] = 1;
					prev = j;
					ans += (char)('a' + j);
					break;
				}
				rep(j, 26) if(nm[ans[0] - 'a'][j] && j != prev && !vis[j]){
					vis[j] = 1;
					reverse(all(ans));
					ans += 'a' + j;
					reverse(all(ans));
				}
			}
			else{
				//try to add to l, then to r
				char r = ans[ans.size() - 1], l = ans[0];
				rep(j, 26) if(nm[r - 'a'][j] && !vis[j]){
					vis[j] = 1;
					ans += (char)('a' + j);
					break;
				}
				rep(j, 26) if(nm[l - 'a'][j] && !vis[j]){
					vis[j] = 1;
					reverse(all(ans));
					ans += 'a' + j;
					reverse(all(ans));
				}
			}
			if(nw == (int)(ans.size())){
				//end
				comps.pb(ans);
				break;
			}
		}
	}
	string bg = "";
	for(string s1 : comps) bg += s1;
	int f = 1;
	rep(i, 26){
		rep(j, bg.size()){
			if(bg[j] == (char)('a' + i)){
				//debug(s[j]);
				//debug(j);
				//debug((char)('a' + i));
				if(j >= 1){
					if(nm[i][bg[j - 1] - 'a']){
						//debug2((char)('a' + i), (char)(bg[j - 1]));
						num[i]--;
					}
				}
				if(j != 25){
					if(nm[i][bg[j + 1] - 'a']){
						//debug2((char)('a' + i), (char)(bg[j + 1]));
						num[i]--;
					}
				}
			}
		}
	}
	rep(i, 26) if(num[i]){
		f = 0;
	}
	if(f){
		cout << "YES" << endl;
		cout << bg << endl;
	}
	else cout << "NO" << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
