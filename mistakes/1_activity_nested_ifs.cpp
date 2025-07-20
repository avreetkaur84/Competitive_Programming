/*
⚔️ Activity Title: “The Battle of the Guards”
🧠 Problem Statement: You are the chief of security at a magical gate. Every person who wants to enter the castle must pass three guards in a row.

Each guard checks for a different rule:
Guard 1: Person must be 18 or older
Guard 2: Person must have a valid ID
Guard 3: Person must not be on the blacklist
Only if all three approve, the person can enter. Otherwise, they’re denied at the point of failure.

Your task:
Implement a function canEnterCastle(person) that returns:
"Approved" if all checks pass
The name of the guard who rejects the person, if they fail any check.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Person {
    int age;
    bool hasID;
    bool blacklisted;
};

string canEnterCastle(Person p) {
    if(p.age<18) return "Guard 1";
    if(!p.hasID) return "Guard 2";
    if(!p.blacklisted) return "Guard 3";
    return "Approved";
}

int main() {
    Person a = {20, true, false};  // → "Approved"
    Person b = {17, true, false};  // → "Guard 1"
    Person c = {20, false, false}; // → "Guard 2"
    Person d = {22, true, true};   // → "Guard 3"
    
    cout<<canEnterCastle(a)<<endl;
    cout<<canEnterCastle(b)<<endl;
    cout<<canEnterCastle(c)<<endl;
    cout<<canEnterCastle(d)<<endl;
}