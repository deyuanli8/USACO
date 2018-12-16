template<int sz> struct BIT {
  int tree[sz+1];
  BIT() {
    memset(tree, 0, sizeof(tree));
  }
  
  void add(int k, int x) {
    k++;
    while (k <= sz) {
      tree[k] += x;
      k += k&-k;
    }
  }
  int sum(int k) {
    k++;
    int s = 0;
    while (k >= 1) {
      s += tree[k];
      k -= k&-k;
    }
    return s;
  }
  int sum(int l, int r) {
    return sum(r)-sum(l-1);
  }
};

