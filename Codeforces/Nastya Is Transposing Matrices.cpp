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

vi a[1005], b[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int x;
			cin >> x;
			a[i + j].pb(x);
		}
	}
	for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        int x;
                        cin >> x;
                        b[i + j].pb(x);
                }
        }
	for(int i = 0; i < (n + m); i++){
		sort(all(a[i]));
		sort(all(b[i]));
		if(a[i] != b[i]){
			cout << "NO" << endl;
			return 0;
		}
	}	
	cout << "YES" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
