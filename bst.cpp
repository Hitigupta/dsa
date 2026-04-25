#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val=data;
        left=right=NULL;
    }
};

Node* bst(Node* root,int x){
    if(root==NULL) {return new Node(x);}
    if(x>root->val){
        root->right=bst(root->right,x);
    }
    else root->left=bst(root->left,x);
    return root;
}
Node* helper(vector<int> &arr){
    Node* root=NULL;
    for(int i=0;i<arr.size();i++){
        root=bst(root,arr[i]);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
bool search(Node* root,int target){
    if(root==NULL) return false;
    if(root->val==target) return true;
    if(root->val>target){return search(root->left,target);}
    else {return search(root->right,target);} 
}
Node* IS(Node* root){
    while(root!=NULL && root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* deletenode(Node* root,int target){
    if(root==NULL) return NULL;
    if(root->val>target){root->left=deletenode(root->left,target);}
    else if(root->val<target){root->right=deletenode(root->right,target);}
    else{
        if(root->left==NULL){
            Node* tree=root->right;
            delete root;
            return tree;
        }
        else if(root->right==NULL){
            Node* tree=root->left;
            delete root;
            return tree;
        }
        else {
            Node* i=IS(root->right);
            root->val=i->val;
            root->right=deletenode(root->right,i->val);
        }
        return root;
    }
}

int main(){
    vector<int>arr={1,5,3,26,7,4};
    Node* curr=helper(arr);
    inorder(helper(arr));
    cout<<endl;
    cout<<search(curr,7)<<endl;
    Node* tree=deletenode(curr,3);
    inorder(tree);
}