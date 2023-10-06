#include <iostream>
#include <vector>
#define INF 1e9
using  namespace std;

long long segmentTree[4 * 1000000];
vector<long long> nums;

void changeNum(int node, int s, int e, int i, long long n) {
  
  // 변경할 노드 찾으면, 변경하기
  if (s == e) {
    segmentTree[node] = n;
    return;
  }

  // 변경할 인덱스 찾아가기
  int mid = (s + e) / 2;
  if (s <= i && i <= mid) changeNum(2 * node, s, mid, i, n);
  else if (mid+1 <= i && i <= e) changeNum(node * 2 + 1, mid+1, e, i, n);

  // 변경 사항 부모 노드에 반영
  segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
}

long long findSum(int node, int s, int e, int l, int r) {
  
  // 범위 안에 안속하면 0 반환
  if (r < s || e < l) return 0;

  // 범위 안에 속하는 경우 반환
  if (l <= s && e <= r) return segmentTree[node];

  // 일부분이 범위에 속하면 나눠서 계산 후 합 반환
  int mid = (s + e) / 2;
  return findSum(node * 2, s, mid, l, r) + findSum(node * 2 + 1, mid+1, e, l, r);
}

void makeSegementTree(int node, int s, int e) {
  if (s == e) {
    segmentTree[node] = nums[s];
    return;
  }

  int mid = (s + e) / 2;
  makeSegementTree(node * 2, s, mid);
  makeSegementTree(node * 2 + 1, mid+1, e);

  segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
  
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); //faster

  long long a, b, c, n, m, k;
  
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a;
    nums.push_back(a);
  }
  makeSegementTree(1, 0, n-1);

  for (int i = 0; i < m + k; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      changeNum(1, 0, n - 1, b - 1, c);
    }
    else cout << findSum(1, 0, n-1, b-1, c-1) <<'\n';
  }

  return 0;
}

