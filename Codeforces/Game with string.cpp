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
	string in;
	cin >> in;
	int k = 0;
	int i = 0;
	while(i < in.size()){
		if(in[i] == in[i + 1]){
			k++;
			in.erase(i, 2);
			i = 0;
		}
		else{
			i++;
		}
		
	}	
	if(k % 2 == 0){
		cout << "No" << endl;
	}
	else{
		cout << "Yes" << endl;
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
