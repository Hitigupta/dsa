#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int aar(int err[2][2]){
    cout<<sizeof(err);
}
int arr(int aar[]){
    cout<<"hi";
    cout<<sizeof(aar);
}
string reversal(string hi){
    int n=hi.length();
    string ans="";
    reverse(hi.begin(),hi.end());
    for(int i=0;i<n;i++){
    string word="";
    while(i<n&&hi[i]!=' '){
        word+=hi[i];
        i++;
    }
    reverse(word.begin(),word.end());
    if(word.length()>0){
     ans+=" "+word;
    }
   }
   return ans.substr(1);
}
int compressprob443(vector<char> &hi){
int n=hi.size(),idx=0;
for(int i=0;i<n;i++){
    char ch=hi[i];
    int count=0;
    while(i<n && ch==hi[i])
    {count++ ;
    i++;}
    if(count==1){
        hi[idx]=ch;
        idx++;
    }
    else{
        hi[idx++]=ch;
        string str=to_string(count);
        for(char dig:str){
            hi[idx++]=dig;
        }
    }i--;
}
hi.resize(idx);
return idx;
}
int main(){
   string hi="hello world";
   string nw=reversal(hi);
   cout<<nw;
   cout<<hi.size()<<endl;
   string hello="aabbccc";
   vector<char>yo={'a','a','b','b','c','c','c'};
   cout<<compressprob443(yo)<<endl;
   for(char cj:yo){
    cout<<cj<<endl;
   }
   int now[]={1,2,3,4};
   arr(now);
   int a=9;
   int *p=&a;
   cout<<sizeof(p);
   int ew[2][2]={{1,2},{2,3}};
   aar((ew));
}