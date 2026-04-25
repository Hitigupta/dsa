#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int maxwaterleet11(vector<int> &nums){int maxwater=0;
int n=nums.size();
for(int i=0;i<n;i++)
{for(int j = i+1;j<n;j++)
{int width=j-i;
int height=nums[i];
int area= width*height;
maxwater=max(maxwater,area);
}}return maxwater;
}
int maxwateroptimal(vector<int>&nums){int maxwater=0;
int lp=0,rp=nums.size()-1;
while(lp<rp)
{int w=rp-lp;
int ht=min(nums[lp],nums[rp]);
int currwater=w*ht;
maxwater=max(maxwater,currwater);
nums[lp]<nums[rp]?lp++:rp--;
}return maxwater;}
vector<int> productwithoutself(vector<int>&nums){
int n= nums.size();
vector<int>ans(n,1);
for(int i =0 ; i<n;i++)
{for(int j=0;j<n;j++)                 //or it could be like product =1
    if(nums[i]!=nums[j])
    ans[i]*=nums[j];                   //product *=nums[j]
}return ans;}                          //ans[i]=product
vector<int>producttimeeff(vector<int>&nums)
{int n=nums.size();
vector<int>suffix(n,1),prefix(n,1),ans(n,1);
for(int i=1;i<n;i++)
{prefix[i]=prefix[i-1]*nums[i-1];}
for(int i=n-2;i>=0;i--)
{suffix[i]=suffix[i+1]*nums[i+1];}
for(int i=0;i<n;i++)
{ans[i]=prefix[i]*suffix[i];}
return ans;}
vector<int>productmostoptimal(vector<int>&nums){
int n= nums.size();
vector<int>ans(n,1);int prefix,suffix=1;
for(int i=1;i<n;i++)
ans[i]=ans[i-1]*nums[i-1];
for(int i=n-2;i>=0;i--)
{suffix*=nums[i+1];
ans[i]*=suffix;
}
return ans;}
int binarysearch(vector<int>&nums,int target){
    int n = nums.size(),mid;
    int st =0,last=n-1;
    while(st<=last){
        mid=st+(last-st)/2;
    if(target<nums[mid]){
        last=mid-1;}
    else if (target>nums[mid])
        {st=mid+1;}
        else return mid;
    }
return -1;
    }
