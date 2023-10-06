#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

int n;
long long segTree[100000 * 4];
long long lazy[100000 * 4];

void updateLazy(int node, int s, int e) {
  if (lazy[node]%2==1) {
    segTree[node] = (e - s + 1) - segTree[node];

    if (s != e) {
      lazy[node * 2] += 1;
      lazy[node * 2 + 1] += 1;
    }
    lazy[node] = 0;
  }

}

void updateSegTree(int node, int s, int e, int l, int r) {
  updateLazy(node, s, e);

  if (r < s || e < l) return;
  if (l <= s && e <= r) {
    segTree[node] = (e - s + 1)- segTree[node];
    if (s != e) {
      lazy[node * 2] += 1;
      lazy[node * 2 + 1] += 1;
    }
    return;
  }
  int m = (s + e) / 2;
  updateSegTree(node * 2, s, m, l, r);
  updateSegTree(node * 2 + 1, m + 1, e, l, r);
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

  int n, m, o, s, t;
  cin >> n >> m;

  for (int i = 1; i <= n*4; i++) {
    segTree[i] = 0;
    lazy[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    cin >> o >> s >> t;
    if (o == 0) {
      updateSegTree(1, 1, n, s, t);
    }
    else {
      cout << getSegTree(1, 1, n, s, t) << '\n';
    }
  }

  return 0;
}

