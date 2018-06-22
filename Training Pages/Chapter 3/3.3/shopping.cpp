/*
ID: eed7573
TASK: shopping
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

int s, b;
int arr[99][1000];
bool t[99];
vi v(999);
vi curV;
vi arrW(999);
vi pro;
map<vi, int> m;
int find(vi vt) {
	if (m[vt] != 0) {
		return m[vt];
	}
	else {
		int curMin = 0;
		FOR(i, s) {
			if (!t[i]) {
				vi temp = vt;
				bool works = true;
				FOR(j, pro.size()) {
					temp[j] -= arr[i][pro[j]];
					if (temp[j] < 0) {
						works = false;
						break;
					}
				}
				if (works) {
					int x = find(temp)+arr[i][999];
					if (curMin == 0 || x < curMin) {
						curMin = x;
					}
				}
			}
		}
		if (curMin == 0) {
			FOR(i, pro.size()) {
				curMin += v[pro[i]] * vt[i];
			}
			curMin++;
		}
		m[vt] = curMin;
		return curMin;
	}
}
int main() {
	FAST
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);
	cin >> s;
	int n;
	FOR(i, s) {
		cin >> n;
		FOR(j, n) {
			int c, k;
			cin >> c >> k;
			arr[i][c - 1] = k;
		}
		cin >> arr[i][999];
	}
	cin >> b;
	FOR(i, b) {
		int c, k, p;
		cin >> c >> k >> p;
		arrW[c - 1] = k;
		v[c - 1] = p;
		pro.PB(c - 1);
	}
	FOR(j, s) {
		FOR(i, 999) {
			if (arr[j][i] > arrW[i]) {
				t[j] = true;
				break;
			}
		}
	}
	vi v1;
	FOR(i, b) {
		v1.PB(0);
	}
	m[v1] = 1;
	FOR(i, pro.size()) {
		curV.PB(arrW[pro[i]]);
	}
	cout << find(curV)-1 << "\n";
	return 0;
}