int binaryrec(vector<int>&nums,int target,int start,int end){
   if(start<=end)
   {int mid=start+(end-start)/2;
    if(target<nums[mid])
   {return binaryrec(nums,target,start,mid-1);} 
    else if(target>nums[mid])
   {return binaryrec(nums,target,mid+1,end);}
   else return mid;
}return -1;}
int rotatedarray33prob(vector<int>&nums,int target){
int start =0,end=nums.size();
while(start<=end)
{int mid=start+(end-start)/2;
    if(nums[mid]==target) return mid;
    if(nums[start]<=nums[mid])       //left sorted
     {if(nums[start]<=target&&target<=nums[mid])
        {end=mid-1;}
    else start=mid+1;}
    else                             //right sorted
    {if(nums[mid]<=target<=nums[end])
     start=mid+1;
    else end=mid-1;}
    
}return -1;}
int peakmountaion852(vector<int>&nums){
int st=1,end=nums.size()-2;
while(st<=end){
    int mid=st+(end-st)/2;
    if(nums[mid-1]<nums[mid]&&nums[mid]>nums[mid+1])
    return mid;
    if(nums[mid-1]<nums[mid])
    st = mid+1;
    else end = mid-1;
}//return -1;
}
int singlelement540(vector<int>&nums){int n=nums.size();
    int start=0,end = nums.size()-1,mid=start+(end-start)/2;
    if(nums.size()==1) return nums[n];
    
    while(start<=end){
    if(mid==0&&nums[0]!=nums[1])return nums[mid];
    if(mid==n-1&&nums[n-1]!=nums[n])return nums[mid];

    if(nums[mid-1]!=nums[mid]&&nums[mid]!=nums[mid+1])
    return nums[mid];
    if(mid%2==0)
    {if(nums[mid]==nums[mid-1]) {end=mid-1;}
    else start=mid+1;}
    else
    {if(nums[mid]==nums[mid-1]) start=mid+1;
    else end=mid-1;}
    }
return -1;
}
bool isValid(vector<int>&nums,int maxAllocatedPages,int n,int m){
int students=1,pages=0;
for(int i=0;i<n;i++){    //O(n)
if(nums[i]>maxAllocatedPages) return false;
if(pages+nums[i]<=maxAllocatedPages)
{pages+=nums[i];}
else{
students++;
pages=nums[i];}
}return students>m?false:true;
}
int allocatebooks(vector<int>&nums,int n ,int m){
int sum=0,ans=-1;
if(m>n){
    return -1;
}
for(int i=0;i<n;i++){    //O(n) n->no of elements
sum+=nums[i];
}
int st=1,end=sum;   //Range of possible answers
while(st<=end){          //O(log N) N->range
    int mid=st+(end-st)/2;
    if(isValid(nums,mid,n,m)){
     ans=mid;
     end=mid-1;}
    else
    st=mid+1;
    }
}
bool ispossible(vector<int>&nums,int n,int m ,int mindistance){
    int cows=1,laststall=nums[0];
    for(int i=1;i<n;i++)
    {if(nums[i]-laststall>=mindistance)
     {cows++;
     laststall=nums[i];}
    if(cows==m)
    return true;
    }return false;
}
int aggressivecows(vector<int>&nums,int n,int m)
{sort(nums.begin(),nums.end());
int st=1,end=nums[n-1]-nums[0],ans=-1;
while(st<=end){
 int mid=st+(end-st)/2;
 if(ispossible(nums,n,m,mid))
 { ans=mid;
  st=mid+1;}
 else
end=mid-1;
}return ans;}
bool canbedone(vector<int>&nums,int n,int m,int maxtime)
{int painter=1,time=0;
for(int i=0;i<n;i++)
  {if(time+nums[i]<=maxtime)
   time=time+nums[i];
   else
   {time=nums[i];
   painter++;}
  }return painter>m?false:true;
}
int painterspartition(vector<int>&nums,int n,int m){
    int sum=0,ans=-1,maxvalue=INT_MIN;
    for(int i=0;i<n;i++){
       sum+=nums[i];
    maxvalue=max(maxvalue,nums[i]); }
    int st=maxvalue,end=sum;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(canbedone(nums,n,m,mid)){
        ans=mid;
        end=mid-1;
        }
        else
        st=mid+1;
    }return ans;}
int main(){
// vector<int>arr={1,8,5,4,6,7,9};
vector<int>nr={1,2,3,4,5,6,7};
vector<int>mountain={1,3,5,7,5,3,2};
vector<int>singlelement={1,1,3,3,4,5,5,6,6};
vector<int>books={15,17,20};
vector<int>cows={1,2,4,8,9};
vector<int>board={10,20,30,40};
// // cout<<maxwaterleet11(arr);
// // cout<<maxwateroptimal(arr);
// int n=arr.size();
// vector<int>newarr=productmostoptimal(nr);
// for(int i:newarr)
// {cout<<i<<" ";}
// int arri[5]={1,7,6,6,6};
// arri[0]=8;
// cout<<arri[0];
// cout<<binarysearch(nr,3);
// cout<<binaryrec(nr,3,0,3);
cout<<rotatedarray33prob(nr,3)<<endl;
//cout<<peakmountaion852(nr)<<endl;
cout<<peakmountaion852(mountain)<<endl;
cout<<singlelement540(singlelement)<<endl;
cout<<isValid<<endl;
int n=3,m=2;
int N=5,C=3;
int x=4,y=2;
cout<<allocatebooks(books,n,m)<<endl;
cout<<aggressivecows(cows,N,C)<<endl;
cout<<painterspartition(board,x,y)<<endl;
}