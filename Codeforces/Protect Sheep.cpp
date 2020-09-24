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

void no(){
	cout << "NO" << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	char g[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> g[i][j];
		}	
	}
	for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        if(g[i][j] == 'S'){
				if(i > 0 && g[i - 1][j] == 'W') no();
				if(i < (n - 1) && g[i + 1][j] == 'W') no();
				if(j > 0 && g[i][j - 1] == 'W') no();
				if(j < (m - 1) && g[i][j + 1] == 'W') no();
			}
                }
        }
	cout << "YES" << endl;
	for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        if(g[i][j] == '.') cout << "D";
			else{
				cout << g[i][j];
			}
                }
		cout << endl;
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
