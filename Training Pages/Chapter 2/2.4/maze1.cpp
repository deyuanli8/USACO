/*
ID: eed7573
TASK: maze1
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

#define maxH 100
#define maxW 38

int w, h;
int visited[maxH][maxW];
vector<pii> adj[maxH][maxW];
queue<pii> q;
int counter = 2;
int main() {
	FAST
	ofstream fout("maze1.out");
	ifstream fin("maze1.in");
	string s;
	getline(fin, s);
	stringstream(s) >> w >> h;
	char ch;
	FOR(i, 2*h+1) {
		getline(fin, s);
		FOR(j, 2*w+1) {
			ch = s[j];
			if (j == 0){
				if (ch == ' ') {
					q.push(MP((i - 1) / 2, 0));
					visited[(i - 1) / 2][0] = 1;
				}
			}
			else if (j == 2 * w) {
				if (ch == ' ') {
					q.push(MP((i - 1) / 2, w - 1));
					visited[(i - 1) / 2][w - 1] = 1;
				}
			}
			else if (i == 0) {
				if (ch == ' ') {
					q.push(MP(0, (j - 1) / 2));
					visited[0][(j - 1) / 2] = 1;
				}
			}
			else if (i == 2 * h) {
				if (ch == ' ') {
					q.push(MP(h - 1, (j - 1) / 2));
					visited[h - 1][(j - 1) / 2] = 1;
				}
			}
			else {
				if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) continue;
				else {
					if (i % 2 == 0) {
						if (ch == ' ') {
							adj[i / 2 - 1][(j - 1) / 2].PB(MP(i / 2, (j - 1) / 2));
							adj[i / 2 ][(j - 1) / 2].PB(MP(i / 2 -1 , (j - 1) / 2));
						}
					}
					else {
						if (ch == ' ') {
							adj[(i - 1) / 2][j / 2 - 1].PB(MP((i - 1) / 2, j / 2));
							adj[(i - 1) / 2][j / 2].PB(MP((i - 1) / 2, j / 2 - 1));
						}
					}
				}
			}
		}
	}
	while (!q.empty()) {
		pii next = q.front();
		q.pop();
		for (pii con : adj[next.F][next.S]) {
			if (visited[con.F][con.S] == 0) {
				visited[con.F][con.S] = visited[next.first][next.second] + 1;
				q.push(con);
			}
		}
	}
	int ans = -1;
	FOR(i, h) {
		FOR(j, w) {
			ans = max(ans, visited[i][j]);
		}
	}
	fout << ans << "\n";
	return 0;
}
