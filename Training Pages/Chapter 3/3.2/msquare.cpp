/*
ID: eed7573
TASK: msquare
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

int a = 0;
unordered_map<int, int> m;
unordered_map<int, string> m1;
queue<int> q;
int main() {
	FAST
	freopen("msquare.in", "r", stdin);
	freopen("msquare.out", "w", stdout);
	int next;
	FOR(i, 8) {
		cin >> next;
		a = a * 10 + next;
	}
	m[12345678] = 1;
	m1[12345678] = "";
	q.push(12345678);
	while (!q.empty()) {
		int b = q.front();
		q.pop();
		if (b == a) {
			cout << m[a] - 1 << "\n" << m1[a] << "\n";
			return 0;
		}
		int fir = b / 10000;
		int sec = b % 10000;
		int num1 = 0;
		int temp = b;
		FOR(i, 8) {
			num1 *= 10;
			num1 += temp % 10;
			temp /= 10;
		}
		int num2 = ((fir % 10) * 1000 + fir / 10) * 10000 + ((sec % 1000) * 10 + sec / 1000);
		int num3 = (((fir / 1000 * 10 + (sec / 10) % 10) * 10 + (fir / 100) % 10) * 10 + fir % 10) * 10000 + ((sec / 1000 * 10 + (fir / 10) % 10) * 10 + (sec / 100) % 10) * 10 + sec % 10;
		if (m[num1] == 0) {
			m[num1] = m[b] + 1;
			m1[num1] = m1[b] + "A";
			q.push(num1);
		}
		if (m[num2] == 0) {
			m[num2] = m[b] + 1;
			m1[num2] = m1[b] + "B";
			q.push(num2);
		}
		if (m[num3] == 0) {
			m[num3] = m[b] + 1;
			m1[num3] = m1[b] + "C";
			q.push(num3);
		}
	}
	return 0;
}
