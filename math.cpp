#include<iostream>
#include<vector>
#include<climits>
using namespace std;
string isprime(int n){
for(int i=2;i*i<n;i++)
{if(n%i==0){
    return "non prime";
}}
return "is prime";
}
int sieveoferatosthenes(int n){
    vector<bool>isprime(n+1,true);
    int count=0;
    if(n==2){
        return{};
    }
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=n;i++)
    {if(isprime[i]){
    count++;
    for(int j=i*i;j<=n;j+=i){
    isprime[j]=false;
    }
    }
}
return count;
}
bool isarmstrong(int n){
    int copy=n;int dig;
    int sumofcubes=0;
    while(n!=0){
        dig=n%10;
        n=n/10;
        sumofcubes+=dig*dig*dig;
    }
    return sumofcubes==copy;
}
int gcd(int a, int b){int gcd=1;
if (a==a && b==0) return a;
if(a==0 && b==b) return b;
if(a==b) return a; 
for(int i=1;i<=min(a,b);i++){
    if(a%i==0 && b%i==0)
    gcd=i;
}
return gcd;
}
int euclidean(int a , int b)
{// {if(a==a,b==0) return a; will check frst condition then discard the result and check the second condition
// if(a==0,b==b) return b;
// if(a==b) return a;
while(a>0 && b>0){
    if(a>b) a=a%b;
    else b=b%a;
}
if(a==a && b==0) return a;
if(a==0 && b==b) return b;
if(a==b) return a;
}
int gcdrec(int a , int b){
    if(b==0) return a;
    return gcdrec(b,a%b);
}
int lcm(int a,int b){
 return (a*b/gcdrec(a,b));
}
int reversenoprob7(int n){
    int ans=0;
    while(n!=0)
    {
    int lastdig = n%10;
    if(ans>INT_MAX/10 || ans<INT_MIN/10)
    return 0;
    ans=ans*10+lastdig;
    n/=10;
    }

    //or 
    class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x != 0) {
            int lastdig = x % 10;

            // overflow check
            if (ans > INT_MAX/10 || (ans == INT_MAX/10 && lastdig > 7))
                return 0;
            if (ans < INT_MIN/10 || (ans == INT_MIN/10 && lastdig < -8))
                return 0;

            ans = ans * 10 + lastdig;
            x /= 10;
        }

        return ans;
    }
};

return ans;
}
bool ispalindrome(int n){
if(n<0) return false;
int cpy=n;
int ans=0,lastdigit;
while(n!=0){                 // call reversenoprob7
    lastdigit=n%10;
    ans=ans*10+lastdigit;
    n/=10;
}
if(cpy==ans)
return true;
else 
return false;
}
int main(){
cout<<isprime(11)<<endl;
cout<<sieveoferatosthenes(11)<<endl;
cout<<isarmstrong(153)<<endl;
cout<<gcd(2,6)<<endl;
cout<<euclidean(2,6)<<endl;
cout<<gcdrec(9,3)<<endl;
cout<<gcdrec(3,9)<<endl;
cout<<lcm(4,8)<<endl;
cout<<reversenoprob7(1999999996)<<endl;
//cout<<reversenoprob7(1999999996)<<endl; this will give a random value on reversing as this will go of range after reversing 
cout<<ispalindrome(11)<<endl;
}