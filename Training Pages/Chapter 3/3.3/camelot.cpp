/*
ID: eed7573
TASK: camelot
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
typedef vector<pii> vp;

int r, c;
int x, y;
int dist[30][26][30][26];
vp v;
queue<pii> q;
int main() {
	FAST
	freopen("camelot.in", "r", stdin);
	//ifstream cin("camelot.in");
	freopen("camelot.out", "w", stdout);
	cin >> r >> c;
	char curC;
	cin >> curC >> x;
	y = curC - 65;
	x--;
	int fir;
	char sec;
	while (cin >> sec) {
		cin >> fir;
		v.PB({ fir - 1, sec - 65 });
	}
	FOR(i, r) {
		FOR(j, c) {
			FOR(k, r) {
				FOR(l, c) {
					dist[i][j][k][l] = 1000000;
				}
			}
			dist[i][j][i][j] = 0;
			q.push({i,j});
			while (!q.empty()) {
				auto a = q.front(); q.pop();
				int f = a.F; int s = a.S;
				FOR(k, 4) {
					if (k == 0) {
						if (f - 2 >= 0 && s - 1 >= 0) {
							if (dist[i][j][f][s] + 1 < dist[i][j][f - 2][s - 1] || dist[i][j][f - 2][s - 1] == -1) {
								dist[i][j][f - 2][s - 1] = dist[i][j][f][s] + 1;
								q.push({f - 2,s - 1});
							}
						}
						if (f - 2 >= 0 && s + 1 < c) {
							if (dist[i][j][f][s] + 1 < dist[i][j][f - 2][s + 1] || dist[i][j][f - 2][s + 1] == -1) {
								dist[i][j][f - 2][s + 1] = dist[i][j][f][s] + 1;
								q.push({ f - 2,s + 1 } );
							}
						}
					}
					if (k == 1) {
						if (f - 1 >= 0 && s - 2 >= 0) {
							if (dist[i][j][f][s] + 1 < dist[i][j][f - 1][s - 2] || dist[i][j][f - 1][s - 2] == -1) {
								dist[i][j][f - 1][s - 2] = dist[i][j][f][s] + 1;
								q.push({ f - 1,s - 2 } );
							}
						}
						if (f + 1 < r && s - 2 >= 0) {
							if (dist[i][j][f][s] + 1 < dist[i][j][f + 1][s - 2] || dist[i][j][f + 1][s - 2] == -1) {
								dist[i][j][f + 1][s - 2] = dist[i][j][f][s] + 1;
								q.push({ f + 1,s - 2 } );
							}
						}
					}
					if (k == 2) {
						if (f + 2 < r && s - 1 >= 0) {
							if (dist[i][j][f][s] + 1 < dist[i][j][f + 2][s - 1] || dist[i][j][f + 2][s - 1] == -1) {
								dist[i][j][f + 2][s - 1] = dist[i][j][f][s] + 1;
								q.push({ f + 2,s - 1 });
							}
						}
						if (f + 2 < r && s + 1 < c) {
							if (dist[i][j][f][s] + 1 < dist[i][j][f + 2][s + 1] || dist[i][j][f + 2][s + 1] == -1) {
								dist[i][j][f + 2][s + 1] = dist[i][j][f][s] + 1;
								q.push({ f + 2,s + 1 });
							}
						}
					}
					if (k == 3) {
						if (f - 1 >= 0 && s + 2 < c) {
							if (dist[i][j][f][s] + 1 < dist[i][j][f - 1][s + 2] || dist[i][j][f - 1][s + 2] == -1) {
								dist[i][j][f - 1][s + 2] = dist[i][j][f][s] + 1;
								q.push({ f - 1,s + 2 } );
							}
						}
						if (f + 1 < r && s + 2 < c) {
							if (dist[i][j][f][s] + 1 < dist[i][j][f + 1][s + 2] || dist[i][j][f + 1][s + 2] == -1) {
								dist[i][j][f + 1][s + 2] = dist[i][j][f][s] + 1;
								q.push({ f + 1,s + 2 } );
							}
						}
					}
				}
			}
		}
	}
	int ans = -1;
	FOR(i, r) {
		FOR(j, c) {
			FOR(k, r) {
				FOR(l, c) {
					if (max(abs(k - x), abs(l - y)) <= 5) {
						int curMin = max(abs(k - x), abs(l - y));
						if (k != i || l != j) {
							bool b = false;
							bool pick = false;
							int saved = -1;
							for (auto a : v) {
								if (dist[i][j][a.F][a.S]==-1) {
									b = true;
									break;
								}
								curMin += dist[i][j][a.F][a.S];
								if (dist[k][l][a.F][a.S] == -1) {
									continue;
								}
								if (dist[i][j][a.F][a.S] - dist[i][j][k][l] - dist[k][l][a.F][a.S] > saved) {
									pick = true;
									saved = dist[i][j][a.F][a.S] - dist[i][j][k][l] - dist[k][l][a.F][a.S];
								}
							}
							if (b || !pick) continue;
							curMin -= saved;
						}
						else {
							for (auto a : v) {
								curMin += dist[i][j][a.F][a.S];
							}
							if (ans == -1 || curMin < ans) {
								ans = curMin;
							}
							continue;
						}
						if (ans == -1 || curMin < ans) {
							ans = curMin;
						}
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
