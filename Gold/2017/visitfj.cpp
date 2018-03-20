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
#define SQ(a) (a)*(a)

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)
#define endl "\n"
#define FAST ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

#define maxN 100
#define maxT 1000000
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n,t;
int arr[maxN][maxN];
int dist[maxN][maxN][3];
bool processed[maxN][maxN][3];
priority_queue<pair<int,tuple<int,int,int>>> q;
int main() { FAST
	ofstream cout("visitfj.out");
	ifstream cin("visitfj.in");
	cin >> n >> t;
	int next;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> next;
			arr[i][j] = next;
		}
	}
	q.push(MP(0, MT(0, 0, 0)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 3; k++) {
				processed[i][j][k] = false;
				dist[i][j][k] = -1;
			}
		}
	}
	dist[0][0][0] = 0;
	while (!q.empty()) {
		auto a = q.top().second;
		q.pop();
		int x = get<0>(a);
		int y = get<1>(a);
		int time = get<2>(a);
		if (processed[x][y][time]) {
			continue;
		}
		processed[x][y][time] = true;
		if (time == 2) {
			if (x - 1 >= 0) {
				if (dist[x][y][time] + t + arr[x - 1][y] < dist[x - 1][y][0] || dist[x - 1][y][0] == -1) {
					dist[x - 1][y][0] = dist[x][y][time] + t + arr[x - 1][y];
					q.push(MP(-dist[x - 1][y][0], MT(x - 1, y, 0)));
				}
			}
			if (x + 1 < n) {
				if (dist[x][y][time] + t + arr[x + 1][y] < dist[x + 1][y][0] || dist[x + 1][y][0] == -1) {
					dist[x + 1][y][0] = dist[x][y][time] + t + arr[x + 1][y];
					q.push(MP(-dist[x + 1][y][0], MT(x + 1, y, 0)));
				}
			}
			if (y - 1 >= 0) {
				if (dist[x][y][time] + t + arr[x][y - 1] < dist[x][y - 1][0] || dist[x][y - 1][0] == -1) {
					dist[x][y - 1][0] = dist[x][y][time] + t + arr[x][y - 1];
					q.push(MP(-dist[x][y - 1][0], MT(x, y - 1, 0)));
				}
			}
			if (y + 1 < n) {
				if (dist[x][y][time] + t + arr[x][y + 1] < dist[x][y + 1][0] || dist[x][y + 1][0] == -1) {
					dist[x][y + 1][0] = dist[x][y][time] + t + arr[x][y + 1];
					q.push(MP(-dist[x][y + 1][0], MT(x, y + 1, 0)));
				}
			}
		}
		else {
			if (x - 1 >= 0) {
				if (dist[x][y][time] + t < dist[x - 1][y][(time + 1) % 3] || dist[x - 1][y][(time + 1) % 3] == -1) {
					dist[x - 1][y][(time + 1) % 3] = dist[x][y][time] + t;
					q.push(MP(-dist[x - 1][y][(time + 1) % 3], MT(x - 1, y, (time + 1) % 3)));
				}
			}
			if (x + 1 < n) {
				if (dist[x][y][time] + t < dist[x + 1][y][(time + 1) % 3] || dist[x + 1][y][(time + 1) % 3] == -1) {
					dist[x + 1][y][(time + 1) % 3] = dist[x][y][time] + t;
					q.push(MP(-dist[x + 1][y][(time + 1) % 3], MT(x + 1, y, (time + 1) % 3)));
				}
			}
			if (y - 1 >= 0) {
				if (dist[x][y][time] + t < dist[x][y - 1][(time + 1) % 3] || dist[x][y - 1][(time + 1) % 3] == -1) {
					dist[x][y - 1][(time + 1) % 3] = dist[x][y][time] + t;
					q.push(MP(-dist[x][y - 1][(time + 1) % 3], MT(x, y - 1, (time + 1) % 3)));
				}
			}
			if (y + 1 < n) {
				if (dist[x][y][time] + t < dist[x][y + 1][(time + 1) % 3] || dist[x][y + 1][(time + 1) % 3] == -1) {
					dist[x][y + 1][(time + 1) % 3] = dist[x][y][time] + t;
					q.push(MP(-dist[x][y + 1][(time + 1) % 3], MT(x, y + 1, (time + 1) % 3)));
				}
			}
		}
	}
	int min = dist[n - 1][n - 1][0];
	if (dist[n - 1][n - 1][1] < min && dist[n - 1][n - 1][1] != -1) {
		min = dist[n - 1][n - 1][1];
	}
	if (dist[n - 1][n - 1][2] < min && dist[n - 1][n - 1][2] != -1) {
		min = dist[n - 1][n - 1][2];
	}
	cout << min << endl;
	return 0;
}
