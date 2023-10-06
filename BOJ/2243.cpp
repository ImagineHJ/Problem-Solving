#include <iostream>
#include <algorithm>
using  namespace std;

int N = 1000000;
int segmentTree[4*1000000]; // s-e 레벨 사탕의 총 개수

void changeSegmentTree(int node, int s, int e, int target, int cnt) {
  if (target < s || e < target) return;

  if (s == e && s == target) {
    segmentTree[node] += cnt;
    return;
  }

  int m = (s + e) / 2;
  changeSegmentTree(node * 2, s, m, target, cnt);
  changeSegmentTree(node * 2 + 1, m+1, e, target, cnt);

  segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
}

void putCandy(int i, int cnt) {
  changeSegmentTree(1, 1, N, i, cnt);
}

int getSegmentTree(int node, int s, int e, int baseRank, int targetRank) {
  if (targetRank < baseRank || baseRank + segmentTree[node]-1 < targetRank) return 0;
  if (s==e && baseRank<=targetRank && targetRank<= baseRank + segmentTree[node]-1) return s;
  
  int m = (s + e) / 2;
  return getSegmentTree(node * 2, s, m, baseRank, targetRank) + getSegmentTree(node * 2 + 1, m + 1, e, baseRank+segmentTree[node*2], targetRank);
}

int getCandy(int rank) {
  int ret = getSegmentTree(1, 1, N, 1, rank);
  putCandy(ret, -1);
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); //faster

  int n, a, b, c;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a == 1) {
      cin >> b;
      cout << getCandy(b) << '\n';
    }
    else {
      cin >> b >> c;
      putCandy(b, c);
    }
  }
  
  return 0;
}

