#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <memory>
using namespace std;

vector<size_t> split(const string &str);
int do_color_DFS(vector<vector<shared_ptr<pair<size_t, int>>>> &adj, shared_ptr<pair<size_t, int>> &node, vector<size_t> &lineage);
int color_DFS(vector<vector<shared_ptr<pair<size_t, int>>>> &adj, vector<shared_ptr<pair<size_t, int>>> &verts);


int main() {
    // Parsing input:
    string raw_inp;
    getline(cin, raw_inp);
    vector<size_t> split_inp = split(raw_inp);
    const size_t num_nodes = split_inp[0];
    const size_t num_edges = split_inp[1];
    // Initialize verts and adjacency list:
    vector<shared_ptr<pair<size_t, int>>> vertices(num_nodes);
    vector<vector<shared_ptr<pair<size_t, int>>>> adj_list(num_edges);
    // Shared ptrs for all verts:
    for (size_t i = 1; i < num_nodes + 1; ++i){
        shared_ptr<pair<size_t, int>> insert(new pair<size_t, int>(i, 0));
        vertices[i - 1] = insert;
    }
    // Form Adj List from verts:
    for (size_t i = 0; i < num_edges; ++i){
        getline(cin, raw_inp);
        split_inp = split(raw_inp);
        adj_list[split_inp[0] - 1].push_back(vertices[split_inp[1] - 1]);
    }
    if (!color_DFS(adj_list, vertices)) cout << '0';
    

    return 0;
}


vector<size_t> split(const string &str) {
    size_t space = str.find(" ");
    if (space == string::npos) return vector<size_t>();
    string s1 = str.substr(0, space);
    string s2 = str.substr(space, str.length() - 1);
    vector<size_t> split_ints(2);
    split_ints[0] = stoull(s1);
    split_ints[1] = stoull(s2);
    return split_ints;
}

int color_DFS(vector<vector<shared_ptr<pair<size_t, int>>>> &adj, vector<shared_ptr<pair<size_t, int>>> &verts) {
    for (auto i = verts.begin(); i != verts.end(); ++i){
        vector<size_t> lineage;
        // If 'color' is 'white'
        if ((*i)->second == 0) {
            do_color_DFS(adj, *i, lineage);
            if (!lineage.empty()) {
                for (size_t j = (lineage.size() - 1); j >= 0; --j) cout << lineage[j] << ' ';
                return 1;
            }
        }
    }
    return 0;
}

int do_color_DFS(vector<vector<shared_ptr<pair<size_t, int>>>> &adj, shared_ptr<pair<size_t, int>> &node, vector<size_t> &lineage) {
    // Color node grey:
    node->second = 1;
    for (auto i = adj[node->first - 1].begin(); i != adj[node->first - 1].end(); ++i){
        if ((*i)->second == 0) {
            if (do_color_DFS(adj, *i, lineage)) {
                lineage.push_back(node->first);
                return 1;
            }
        }
        if ((*i)->second == 1) {
            cout << '1' << '\n';
            lineage.push_back(node->first);
            return 1;
        }
    }
    node->second = 2;
    return 0;
}
