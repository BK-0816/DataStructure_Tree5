#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
	
} TreeNode;
TreeNode n1 = { 25, NULL, NULL };
TreeNode n2 = { 16, NULL, &n1 };
TreeNode n3 = { 42, NULL, NULL };
TreeNode n4 = { 46, &n3, NULL };
TreeNode n5 = { 55, NULL, NULL };
TreeNode n6 = { 53, &n4, &n5 };
TreeNode n7 = { 41, &n2, &n6 };;
TreeNode n8 = { 62, NULL, NULL };
TreeNode n9 = { 64, NULL, NULL };
TreeNode n10 = { 63, &n8, &n9 };
TreeNode n11 = { 70, NULL, NULL };
TreeNode n12 = { 65, &n10, &n11 };
TreeNode n13 = { 74, &n12, NULL };
TreeNode n14 = { 60, &n7, &n13 };
TreeNode* node = &n14;

TreeNode* search(TreeNode* node, int key)
{
	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL; 	// Ž���� �������� ��� NULL ��ȯ
}

TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (node == NULL) return new_node(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;

	return current;
}

TreeNode* delete_node(TreeNode* node, int key)
{
	if (node == NULL) return node;

	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (key < node->key)
		node->left = delete_node(node->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (key > node->key)
		node->right = delete_node(node->right, key);
	// Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else {
		// ù ��°�� �� ��° ���
		if (node->left == NULL) {
			TreeNode* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL) {
			TreeNode* temp = node->left;
			free(node);
			return temp;
		}
		// �� ��° ���
		TreeNode* temp = min_value_node(node->right);

		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
		node->key = temp->key;
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
		node->right = delete_node(node->right, temp->key);
	}
	return node;
}

int main() {
	char menu = 0;

	printf("-----------------\n");
	printf("   s    : �˻�\n");
	printf("   i    : ��� �߰�\n");
	printf("   d    : ��� ����\n");
	printf("   t    : ���� ��ȸ\n");
	printf("   I    : ��� �߰�(�ݺ�)\n");
	printf("   D    : ��� ����(�ݺ�)\n");
	printf("   c    : ����\n");
	printf("-----------------\n");

	while (menu = 'c') {
		printf("�޴� �Է� :");
		scanf_s("%c", menu);
		switch (menu)
		case 's':
		 



		
	}
	return 0;
}
