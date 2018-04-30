/*
ID: eed7573
TASK: ttwo
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

bool visited[10][10][4][10][10][4]; //0 is north, 1 is east, 2 is south, 3 is west
bool obstacle[10][10];
int fdir = 0, cdir = 0;
int counter = 0;
pii f, c;
void nextPos(pii& p, int& dir) {
	int i = p.first;
	int j = p.second;
	if (dir == 0) {
		if (i == 0 || obstacle[i - 1][j]) {
			dir = 1;
			return;
		}
		p = MP(i - 1, j);
		return;
	}
	if (dir == 1) {
		if (j == 9 || obstacle[i][j + 1]) {
			dir = 2;
			return;
		}
		p = MP(i, j + 1);
		return;
	}
	if (dir == 2) {
		if (i == 9 || obstacle[i + 1][j]) {
			dir = 3;
			return;
		}
		p = MP(i + 1, j);
		return;
	}
	if (dir == 3) {
		if (j == 0 || obstacle[i][j - 1]) {
			dir = 0;
			return;
		}
		p = MP(i, j - 1);
		return;
	}
}
int main() {
	FAST
	ofstream fout("ttwo.out");
	ifstream fin("ttwo.in");
	char ch;
	FOR(i, 10) {
		FOR(j, 10) {
			fin >> ch;
			if (ch == '*') obstacle[i][j] = true;
			else if (ch == 'F') f = MP(i, j);
			else if (ch == 'C') c = MP(i, j);
		}
	}
	visited[f.F][f.S][fdir][c.F][c.S][cdir] = true;
	while (true) {
		counter++;
		nextPos(f, fdir);
		nextPos(c, cdir);
		if (visited[f.F][f.S][fdir][c.F][c.S][cdir]) {
			fout << 0 << "\n";
			return 0;
		}
		if (f == c) {
			fout << counter << "\n";
			return 0;
		}
		visited[f.F][f.S][fdir][c.F][c.S][cdir] = true;
	}
	return 0;
}
