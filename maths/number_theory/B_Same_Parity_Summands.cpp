    // Question Link - https://codeforces.com/contest/1352/problem/B
     
    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;

    /*
        Poll :  What is more hateable - Maths or DSA :|, (for beginers)
    */
     
    void solve() {
        ll n, k;  cin>>n>>k;   
        if(n<k)  {
            cout<<"NO"<<endl; return;
        }
     
        if(n%2 == k%2) {
            cout<<"YES"<<endl;
            int first_num=n-(k-1);
            if(first_num<=0) {
                cout<<"NO"<<endl; return;
            }
            k--;
            cout<<first_num<<" ";
            while(k--) {
                cout<<1<<" ";
            }
            cout<<"\n";
            return;
        }
     
        if(!(n&1) && n>=2*k) {
            cout<<"YES"<<endl;
            int first_num=n-(2*(k-1));
            if(first_num<=0) {
                cout<<"NO"<<endl; return;
            }
            k--;
            cout<<first_num<<" ";
            while(k--) {
                cout<<2<<" ";
            }
            cout<<"\n";
            return;
        }

        cout<<"NO"<<endl;
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