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
#define endl '\n'

#ifdef LOCAL
clock_t timer = clock();
#endif

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	vi p1, p2;
	for(int i = 0; i < s.size() - 1; i++){
		if(s.substr(i, 2) == "AB") p1.pb(i);
		if(s.substr(i, 2) == "BA") p2.pb(i);
	}
	int i, j;
	for(i = 0; i < p1.size(); i++){
		for(j = 0; j < p2.size(); j++){
			if(abs(p1[i] - p2[j]) >= 2) break;
		}
		if(j < p2.size()) break;
	}
	if(i < p1.size()) cout << "YES" << endl;
	else{
		cout << "NO" << endl;
	}
#ifdef LOCAL
        cout << "Total Time: " << (double)(clock() - timer) / CLOCKS_PER_SEC << endl;
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
