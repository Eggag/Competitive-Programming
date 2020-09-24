#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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

string s[15];

void solve(){
        rep(i, 9) cin >> s[i];
        vector<pi> pos = {{0, 0}, {4, 1}, {8, 2}, {1, 3}, {5, 4}, {6, 5}, {2, 6}, {3, 7}, {7, 8}};
        rep(m, pos.size()){
                int i = pos[m].fi, j = pos[m].se;
                repn(k, 1, 10){
                        if(s[i][j] != (char)(k + '0')){
                                s[i][j] = (char)(k + '0');
                                break;
                        }
                }
        }
        rep(i, 9) cout << s[i] << endl;
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
