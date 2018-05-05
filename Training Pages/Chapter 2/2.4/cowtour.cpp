/*
ID: eed7573
TASK: cowtour
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
#define F0Rd(i,a,b) for (int i = (b)-1.0; i >= (a); i--)
#define FORd(i,a) for (int i = (a)-1.0; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define maxN 150
int n;
bool adj[maxN][maxN];
ld arr[maxN][maxN];
ld larD[maxN];
pii coord[maxN];
ld dist(pii aa, pii bb) {
	return pow((ld)(SQ(aa.F - bb.F) + SQ(aa.S - bb.S)), 0.5);
}
int main() {
	FAST
	ofstream fout("cowtour.out");
	ifstream fin("cowtour.in");
	fin >> n;
	int x, y;
	FOR(i, n) {
		fin >> x >> y;
		coord[i] = MP(x, y);
	}
	string s;
	FOR(i, n) {
		fin >> s;
		FOR(j, n) {
			if (s[j] == '1') {
				adj[i][j] = true;
			}
			arr[i][j] = -1.0;
		}
	}
	FOR(i, n) {
		FOR(j, n) {
			if (adj[i][j]) {
				arr[i][j] = dist(coord[i], coord[j]);
			}
		}
	}
	FOR(k, n) {
		FOR(j, n) {
			FOR(i, n) {
				if (i == j) continue;
				if (arr[i][k] >= 0 && arr[k][j] >= 0 && (arr[i][k] + arr[k][j] < arr[i][j] || arr[i][j] < 0)) {
					arr[i][j] = arr[i][k] + arr[k][j];
					arr[j][i] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	ld curMax=0;
	FOR(i, n) {
		FOR(k, n) {
			if (arr[i][k] >= 0) {
				FOR(l, n) {
					if (arr[k][l] > curMax) {
						curMax = arr[k][l];
					}
				}
			}
		}
		larD[i] = curMax;
	}	
	ld ans = -1.0;
	FOR(i, n) {
		FOR(j, n) {
			if (arr[i][j] >= 0 || i==j) continue;
			ld curLen = dist(coord[i], coord[j]);
			ld maxA = 0.0;
			ld maxB = 0.0;
			FOR(k, n) {
				if (arr[i][k] > maxA) {
					maxA = arr[i][k];
				}
				if (arr[j][k] > maxB) {
					maxB = arr[j][k];
				}
			}
			ld dia = curLen + maxA + maxB;
			if (larD[i] > dia) {
				dia = larD[i];
			}
			if (larD[j] > dia) {
				dia = larD[j];
			}
			if (ans < 0 || ans > dia) {
				ans = dia;
			}
		}
	}
	fout << fixed << setprecision(6) << ans << "\n";
	return 0;
}
