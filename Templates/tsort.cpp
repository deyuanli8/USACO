#define MAXN 100005
int n;
vi edges[MAXN];
vi tsort; //order of toposort
bool visited[MAXN];
void dfs(int u) {
	if (visited[u]) return;
	visited[u] = true;
	for (int v : edges[u]) {
		dfs(v);
	}
	tsort.PB(u);
}
void toposort() {
	FOR(i, n) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	reverse(tsort.begin(), tsort.end()); //edges now point right
}
