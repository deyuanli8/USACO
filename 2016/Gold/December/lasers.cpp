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
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define UB upper_bound
#define LB lower_bound
#define SQ(a) (a)*(a)
//#define min(a,b) (a)<(b) ? (a) : (b)

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)
#define endl "\n"
#define FAST ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

#define maxN 1000000
#define maxCoord 1000000000
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

pii arrX[maxN];
pii arrY[maxN];
unordered_set<int> xVisit;
unordered_set<int> yVisit;
queue<tuple<int, bool, int>> que; 
int n,x1,y3,x2,y2;
int main() {
	FAST
	ofstream cout("lasers.out");
	ifstream cin("lasers.in");
	cin >> n >> x1 >> y3 >> x2 >> y2;
	que.push(MT(x1, true, 0));
	que.push(MT(y3, false, 0));
	xVisit.insert(x2);
	yVisit.insert(y2);
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arrX[i] = MP(x, y);
		arrY[i] = MP(y, x);
		xVisit.insert(x);
		yVisit.insert(y);
	}
	sort(arrX, arrX + n);
	sort(arrY, arrY + n);
	while (!que.empty()) {
		auto next = que.front();
		que.pop();
		int curLine = get<0>(next);
		if (get<1>(next) == true) {
			if (curLine == x2) {
				cout << get<2>(next) << endl;
				return 0;
			}
			for (int i = (LB(arrX, arrX+n, MP(curLine,0)) - arrX); i < (UB(arrX, arrX+n, MP(curLine,maxCoord))-arrX); i++) {
				if (yVisit.count(arrX[i].S) == 1) {
					que.push(MT(arrX[i].second, false, get<2>(next) + 1));
					yVisit.erase(arrX[i].S);
				}
			}
		}
		else {
			if (curLine == y2) {
				cout << get<2>(next) << endl;
				return 0;
			}
			for (int i = (LB(arrY, arrY + n, MP(curLine,0)) - arrY); i < (UB(arrY, arrY + n, MP(curLine,maxCoord)) - arrY); i++) {
				if (xVisit.count(arrY[i].S) == 1) {
					que.push(MT(arrY[i].second, true, get<2>(next) + 1));
					xVisit.erase(arrY[i].S);
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
