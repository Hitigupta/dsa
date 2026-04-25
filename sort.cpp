#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void bubblesort(int arr[],int n){
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1])
      {swap(arr[j],arr[j+1]);}
    }
}
}
void searchsort(int arr[],int n){
 for(int i=0;i<n-1;i++) {
 int smallestidx=i;
  for(int j=i+1;j<n;j++){
   if(arr[j]<arr[smallestidx])
   {smallestidx=j;}}
   swap(arr[i],arr[smallestidx]); }
}
void insertionsort(int arr[],int n ){
for(int i=1;i<n;i++){
  int curr=arr[i];
  int prev=i-1;
  while(prev>=0 && arr[prev]>curr){
arr[prev+1]=arr[prev];
prev--;
  }
arr[prev+1]=curr;
}
}
void printarray(int arr[],int n ){
    for(int i=0;i<n;i++){
     cout<<arr[i];
    }
}
void sortcolorleetcode75(int arr[],int n){
  int count0=0,count1=0,count2=0;
  for(int i=0;i<n;i++)
  {if(arr[i]==0) count0++;
  else if(arr[i]==1) count1++;
  else count2++;}
  for(int j=0;j<count0;j++){
    cout<< 0 ;   //nums[j]=0
  }
  for(int k=0;k<count1;k++){
    cout<<1;     //nums[k]=1
  }
  for(int x=0;x<count2;x++)
  {
  cout<<2;        //nums[x]=2
  }
}
void sortcolor(int arr[],int n){
int low=0,mid=0,high=n-1;
while(mid<=high){
  if(arr[mid]==0)
  {swap(arr[low],arr[mid]);
    low++;
    mid++;
  }
  else if(arr[mid]==1)
  {mid++;}
  else 
  {swap(arr[high],arr[mid]);
  high--;}
}
}
void merge(vector<int>&nums1,vector<int>&nums2,int n,int m){
int i=n-1,j=m-1,idx=m+n-1;
while(i>=0 && j>=0){
if(nums1[i]>=nums2[j]){
nums1[idx]=nums1[i];
idx--; i--;
}
else{
  nums1[idx]=nums2[j];
  idx--; j--;
}
}
while(j>=0){
  nums1[idx--]=nums2[j--];
}
}
vector<int> nextpermutation(vector<int>&nums){
  int pivot=-1,n=nums.size();
  for(int i=n-2;i>=0;i--){
  if(nums[i+1]>nums[i]){
    pivot=i;
    break;
  }
  if(pivot==-1){
    reverse(nums.begin(),nums.end());
  }
  for(int i=n-1;i>pivot;i--)
  {if(nums[i]>nums[pivot])
  swap(nums[i],nums[pivot]);
  break;}
  i=pivot+1; int j=n-1;
  while(i<=j){
    swap(nums[i],nums[j]);
    i++;
    j--;
  }
  return nums;
}
}
int main(){
int arr[]={9,4,3,2,7,5,4};
int sort[]={0,1,0,1,1,2,0,2,0,2};
vector<int>apple={1,2,3,0,0,0};
vector<int>ban={2,5,6};
int m=3,n=3;
// bubblesort(arr,7);
// printarray(arr,7);
// searchsort(arr,7);
insertionsort(arr,7);
printarray(arr,7);
cout<<endl;
// sortcolorleetcode75(sort,10);
sortcolor(sort,10);
printarray(sort,10);
merge(apple,ban,m,n);
for(int val:apple)
{cout<<val;}
cout<<endl;
vector<int>hi=nextpermutation(ban);
for(int val:hi)
{cout<<val;}
cout<<endl;
}
