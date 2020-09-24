int vis1[100005]; //don't forget to initialize to zeroes
vi ord; //don't forget to reverse in the end
 
void dfs0(int cur){
	vis1[cur] = 1;
	for(pi x : g[cur]) if(!vis1[x.fi]) dfs0(x.fi);
	ord.pb(cur);
}
