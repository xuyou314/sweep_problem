#include <iostream> 
#include <vector>
#include <queue>
using namespace std;
struct Node{
	int x1,y1,x2,y2,max,height;
	Node *left, *right;
	Node():x1(0),y1(0),left(NULL),right(NULL){}
	Node(int x1, int y1, int x2, int y2):x1(x1),y1(y1),x2(x2),y2(y2),left(NULL),right(NULL){}
};
int getHeight(Node *root){
	if(!root) return 0;
	return root->height;
}
void print_tree(Node *tree){
	queue<Node*>cur_nodes;
	cur_nodes.push(tree);
	while(!cur_nodes.empty()){
		int cur_num = cur_nodes.size();
		for(int i = 0;i<cur_num; i++){
			Node *tmp = cur_nodes.front();
			cout<<tmp->x1<<","<<tmp->x2<<":"<<tmp->height<<","<<tmp->max<<" ";
			if(tmp->left) cur_nodes.push(tmp->left);
			if(tmp->right) cur_nodes.push(tmp->right);
			cur_nodes.pop();
		}
		cout<<endl;
	
	}

}
Node* rightRotate(Node *root){
	Node *tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	root->height = max(getHeight(root->left),getHeight(root->right))+1;
	tmp->height = max(getHeight(tmp->left),getHeight(tmp->right))+1;
	return tmp;
}
Node* leftRotate(Node *root){
	Node *tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	root->height = max(getHeight(root->left),getHeight(root->right))+1;
	tmp->height = max(getHeight(tmp->left),getHeight(tmp->right))+1;
	return tmp;

}
Node* insert(Node *root, vector<int>&rect){
	if(!root){
		Node *node = new Node(rect[0], rect[1], rect[2], rect[3]);
		node->max = rect[2];
		node->height = 1;
		return node;
	}
	if(rect[0]<=root->x1){
			cout<<"choose left"<<endl;
		if(!root->left){
			Node *node = new Node(rect[0], rect[1], rect[2], rect[3]);
			node->max = rect[2];
			node->height = 1;
			root->left = node;
			//return;
		}
		else{
			cout<<"choose left"<<endl;
			root->left = insert(root->left, rect);
		}
	}
	if(rect[0]>root->x1){
			cout<<"choose right"<<endl;
		if(!root->right){
			Node *node = new Node(rect[0], rect[1], rect[2], rect[3]);
			node->max = rect[2];
			node->height = 1;
			root->right = node;
			//return;
		}
		else{
			cout<<"choose right"<<endl;
			root->right = insert(root->right, rect);
		}
	}
	if(rect[2]>root->max){
		root->max = rect[2];
	}
	root->height = 1+ max(getHeight(root->left), getHeight(root->right));	
	if(getHeight(root->right)-getHeight(root->left)>1){
		if(rect[0]<=root->right->x1){
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
		else{
			return leftRotate(root);
		}
	}
	if(getHeight(root->right)-getHeight(root->left)<-1){
		if(rect[0]>root->left->x1){
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		else{
			return rightRotate(root);
		}
	}
	return root;

}
void search(Node *root, int val, vector<Node*>&ret){
	if(root->x1<=val&&root->x2>=val){
		ret.push_back(root);
	}
	if(root-left&&root->left->max>)
}
bool overlap(vector<int>& rect1, vector<int>& rect2){
	vector<int> low = rect1;
	vector<int> high = rect2;
	if(rect1[1] > rect2[1]){
		low = rect2;
		high = rect1;
	}
	//higher rectangle on the right
	if(low[2]>high[0]&&low[3]>high[1]&&high[0]>=low[0]){
		return 1;
	}
	//higher rectangle on the left
	if(low[0]<high[2]&&low[3]>high[1]&&high[0]<low[0]){
		return 1;
	}
	return 0;

}
bool isRectangleCover(vector<vector<int>>&rectangles){
	int rectnum = rectangles.size();
	int x1=0x7fffffff,y1=0x7fffffff;
	int x2=0,y2=0;
	int area_sum = 0;
	for(int i = 0;i < rectnum;i++){
		if(rectangles[i][0]<x1){
			x1 = rectangles[i][0];
		}
		if(rectangles[i][1]<y1){
			y1 = rectangles[i][1];
		}
		if(rectangles[i][2]>x2){
			x2 = rectangles[i][2];
		}
		if(rectangles[i][3]>y2){
			y2 = rectangles[i][3];
		}
		area_sum += (rectangles[i][2]-rectangles[i][0])*(rectangles[i][3]-rectangles[i][1]);
	
	}
	int area = (x2 - x1)*(y2 - y1);
	if(area != area_sum){
		return 0;
	}
	for(int i = 0;i<rectnum;i++){
		for(int j = i+1;j<rectnum;j++){
			if(overlap(rectangles[i], rectangles[j])) return 0;
		}
	
	}
	return 1;
}
int main(){
	vector<vector<int>>rects = {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
	vector<vector<int>>rects1 = {{1,1,3,3},{3,1,4,2},{4,2,4,4},{5,3,2,4},{6,3,3,4}};
	vector<vector<int>>rects2 = {{1,1,2,3},{1,3,2,4},{3,1,4,2},{3,2,4,4}};
	Node *n = new Node(rects[0][1],rects[0][2],rects[0][2],rects[0][3]);
	Node *n1 = new Node();
	Node *n2 = new Node();
	Node *n3 = new Node();
	Node *root = NULL;
	//n->left = n1;
	//n1->left = n2;
	//n2->left = n3;
	for(int i = 0;i<5;i++){
		cout<<"insert "<<rects[i][0]<<" "<<rects[i][2]<<endl;
		root = insert(root, rects[i]);
	}
	print_tree(root);
	cout<<max(2,4)<<endl;
	cout<<n->x1<<n->left<<endl;
	return 0;
}

