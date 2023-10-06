#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define INF 1e9
using  namespace std;

pair<int, int> segmentTree[4*100000];
vector<int> nums;

pair<int, int> findMinMAx(int node, int s, int e, int l, int r) {
  
  // 범위 안에 안속하면 0 반환
  if (r < s || e < l) return {INT_MAX, INT_MIN};

  // 범위 안에 속하는 경우 반환
  if (l <= s && e <= r) return segmentTree[node];

  // 일부분이 범위에 속하면 나눠서 계산 후 합 반환
  int mid = (s + e) / 2;
  pair<int, int> lt, rt;
  lt = findMinMAx(node * 2, s, mid, l, r);
  rt = findMinMAx(node * 2 + 1, mid + 1, e, l, r);
  return { min(lt.first, rt.first),  max(lt.second, rt.second) };
}

void makeSegementTree(int node, int s, int e) {
  if (s == e) {
    segmentTree[node] = { nums[s], nums[s] };
    return;
  }

  int mid = (s + e) / 2;
  makeSegementTree(node * 2, s, mid);
  makeSegementTree(node * 2 + 1, mid+1, e);

  segmentTree[node] = { min(segmentTree[node * 2].first, segmentTree[node * 2 + 1].first), max(segmentTree[node * 2].second, segmentTree[node * 2 + 1].second) };
  
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); //faster

  int a, b, n, m;
  
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a;
    nums.push_back(a);
  }
  makeSegementTree(1, 0, n-1);

  pair<int, int> p;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    p = findMinMAx(1, 0, n - 1, a-1, b-1);
    cout << p.first << ' ' << p.second << '\n';
  }
  return 0;
}

