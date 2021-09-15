#include <iostream>
using namespace std;
#include <iomanip>
typedef int DATA;
// tao cay
typedef struct BNODE {
	int info;
	BNODE* left;
	BNODE* right;
} BNODE;

typedef struct BTREE{
	BNODE* root;
};

void Initialize(BTREE &tree) { tree.root = NULL; }

bool isEmpty(BTREE &tree)
{
     return tree.root = NULL;
}

BNODE* CreateNode(DATA x) {
	BNODE* p = new BNODE;
	if (p != NULL) {
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

void CreateBTree(BNODE* &p) {
	int x;
	cout << "\nEnter value of NODE = "; cin >> x;
	if (x == -1) return; // break condition
	p = CreateNode(x);
	if (p != NULL) {
		cout << "+++ LEFT-BRANCH of NODE " << x;
		CreateBTree(p->left);
		cout << "+++ RIGHT-BRANCH of NODE " << x;
		CreateBTree(p->right);
	}
}	
// in cay
void PrintTree(BNODE* p, int k) { // k là mức của node
	if (p == NULL) return;
	PrintTree(p->right, k + 1);
	cout << endl << setw(4 * k) << p->info;
	PrintTree(p->left, k + 1);
}
//////////////////////////////////////////////// duyet cay LNR NLR LRN
void LNR(BNODE* p) {
	if (p == NULL) return;
	LNR(p->left);
	cout << p->info << " ";
	LNR(p->right);
}

void NLR(BNODE* p) {
	if (p == NULL) return;
	cout << p->info << " ";
	NLR(p->left);
	NLR(p->right);
}

void LRN(BNODE* p) {
	if (p == NULL) return;
	LRN(p->left);
	LRN(p->right);
	cout << p->info << " ";
}
///////////////////////////////// ham dem node
int CountNode(BNODE* p) {
	if (p == NULL) return 0;
	int a = CountNode(p->left);
	int b = CountNode(p->right);
	return (a + b + 1);
}

int CountLeafNode(BNODE* p) {
	if (p == NULL) return 0;
	int a = CountLeafNode(p->left);
	int b = CountLeafNode(p->right);
	if (p->left == NULL && p->right == NULL)
		return (a + b + 1);
	else
		return (a + b);
}

int CountBranchNode(BNODE* p) {
	int totalNodes = CountNode(p);
	int leafNodes = CountLeafNode(p);
	return totalNodes - leafNodes - 1; // - rootNode
}
///////////////////////////////////// chieu cao va muc
int GetHeight(BNODE* p) {
	if (p == NULL) return -1; // counting by edges
	//if (p == NULL) return 0; // counting by nodes
	int a = GetHeight(p->left);
	int b = GetHeight(p->right);
	int max = a > b ? a : b;
	return (max + 1);
}

void DiplayAtLevel(BNODE* p, int k) {
	if (p == NULL) return;
	if (k == 0) {
		cout << p->info << " ";
		return;
	}
	DiplayAtLevel(p->left, k - 1);
	DiplayAtLevel(p->right, k - 1);
}


int main()
{
    BTREE tree;
    Initialize (tree);
    CreateBTree(tree.root);
    PrintTree(tree.root,0);
    ////////////// duyet cay
    cout<<endl;
    NLR(tree.root);
    cout<<endl;
    LNR(tree.root);
    cout<<endl;
    LRN(tree.root);
    //////////////// dem node (dem la cay)
    cout<<endl;
    cout<<CountNode(tree.root);
    cout<<endl;
    cout<<CountLeafNode(tree.root);
    cout<<endl;
    cout<<CountBranchNode(tree.root);
    ////////////////////(chieu cao node và liet ke phan tu ở muc k)
    cout<<GetHeight(tree.root);
    cout<<endl;
    DiplayAtLevel(tree.root,2);
    return 0;
}
