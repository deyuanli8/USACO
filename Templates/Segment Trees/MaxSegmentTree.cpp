struct MaxSegmentTree {
	int sz;
	ll *tree;

	MaxSegmentTree(int s) {
		sz = 1 << (int)ceil(log2(s));
		tree = new ll[2 * sz];
		memset(tree, 0, 2 * sz * sizeof(ll));
	}
	MaxSegmentTree(int s, ll* st) {
		sz = 1 << (int)ceil(log2(s));
		tree = new ll[2 * sz];
		memset(tree, 0, 2 * sz * sizeof(ll));
		FOR(i, s) {
			tree[i + sz] = st[i];
		}
		F0Rd(ind, 1, sz) {
			tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
		}
	}
	void add(int ind, ll x) {
		ind += sz;
		tree[ind] += x;
		for (ind /= 2; ind >= 1; ind /= 2) {
			tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
		}
	}
	ll query(int a, int b) { //max of [a,b] inclusive
		a += sz; b += sz;
		ll s = tree[a];
		while (a <= b) {
			if (a % 2 == 1) s = max(s, tree[a++]);
			if (b % 2 == 0) s = max(s, tree[b--]);
			a /= 2; b /= 2;
		}
		return s;
	}
};
