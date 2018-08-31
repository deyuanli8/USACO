template<int sz> struct Dijkstra {
	bool visited[sz];
	vector<pair<int, ll>> adj[sz];
	ll dist[sz];

	ll getDist(int a) {
		return dist[a];
	}
	void addEdge(int x, int y, ll d) {
		adj[x].PB(MP(y, d));
	}
	void calculate(int st) {
		FOR(i, sz) {
			visited[i] = false;
			dist[i] = 0x7FFFFFFFFFFFFFFF;
		}
		dist[st] = 0;
		priority_queue<pair<ll, int>> q;
		q.push({ 0,st });
		while (!q.empty()) {
			int a = q.top().second; q.pop();
			if (visited[a]) continue;
			visited[a] = true;
			for (auto &u : adj[a]) {
				int b = u.first;
				ll w = u.second;
				if (dist[a] + w < dist[b]) {
					dist[b] = dist[a] + w;
					q.push({ -dist[b],b });
				}
			}
		}
	}
};
