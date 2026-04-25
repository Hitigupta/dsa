#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void reversestring(vector<char>&s){
int n=s.size();
int st=0,end=n-1;
while(st<end){
swap(s[st],s[end]);
st++; end--;
}
}
bool isalphanumeric(char ch){
    if((ch>='0'&&ch<='9')||(islower(ch)>='a'&&islower(ch)<='z'))
    return true;
    return false;
}
bool ispalindrome(string s){
  int st=0,end=s.length()-1;
 while (st<end)
 {if(!isalphanumeric(s[st])){
 st++; continue;}
 if(!isalphanumeric(s[end])){ end--; continue;}
 if(st!=end){
    return false;
 }st++; end--;}
 return true;
}
string removeoccurences1910(string s,string part){
    while(s.length()>0&&s.find(part)<s.length())
    {s.erase(s.find(part),part.length());}
    return s;
}
void permutation(string &s){
int pivot=-1,n=s.length();
for(int i=s.length()-2;i>=0;i--){
    if(s[i+1]<s[i]){
        pivot=i;
        break;
    }
}
if(pivot==-1){
    return reverse(s.begin(),s.end());
}
for(int i=n-1;i>pivot;i--){
    if(s[i]>s[pivot]){
        swap(s[i],s[pivot]);
        break;
    }
}
int st=pivot,end=n-1;
while(st<=end){
    swap(s[st],s[end]);
 st++; end--;
}
}
bool isfreqsame(int freq[],int freq2[]){
for(int i=0;i<26;i++)
{if(freq[i]!=freq2[i])
return false;}
return true;}
bool permutationinstringapproach1(string s1,string s2){
int freq[26]={0};
for(int i=0;i<s1.length();i++){
freq[s1[i]-'a']++;
}
int windSize=s1.length();
for(int i=0;i<s2.length();i++){
    int windidx=0,idx=i;
    int freq2[26]={0};
    while(windidx<windSize && idx<s2.length()){
    freq2[s2[idx]-'a']++;
    windidx++; idx++;}
    if(isfreqsame(freq,freq2)){
    return true;} 
}
return false;
}
bool anotherapproach(string s1,string s2){
    if(s2.size()<s1.size()) return false;
    vector<int>count1={26,0},count2={26,0};
    for(int i=0;i<s1.size();i++){
        count1[s1[i]-'a']++;
        count2[s2[i]-'a']++;
    }
    for(int i=0;i<=s2.length()-s1.length();i++){
    if(count1==count2) return true;
    if(i+s1.size()<s2.size()){
    count2[s2[i]-'a']--;
    count2[s2[i+s1.length()]-'a']++;
    }}
    return false;
}
int main(){
    string now="hello";
    cout<<now;
    now="new";
    cout<<now[7];
    cout<<now.at(7);
char str[]={'a','b','c','\0'};
int arr[]={1,2,3,4,5,6};
char me[100],see[11];
cout<<arr<<endl;
cout<<str<<endl;
// cout<<strlen(str)<<endl;
// //Runtime input
// cout<<"Enter string"<<endl;
// cin>>me; //if i enter "hello world" here ...it will not take all and just print hello
// cout<<me<<endl;
// char meow[]="hello world";
// cout<<meow<<endl;
// cin.ignore();
// cin.getline(see,11);
// cout<<see<<endl;
// cin.getline(see,11,'&');
// cout<<see<<endl;
// for(char val:see){ //as sees size is 100 so we get a lot of extra variables
//     cout<<val;
// }
//for counting length of string 
// int len=0;char mr[]="htiti";
// for(int i =0;mr[i]!='\0';i++){
//     len++;
// }
// // mr="new";  gives error
// cout<<len;
// vector<char>nemo={'a','b','c','d','e'};
// string str1="helo ";
// string str2="I am hiti ";
// string str3= str1+str2;
// cout<<str3<<endl;
// cout<<(str1==str2)<<endl;
// cout<<(str1>str2)<<endl;
// cout<<(str1<str2)<<endl;
// for(int i=0;i<str2.length();i++){ //for(char ch:str2)
//     cout<<str2[i]<<" ";
// }
// cout<<endl;
// reversestring(nemo);
// for(char ch:nemo){
//     cout<<ch;
// }
// string hi="oye";
// reverse(hi.begin(),hi.end());
// cout<<hi<<endl;
string st="madam";
string hi="ababaabab";
string part="ab";
cout<<ispalindrome(st)<<endl;
cout<<removeoccurences1910(hi,part)<<endl;
cout<<hi<<endl;
permutation(part);
cout<<part<<endl;
cout<<permutationinstringapproach1(part,hi);
cout<<anotherapproach(part,hi);
}