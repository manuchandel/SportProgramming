#include <stdio.h>
#include <cmath>
#define maxN 100001
using namespace std;
int *a=new int [maxN];
int *b=new int [maxN];
int storeIntervals(int n){
	int i,j=0,count=0;
	for(i=0;i<n-1;i++)
		if(a[i]!=a[i+1]){
			b[j]=i;
			count++;
			j=i+1;
		}
	if(j!=n){
		b[j]=n-1;
		count++;
	}return count;

}
int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
class Node{
	public:
		Node(){
			set();
		}
		void set(){
			leftchild=0;
			rightchild=0;
			interval[0]=0;
			interval[1]=0;
			value=0;
		}
		Node *leftchild;
		Node *rightchild;
		int interval[2];
		int value;
		bool color;
};
class Tree{
	public:
		Tree():root(0){}
		void print(Node*);
		void createTree(int,int,Node*);
		int searchKey(Node *p,int i,int j);
		void deleteT(Node*);
		Node *root;

};
int index=0;
void Tree::createTree(int height,int n,Node *currentParent){
	if(height<0)
		return;
	Node *newone=new Node();
	if(!this->root)
		this->root=newone;
	else if(!currentParent->leftchild){
		currentParent->leftchild=newone;
		newone->color=false;
		if(height==0&&index!=n){
			newone->interval[0]=index;
			newone->interval[1]=b[index];
			newone->value=b[index]-index+1;
			index=b[index]+1;
		}
	}
	else if(!currentParent->rightchild){
		currentParent->rightchild=newone;
		newone->color=true;
		if(height==0&&index!=n){
			newone->interval[0]=index;
			newone->interval[1]=b[index];
			newone->value=b[index]-index+1;
			index=b[index]+1;
		}
	}else;
	createTree(height-1,n,newone);
	createTree(height-1,n,newone);
	if(height>0){
		Node *left,*right=NULL;
		left=newone->leftchild;
		right=newone->rightchild;
		if(right->interval[0]==right->interval[1]&&right->interval[0]==0){
			if(newone->color==true){
				currentParent->rightchild=left;
			}else{
				currentParent->leftchild=left;
			}
			delete newone;
		}else{
			newone->interval[0]=left->interval[0];
			newone->interval[1]=right->interval[1];
			newone->value=max(left->value,right->value);
		}
	}return;
}
void Tree::deleteT(Node *p){
	if(!p)
		return;
	deleteT(p->leftchild);
	deleteT(p->rightchild);
	delete p;
}
void Tree::print(Node *p){
	if(!p)
		return;
	//printf("root %d %d %d\n",this->root->interval[0],this->root->interval[1],this->root->value);
	printf("%d %d %d\n",p->interval[0],p->interval[1],p->value);
	print(p->leftchild);
	print(p->rightchild);
}
int Tree::searchKey(Node *p,int i,int j){
	if(i==p->interval[0]&&j==p->interval[1])
		return p->value;
	else if(!p->leftchild){
		return j-i+1;
	}else{
		int leftstart=p->leftchild->interval[0];
		int leftend=p->leftchild->interval[1];
		int rightstart=p->rightchild->interval[0];
		int rightend=p->rightchild->interval[1];
		if(i>leftend)
			return this->searchKey(p->rightchild,i,j);
		else if(j<rightstart)
			return this->searchKey(p->leftchild,i,j);
		else return max(searchKey(p->leftchild,i,leftend),searchKey(p->rightchild,rightstart,j));
	}
}
int main(){
	int n,q,i,j;
	while(1){
		scanf("%d",&n);
		if(n==0)
			break;
		scanf("%d",&q);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			b[i]=-1;
		}
		i=storeIntervals(n);
		i=ceil(log2(i));
		Tree tree;
		index=0;
		tree.createTree(i,n,tree.root);
		//tree.print(tree.root);
		while(q--){
			scanf("%d%d",&i,&j);
			if(i==j)
				printf("1\n");
			else printf("%d\n",tree.searchKey(tree.root,i-1,j-1));
		}
		//	tree.deleteT(tree.root);
	}
}

