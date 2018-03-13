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

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)
#define endl "\n"
#define FAST ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

#define maxN 100001
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;
int arr[maxN];
pii sorted[maxN];

template<int size> struct BIT {
	int tree[size + 1];
	BIT() {
		for (int i = 0; i<size + 1; i++) tree[i] = 0;
	}

	void add(int k, int x) {
		k++;
		while (k <= size) {
			tree[k] += x;
			k += k & -k;
		}
	}
	int sum(int k) {
		k++;
		int s = 0;
		while (k >= 1) {
			s += tree[k];
			k -= k & -k;
		}
		return s;
	}
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};
bool comp(pii a, pii b) {
	return a > b;
}
int main() {
	FAST
	ofstream cout("bphoto.out");
	ifstream cin("bphoto.in");
	cin >> n;
	int next;
	for (int i = 0; i < n; i++) {
		cin >> next;
		arr[i] = next;
		sorted[i] = MP(next, i);
	}
	sort(sorted, sorted + n, comp);
	BIT<maxN> btree = BIT<maxN>();
	int counter = 0;
	for (int i = 0; i < n; i++) {
		pii curP = sorted[i];
		if ((double)btree.sum(curP.S) / btree.sum(curP.S, n) > 2 || (double)btree.sum(curP.S) / btree.sum(curP.S, n) < 0.5) {
			counter++;
		}
		btree.add(curP.S, 1);
	}
	cout << counter << endl;
	return 0;
}
