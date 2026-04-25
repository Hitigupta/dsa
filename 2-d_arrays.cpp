#include<iostream>
#include<climits>
#include<vector>
using namespace std;
bool linearsearch(int mat[][3],int rows,int cols,int target){
  for(int i=0;i<rows;i++)
  {for(int j=0;j<cols;j++){
    if (mat[i][j]==target) return true;
  } }
  return false;
}
int maximumrowsum(int mat[][3],int rows,int cols){
  int maxsum=INT_MIN;
  for(int i=0;i<rows;i++){
    int rowsum=0;
    for(int j=0;j<cols;j++){
    rowsum+=mat[i][j];
    }
  maxsum=max(maxsum,rowsum);
  }return maxsum;
}
int maximumcolssum(int mat[][3],int rows,int cols){
  int maxsum=INT_MIN;
  for(int j=0;j<cols;j++){
    int colssum=0;
    for(int i=0;i<rows;i++){
     colssum+=mat[i][j];
    }maxsum=max(maxsum,colssum);
}return maxsum;
}
int diagonalsum(int mat[][3],int n){
  int diasum=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++){
      if (i==j){
        diasum+=mat[i][j];
      }
      else if(j==n-1-i){
        diasum+=mat[i][j];
      }
    }
  }return diasum;
}
int diagonalsumoptimised(int mat[][3],int n){
  int diasum=0;
  for(int i=0;i<n;i++){
       diasum+=mat[i][i];
       if(i!=n-i-1){
        diasum+=mat[i][n-i-1];
       }
     }
  return diasum;}
bool searchinrow(vector<vector<int>>&mat,int target,int midr){
  int n=mat[0].size();
  int st=0,end=n-1;
  while(st<=end){
    int mid=st+(end-st)/2;
    if(target==mat[midr][mid]) return true;
    else if(target>mat[midr][mid]) st=mid+1;
    else end=mid-1;
  }
  return false;
}
bool searchinmatrixprob75(vector<vector<int>> &mat,int x){
//BS on total no of rows
  int m=mat.size(),n=mat[0].size();
  int strow=0,endrow=m-1;
  while(strow<=endrow){
    int midrow=strow+(endrow-strow)/2;
    if(x>=mat[midrow][0] && x<=mat[midrow][n-1])
    return searchinrow(mat,x,midrow);
    else if (x>=mat[midrow][n-1]) strow=midrow+1;
    else endrow=midrow-1;
  }
  return false;
}
bool searchinmatrix2prob240(vector<vector<int>>&mat,int x){
  int n=mat[0].size(),m=mat.size();
  int str=0,endc=n-1;
  while(str<m && endc>=0){
    if(x==mat[str][endc]){
      return true;}
    else if(x<mat[str][endc]) endc--;
    else str++;
  }return false;
}
int main(){
  int mar[][3]={{1,2,3},{4,5,6},{7,8,9}};
    int matrix[4][3]={{1,3,5},{7,8,9},{9,0,8},{5,4,3}};  int rows=4,cols=3; 
    int mat[5][2]; int r=5; int c=2;
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        cin>>mat[i][j];
      }
    }
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        cout<<mat[i][j]<<" ";
      }cout<<endl;
    } cout<<endl;   
    for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
        cout<<matrix[i][j]<<" ";
      }cout<<endl;
    }
    vector<vector<int>>mki={{1,2,3},{4,5,6},{7,8,9}};
    cout<<linearsearch(matrix,4,3,5)<<endl;
    cout<<maximumrowsum(matrix,4,3)<<endl;
    cout<<maximumcolssum(matrix,4,3)<<endl;
    cout<<diagonalsum(mar,3)<<endl;
    cout<<diagonalsumoptimised(mar,3)<<endl;
    cout<<searchinmatrixprob75(mki,0)<<endl;
    cout<<searchinmatrix2prob240(mki,5)<<endl;
    int $a = 5;
    cout<< $a;
    
}