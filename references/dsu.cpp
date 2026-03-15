// ============================================================
//  DSU (Disjoint Set Union) / Union-Find  —  CP Reference
// ============================================================
//
//  WHAT IT DOES:
//    Tracks N elements split into groups.
//    Two operations, both nearly O(1):
//      - find(x)      → who is the "root/boss" of x's group?
//      - union(x, y)  → merge the groups of x and y
//
//  WHEN TO USE:
//    - Is there a path between node x and y? (connectivity)
//    - Cycle detection in undirected graphs
//    - Kruskal's MST
//    - Grouping / clustering problems
//
// ============================================================

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int parent[MAXN];   // parent[i] = parent of i (root if parent[i] == i)
int rnk[MAXN];      // rank[i]   = approximate height of i's subtree
                    // (used to keep trees flat)

// Call this before using DSU.
// Sets every element as its own group.
void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;   // each node points to itself → is its own root
        rnk[i] = 0;
    }
}

// Returns the root of x's group.
// PATH COMPRESSION: on the way back up, point every node directly
// to the root → future find() calls on same nodes are O(1).
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);   // compress path
    return parent[x];
}

// Merges the groups of x and y.
// UNION BY RANK: attach the shorter tree under the taller one
// → keeps trees flat → find() stays fast.
// Returns false if already in the same group (useful for cycle detection).
bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;   // same group, nothing to do

    // attach smaller tree under larger
    if (rnk[x] < rnk[y]) swap(x, y);
    parent[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;   // same height → new tree is taller by 1

    return true;
}

// Returns true if x and y are in the same group.
bool connected(int x, int y) {
    return find(x) == find(y);
}

// ============================================================
//  BONUS: loop through all members of a group
//
//  DSU doesn't store members directly. Build a map on the fly:
//
//    map<int, vector<int>> groups;
//    for (int i = 0; i < n; i++)
//        groups[find(i)].push_back(i);
//
//    for (auto& [root, members] : groups) {
//        // members = all elements in this group
//    }
//
// ============================================================

// ============================================================
//  EXAMPLE PROBLEMS
// ============================================================

// --- 1. Cycle detection ---
// An undirected graph has a cycle if unite() returns false
// (meaning both nodes were already in the same group).
//
//    for (auto [u, v] : edges)
//        if (!unite(u, v))
//            cout << "Cycle found!\n";

// --- 2. Kruskal's MST ---
// Sort edges by weight, greedily add if they connect two
// different components.
//
//    sort(edges.begin(), edges.end());  // sort by weight
//    for (auto [w, u, v] : edges)
//        if (unite(u, v))
//            mst_cost += w;

// --- 3. Count connected components ---
//
//    for (auto [u, v] : edges) unite(u, v);
//
//    set<int> roots;
//    for (int i = 0; i < n; i++) roots.insert(find(i));
//    cout << roots.size() << " components\n";

// ============================================================

int main() {
    int n = 6;
    init(n);

    unite(0, 1);
    unite(1, 2);   // now 0,1,2 are one group
    unite(3, 4);   // now 3,4 are one group
                   // 5 is alone

    cout << connected(0, 2) << "\n";   // 1 (yes)
    cout << connected(0, 3) << "\n";   // 0 (no)
    cout << connected(3, 4) << "\n";   // 1 (yes)

    // count components
    set<int> roots;
    for (int i = 0; i < n; i++) roots.insert(find(i));
    cout << roots.size() << " components\n";   // 3

    return 0;
}