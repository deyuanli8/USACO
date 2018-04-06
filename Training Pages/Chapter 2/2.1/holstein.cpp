/*
ID: eed7573
TASK: holstein
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

int v, g;
int vit[1000];
int feed[15][1000];
vi ans;
int arr[1000];
int minFeed=-1;
void recur(vector<bool> cur, int index, int numFeed) {
	if (index == g) {
		for (int i = 0; i < v; i++) {
			arr[i] = 0;
		}
		for (int i = 0; i < g; i++) {
			if (cur[i]) {
				for (int j = 0; j < v; j++) {
					arr[j] += feed[i][j];
				}
			}
		}
		for (int i = 0; i < v; i++) {
			if (arr[i] < vit[i]) return;
		}
		if (minFeed == -1 || numFeed <= minFeed) {
			minFeed = numFeed;
			ans.clear();
			for (int i = 0; i < g; i++) {
				if (cur[i]) {
					ans.PB(i+1);
				}
			}
		}
		return;
	}
	recur(cur, index+1, numFeed);
	cur[index] = true;
	recur(cur, index + 1, numFeed+1);
}
int main() {
	FAST
	ofstream cout("holstein.out");
	ifstream cin("holstein.in");
	cin >> v;
	int next;
	for (int i = 0; i < v; i++) {
		cin >> next;
		vit[i] = next;
	}
	cin >> g;
	for (int i = 0; i < g; i++) {
		for (int j = 0; j < v; j++) {
			cin >> next;
			feed[i][j] = next;
		}
	}
	vector<bool> ve;
	for (int i = 0; i < g; i++) {
		ve.PB(false);
	}
	recur(ve, 0, 0);
	cout << minFeed;
	for (int a : ans) {
		cout << " " << a;
	}
	cout << endl;
}
