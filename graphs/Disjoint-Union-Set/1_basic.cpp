#include <bits/stdc++.h>
using namespace std;

/*
    My understanding of DSU so far -
        1. We have nodes in a graph and we want to see if there exists a path between x and y node, at that time, we use DSU.
        2. To implement DSU, we first perfom the:
            i) Make_Set(x) operation : here, we take each node and convert it into a set where that particular node is representative of its own set.
            ii) Union(x, y) operation : in this, we take the two nodes and make them part of single set and then one of the node becomes the representative of that set. We follow this for all the edges.
            iii) Find(x) operation: this operation returns the representative of the set in which node x is present. Now, if two nodes have same representative, then there exists a path between them.
        But here we are performing the union operation, now if we will perform the union operation for all the nodes, then full graph will be connected, so I guess, are we just connecting the nodes on basis of edges, as this will form the proper distinct sets.
        My guess is right, we only perform the union on basis of edges. If there is a edge between two nodes, we perform union between them.

        - Naive approach implementation is done, but naive approach will take O(N) time in worst case for find operation. Therefore, to optimise this, we are gonna implement the path compression technique, where each node parent is the main root node parent, like the final one, There won't be herarhies in between.

        - Another optimization is in the union set operation, where we make the larger tree the parent of smaller tree. I am gonna do this on basis of size of tree, but another technique, union by rank can also be used. For union by size, we also have to maintain another array size.
*/

// Naive Approach Implementation

const int N = 1e5 + 10; // max number of elements
int parent[N];          // parent array
int size[N];          // size array

// Make-set: every element is its own parent
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;   // for union by size operation
}

// Find-set: climb up until root (representative)
int naive_find_set(int v) {
    if (v == parent[v])
        return v;
    return naive_find_set(parent[v]); 
}

// path compression : optimised find_Set
int find_set(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

// Union-sets: connect two components
void naive_union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a; // just attach b's root to a
}

// union by size
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a!=b) {
        if(size[a]<size[b]) swap(a, b);   // ensure a is always greater in size
        parent[b] = a;
        size[a] += size[b];
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // Step 1: initialize each node as its own set
    for (int i = 1; i <= n; i++)
        make_set(i);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }

    cout << "\nRepresentatives of each node:\n";
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " -> Representative: " << find_set(i) << "\n";
    }

    return 0;
}