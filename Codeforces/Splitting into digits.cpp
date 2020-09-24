#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int x = 9;
	vi ans;
	int a = 0;
	a = n;
	for(int i = 0; i < n; i++){
		ans.pb(1);
	}
	cout << a << endl;
	for(int i = 0; i < ans.size(); i++){
		if(i != ans.size() - 1){
			cout << ans[i] << " ";
		}
		else{
			cout << ans[i] << endl;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
