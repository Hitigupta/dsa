#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node *buildtree(vector<int> &x, int &idx)
{
    if (idx > x.size() - 1 || x[idx] == -1)
    {
        idx++;
        return NULL;
    }
    Node *root = new Node(x[idx]);
    idx++;
    root->left = buildtree(x, idx);
    root->right = buildtree(x, idx);
    return root;
}
void preordert(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    preordert(root->left);
    preordert(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}
void levelorder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
    cout << endl;
}
void level(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();
        if(curr == NULL)
        {if(!q.empty())
            {cout << endl;
             q.push(NULL);
            continue;
            }
            else
            {break;}
        }
        cout << curr->data << " ";
        if (curr->left != NULL)
        {q.push(curr->left);}
        if (curr->right != NULL)
        {q.push(curr->right);}
    }
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return 1 + max(leftheight, rightheight);
}
int count(Node *root)
{
    if (root == NULL)
        return 0;
    int leftcount = count(root->left);
    int rightcount = count(root->right);
    return 1 + leftcount + rightcount;
}
int sum(Node *root)
{
    if (root == NULL)
        return 0;
    int leftsum = sum(root->left);
    int rightsum = sum(root->right);
    return root->data + leftsum + rightsum;
}
void topview(Node *root)
{ map<int, int> m;
    if (root == NULL)
        return ;
    queue<pair<Node *,int>> q;
    q.push({root,0});
    while (q.size() > 0)
    {   int dist=q.front().second;
        Node* curr=q.front().first;
        q.pop();
        if (m.find(dist) == m.end())
        {
           m[dist]=curr->data;
        }
        if (curr->left)
            q.push({curr->left,dist-1});
        if (curr->right)
            q.push({curr->right,dist+1});
    }
    for(auto it:m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}
void klevel(Node* root,int x){    
    if(root==NULL) return;
    if(x==1) {cout<<root->data;
        return;}
    klevel(root->left,x-1);
    klevel(root->right,x-1);
}
void kleveliter(Node* root,int k){
    if(root==NULL) return;
    int x=0;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0 && x<=k){
        Node* curr=q.front();
        q.pop();
        if(curr==NULL) {
            cout<<endl;
            x++;
            if(!q.empty()) q.push(NULL);
        }
        else{
        if(x==k) cout<<curr->data<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);}
    }
}
int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = 0;
    Node *b = buildtree(preorder, idx);
    cout << b->data << endl;
    cout << b->left->data << endl;
    cout << b->right->data << endl;
    preordert(b);
    cout << endl;
    inorder(b);
    cout << endl;
    postorder(b);
    cout << endl;
    levelorder(b);
    level(b);
    cout << endl;
    cout << height(b);
    cout << endl;
    cout << count(b);
    cout << endl;
    cout << sum(b);
    topview(b);
    cout<<endl;
    klevel(b,2);
    cout<<endl;
    kleveliter(b);
}