#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define debug(x) cerr << #x << " " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sq(x) ((x) * (x))
const int mxN = 4005;

int st[mxN][mxN];
int cnt[mxN];
int deg[120005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<pair<char, vi>> p(n + k - 1);
	rep(i, n + k - 1){
		char c;
		int a, b;
		cin >> c;
		if(c == 'S' || c == 'Q'){
			cin >> a >> b;
			a--, b--;
			if(c == 'S') deg[a]++, deg[b]++;
			p[i] = mp(c, vi{a, b});
		}
		else{
			cin >> a;
			a--;
			p[i] = mp(c, vi{a});
		}
	}
	if(n <= 4000){
		rep(i, n) st[i][i] = 1, cnt[i] = 1;
		rep(i, n + k - 1){
			if(p[i].fi == 'S'){
				int a = p[i].se[0], b = p[i].se[1];
				rep(j, n) if(st[a][j] || st[b][j]){
					if(!st[a][j] || !st[b][j]) cnt[j]++;
					st[a][j] = st[b][j] = 1;
				}
			}
			else if(p[i].fi == 'Q'){
				int a = p[i].se[0], b = p[i].se[1];
				if(st[a][b]) cout << "yes\n";
				else cout << "no\n";
			}
			else cout << cnt[p[i].se[0]] << '\n';
		}
	}
	else if(deg[0] == n - 1){
		vi fst(n, -1);
		int ind = 0;
		rep(i, n + k - 1){
			if(p[i].fi == 'S'){
				int a = p[i].se[0], b = p[i].se[1];
				if(a) fst[a] = ind++;
				else fst[b] = ind++;
			}
			else if(p[i].fi == 'Q'){
				int a = p[i].se[0], b = p[i].se[1];
				if(a == b){
					cout << "yes\n";
					continue;
				}
				if(!b){
					if(fst[a] != -1) cout << "yes\n";
					else cout << "no\n";
				}
				else if(!a){
					if(fst[b] != -1) cout << "yes\n";
					else cout << "no\n";
				}
				else{
					if(fst[a] != -1 && fst[b] != -1 && fst[a] > fst[b]) cout << "yes\n";
					else cout << "no\n";
				}
			}
			else{
				int a = p[i].se[0];
				if(!a) cout << ind + 1 << '\n';
				else{
					cout << (fst[a] == -1 ? 1 : ind - fst[a] + 1) << '\n';
				}
			}
		}
	}
	return 0;
}
