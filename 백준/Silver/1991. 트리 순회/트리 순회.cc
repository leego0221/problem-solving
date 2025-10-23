#include <iostream>
#include <map>
using namespace std;

map<char, pair<char, char>> tree;

void preorder_traverse(char root) {
	if (root == '.') {
		return;
	}
	cout << root;
	preorder_traverse(tree[root].first);
	preorder_traverse(tree[root].second);
}

void inorder_traverse(char root) {
	if (root == '.') {
		return;
	}
	inorder_traverse(tree[root].first);
	cout << root;
	inorder_traverse(tree[root].second);
}

void postorder_traverse(char root) {
	if (root == '.') {
		return;
	}
	postorder_traverse(tree[root].first);
	postorder_traverse(tree[root].second);
	cout << root;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	char parent, l_child, r_child;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> parent >> l_child >> r_child;
		pair<char, char> child = make_pair(l_child, r_child);
		tree.insert(make_pair(parent, child));
	}

	preorder_traverse('A');
	cout << '\n';
	inorder_traverse('A');
	cout << '\n';
	postorder_traverse('A');
	return 0;
}