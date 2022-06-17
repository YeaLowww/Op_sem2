#include"MyTree.h"
#include"levell.h"
Node* Tree::makeTree(string m[], int from, int n) {
	if (n == 0)return NULL;
	Node* p = new Node(m[from]);
	int nl = n / 2;
	int nr = n - nl - 1;
	p->left = makeTree(m, from + 1, nl);
	p->right = makeTree(m, from + nl + 1, nr);
	return p;
}
void Tree::printTree(const string& prefix, const Node* node, bool isLeft) {
	if (node != nullptr) {
		cout << prefix;
		cout << (isLeft ? "|---" : "L___");
		cout << node->inf << endl;
		// enter the next tree level - left and right branch
		printTree(prefix + (isLeft ? "|   " : "    "), node->left, true);
		printTree(prefix + (isLeft ? "|   " : "    "), node->right, false);
	}
}
void Tree::level(Node* root, string m[], int from) {
	levell T;
	T.addlevel(root);
	Node* tmp;
	while (!T.isEmpty()) {
		tmp = T.dellevel();
		tmp->inf = m[from];
		from++;
		if (tmp->left != NULL)
			T.addlevel(tmp->left);
		if (tmp->right != NULL)
			T.addlevel(tmp->right);
	}
}