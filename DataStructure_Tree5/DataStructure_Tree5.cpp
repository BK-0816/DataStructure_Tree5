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
	return NULL; 	// 탐색에 실패했을 경우 NULL 반환
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
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// 변경된 루트 포인터를 반환한다. 
	return node;
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;

	return current;
}

TreeNode* delete_node(TreeNode* node, int key)
{
	if (node == NULL) return node;

	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (key < node->key)
		node->left = delete_node(node->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (key > node->key)
		node->right = delete_node(node->right, key);
	// 키가 루트와 같으면 이 노드를 삭제하면 됨
	else {
		// 첫 번째나 두 번째 경우
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
		// 세 번째 경우
		TreeNode* temp = min_value_node(node->right);

		// 중외 순회시 후계 노드를 복사한다. 
		node->key = temp->key;
		// 중외 순회시 후계 노드를 삭제한다. 
		node->right = delete_node(node->right, temp->key);
	}
	return node;
}

int main() {
	char menu = 0;

	printf("-----------------\n");
	printf("   s    : 검색\n");
	printf("   i    : 노드 추가\n");
	printf("   d    : 노드 삭제\n");
	printf("   t    : 중위 순회\n");
	printf("   I    : 노드 추가(반복)\n");
	printf("   D    : 노드 삭제(반복)\n");
	printf("   c    : 종료\n");
	printf("-----------------\n");

	while (menu = 'c') {
		printf("메뉴 입력 :");
		scanf_s("%c", menu);
		switch (menu)
		case 's':
		 



		
	}
	return 0;
}
