#include <iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class Graph{
    public:
        int V;
        vector<vector<int>> arr;
    Graph(int V){
        this->V=V;
        arr.resize(V);
    }
    void addEdges(int u,int v){
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<"->";
            for(int j:arr[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(){
    vector<bool>find(false,arr.size());
    queue<int>q;
    q.push(0);
    find[0]=true;
    while(q.size()>0){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:arr[u]){
            if(!find[v]){
                find[v]=true;
                q.push(v);
            }
        }
    }
    }
    void dfsHelper(int u,vector<bool>&visited){
        cout<<u<<" ";
        visited[u]=true;
        for(int i:arr[u]){
            if(!visited[i]){
                dfsHelper(i,visited);
            }
        }
    }
    void dfs(){
        vector<bool>vis(V,false);
        dfsHelper(0,vis);
    }
    bool detectcycviadfs(int u,int parent,vector<bool>&visited){
        cout<<u<<" ";
        visited[u]=true;
        for(int i:arr[u]){
            if(!visited[i]){
                if(detectcycviadfs(i,u,visited)) return true;
            }
            else if(i!=parent){return true;}
        }
        return false;
    }
    bool detect1(){
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]) 
            {if(detectcycviadfs(0,-1,visited)) return true;}
        }
        return false;
    }
    bool detectundir(int v,vector<bool>&vis,vector<bool>path){
        vis[v]=true;
        path[v]=true;
        for(auto u:arr[v]){
            if(!vis[u]){if(detectundir(u,vis,path)) return true;}
            else {
                if(path[u]) return true;
            }
        }
        path[v]=false;
        return false;
    }
    bool detectcycviabfs(int u){
        vector<bool>vis(V,false);
        queue<pair<int,int>>q;
        int i=0;
        q.push({u,-1});
        while(q.size()>0){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i:arr[x]){
                if(!vis[i]) {
                    q.push({i,x});
                    vis[i]=true;
                }
                else if(i!=y) return true;
            }
        }
    }
    void topsort(int u,stack<int>&s,vector<bool> &vis){
        vis[u]=true;
        for(int i:arr[u]){
            if(!vis[i]){
                topsort(i,s,vis);
            }
        }
        s.push(u);
    }
    void sort(){
        vector<bool>vis(V,false);
        stack<int>s;
        for(int i=0;i<arr.size();i++){
            if(!vis[i]) topsort(i,s,vis);
        }
        while(s.size()>0){
            cout<<s.top();
            s.pop();
        }
    }
    void kahn(vector<vector<int>>&grid){
        vector<int>Ans;
        vector<int>indegree(0,grid.size());
        for(int i=0;i<grid.size();i++){
            for(auto x:i){
                indegree[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<grid.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int z=q.front();
            Answer.push_back(z);
            q.pop();
            for(auto i:z){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push_back(i);
                }
            }
        }
    }
};

int main(){
Graph g(5);
g.addEdges(0,1);
g.addEdges(1,2);
g.addEdges(1,3);
g.addEdges(2,4);
g.addEdges(2,3);
g.addEdges(4,3);

g.print();
g.bfs();
cout<<endl;
g.dfs();
cout<<endl;
cout<<g.detect1();
cout<<endl;
cout<<g.detectcycviabfs(0)<<endl;
g.sort();
}