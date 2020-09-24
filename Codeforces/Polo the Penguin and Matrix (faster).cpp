#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, d;
        cin >> n >> m >> d;
        int f = -1;
	vi t;
        rep(i, n){
                rep(j, m){
			int a;
                        cin >> a;
			t.pb(a);		
                        if(f == -1) f = a % d;
                        if(a % d != f){
                                cout << "-1" << endl;
                                return 0;
                        }
                }
        }
        int ans = 1e9;	
	rep(i, n * m){
		int sum = 0;
		rep(j, n * m){
			sum += abs(t[i] - t[j]) / d;
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
