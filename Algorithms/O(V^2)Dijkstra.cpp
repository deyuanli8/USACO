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
		while (true) {
			int s = -1;
			FOR(i, sz) {
				if (!visited[i]) {
					if (s == -1) s = i;
					if (dist[i] < dist[s]) s = i;
				}
			}
			visited[s] = true;
			if (s == -1) return;
			for (auto &e : adj[s]) {
				if (!visitied[e.F]) {
					if (dist[e.F] > dist[s] + e.S) dist[e.F] = dist[s] + e.S;
				}
			}
		}
	}
};
