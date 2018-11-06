#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <assert.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define SQ(a) (a)*(a)

#define F0R(i, a, b) for (int i=(a); i<(b); i++)
#define FOR(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define FORd(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0)
#define INF 1000000000
#define MAXN 100005

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vp;

int n;
vi adj[MAXN];
int sz[MAXN];
ll ans = 0;
ll dp[MAXN][3];
int di[MAXN];
int depth = 0;
bool cent[MAXN];
deque<int> dis[MAXN];
unordered_map<int, int> mp[MAXN];
int findCentroid(int u, int p, int n) { // assumes n-sz[u] <= n/2
	for (int v : adj[u]) {
		if (v == p) continue;
		if (sz[v] > n / 2) {
			return findCentroid(v, u, n);
		}
	}
	return u;
}
void getSizes(int u, int p) {
	sz[u] = 1;
	for (int v : adj[u]) {
		if (v == p || cent[v]) continue;
		getSizes(v, u);
		sz[u] += sz[v];
	}
}
void dfs(int u, int p, int d) {
	di[d]++;
	depth = max(depth, d);
	for (auto v : adj[u]) {
		if (v == p || cent[v]) continue;
		dfs(v, u, d + 1);
	}
}
void dfsC1(int u, int p, int d, int anc) {
	di[d]++;
	if (anc != -1) mp[anc][d]++;
	depth = max(depth, d);
	for (auto v : adj[u]) {
		if (v == p || cent[v]) continue;
		if (p == -1) {
			dfsC1(v, u, d + 1, v);
		}
		else {
			dfsC1(v, u, d + 1, anc);
		}
	}
}
void dfsC(int u, int p, int d, int c, int anc) {
	for (auto v : adj[u]) {
		if (v == p || cent[v]) continue;
		if (p == -1) dfsC(v, u, d + 1, c, v);
		else dfsC(v, u, d + 1, c, anc);
	}
	if (p == -1) {
		dis[u].clear();
		for (auto v : adj[u]) {
			if (v == p || cent[v]) continue;
			dis[v].clear();
		}
		return;
	}
	for (auto v : adj[u]) {
		if (v == p || cent[v]) continue;
		if (dis[u].size() < dis[v].size()) {
			swap(dis[u], dis[v]);
		}
		FOR(i, dis[v].size()) {
			if (i >= d - 1) {
				ans += (ll)dis[u][i] * dis[v][i] * (di[i - d + 1] - mp[anc][i - d + 1]);
			}
			dis[u][i] += dis[v][i];
		}
		dis[v].clear();
	}
	dis[u].push_front(1);
}
void decomp(int u, int p) {
	getSizes(u, p);
	if (sz[u] <= 2) return;
	int c = findCentroid(u, p, sz[u]);
	cent[c] = true;
	int maxDepth = 0;
	FOR(i, adj[c].size()) {
		depth = 0;
		if (!cent[adj[c][i]]) dfs(adj[c][i], c, 0);
		maxDepth = max(depth, maxDepth);
		FOR(j, depth + 1) {
			dp[j][2] += di[j] * dp[j][1];
			dp[j][1] += di[j] * dp[j][0];
			dp[j][0] += di[j];
			di[j] = 0;
		}
	}
	FOR(i, maxDepth + 1) {
		ans += dp[i][2];
		dp[i][2] = 0;
		dp[i][1] = 0;
		dp[i][0] = 0;
		sz[i] = 0;
	}
	dfsC1(c, -1, 0, -1);
	dfsC(c, -1, 0, c, -1);
	FOR(i, depth + 1) {
		di[i] = 0;
	}
	for (auto a : adj[c]) {
		mp[a] = unordered_map<int, int>();
	}
	for (int v : adj[c]) {
		for (auto itr = adj[v].begin(); itr != adj[v].end(); itr++) {
			if (*itr == c) {
				adj[v].erase(itr);
				break;
			}
		}
		decomp(v, c);
	}
}
int main() {
	FAST;
	cin >> n;
	int a, b;
	FOR(i, n - 1) {
		cin >> a >> b;
		a--; b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	decomp(0, -1);
	cout << ans << "\n";
	return 0;
}
