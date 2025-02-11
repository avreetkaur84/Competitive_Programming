// Question Link -

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string word;
    cin >> word;

    if ((word.length() == 2 && (word[1] == word[0])) || word.length() == 1)
    {
        cout << 1 << endl;
        return;
    }

    for (int i = 2; i < word.length(); i++)
    {
        if (word[i - 1] == word[i])
        {
            word[i - 1] = word[i - 2];
            word = word.substr(0, i) + word.substr(i + 1, word.length());
            i--;
            if (word[i - 1] == word[i]) {
                word = word.substr(0, i) + word.substr(i + 1, word.length());
            }
        }
    }

    // if (word.length() == 2 && (word[1] == word[0])) 
    // {
    //     cout << 1 << endl;
    //     return;
    // }

    cout << word.length() << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}