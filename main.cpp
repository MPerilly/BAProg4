#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> split(const string &str);

int main() {
    // Parsing input:
    string raw_inp;
    cin >> raw_inp;
    vector<string> split_inp = split(raw_inp);

    const size_t num_nodes = stoul(split_inp[0]);
    const size_t num_edges = stoul(split_inp[1]);



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