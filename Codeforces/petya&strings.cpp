#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string word1, word2;
	cin >> word1;
	cin >> word2;
	transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
	transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
	if(word1 == word2){
		cout << 0 << endl;
	}
	if(word2 > word1){
		cout << -1 << endl;
	}
	if(word2 < word1){
		cout << 1 << endl;
	}
	return 0;
}
