/*
ID: eed7573
TASK: butter
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

int n, p, c;
int arr[800][800];
bool processed[800][800];
vector<pii> v[800];
unordered_map<int,int> m;
int main() {
	FAST
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);
	cin >> n >> p >> c;
	int next;
	FOR(i, n) {
		cin >> next;
		m[next-1]++;
	}
	int x, y, num;
	FOR(i, c) {
		cin >> x >> y >> num;
		x--; y--;
		v[x].PB(MP(y,num));
		v[y].PB(MP(x,num));
	}
	FOR(i, p) {
		priority_queue<pii> q;
		q.push({ 0 , i });
		bool b = false;
		while (!q.empty()) {
			int a = q.top().second; q.pop();
			if (processed[i][a]) continue;
			processed[i][a]=true;
			for (auto u : v[a]) {
				int b = u.first, w = u.second;
				if (arr[i][a] + w < arr[i][b] || (arr[i][b]==0 && b!=i)) {
					arr[i][b] = arr[i][a] + w;
					q.push({ -arr[i][b],b });
				}
			}
		}
	}
	int smallest = -1;
	FOR(i, p) {
		int curLen = 0;
		for(auto it : m) {
			curLen+=it.S*arr[i][it.F];
		}
		if (curLen < smallest || smallest == -1) {
			smallest = curLen;
		}
	}
	cout << smallest << "\n";
	return 0;
}
