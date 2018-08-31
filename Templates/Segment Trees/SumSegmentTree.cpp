struct SumSegmentTree {
	int sz;
	ll *tree;

	SumSegmentTree(int s) {
		sz = 1 << (int)ceil(log2(s));
		tree = new int[2 * sz];
		memset(tree, 0, 2 * sz * sizeof(ll));
	}
	void add(int ind, ll x) {
		ind += sz;
		tree[ind] += x;
		for (ind /= 2; ind >= 1; ind /= 2) {
			tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
		}
	}
	ll sum(int a, int b) { //sums [a,b] inclusive
		a += sz; b += sz;
		ll s = 0;
		while (a <= b) {
			if (a % 2 == 1) s += tree[a++];
			if (b % 2 == 0) s += tree[b--];
			a /= 2; b /= 2;
		}
		return s;
	}
};
