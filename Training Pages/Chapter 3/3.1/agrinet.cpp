/*
ID: eed7573
TASK: agrinet
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
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

#define FAST ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;
vector<pair<int, pii>> v;
template<int sz> struct DSU {
	int parent[sz];
	int numNodes[sz];
	int rank[sz];

	DSU() {
		for (int i = 0; i < sz; i++) {
			parent[i] = i;
			numNodes[i] = 1;
			rank[i] = 0;
		}
	}

	int getSize(int n) {
		return numNodes[find(n)];
	}
	bool connected(int n1, int n2) {
		return find(n1) == find(n2);
	}
	int find(int n) {
		if (parent[n] != n) parent[n] = find(parent[n]);
		return parent[n];
	}
	void unite(int n1, int n2) {
		int p1 = find(n1);
		int p2 = find(n2);
		if (p1 == p2) return;
		if (rank[p1] == rank[p2]) {
			parent[p1] = p2;
			numNodes[p2] = numNodes[p1] + numNodes[p2];
			rank[p2]++;
		}
		else if (rank[p1] < rank[p2]) {
			parent[p1] = p2;
			numNodes[p2] = numNodes[p1] + numNodes[p2];
		}
		else {
			parent[p2] = p1;
			numNodes[p1] = numNodes[p1] + numNodes[p2];
		}
	}
};
int main() {
	FAST
	ofstream fout("agrinet.out");
	ifstream fin("agrinet.in");
	fin >> n;
	int next;
	FOR(i, n) {
		FOR(j, n) {
			fin >> next;
			if (i > j) {
				v.PB(MP(next, MP(i, j)));
			}
		}
	}
	sort(v.begin(), v.end());
	DSU<100> d = DSU<100>();
	int ans = 0;
	for (int i = 0; i<v.size() && d.getSize(0)!=n; i++){
		int a = v[i].second.first;
		int b = v[i].second.S;
		if (!d.connected(a, b)) {
			d.unite(a, b);
			ans += v[i].first;
		}
	}
	fout << ans << "\n";
	return 0;
}
