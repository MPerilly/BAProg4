#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

vector<string> split(const string &str);

int main() {
    // Parsing input:
    string raw_inp;
    cin >> raw_inp;
    vector<string> split_inp = split(raw_inp);
    const size_t num_nodes = stoul(split_inp[0]);
    const size_t num_edges = stoul(split_inp[1]);
    // Initialize adjacency list:
    vector<vector<pair<long, int>>> adj_list(num_nodes);

    for (size_t i = 0; i < num_edges; i++){
        cin >> raw_inp;
        split_inp = split(raw_inp);
        pair<long, int> node_a(stol(split_inp[0]), 0) ;
        pair<long, int> node_b(stol(split_inp[1]), 0) ;
        adj_list[node_a.first].push_back(node_b);
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