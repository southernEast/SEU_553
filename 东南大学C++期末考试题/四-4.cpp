#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* insert(Node* head, Node* p) {
	Node* p1, * p2;
	if (head == 0) {		// 插入链表的head
		head = p;
		head->next = 0;
		return head;
	}
	if (head->data >= p->data) {	// 插入链表首部的前面，成为新的head
		p->next = head;
		head = p;
		return head;
	}
	p2 = p1 = head;
	while (p2->next && p2->data < p->data) {	// 注意这个要判断p2->next，因为后面还是有可能会访问到p2的数据成员
		p1 = p2;
		p2 = p2->next;
	}
	if (p2->data < p->data) {	// 插入链表尾部
		p2->next = p;
		p->next = 0;
	}
	else {				// 插入链表p1与p2之间
		p->next = p2;
		p1->next = p;
	}
	return head;		// 题目中少了这一句，如果没有这一句，程序可能会出错，取决于怎么调用
}

int main() {
	Node* head = 0, *temp;
	
	for (int i = 0; i < 10; ++i) {
		temp = new Node;
		temp->data = rand() % 10;
		temp->next = 0;
		head = insert(head, temp);
	}
	Node* now = head;
	while (now) {
		cout << now->data << " ";
		now = now->next;
	}

	return 0;
}