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

queue<int> A[27], B[27];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	rep(i, n){
		if(a[i] == '?'){
			A[26].push(i + 1);
		}
		else{
			A[a[i] - 'a'].push(i + 1);
		}
		if(b[i] == '?'){
			B[26].push(i + 1);
		}
		else{
			B[b[i] - 'a'].push(i + 1);
		}
	}
	vector<pi> ans;
	rep(i, 26){
		while(A[i].size() && B[i].size()){
			ans.pb(mp(A[i].front(), B[i].front()));
			A[i].pop();
			B[i].pop();
		}
	}
	rep(i, 26){
		while(A[i].size() && B[26].size()){
			ans.pb(mp(A[i].front(), B[26].front()));
                        A[i].pop();
                        B[26].pop();
		}
		while(A[26].size() && B[i].size()){
			ans.pb(mp(A[26].front(), B[i].front()));
                        A[26].pop();
                        B[i].pop();
		}
	}
	while(A[26].size() && B[26].size()){
		ans.pb(mp(A[26].front(), B[26].front()));
                A[26].pop();
                B[26].pop();
	}
	cout << ans.size() << endl;
	rep(i, ans.size()){
		cout << ans[i].fi << " " << ans[i].se << endl;
	}
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
