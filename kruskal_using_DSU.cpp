
//Problem Link:- https://www.spoj.com/problems/MST/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class DSU {
    int *parent;
    int *rank;
public:
    DSU(int V) {
        parent = new int[V];
        rank = new int[V];
        
        for(int i=0;i<V;i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find Fuction with Path Compresion
    int find(int i) {
        if (parent[i] == -1) { return i;}
        return parent[i] = find(parent[i]);
    }

    // Union Funtion by Rank
    void union_set(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        
        if (s1 != s2) {
            if(rank[s1]<rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph {
    vector<vector<int>> edgelist;
    int V;
public:
    Graph(int V) {
        this->V = V;
    }

    void add_edge(int x,int y, int w) {
        //  maintaining edge on the basis of weight which help in sorting.
        edgelist.push_back({w,x,y});
    }

    //Greedy Algorithm
    int kruskal_mst() {
        //Step 1>  Sort all edges on the basic of weight
        sort(edgelist.begin(), edgelist.end());

        DSU s(V);
        int ans = 0;
        for(auto edge: edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            //Step 2> Take A egde in MST if it doesnot form a cycle.
            if(s.find(x) != s.find(y)) {
                s.union_set(x,y);
                ans += w;
            }
        }
        return ans;
    }
};

int main() {
    // Graph g(4);
    // g.add_edge(0,1,1);
    // g.add_edge(1,3,3);
    // g.add_edge(3,2,4);
    // g.add_edge(2,0,2);
    // g.add_edge(0,3,3);
    // g.add_edge(1,2,2);

    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        g.add_edge(x-1,y-1,z);
    }
    cout<<g.kruskal_mst();
    return 0;
}
