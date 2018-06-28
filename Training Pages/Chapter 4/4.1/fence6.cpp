/*
ID: eed7753
TASK: fence6
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

int n;
vi arr[10000];
int len[100];
pii node[100];
int nOpen = 0;
vi vt;
int main() {
	FAST
	freopen("fence6.in", "r", stdin);
	freopen("fence6.out", "w", stdout);
	cin >> n;
	int next, x, y, l;
	FOR(i, n) {
		cin >> next >> l >> x >> y;
		next--;
		len[next] = l;
		bool lNew = true;
		vt.clear();
		int a;
		FOR(j, x) {
			cin >> a;
			vt.PB(a-1);
		}
		vt.PB(next);
		sort(vt.begin(), vt.end());
		FOR(j, nOpen) {
			if (vt.size() == arr[j].size()) {
				bool same = true;
				FOR(k, vt.size()) {
					if (vt[k] != arr[j][k]) {
						same = false;
						break;
					}
				}
				if (same) {
					lNew = false;
					break;
				}
			}
		}
		if (lNew) {
			FOR(j, vt.size()) {
				arr[nOpen].PB(vt[j]);
			}
			nOpen++;
		}
		bool rNew = true;
		vt.clear();
		FOR(j, y) {
			cin >> a;
			vt.PB(a-1);
		}
		vt.PB(next);
		sort(vt.begin(), vt.end());
		FOR(j, nOpen) {
			if (vt.size() == arr[j].size()) {
				bool same = true;
				FOR(k, vt.size()) {
					if (vt[k] != arr[j][k]) {
						same = false;
						break;
					}
				}
				if (same) {
					rNew = false;
					break;
				}
			}
		}
		if (rNew) {
			FOR(j, vt.size()) {
				arr[nOpen].PB(vt[j]);
			}
			nOpen++;
		}
	}
	FOR(i, n) {
		node[i] = { -1,-1 };
	}
	FOR(i, nOpen) {
		for (int j : arr[i]) {
			if (node[j].F == -1) {
				node[j].F = i;
			}
			else {
				node[j].S = i;
			}
		}
	}
	int ans = -1;
	FOR(i, n) {
		int distance[5005];
		bool processed[5005];
		FOR(j, 5005) {
			distance[j] = 0;
			processed[j] = false;
		}
		priority_queue<pii> q;
		distance[node[i].F] = 0;
		q.push({ 0,node[i].F });
		while (!q.empty()) {
			int a = q.top().second; q.pop();
			if (processed[a]) continue;
			processed[a] = true;
			for (auto u : arr[a]) {
				if (u == i) {
					continue;
				}
				int b = node[u].first==a ? node[u].S : node[u].F, w = len[u];
				if (distance[a] + w < distance[b] || (distance[b]==0 && b!=node[i].F)) {
					distance[b] = distance[a] + w;
					q.push({ -distance[b],b });
				}
			}
		}
		if (distance[node[i].S] == 0) continue;
		int nAns = len[i] + distance[node[i].S];
		if (ans == -1 || nAns < ans) {
			ans = nAns;
		}
	}
	cout << ans << "\n";
	return 0;
}
