/*
ID: eed7573
TASK: heritage
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

string inO, preO;
vector<char> v(26);
int nextE = 0;
vi pointB(26);
vi pointS(26);
unordered_map<char, int> m;
void find(char a, int curIndex, int& lastI) {
	lastI = curIndex;
	if (m[v[curIndex]] < m[a]) {
		if (pointB[curIndex] != 0) {
			return find(a, pointB[curIndex], lastI);
		}
	}
	else {
		if (pointS[curIndex] != 0) {
			return find(a, pointS[curIndex], lastI);
		}
	}
}
void post(int index) {
	if (pointS[index] != 0) {
		post(pointS[index]);
	}
	if (pointB[index] != 0) {
		post(pointB[index]);
	}
	cout << v[index];
}
int main() {
	FAST
	freopen("heritage.in", "r", stdin);
	freopen("heritage.out", "w", stdout);
	cin >> inO >> preO;
	FOR(i, inO.length()) {
		m[inO[i]] = i + 1;
	}
	FOR(i, preO.length()) {
		int lastE = 0;
		find(preO[i],0,lastE);
		v[nextE] = preO[i];
		if (m[v[lastE]] > m[preO[i]]) {
			pointS[lastE] = nextE;
		}
		else {
			pointB[lastE] = nextE;
		}
		nextE++;
	}
	post(0);
	cout << "\n";
	return 0;
}
