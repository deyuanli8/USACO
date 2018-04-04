/*
ID: eed7573
TASK: milk3
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

int a, b, c;
queue<tuple<int, int, int>> q;
set<int> ans;
set<pair<int, pii>> visi;
int main() {
	FAST
	ofstream cout("milk3.out");
	ifstream cin("milk3.in");
	cin >> a >> b >> c;
	q.push(MT(0, 0, c));
	while (!q.empty()) {
		auto next = q.front();
		q.pop();
		if (get<0>(next) == 0) {
			ans.insert(get<2>(next));
		}
		for (int i = 0; i < 3; i++) {
			int fir;
			if (i == 0) {
				fir = get<0>(next);
			}
			else if (i == 1) {
				fir = get<1>(next);
			}
			else {
				fir = get<2>(next);
			}
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				int a1, b1, c1;
				a1 = get<0>(next);
				b1 = get<1>(next);
				c1 = get<2>(next);
				int howMuch;
				if (j == 0) {
					howMuch = min(fir, a - get<0>(next));
					a1 += howMuch;
				}
				else if (j == 1) {
					howMuch = min(fir, b - get<1>(next));
					b1 += howMuch;
				}
				else {
					howMuch = min(fir, c - get<2>(next));
					c1 += howMuch;
				}
				if (i == 0) {
					a1 -= howMuch;
				}
				else if (i == 1) {
					b1 -= howMuch;
				}
				else {
					c1 -= howMuch;
				}
				auto toI = MP(a1, MP(b1, c1));
				if (visi.count(toI) == 1) {
					continue;
				}
				else {
					visi.insert(toI);
					q.push(MT(a1, b1, c1));
					if (a1 == 0) {
						ans.insert(c1);
					}
				}
			}
		}
	}
	auto it = ans.begin();
	bool firs = true;
	while (it != ans.end()) {
		if (firs) {
			cout << *it;
			firs = false;
		}
		else {
			cout << " " << *it;
		}
		it++;
	}
	cout << endl;
	return 0;
}
