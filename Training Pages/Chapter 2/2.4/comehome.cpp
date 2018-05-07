/*
ID: eed7573
TASK: comehome
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

int p;
int path[70][70];
int main() {
	FAST
		ofstream fout("comehome.out");
	ifstream fin("comehome.in");
	fin >> p;
	char c1, c2;
	int dist;
	FOR(i, 70) {
		FOR(j, 70) {
			path[i][j] = -1;
		}
	}
	FOR(i, p) {
		fin >> c1 >> c2 >> dist;
		if (path[c1 - 'A'][c2 - 'A'] == -1) {
			path[c1 - 'A'][c2 - 'A'] = dist;
		}
		else {
			path[c1 - 'A'][c2 - 'A'] = min(path[c1 - 'A'][c2 - 'A'], dist);
		}
		path[c2 - 'A'][c1 - 'A'] = path[c1 - 'A'][c2 - 'A'];
	}
	FOR(k, 70) {
		FOR(i, 70) {
			FOR(j, 70) {
				if (i == j) continue;
				if (path[i][k] != -1 && path[k][j] != -1 && (path[i][j] == -1 || path[i][k] + path[k][j] < path[i][j])) {
					path[i][j] = path[i][k] + path[k][j];
					path[j][i] = path[i][j];
				}
			}
		}
	}
	int curMax = -1;
	char a = -1;
	F0R(i, 0, 25) {
		if ((curMax == -1 || path[i][25] < curMax) && path[i][25] != -1) {
			curMax = path[i][25];
			a = i + 65;
		}
	}
	fout << a << " " << curMax << "\n";
	return 0;
}
