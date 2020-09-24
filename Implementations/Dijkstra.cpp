int dist[200005]; //don't forget to initialize to inf, change to ll if necessary

void dijkstra(int t){
	//find the shortest paths to t
	rep(i, 200005) dist[i] = 1e9;
	dist[t] = 0;
	set<pi> q;
	q.insert(mp(dist[t], t));
	while(!q.empty()){
		int u = q.begin() -> se;
		q.erase(q.begin());
		for(int x : g[u]){
			if((dist[u] + 1) < dist[x]){
				q.erase(mp(dist[x], x));
				dist[x] = dist[u] + 1;
				q.insert(mp(dist[x], x));
			}
		}
	}
}
