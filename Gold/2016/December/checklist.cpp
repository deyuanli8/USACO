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
#define SQ(a) (a)*(a)
//#define min(a,b) (a)<(b) ? (a) : (b)

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)
#define endl "\n"
#define FAST ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

#define maxN 1000
#define maxInt 214748364
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int h, g;
int arr[maxN+1][maxN+1][2];
int dist[maxN][maxN];
int distG[maxN];
int distH[maxN];
pii coordsH[maxN];
pii coordsG[maxN];

int min(int a, int b) {
	if (a < 0 && b>=0) {
		return b;
	}
	else if (a >= 0 && b < 0) {
		return a;
	}
	if (a < 0 && b < 0) return -maxInt;
	int ans = a < b ? a : b;
	return ans;
}
int main() {
	FAST
	ofstream cout("checklist.out");
	ifstream cin("checklist.in");
	cin >> h >> g;
	int x, y;
	for (int i = 0; i < h; i++) {
		cin >> x >> y;
		//cout << i << " " << x << " " << y << endl;
		coordsH[i] = MP(x, y);
	}
	for (int i = 0; i < g; i++) {
		cin >> x >> y;
		//cout << i << " " << x << " " << y << endl;
		coordsG[i] = MP(x, y);
	}
	int distance;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < g; j++) {
			distance = (int)(pow(coordsH[i].first - coordsG[j].F, 2) + pow(coordsH[i].second - coordsG[j].second, 2)+0.2);
			dist[i][j] = distance;
		}
	}
	for (int i = 0; i < h - 1; i++) {
		distH[i] = (int)(pow(coordsH[i].first - coordsH[i+1].F, 2) + pow(coordsH[i].second - coordsH[i+1].second, 2)+0.2);
	}
	for (int i = 0; i < g - 1; i++) {
		distG[i] = (int)(pow(coordsG[i].first - coordsG[i + 1].F, 2) + pow(coordsG[i].second - coordsG[i + 1].second, 2)+0.2);
	}
	arr[1][0][0] = 0;
	arr[0][0][0] = -maxInt;
	arr[1][0][1] = -maxInt;
	arr[0][1][0] = -maxInt;
	arr[0][1][1] = -maxInt;
	arr[0][0][1] = -maxInt;
	arr[1][1][0] = -maxInt;
	arr[1][1][1] = dist[0][0];
	for (int i = 1; i <= h; i++) {
		for (int j = 0; j <= g; j++) {
			if (i == 1 && j == 0) continue;
			if (j == 0) {
				arr[i][j][1] = -maxInt;
				arr[i][j][0] = arr[i - 1][j][0] + distH[i - 2];
				continue;
			}
			if (i == j && j == 1) continue;
			if (i == 1) {
				arr[i][j][0] = -maxInt;
				arr[i][j][1] = arr[i][j - 1][1] + distG[j - 2];
				continue;
			}
			int dist1 = distH[i - 2];
			int dist2 = dist[i - 1][j - 1];
			if (j == 1) {
				arr[i][j][1] = arr[i][j - 1][0] + dist2;
				arr[i][j][0] = min(arr[i - 1][j][0] + dist1, arr[i - 1][j][1] + dist2);
				continue;
			}
			int dist3 = distG[j - 2];
			arr[i][j][0] = min(arr[i - 1][j][0] + dist1, arr[i - 1][j][1] + dist2);
			arr[i][j][1] = min(arr[i][j - 1][0] + dist2, arr[i][j - 1][1] + dist3);
		}
	}
	cout << arr[h][g][0] << endl;
	return 0;
}
