#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

void Combin(int tar, vector<int> &ans, int i, vector<int> &arr, vector<vector<int>> &combine, set<vector<int>> &s)
{
    int n = arr.size();
    if (tar == 0)
    {
        s.insert(ans);
        return;
    }
    if (i == n || tar < 0)
        return;
    ans.push_back(arr[i]);
    // Combin(tar-arr[i],ans,i+1,arr,combine); - -> unnecessary acc to chatgpt
    Combin(tar - arr[i], ans, i, arr, combine, s);
    ans.pop_back();
    Combin(tar, ans, i + 1, arr, combine, s);
}
set<vector<int>> combinesum(vector<int> &arr, int tar)
{
    vector<int> ans;
    vector<vector<int>> combine;
    set<vector<int>> s;
    Combin(tar, ans, 0, arr, combine, s);
    return s;
}


bool ispalindrome(string s)
{
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return s == s2;
}
void Palindrome(vector<vector<string>> &ans, vector<string> &partition, string s)
{
    int n = s.size();
    if (s.size() == 0)
    {
        ans.push_back(partition);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        string part = s.substr(0, i + 1);
        if (ispalindrome(part))
        {
            partition.push_back(part);
            string nextpart = s.substr(i + 1);
            Palindrome(ans, partition, nextpart);
            partition.pop_back();
        }
    }
}
vector<vector<string>> getallpalidromes(string s)
{
    vector<vector<string>> ans;
    vector<string> partition;
    Palindrome(ans, partition, s);
    return ans;
}


void merge(vector<int> &arr, int st, int end, int mid)
{
    int i = st, j = mid + 1;
    vector<int> storage;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            storage.push_back(arr[i]);
            i++;
        }
        else
        {
            storage.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        storage.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        storage.push_back(arr[j]);
        j++;
    }
    for (int idx = 0; idx < storage.size(); idx++)
    {
        arr[st + idx] = storage[idx];
    }
}
void mergesort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergesort(arr, st, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, st, end, mid);
    }
}


int partition(vector<int> &arr, int st, int end)
{
    int pivot = arr[end];
    int idx = st - 1;
    for (int j = st; j <= end; j++)
    {
        if (arr[j] < pivot)
        {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}
void quicksort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int pividx = partition(arr, st, end);
        quicksort(arr, st, pividx - 1);
        quicksort(arr, pividx + 1, end);
    }
}


int invers(vector<int> &arr, int st, int mid, int end)
{
    int invercount = 0;
    vector<int> temp;
    int i = st, j = mid + 1;
    while (i < mid + 1 && j <= end)
    {
        if (arr[i] > arr[j])
        {
            temp.push_back(arr[j]);
            invercount += mid + 1 - i;
            j++;
        }
        else{
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx=0;idx<temp.size();idx++){
        arr[st+idx]=temp[idx];
    }
    return invercount;
}
int count(vector<int> &arr, int st, int end)
{
    int inversion = 0;
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        int leftinver = count(arr, st, mid);
        int rightinver = count(arr, mid+1, end);
        int inver = invers(arr, st, mid, end);
        inversion = leftinver + rightinver + inver;
   }
    return inversion;
}


bool isvalid (vector<vector<int>>&arr,int r,int c,int expval,int n){
    if(r<0||c<0||r>=n||c>=n) return false;
    if(arr[r][c]!=expval) return false;
    if(expval==n*n-1) return true;
    bool ans1=isvalid(arr,r-2,c+1,expval+1,n);
    bool ans2=isvalid(arr,r-1,c+2,expval+1,n);
    bool ans3=isvalid(arr,r-1,c-2,expval+1,n);
    bool ans4=isvalid(arr,r-2,c-1,expval+1,n);
    bool ans5=isvalid(arr,r+1,c+2,expval+1,n);
    bool ans6=isvalid(arr,r+2,c+1,expval+1,n);
    bool ans7=isvalid(arr,r+1,c-2,expval+1,n);
    bool ans8=isvalid(arr,r+2,c-1,expval+1,n);
    return (ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8);
}
bool knights(vector<vector<int>>&arr){
    isvalid(arr,0,0,0,arr.size());
}

    int main()
    {
        vector<vector<int>> hi;
        set<vector<int>> s;
        vector<int> ar = {2, 2, 3};
        s = combinesum(ar, 4);
        for (auto val : s)
        {
            for (auto v : val)
                cout << v << " ";
            cout << endl;
        }
        string si = "aba";
        vector<vector<string>> answer;
        answer = getallpalidromes(si);
        for (auto val : answer)
        {
            for (auto v : val)
            {
                cout << v << " ";
            }
            cout << endl;
        }
        vector<int> arr = {4, 2, 1, 6, 7};
        mergesort(arr, 0, arr.size() - 1);
        for (int val : arr)
        {
            cout << val << " ";
        }
        cout << endl;
        vector<int> yo = {8, 3, 5, 3, 5};
        quicksort(yo, 0, yo.size() - 1);
        for (int val : yo)
        {
            cout << val << " ";
        }cout<<endl;
        cout << INT_MIN << endl;
        cout << INT_MAX<<endl;
        vector<int>baby={3,2,1,6,7,8,9};
        int ns=baby.size();
        //Rechecking count inversion
        int invcount=0;
        for(int i=0;i<ns-1;i++){
         for(int j=i+1;j<ns;j++){
            if(baby[i]>baby[j])
            {invcount++;}
         }
        }
        cout<<invcount<<endl;
        int i=count(baby,0,baby.size()-1);
        cout<<i<<endl;

        vector<vector<int>>mee={{0,3,6},{5,8,7},{2,7,4}};
        cout<<knights(mee);
    }