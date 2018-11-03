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
#define MAXN 10005
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vp;
struct MaxSegmentTree {
	int sz;
	int *tree;

	MaxSegmentTree(int s) {
		sz = 1 << (int)ceil(log2(s));
		tree = new int[2 * sz];
		memset(tree, 0, 2 * sz * sizeof(int));
	}
	MaxSegmentTree(int s, int* st) {
		sz = 1 << (int)ceil(log2(s));
		tree = new int[2 * sz];
		memset(tree, 0, 2 * sz * sizeof(int));
		FOR(i, s) {
			tree[i + sz] = st[i];
		}
		F0Rd(ind, 1, sz) {
			tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
		}
	}
	void add(int ind, int x) {
		ind += sz;
		tree[ind] = x;
		for (ind /= 2; ind >= 1; ind /= 2) {
			tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
		}
	}
	int query(int a, int b) { //max of [a,b] inclusive
		a += sz; b += sz;
		int s = tree[a];
		while (a <= b) {
			if (a % 2 == 1) s = max(s, tree[a++]);
			if (b % 2 == 0) s = max(s, tree[b--]);
			a /= 2; b /= 2;
		}
		return s;
	}
};
template<int sz> struct Sparse {
	int lookup[2 * MAXN][14]; //contains index of minimum in the range [i,i+2^j-1]
	pii* arr;
	Sparse(pii* a) {
		arr = a;
		int power = 1;
		for (int i = 0; i <= (int)log2(sz); i++) {
			power *= 2;
			for (int j = 0; j < sz; j++) {
				if (i == 0) {
					lookup[j][0] = j;
					continue;
				}
				if (j + power / 2 - 1 >= sz) break;
				if (arr[lookup[j][i - 1]] <= arr[lookup[j + power / 4][i - 1]]) {
					lookup[j][i] = lookup[j][i - 1];
				}
				else {
					lookup[j][i] = lookup[j + power / 4][i - 1];
				}
			}
		}
	}

	int indexMin(int a, int b) {
		if ((b - a) == 0) return a;
		int k = (int)log2(b - a + 1);
		int j = (int)(pow(2, k));
		if (arr[lookup[a][k]] <= arr[lookup[b - j + 1][k]]) {
			return lookup[a][k];
		}
		return lookup[b - j + 1][k];
	}
	pii getMin(int a, int b) {
		return arr[indexMin(a, b)];
	}
};

vp children[MAXN];
pii parent[MAXN];
pii arr[2 * MAXN];
vp adj[MAXN];
//int sz[MAXN];
int lci[MAXN];
int n, t;
int indx = 0;
void makeTree(int u, int p, int d) {
	arr[indx] = MP(d, u);
	lci[u] = indx;
	indx++;
	for (auto a : adj[u]) {
		if (a.F != p) {
			children[u].PB(a);
			parent[a.F] = MP(u, a.S);
			makeTree(a.F, u, d + 1);
			arr[indx] = MP(d, u);
            lci[u] = indx;
            indx++;
		}
	}
}
int getLCA(int a, int b, Sparse<2 * MAXN> &slca) {
	return lci[a] < lci[b] ? slca.getMin(lci[a], lci[b]).S : slca.getMin(lci[b], lci[a]).S;
}
/*void dfsHLD(int u) { //helper for HLD
	sz[u] = 1;
	for (pii edge : children[u]) {
		int v = edge.F;
		dfsHLD(v);
		sz[u] += sz[v];
	}
}*/
int cNo = 0, cHead[MAXN], cPos[MAXN], cInd[MAXN], cSize[MAXN]; //head of a given chain, position of node in its chain, index number of the chain, size of the chain
vector<MaxSegmentTree> vec;
void hld(int cur) {
	if (cHead[cNo] == -1) {
		MaxSegmentTree mst(MAXN);
		vec.PB(mst);
		cHead[cNo] = cur;
	}
	cInd[cur] = cNo;
	cPos[cur] = cSize[cNo];
	cSize[cNo]++;
	int ind = -1, cMax = -1;
	FOR (i, children[cur].size()) {
		if (children[cur][i].S > cMax) {
			cMax = children[cur][i].S;
			ind = i;
		}
	}
	if (ind >= 0) {
		vec[cNo].add(cSize[cNo], cMax);
		hld(children[cur][ind].F);
	}
	FOR (i, children[cur].size()) {
		if (i != ind) {
			cNo++;
			hld(children[cur][i].F);
		}
	}
}

int query_up(int u, int v) { //v is ancestor of u
	int uchain, vchain = cInd[v], ans = -1;
	while (true) {
		uchain = cInd[u];
		int cur = 0;
		if (uchain == vchain) {
			if(cPos[v]!=cPos[u]) cur = vec[vchain].query(cPos[v] + 1, cPos[u]);
			if (cur > ans) ans = cur;
			break;
		}
        if (cPos[u] != 0) {
            cur = vec[uchain].query(1, cPos[u]);
        }
		ans = max(ans, cur);
		u = cHead[uchain];
		ans = max(parent[u].S, ans);
		u = parent[u].F;
	}
	return ans;
}
int query(int u, int v, Sparse<2 * MAXN> &slca) {
	int lca = getLCA(u, v, slca);
	return max(query_up(u, lca), query_up(v, lca));
}
void change(int u, int v) {
    parent[u].S=v;
    if(cPos[u]==0) return;
	vec[cInd[u]].add(cPos[u], v); //replace vs add
}
vp edge;
int main() {
	FAST;
	cin >> t;
	FOR(j, t) {
        cin >> n;
        int a, b, c;
        FOR(i, n-1) {
            cin >> a >> b >> c;
            adj[a-1].PB({ b-1,c });
            adj[b-1].PB({ a-1,c });
            edge.PB(MP(a-1, b-1));
        }
        FOR(i,MAXN){
            cHead[i]=-1;
        }
        makeTree(0, -1, 0);
        //dfsHLD(0);
        Sparse<2 * MAXN> slca = Sparse<2 * MAXN>(arr);\
        hld(0);
        string s;
        bool firL=true;
        while (true) {
            cin >> s;
            if (s == "DONE") break;
            cin >> a >> b;
            a--; b--;
            if (s != "QUERY") {
                change((parent[edge[a].F].F == edge[a].S ? edge[a].F : edge[a].S), b+1);
            }
            else {
                cout << query(a, b, slca) << "\n";
            }
        }
        vec.clear();
        edge.clear();
	    FOR(k, MAXN){
            adj[k].clear();
            children[k].clear();
            parent[k]={0,0};
            cNo=0;
            cHead[k]=-1;
            cInd[k]=0;
            cPos[k]=0;
            cSize[k]=0;
            //sz[k]=0;
            lci[k]=0;
            indx=0;
	    }
	    FOR(k,2*MAXN){
            arr[k]={0,0};
	    }
	}
	return 0;
}
