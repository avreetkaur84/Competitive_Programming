// Question Link - https://codeforces.com/contest/2121/problem/C

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    my intution -
    1. Take input of elemenst and in same step find the max element as we have to find minimum value of the max element in the array.
    2. Then track the occurences of the max element in the array and insert the index of that max value in set and update the row and column in whihc it is present. We using using row and column because, we will check at last only those rows and column which have the maxx number of maxx value occurence in them.
    3. Then, I will traverse row adn column of the one with maximum max value occurence and I will delete that index from set.
    4. If at last, set is empty, means all max value occurences were covered in that max row and coulmn, then we will return max-1 or else we will return maxx value

    Editorial intution-
    1. Cal the max element and total occurences of max element
    2. For each row and column count number of times max element occurs and store it in array
    3. Then, traverse all the rows adn columns possibilities and check if r[i]+c[j]==maxx, if yes, then we haev found one row and column that can decrease all max values by one. 
    4. But there is problem with r[i]+c[j] formula when r[i] and c[j] have counted the same element twice, means of a[i][j]==maxx, then we have to subtract 1, to abvoid subtracting double.
*/


void solve() {
    int n, m;  cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));
    int maxx=-1, cnt=0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j]; 
            if(arr[i][j]>maxx) {
                maxx=arr[i][j]; cnt=1;
            } else if(arr[i][j]==maxx) {
                cnt++;
            }
        }
    }
    
    vector<int> r(n); vector<int> c(m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j]==maxx) r[i]++;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j]==maxx) c[j]++;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if((r[i]+c[j]-(arr[i][j]==maxx))==cnt) {
                cout<<maxx-1<<endl; return;
            }
        }
    }

    cout<<maxx<<endl;
}



int main()
{
    int t;
    cin >> t;

    
    while(t--)
    {
        solve();
    }
}