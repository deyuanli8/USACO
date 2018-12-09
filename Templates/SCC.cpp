#define MAXN 100005
vi edges[MAXN]; // initialize to -1
int dfsNum[MAXN];
int lowlink[MAXN];
vi S; // stack
bool inStack[MAXN];
int SCCCount = 0;
int cnt = 0;

int SCCNum[MAXN]; // node i is in SCC SCCNum[i]
vi SCC[MAXN]; // list of nodes of each SCC

void dfs(int u) { // finds SCC
	lowlink[u] = dfsNum[u] = cnt++;
	S.PB(u);
	inStack[u] = true;
	for (int v : edges[u]) {
		bool backEdge = true;
		if (dfsNum[v] == -1) {
			dfs(v);
			backEdge = false;
		}
		if (inStack[v]) {
			lowlink[u] = min(lowlink[u], backEdge ? dfsNum[v] : lowlink[v]);
		}
	}
	if (lowlink[u] == dfsNum[u]) { // u is the base
		while (true) {
			int v = S.back();
			S.pop_back();
			inStack[v] = false;
			SCCNum[v] = SCCCount;
			SCC[SCCCount].PB(v);
			if (u == v) break;
		}
		SCCCount++;
	}
}
