// accepted
#include <iostream>
#include <map>
using namespace std;

map<string, string> parent;
map<string, int> ranks;
map<string, int> count; // count the disjoint set size

void makeSet(string x) {
    if (parent.find(x) == parent.end()) {
        parent[x] = x;
        ranks[x] = 0;
        count[x] = 1;   // count the disjoint set size
    }
}

string find(string x) {
    if (parent[x] == x) return x;
    // include path compression
    return parent[x] = find(parent[x]);
}

void unionSet(string x, string y) {
    // find x and y 's root
    string px = find(x);
    string py = find(y);

    if (px == py) return;   // already in the same set

    if (ranks[px] > ranks[py]) {
        parent[py] = px;    // make px as the root
        count[px] += count[py];
    } else {
        parent[px] = py;
        if (ranks[px] == ranks[py]) {
            ranks[py]++;
        }
        count[py] += count[px];
    }
}

int main() {
    int cases;
    cin >> cases;   // number of test cases
    while (cases--) {
        int n;  // number of friends
        cin >> n;

        // reset in every test case
        parent.clear();
        ranks.clear();
        count.clear();

        for (int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;
            makeSet(a);
            makeSet(b);
            unionSet(a, b);

            cout << count[find(a)] << endl;
        }
    }
    return 0;
}