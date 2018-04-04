/*
ID: eed7573
TASK: ariprog
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

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n, m;
unordered_set<int> biS;
vi bi;
vector<pii> ans;
int main() { FAST
	ofstream cout("ariprog.out");
	ifstream cin("ariprog.in");
	cin >> n >> m;
	bool none = true;
	for (int i = 0; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			biS.insert(SQ(i) + SQ(j));
		}
	}
	for (auto a : biS) {
		bi.PB(a);
	}
	sort(bi.begin(), bi.end());
	for (int i = 0; i < bi.size()-n; i++) {
		for (int j = i + 1; j < bi.size(); j++) {
			int d = bi[j] - bi[i];
			if (bi[i]+(n-1)*d > bi[bi.size()-1]) {
				break;
			}
			bool isBi = true;
			for (int k = 2; k < n; k++) {
				if (biS.count(bi[i] + k * d) == 0) {
					isBi = false;
					break;
				}
			}
			if (isBi) {
				ans.PB(MP(d, bi[i]));
				none = false;
			}
		}
	}
	if (none) {
		cout << "NONE" << endl;
		return 0;
	}
	sort(ans.begin(), ans.end());
	for (auto a : ans) {
		cout << a.second << " " << a.first << endl;
	}
	return 0;
}
