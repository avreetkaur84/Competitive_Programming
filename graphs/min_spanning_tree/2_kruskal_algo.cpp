#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    1. Algo starts with having all the nodes individually. No node is connected to another node.
    2. Then, edges are sorted in ascending order according to their weights.
    3. Edges array is traversed and it performs:
        1. If two nodes are not connected by any path, then those two nodes are connected by that edge.
            i) We perform the union operation to connect the two nodes.
            ii) We check if two nodes are connected or not through find operation.
        2. Edge weight is added and that particular edge is added to the result array.
        3. If two nodes were already connected then that edge is skipped.
*/

/*
    For Input :
7
7
0 1 3
1 3 3
1 5 10
2 4 6
2 6 9
3 6 8
4 5 6
Your Code's output is:
45
It's Correct output is:
35
*/

void outArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

void outArr2d(vector<vector<int>> arr) {
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[i].size(); j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

class Solution
{
public:
    // find op
    int find(int x, vector<int> &parent)
    {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x], parent);
    }

    void union_set(int u, int v, vector<int> &parent, vector<int> &size)
    {
        int u_par = find(u, parent);
        int v_par = find(v, parent);

        if (size[u_par] < size[v_par])
            swap(u_par, v_par);
        parent[v_par] = u_par;
        size[u_par] += size[v_par];
    }

    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        int sum = 0;
        // sort the edges
        sort(edges.begin(), edges.end(), [](vector<int> a, vector<int> b) { 
            return a[2] < b[2]; 
        });

        // for(int i=0; i<edges.size(); i++) {
        //     cout<<edges[i][2]<<"  ";
        // }
        // cout<<"\n";

        // provide parent to each node
        vector<int> parent(V);
        vector<int> size(V);
        vector<vector<int>> res;

        // make_set operation
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }

        // traverse the egdes
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            int u_par = find(u, parent);
            int v_par = find(v, parent);
            if(u_par == v_par) continue;

            // not connected. Perform union
            union_set(u, v, parent, size);
            res.push_back({u, v, w});
            sum += w;
        }

        // outArr(parent);
        outArr2d(res);
        return sum;
    }
};

int main() {
    int V=7; 
    vector<vector<int>> edges = {{0,1,3}, {1,3,3}, {1,5,10}, {2,4,6}, {2,6,9}, {3,6,8}, {4,5,6}};
    Solution obj;
    cout<<obj.kruskalsMST(V, edges)<<" ";
}