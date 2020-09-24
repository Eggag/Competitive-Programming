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
	cin >> n;
	string s;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		s += c;
	}
	s = s + s;
	int ans = 0;
	int a = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '1') a++;
		else{
			ans = max(a, ans);
			a = 0;
		}
	}
	cout << ans << endl;
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
