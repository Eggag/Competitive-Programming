#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(),v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define p push
#define MAXN 200001

int n;
vi adj[MAXN];
int io[MAXN];
int ro[MAXN];
bool vis[MAXN];
bool check = true;
vi ans;
queue<int> q;

bool cmp(int a, int b){
	return ro[a] < ro[b];	
}

void bfs(){
	q.push(1);
	while(!(q.empty())){
		queue<int> temp;
		while(!(q.empty())){
			int x = q.front();
			q.pop();
			vis[x] = true;
			ans.pb(x);
			for(int i = 0; i < adj[x].size(); i++){
				if(!vis[adj[x][i]]){
					temp.p(adj[x][i]);
				}
			}
		}
		q = temp;
	}	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("input.out", "w", stdout);
	cin >> n;
	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for(int i = 0; i < n; i++){
		cin >> io[i];
		ro[io[i]] = i;
	}
	for(int i = 1; i <= n; i++){
                sort(all(adj[i]), cmp);
        }
	bfs();
	for(int i = 0; i < n; i++){
		if(ans[i] != io[i]){
			check = false;
		}
	}
	if(check){
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
*/
