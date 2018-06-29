/*
ID: eed7573
TASK: stall4
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
vi arr[402];
int dist[402][402];
bool b[402];
int curMin = -1;
int ans = 0;
bool recurse(int index, int sMin) {
	b[index] = true;
	if (index == 1) {
		curMin = sMin;
		return true;
	}
	for (int a : arr[index]) {
		if (!b[a] && dist[index][a] > 0 && recurse(a, sMin == -1 ? dist[index][a] : min(sMin, dist[index][a]))) {
			dist[index][a] -= curMin;
			dist[a][index] += curMin;
			return true;
		}
	}
	return false;
}
int main() {
	FAST
	freopen("stall4.in", "r", stdin);
	freopen("stall4.out", "w", stdout);
	cin >> n >> m;
	FOR(i, n) {
		arr[0].PB(i + 2);
		arr[i + 2].PB(0);
		dist[0][i + 2] = 1;
	}
	FOR(i, m) {
		arr[1].PB(i + n + 2);
		arr[i + n + 2].PB(1);
		dist[i + n + 2][1] = 1;
	}
	FOR(i, n) {
		int s;
		cin >> s;
		int next;
		FOR(j, s) {
			cin >> next;
			next--;
			arr[i + 2].PB(next + 2 + n);
			arr[next + 2 + n].PB(i + 2);
			dist[i + 2][next + 2 + n] = 1;
		}
	}
	while (true) {
		FOR(i, n + m + 2) {
			b[i] = false;
		}
		if (!recurse(0, -1)) {
			break;
		}
		else {
			ans += curMin;
		}
	}
	cout << ans << "\n";
	return 0;
}
