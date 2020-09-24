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

#ifdef LOCAL
clock_t t = clock();
#endif

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	repn(i, 1, n){
		if(s[i] == s[i - 1]){
			ans++;
			if(s[i] == 'R'){
				if(s[i + 1] != 'B') s[i] = 'B';
				else s[i] = 'G';
			}
			else if(s[i] == 'G'){
				if(s[i + 1] != 'R') s[i] = 'R';
                                else s[i] = 'B';
			}
			else{
				if(s[i + 1] != 'G') s[i] = 'G';
                                else s[i] = 'R';
			}
		}
	}
	cout << ans << endl;
	cout << s << endl;
#ifdef LOCAL
        cout << "Total Time: " << (double)(clock() - t) / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
