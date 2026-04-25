#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int printsubarrays(int arr[],int n){
   for(int start=0;start<5;start++)
   {for(int end=start;end<5;end++)
     {for(int i=start;i<=end;i++)
        {cout<<arr[i];
}cout<<" ";}
    cout<<endl;}
}
int maxSumfun(int arr[],int n){
int maxSum=INT_MIN;
for(int start=0;start<n;start++)
{int cursum=0;
for(int end=start;end<n;end++)
{cursum+=arr[end];
maxSum=max(cursum,maxSum);}

}cout<<maxSum;}
int maxsubarray(vector<int>&nums){
    int currSum=0,maxSum=INT_MIN;
    for(int val:nums){
        currSum+=val;
        maxSum=max(currSum,maxSum);
        if (currSum<0){
            currSum=0;
            //or Currsum=max(arr[i],currsum+arr[i])
        }
        
    }cout<<maxSum;
} 
int pairsum(vector<int>&nums,int target){
int n=nums.size();
for(int i=0;i<n;i++)
{ for(int j=i+1;j<n;j++)
{if(nums[i]+nums[j]==target)
  {cout<<i;
  cout<<j;
}
}}}
int pairsumoptimal(vector<int>&nums,int target){
    int n=nums.size();
    int i=0,j=n-1;
    while(i<j){
        int pairsum=nums[i]+nums[j];
        if(pairsum>target){
            j--;}
        else if(pairsum<target){
            i++;}
        else {
            cout<<i;
            cout<<j;
            break;
        }
    }
}
int majorityelement(vector<int>&nums){
    for(int val:nums){
        int flag=0;
        int n=nums.size();
        for(int el:nums){
            if(el==val)
            {flag++;}
        }if (flag>n/2)
        {return val;}
    }

}
int majorityelementmoreoptimal(vector<int>&nums){
    int n = nums.size();
    int freq=1,ans=nums[0];
sort(nums.begin(),nums.end());
for(int i=1;i<n;i++)
{if(nums[i]==nums[i-1])
freq++;
else 
{freq=1;ans=nums[i];}
if(freq>n/2)
return ans;
}
}
int mooresvotingalgo(vector<int>&nums){
    int freq=0,ans=0,n=nums.size();
    for(int i=0;i<n;i++)
    {if(freq==0)
    ans=nums[i];
    if (ans==nums[i])
    freq++;
    else 
    freq--;}
    return ans;
}
int mooresalgovariation(vector<int>&nums)
{   int freq=0,ans=0,n=nums.size(),count=0;
    for(int i=0;i<n;i++){
    if (freq==0)
    ans=nums[i];
    if(ans==nums[i])
    freq++;
    else freq--;  
}
    for(int i=0;i<n;i++)
    {if (nums[i]==ans)
    count++;}
    if(count>n/2)
        cout<<"majority element"<<ans;
    else
        cout<<"not found";
    }
double mypow(double x,int n)
{long binform = n;
double ans=1;
if (binform<0){
    x=1/x;
    binform=-binform;
}
while(binform>0)
{if (binform%2==1)
ans*=x;
x*=x;
binform/=2;}
return ans;}  
int stock(vector<int>&prices){
int n = prices.size();
int bestBuy=prices[0],maxProfit=0;
for(int i=1;i<n;i++)
{if (prices[i]>bestBuy)
maxProfit=max(maxProfit,prices[i]-bestBuy);
bestBuy=min(bestBuy,prices[i]);}
return maxProfit;
}

int main(){
    int ar[7]={3,-4,5,4,-1,7,-8};
    vector<int>a={1,1,1,2,2};
    printsubarrays(ar,5);
    // maxSumfun(ar,7);
    vector<int>arr={2,7,11,15};
    // maxsubarray(arr);
    //  pairsum(arr,13);
    //pairsumoptimal(arr,13);
    // cout<<majorityelementmoreoptimal(a);
    // cout<<mooresvotingalgo(a)<<endl;
    // mooresalgovariation(arr);
    // cout<<"hi";
    // cout<<mypow(0,3);
    cout<<stock(arr);}