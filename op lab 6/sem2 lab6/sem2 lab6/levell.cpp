#include"levell.h"
int levell::isEmpty() {
	if (Head == NULL)
		return 1;
	else
		return 0;
}
void levell::addlevel(Node* tmp) {
	levelNode* Ptr = new levelNode;
	Ptr->trans = tmp;
	if (Head == NULL) {
		Head = Ptr;
		Ptr->next = NULL;
	}
	else {
		levelNode* tmp_c = Head;
		while (tmp_c->next != NULL)
			tmp_c = tmp_c->next;
		tmp_c->next = Ptr;
		Ptr->next = NULL;
	}
}
Node* levell::dellevel() {
	levelNode* cur = Head->next;
	Node* tmp_c = Head->trans;
	if (Head != NULL) {
		delete Head;
		Head = cur;
		return tmp_c;
	}
	else
		return NULL;
}
