#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <memory>
using namespace std;

vector<string> split(const string &str);
int do_color_DFS(vector<vector<shared_ptr<pair<long, int>>>> &adj, shared_ptr<pair<long, int>> &node);
void color_DFS(vector<vector<shared_ptr<pair<long, int>>>> &adj, vector<shared_ptr<pair<long, int>>> &verts);


int main() {
    // Parsing input:
    string raw_inp;
    cin >> raw_inp;
    vector<string> split_inp = split(raw_inp);
    const size_t num_nodes = stoul(split_inp[0]);
    const size_t num_edges = stoul(split_inp[1]);
    // Initialize verts and adjacency list:
    vector<shared_ptr<pair<long, int>>> vertices(num_nodes);
    vector<vector<shared_ptr<pair<long, int>>>> adj_list(num_edges);
    // Shared ptrs for all verts:
    for (long i = 1; i < num_nodes + 1; ++i){
        shared_ptr<pair<long, int>> insert;
        insert->first = i;
        insert->second = 0;
        vertices[i] = insert;
    }
    // Form Adj List from verts:
    for (size_t i = 0; i < num_edges; i++){
        cin >> raw_inp;
        split_inp = split(raw_inp);
        adj_list[stoul(split_inp[0])].push_back(vertices[stoul(split_inp[1])]);
    }

    

    return 0;
}


vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

void color_DFS(vector<vector<shared_ptr<pair<long, int>>>> &adj, vector<shared_ptr<pair<long, int>>> &verts) {
    for (auto i = verts.begin(); i != verts.end(); ++i){
        // If 'color' is 'white'
        if ((*i)->second == 0) do_color_DFS()
    }
}

int do_color_DFS(vector<vector<shared_ptr<pair<long, int>>>> &adj, shared_ptr<pair<long, int>> &node) {
    // Color node grey:
    node->second = 1;
    for (auto i = adj[node->first].begin(); i != adj[node->first].end(); ++i){
        if ((*i)->second == 0) do_color_DFS();
        if ((*i)->second == 1) return;
    }
    node->second = 2;
    return 0;
}
