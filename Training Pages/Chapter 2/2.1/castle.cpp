/*
ID: eed7573
TASK: castle
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
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
#define endl "\n"

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
int m, n;
bool arr[105][105];
bool cop[105][105];
int rooms = 0;
int sz(pii p, DSU<105 * 105> &d) {
	int fir = p.F;
	int sec = p.S;
	arr[fir][sec] = true;
	if (!arr[fir - 1][sec]) {
		if ((fir - 1) % 2 == 1 && sec % 2 == 1) {
			d.unite(105 * (fir + 1) + sec, 105 * (fir - 1) + sec);
		}
		sz(MP(fir - 1, sec), d);
	}
	if (!arr[fir + 1][sec]) {
		if ((fir + 1) % 2 == 1 && sec % 2 == 1) {
			d.unite(105 * (fir - 1) + sec, 105 * (fir + 1) + sec);
		}
		sz(MP(fir + 1, sec), d);
	}
	if (!arr[fir][sec + 1]) {
		if (fir % 2 == 1 && (sec + 1) % 2 == 1) {
			d.unite(105 * fir + sec - 1, 105 * fir + sec + 1);
		}
		sz(MP(fir, sec + 1), d);
	}
	if (!arr[fir][sec - 1]) {
		if (fir % 2 == 1 && (sec - 1) % 2 == 1) {
			d.unite(105 * fir + sec + 1, 105 * fir + sec - 1);
		}
		sz(MP(fir, sec - 1), d);
	}
	return d.getSize(fir * 105 + sec);
}
int lar(DSU<105 * 105> &d) {
	int largest = -1;
	pii where;
	bool full = false;
	while (!full) {
		full = true;
		FOR(i, 2 * n) {
			FOR(j, 2 * m) {
				if (arr[i][j] == false) {
					where = MP(i, j);
					full = false;
					break;
				}
			}
		}
		if (!full) {
			largest = max(sz(where, d), largest);
			rooms++;
		}
	}
	return largest;
}
int main() {
	FAST
	ofstream cout("castle.out");
	ifstream cin("castle.in");
	cin >> m >> n;
	int next;
	FOR(i, n) {
		FOR(j, m) {
			cin >> next;
			if (next % 2 == 1) {
				arr[2 * i + 1][2 * j] = true;
				cop[2 * i + 1][2 * j] = true;
				next--;
			}
			next /= 2;
			if (next % 2 == 1) {
				arr[2 * i][2 * j + 1] = true;
				cop[2 * i][2 * j + 1] = true;
				next--;
			}
			next /= 2;
			if (next % 2 == 1) {
				arr[2 * i + 1][2 * j + 2] = true;
				cop[2 * i + 1][2 * j + 2] = true;
				next--;
			}
			next /= 2;
			if (next % 2 == 1) {
				arr[2 * i + 2][2 * j + 1] = true;
				cop[2 * i + 2][2 * j + 1] = true;
				next--;
			}
		}
	}
	for (int i = 0; i <= 2 * n; i += 2) {
		for (int j = 0; j <= 2 * m; j += 2) {
			arr[i][j] = true;
			cop[i][j] = true;
		}
	}
	DSU<105 * 105> d = DSU<105 * 105>();
	int larRoom = lar(d);
	cout << rooms << endl;
	cout << larRoom << endl;
	int curLar = larRoom;
	tuple<int, int, char> loc;
	FOR(k, 2 * n + 2) {
		FOR(l, 2 * m + 2) {
			arr[k][l] = cop[k][l];
		}
	}
	FOR(j, m) {
		FORd(i, n) {
			if (arr[2 * i + 1][2 * j + 1]) continue;
			if (i != 0 && !d.connected((2 * i + 1) * 105 + 2 * j + 1, (2 * i - 1) * 105 + 2 * j + 1) && arr[2 * i][2 * j + 1]) {
				int howLar = d.getSize((2 * i + 1) * 105 + 2 * j + 1) + d.getSize((2 * i - 1) * 105 + 2 * j + 1);
				if (howLar > curLar) {
					curLar = howLar;
					loc = MT(i + 1, j + 1, 'N');
				}
			}
			if (j != m - 1 && !d.connected((2 * i + 1) * 105 + 2 * j + 1, (2 * i + 1) * 105 + 2 * j + 3) && arr[2 * i + 1][2 * j + 2]) {
				int howLar = d.getSize((2 * i + 1) * 105 + 2 * j + 1) + d.getSize((2 * i + 1) * 105 + 2 * j + 3);
				if (howLar > curLar) {
					curLar = howLar;
					loc = MT(i + 1, j + 1, 'E');
				}
			}
		}
	}
	cout << curLar << endl;
	cout << get<0>(loc) << " " << get<1>(loc) << " " << get<2>(loc) << endl;
	return 0;
}
