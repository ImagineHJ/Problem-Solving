#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

long long nums[1000001];
long long segTree[1000000 * 4];
long long lazy[1000000 * 4];

void makeSegTree(int node, int s, int e) {
  if (s == e) {
    segTree[node] = nums[s];
    return;
  }

  int m = (s + e) / 2;
  makeSegTree(node * 2, s, m);
  makeSegTree(node * 2+1, m+1, e);

  segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

void updateLazy(int node, int s, int e) {
  if (lazy[node] != 0) {
    segTree[node] += lazy[node] * (e - s + 1);

    if (s != e) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }

}

void updateSegTree(int node, int s, int e, int l, int r, long long val) {
  updateLazy(node, s, e);

  if (r < s || e < l) return;
  if (l <= s && e <= r) {
    segTree[node] += val * (e - s + 1);
    if (s != e) {
      lazy[node * 2] += val;
      lazy[node * 2 + 1] += val;
    }
    return;
  }
  int m = (s + e) / 2;
  updateSegTree(node * 2, s, m, l, r, val);
  updateSegTree(node * 2 + 1, m + 1, e, l, r, val);
  segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

long long getSegTree(int node, int s, int e, int l, int r) {
  updateLazy(node, s, e);

  if (r < s || e < l) return 0;
  if (l <= s&&e <= r) return segTree[node];

  int m = (s + e) / 2;
  return getSegTree(node * 2, s, m, l, r) + getSegTree(node * 2 + 1, m + 1, e, l, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); //faster

  long long n, m, k, a, b, c, d;
  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++) {
    cin >> a;
    nums[i] = a;
  }

  makeSegTree(1, 1, n);
  for (int i = 1; i <= n*4; i++) {
    lazy[i] = 0;
  }


  for (int i = 0; i < m + k; i++) {
    cin >> a;
    if (a == 1) {
      cin >> b >> c >> d;
      updateSegTree(1, 1, n, b, c, d);
    }
    else {
      cin >> b >> c;
      cout << getSegTree(1, 1, n, b, c) << '\n';
    }

  }

  return 0;
}

