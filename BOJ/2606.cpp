#include <iostream>
using namespace std;

int parent[101];

int findParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	int a, b, n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i; // init
	}
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		unionParent(a, b);
	}

	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (findParent(i) == findParent(1)) ans++;
	}

	cout << ans << '\n';
	
	return 0;
}
