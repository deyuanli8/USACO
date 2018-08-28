struct SumSegmentTree {
	int sz;
	int *tree;

	SumSegmentTree(int s) {
		sz = 1 << (int)ceil(log2(s));
		tree = new int[2 * sz];
		FOR(i, 2 * sz) {
			tree[i] = 0;
		}
	}
	void add(int ind, int x) {
		ind += sz;
		tree[ind] += x;
		for (ind /= 2; ind >= 1; ind /= 2) {
			tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
		}
	}
	int sum(int a, int b) { //sums [a,b] inclusive
		a += sz; b += sz;
		int s = 0;
		while (a <= b) {
			if (a % 2 == 1) s += tree[a++];
			if (b % 2 == 0) s += tree[b--];
			a /= 2; b /= 2;
		}
		return s;
	}
};
