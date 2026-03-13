#include <bits/stdc++.h>
using namespace std;

/*
    
*/

vector<int> lps_Arr(string pat) {
    int n=pat.size();
    vector<int> arr(n, 0);

    for(int i=1; i<n; i++) {
        int j=arr[i-1];
        while(j>0 && pat[i]!=pat[j]) {
            j = arr[j-1];
        }
        if(pat[i]==pat[j]) j+=1;
        arr[i]=j;
    }
    return arr;
}

vector<int> match_idx(string s, string p) {
    vector<int> res;
    vector<int> lps = lps_Arr(p);

    int i=0, j=0, n=s.size(), m=p.size();
    while(i<n) {
        if(s[i]==s[j]) {
            i++; j++;
            if(j==m) {
                res.push_back(i-j);
                j=lps[j-1];
            }
        } else {
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }

    return res;
}

int main() {
    vector<int> res = match_idx("aabaacaadaabaaba", "aaba");
    for(auto it : res) cout<<it<<" ";
    return 0;
}