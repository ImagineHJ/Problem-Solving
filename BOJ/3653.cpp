#include <iostream>
#include <algorithm>
using  namespace std;

int N = 200005;
int place[100001];
int segmentTree[4*200005]; // s-e 위치의 총 개수
int top;

void printTree() {
  for (int i = 0; i < N*4; i++) {
    //printf("-- %d %d\n", i, segmentTree[i]);
  }

}

void makeSegmentTree(int node, int s, int e) {
  if (s == e && top>s) {
    segmentTree[node] = 1;
    return;
  }

  if (s == e && top <= s) {
    segmentTree[node] = 0;
    return;
  }
  
  int m = (s + e) / 2;
  makeSegmentTree(node * 2, s, m);
  makeSegmentTree(node * 2 + 1, m + 1, e);
  segmentTree[node] = segmentTree[node*2] + segmentTree[node*2+1];
}

int getSeg(int node, int s, int e, int l, int r) {
  if (r < s || e < l) return 0;
  if (l<=s && e <= r) return segmentTree[node];
  int m = (s + e) / 2;
  return getSeg(node * 2, s, m, l, r) + getSeg(node * 2+1, m+1, e, l, r);
}


void changeSeg(int node, int s, int e, int place, int val) {
  if (place < s || e < place) return;
  if (s == e && s == place) {
    segmentTree[node] += val;
    return;
  }

  int m = (s + e) / 2;
  changeSeg(node * 2, s, m, place, val);
  changeSeg(node * 2 + 1, m + 1, e, place, val);
  segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
}

int getDvd(int d) {
  int oldP = place[d];

  printTree();
  int ret = getSeg(1, 0, N, oldP+1, N);
  //printf("books from %d-%d = %d\n", oldP + 1, N, ret);
  
  place[d] = top++;
  //printf("remove %d from %d\n", d, oldP);
  changeSeg(1, 0, N, oldP, -1);
  //printTree();
  //printf("put %d from %d\n", d, place[d]);
  changeSeg(1, 0, N, place[d], 1);
  //printTree();

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); //faster

  int t, n, m, a;

  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> m;

    N = n + m ;
    for (int j = 1; j <= n; j++) place[j]=n-j;
    top = n;
    
    makeSegmentTree(1, 0, N);
    //printTree();

    for (int j = 0; j < m; j++) {
      cin >> a;
      cout << getDvd(a) << '\n';
      //printTree();
    }
  }
  
  return 0;
}

