/*
ID: eed7573
TASK: fence
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

int f;
multiset<int> arr[500];
int numF[500][500];
int circuit[1024];
int circuitpos;
void findCircuit(int i) {
	if (arr[i].size() == 0) {
		circuit[circuitpos] = i;
		circuitpos++;
	}
	else {
		while (arr[i].size() != 0) {
			int last = *arr[i].begin();
			numF[i][last]--; numF[last][i]--;
			if (numF[i][last] == 0) {
				arr[i].erase(last);
				arr[last].erase(i);
			}
			findCircuit(last);
		}
		circuit[circuitpos] = i;
		circuitpos++;
	}
}
int main() {
	FAST
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	cin >> f;
	int x, y;
	int maxF = -1;
	bool nMax = true;
	FOR(i, f) {
		cin >> x >> y;
		arr[x - 1].insert(y - 1);
		arr[y - 1].insert(x - 1);
		numF[x - 1][y - 1]++; numF[y - 1][x - 1]++;
		if (maxF == -1 || x - 1 < maxF || y - 1 < maxF) {
			maxF = min(x - 1, y - 1);
		}
	}
	FOR(i, 500) {
		if (arr[i].size() % 2 == 1) {
			if (nMax) {
				nMax = false;
				maxF = i;
				continue;
			}
			maxF = min(maxF, i);
		}
	}
	circuitpos = 0;
	findCircuit(maxF);
	FORd(i, circuitpos) {
		cout << circuit[i] + 1 << "\n";
	}
	return 0;
}
