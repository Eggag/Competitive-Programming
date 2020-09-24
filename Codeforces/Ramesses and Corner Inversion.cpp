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

int a[505][505], b[505][505];
int ch[505][505], done[505][505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> a[i][j];
	rep(i, n) rep(j, m) cin >> b[i][j];
	rep(i, n) rep(j, m) if(a[i][j] != b[i][j]) ch[i][j] = 1;
	rep(i, n){
		int p = -1;
		rep(j, m){
			if(ch[i][j]){
				if(p == -1) p = j;
				else{
					rep(k, n) if(k != i){
						if(ch[k][p] && ch[k][j]){
							ch[k][p] = 0, ch[k][j] = 0;
							ch[i][p] = 0, ch[i][j] = 0;
							break;
						}
					}
					p = -1;
				}
			}

		}
	}
	rep(i, n){
		int p = -1;
		rep(j, m){
			if(ch[i][j]){
				if(p == -1) p = j;
				else{
					rep(k, n) if(k != i){
						if(!ch[k][p] && ch[k][j]){
							ch[k][p] = 1, ch[k][j] = 0;
							ch[i][p] = 0, ch[i][j] = 0;
							break;
						}
						else if(ch[k][p] && !ch[k][j]){
							ch[k][p] = 0, ch[k][j] = 1;
							ch[i][p] = 0, ch[i][j] = 0;
							break;
						}
						else if(ch[k][p] && ch[k][j]){
							ch[k][p] = 0, ch[k][j] = 0;
							ch[i][p] = 0, ch[i][j] = 0;
							break;
						}
					}
					p = -1;
				}
			}

		}
	}
	int f = 1;
	rep(i, n){
		rep(j, m) if(ch[i][j]){
			f = 0;
			break;
		}
	}
	if(f) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

