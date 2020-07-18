#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

size_t num_nodes;
size_t num_edges;
size_t pre;
long long beg = -1;

vector<size_t> colors;
vector<vector<size_t>> adj_list;
vector<size_t> parents;


vector<size_t> split(const string &str);
void do_color_DFS(const size_t &node);
void color_DFS(const size_t &nodes);


int main() {
    // Parsing input:
    string raw_inp;
    getline(cin, raw_inp);
    vector<size_t> split_inp = split(raw_inp);

    num_nodes = split_inp[0];
    num_edges = split_inp[1];


    // Initialize adjacency list:
    colors = vector<size_t>(num_nodes, 0);
    adj_list = vector<vector<size_t>>(num_nodes);
    parents = vector<size_t>(num_nodes);

    // Form Adj List from verts:
    for (size_t i = 0; i < num_edges; ++i) {
        getline(cin, raw_inp);
        split_inp = split(raw_inp);
        adj_list[split_inp[0] - 1].push_back(split_inp[1] - 1);
    }
    color_DFS(num_nodes);
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

void color_DFS(const size_t &nodes) {
    for (size_t i = 0; i < nodes; ++i){
        // If 'color' is 'white'
        if (colors[i] == 0) {
            do_color_DFS(i);
            if (beg >= 0) {
                cout << '1' << '\n';
                size_t next = parents[beg];
                while (next != beg) {
                    cout << next + 1 << ' ';
                    next = parents[next];
                }
                cout << beg + 1 << ' ';
                return;
            }
        }
    }
    cout << '0';
}

void do_color_DFS(const size_t &node) {
    // Color node grey:
    colors[node] = 1;
    for (size_t i = 0; i < adj_list[node].size(); ++i){
        if (colors[adj_list[node][i]] == 0) {
            parents[node] = adj_list[node][i];
            do_color_DFS(adj_list[node][i]);
            if (beg >= 0) return;
        }
        if (colors[adj_list[node][i]] == 1) {
            parents[node] = adj_list[node][i];
            beg = node;
            return;
        }
    }
    colors[node] = 2;
}
