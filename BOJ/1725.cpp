#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define INF 1e9
using  namespace std;

pair<int, int> segmentTree[4*100000];
vector<int> nums;

pair<int, int> findMin(int node, int s, int e, int l, int r) {
  if (r < s || e < l) return { s, INT_MAX };

  if (l <= s && e <= r) return segmentTree[node];

  int mid = (s + e) / 2;
  pair<int, int> lt, rt;
  lt = findMin(node * 2, s, mid, l, r); rt = findMin(node * 2 + 1, mid + 1, e, l, r);

  if (lt.second < rt.second) return { lt.first, lt.second };
  else return { rt.first, rt.second };
}

void makeSegementTree(int node, int s, int e) {
  if (s == e) {
    segmentTree[node] = { s, nums[s] };
    return;
  }

  int mid = (s + e) / 2;
  makeSegementTree(node * 2, s, mid);
  makeSegementTree(node * 2 + 1, mid+1, e);

  pair<int, int> lt, rt;
  lt = segmentTree[node * 2]; rt = segmentTree[node * 2 + 1];

  if (lt.second < rt.second)  segmentTree[node] = { lt.first, lt.second };
  else segmentTree[node] = { rt.first, rt.second };
  
  return;
}

long long getBiggestRec(int n, int s, int e) {
  if (s > e) return -1;

  pair<int, int> minH = findMin(1, 0, n - 1, s, e);

  long long bigR = (e - s + 1)*minH.second;
  return max({ bigR, getBiggestRec(n, s, minH.first - 1), getBiggestRec(n, minH.first + 1, e) });
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); //faster

  int a, n;
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    nums.push_back(a);
  }
  makeSegementTree(1, 0, n-1);

  cout << getBiggestRec(n, 0, n - 1);
  return 0;
}

