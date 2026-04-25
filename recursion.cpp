#include<iostream>
#include<vector>
using namespace std;
int fact(int n){
    if(n==1) return 1;
    return n*fact(n-1);
}
int sum(int n){
    if(n==1) return 1;
    return n+sum(n-1);
}
int  fib(int n){
    if(n==0||n==1) return n;
    return fib(n-1)+fib(n-2);
}
bool issorted(int arr[],int n){
    if(n==0||n==1)  return true;
    return arr[n-1]>=arr[n-2] && issorted(arr,n-1);  
}
int binarysearch(vector<int>& arr,int tar,int st,int end)
{   if(st<=end){
    int mid=st+(end-st)/2;
    if(arr[mid]==tar) return mid;
    else if(arr[mid]<tar) return binarysearch(arr,tar,mid+1,end);
    else 
    return binarysearch(arr,tar,st,mid-1); 
}
return -1;}
void permutation(vector<vector<int>>ans,int i,vector<int>&nums){
    if(i==nums.size())
    {for(int j=0;j<nums.size();j++){
        cout<<nums[j];
    }
    cout<<endl;
    return;}
    for(int idx=i;idx<nums.size();idx++){
        swap(nums[i],nums[idx]);
        permutation(ans,i+1,nums);
        swap(nums[i],nums[idx]);
    }
}
void Subsets(vector<int>&arr,vector<int>ans,int i)
{
    if(arr.size()==i){
        for(int bal:ans){
            cout<<bal;}
            cout<<endl;
            return;
        }
    
    ans.push_back(arr[i]);
    Subsets(arr,ans,i+1);
    ans.pop_back();
    Subsets(arr,ans,i+1);
}
void Subsets2(vector<int>&arr,vector<int>ans,int i){
sort(arr.begin(),arr.end());
if(i==arr.size()){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cout<<endl;
    return;
}
ans.push_back(arr[i]);
Subsets2(arr,ans,i+1);
ans.pop_back();
int idx = i+1;
while(idx<arr.size() && arr[idx-1]==arr[idx]) idx++;
Subsets2(arr,ans,idx);
}
void issafe(vector<char> &board,int row,int col)
{}
void Nqueens(vector<string> &board,int row,int n){
if(row==n){
    for(int i=0;i<n;i++){
        board[][]
    }
 return;   
}
}
int main(){
    int arr[5]={1,2,3,6,5};
    vector<int>ans;
    cout<<issorted(arr,5)<<endl;
    vector<int>nee={1,2,3,5};
    cout<<binarysearch(nee,2,0,3);
    nee.pop_back();
    for(int val:nee){
        cout<<val;
    }
    cout<<endl;
    vector<vector<int>>anr;
    vector<int>p={1,2,3};
    Subsets(p,ans,0);
    permutation(anr,0,p);
    cout<<endl;
    vector<int>hi={1,2,2,2,3};
    Subsets2(hi,ans,0);
    
}