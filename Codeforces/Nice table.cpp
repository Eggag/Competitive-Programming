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

vector<char> ch = {'A', 'C', 'T', 'G'};

int h(char c){
	if(c == 'A') return 0;
	if(c == 'C') return 1;
	if(c == 'T') return 2;
	if(c == 'G') return 3;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<vi> odR(4, vi(n)), evR(4, vi(n)), odC(4, vi(m)), evC(4, vi(m));
	rep(i, n) rep(j, m){
		if(j & 1) odR[h(s[i][j])][i]++;
		else evR[h(s[i][j])][i]++;
		if(i & 1) odC[h(s[i][j])][j]++;
		else evC[h(s[i][j])][j]++;
	}
	//rows
	int ans = 1e9;
	pair<int, vector<char>> bst;
	rep(i, 4) repn(j, i + 1, 4){
		pair<char, char> p = {ch[i], ch[j]};
		pair<char, char> p1 = {'#', '#'};
		rep(d, 4) if(d != i && d != j){
			if(p1.fi == '#') p1.fi = ch[d];
			else p1.se = ch[d];
		}
		int cur = 0;
		rep(d, n){
			if(d % 2 == 0){
				cur += m - max(odR[h(p.fi)][d] + evR[h(p.se)][d], odR[h(p.se)][d] + evR[h(p.fi)][d]);
			}
			else{
				cur += m - max(odR[h(p1.fi)][d] + evR[h(p1.se)][d], odR[h(p1.se)][d] + evR[h(p1.fi)][d]);
			}
		}
		if(cur < ans){
			ans = cur;
			vector<char> c = {p.fi, p.se, p1.fi, p1.se};
			bst = mp(0, c);
		}
	}
	//cols
	rep(i, 4) repn(j, i + 1, 4){
		pair<char, char> p = {ch[i], ch[j]};
		pair<char, char> p1 = {'#', '#'};
		rep(d, 4) if(d != i && d != j){
			if(p1.fi == '#') p1.fi = ch[d];
			else p1.se = ch[d];
		}
		int cur = 0;
		rep(d, m){
			if(d % 2 == 0){
				cur += n - max(odC[h(p.fi)][d] + evC[h(p.se)][d], odC[h(p.se)][d] + evC[h(p.fi)][d]);
			}
			else{
				cur += n - max(odC[h(p1.fi)][d] + evC[h(p1.se)][d], odC[h(p1.se)][d] + evC[h(p1.fi)][d]);
			}
		}
		if(cur < ans){
			ans = cur;
			vector<char> c = {p.fi, p.se, p1.fi, p1.se};
			bst = mp(1, c);
		}
	}
	pair<char, char> p = {bst.se[0], bst.se[1]};
	pair<char, char> p1 = {bst.se[2], bst.se[3]};
	if(!bst.fi){
		rep(d, n){
			if(d % 2 == 0){
				if((odR[h(p.fi)][d] + evR[h(p.se)][d]) > (odR[h(p.se)][d] + evR[h(p.fi)][d])){
					rep(i, m){
						if(i % 2 == 0) cout << p.se;
						else cout << p.fi;
					}
				}
				else{
					rep(i, m){
						if(i % 2 == 0) cout << p.fi;
						else cout << p.se;
					}
				}
			}
			else{
				if((odR[h(p1.fi)][d] + evR[h(p1.se)][d]) > (odR[h(p1.se)][d] + evR[h(p1.fi)][d])){
					rep(i, m){
						if(i % 2 == 0) cout << p1.se;
						else cout << p1.fi;
					}
				}
				else{
					rep(i, m){
						if(i % 2 == 0) cout << p1.fi;
						else cout << p1.se;
					}
				}

			}
			cout << endl;
		}
	}
	else{
		vector<vector<char>> an(n, vector<char>(m));
		rep(d, m){
			if(d % 2 == 0){
				if((odC[h(p.fi)][d] + evC[h(p.se)][d]) > (odC[h(p.se)][d] + evC[h(p.fi)][d])){
					rep(i, n){
						if(i % 2 == 0) an[i][d] = p.se;
						else an[i][d] = p.fi;
					}
				}
				else{
					rep(i, n){
						if(i % 2 == 0) an[i][d] = p.fi;
						else an[i][d] = p.se;
					}
				}
			}
			else{
				if((odC[h(p1.fi)][d] + evC[h(p1.se)][d]) > (odC[h(p1.se)][d] + evC[h(p1.fi)][d])){
					rep(i, n){
						if(i % 2 == 0) an[i][d] = p1.se;
						else an[i][d] = p1.fi;
					}
				}
				else{
					rep(i, n){
						if(i % 2 == 0) an[i][d] = p1.fi;
						else an[i][d] = p1.se;
					}
				}
			}
		}
		rep(i, n){
			rep(j, m) cout << an[i][j];
			cout << endl;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
