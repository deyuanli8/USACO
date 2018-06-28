/*
ID: eed7573
TASK: ditch
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

#define FAST ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vp;

int n, m;
vi arr[200];
int dist[200][200];
bool b[200];
int c = 0;
int ans = 0;
int curMin = -1;
bool recurse(int index, int minF) {
	b[index] = true;
	if (index == m - 1) {
		curMin = minF;
		return true;
	}
	for(auto i : arr[index]) {
		if (dist[index][i] >= c && !b[i]) {
			if (recurse(i, min(minF, dist[index][i]))) {
				dist[index][i] -= curMin;
				dist[i][index] += curMin;
				return true;
			}
		}
	}
	return false;
}
int main() {
	FAST
	freopen("ditch.in", "r", stdin);
	freopen("ditch.out", "w", stdout);
	cin >> n >> m;
	int s, e, t;
	FOR(i, n) {
		cin >> s >> e >> t;
		s--;
		e--;
		if (dist[s][e] == 0 && dist[e][s] == 0) {
			arr[s].PB(e);
			arr[e].PB(s);
		}
		dist[s][e] += t;
		c = max(c,t);
	}
	while (true) {
		curMin = -1;
		FOR(i, m) {
			b[i] = false;
		}
		if (!recurse(0,10000001)) {
			c /= 2;
		}
		else {
			ans += curMin;
		}
		if (c == 0) {
			cout << ans << "\n";
			break;
		}
	}
	return 0;
}
