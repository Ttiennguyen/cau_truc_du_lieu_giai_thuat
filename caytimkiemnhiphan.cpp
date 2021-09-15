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

typedef struct BSTREE{
	BNODE* root;
};

void Initialize(BSTREE &tree) { tree.root = NULL; }

bool isEmpty(BSTREE &tree)
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

// in cay
void PrintTree(BNODE* p, int k) { // k là mức của node
	if (p == NULL) return;
	PrintTree(p->right, k + 1);
	cout << endl << setw(4 * k) << p->info;
	PrintTree(p->left, k + 1);
}

bool InsertNode(BNODE *&p, int x)
{
if(p!=NULL)
{
    if(p->info == x) return 0;
    if(p->info > x) return InsertNode(p->left,x);
    if(p->info < x) return InsertNode(p->right,x);
}
else
{
    p = CreateNode(x);
    if (p==NULL) return -1;
    return 1;
}

}

void CreateBST(BNODE *&p)
{
    int x;
while (true)
{
    cin>>x ;
    if( x == -1) break;
    InsertNode(p,x);
}

}
///tim kiem phan tu x
BNODE* SearchNode(BNODE* p, int x) {
	if (p == NULL) return NULL; 
	if (p->info == x) return p; 
	 
	if (p->info > x) return SearchNode(p->left, x);
	if (p->info < x) return SearchNode(p->right, x);
}
// tim gia tri nho nhat trong cay
int GetMinValue(BNODE* p) {
	if (p->left == NULL) return p->info;
	return GetMinValue(p->left);
}
// tim gia tri lon nhat trong cay
int GetMaxValue(BNODE* p) {
	if (p->right == NULL) return p->info;
	return GetMaxValue(p->right);
}
/// hàm tim node the mang
void SearchStandFor(BNODE* &q, BNODE* &sf) {
	if (sf->left != NULL) SearchStandFor(q, sf->left);
	else { //trai nhat 
		q->info = sf->info;
		q = sf;
		sf = sf->right;
	}
}

bool DeleteNode(BNODE* &p, int x) {
    if (p == NULL) return false;// ko tìm thấy x
    if (p->info > x) return DeleteNode(p->left, x);
    if (p->info < x) return DeleteNode(p->right, x);
    if (p->info == x) {
	BNODE* q = p;
	if (p->left == NULL && p->right == NULL)
		p = NULL;
	else if (p->left == NULL)// co 1 con ben phai
		p = p->right;
	else if (p->right == NULL) // co 1 con trai
		p = p->left;
	else // co 2 con 
		SearchStandFor(q, p->right);// tim node the mang
	delete q; return true;
    }
}

int main()
{
    BSTREE tree;
    Initialize(tree);
    CreateBST(tree.root);
    PrintTree(tree.root,0);
    cout<<endl;
    // tim lon nhat nho nhat
    BNODE *p = SearchNode(tree.root,50);
    if(p=NULL)
    cout<<"khong tim thay "<<endl;
    else cout<<"tim thay"<<endl;
    cout<<"min: "<<GetMinValue(tree.root)<<endl;
    cout<<"max: "<<GetMaxValue(tree.root)<<endl;
// xoa node trong cay 
    DeleteNode(tree.root,59);
    PrintTree(tree.root,0);
}