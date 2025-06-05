// Question Link - https://www.naukri.com/code360/problems/minimum-window-subsequence_2181133?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
#define ll long long
using namespace std;

string minWindow(string S, string T)
{
	if(T.size()>S.size()) return "";
	int n=S.size(), m=T.size();
	int i=n-1, j=n-1, k=m-1;
	int minLen=INT_MAX, startIdx=-1;

	while(j>=0 && S[j]!=T[k]) j--;
	if(j<0) return "";

	while(i>=0 && j>=0) {
		if(S[i]==T[k]) k--;		

		if(k<0) {
			// cout<<minLen<<endl;
			if(minLen>=j-i+1) {
				minLen = j-i+1; startIdx=i;
			}

			k=m-1; j--;
			while(j>=0 && S[j]!=T[k]) j--;
			i=j+1;
		}

		i--;
	}

	string res = S.substr(startIdx, minLen);
	return res;
}

int main() {
    string s = "abcdebdde";
    string t = "bde";
    cout<<minWindow(s, t);
}