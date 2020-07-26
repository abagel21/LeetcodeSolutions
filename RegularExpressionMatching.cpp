#include <vector>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// although there are likely simpler solutions, having just finished the Algorithms I and II courses on coursera I wanted to implement a full nondeterministic finite automata capable of more regex processing operations
// https://leetcode.com/problems/regular-expression-matching/
class Solution {
public:
    int size;
    bool isMatch(string s, string p) {
        NFA* x = new NFA(p);
        return x->matches(s);
    }
    class Digraph {
        vector<vector<int>> adj;
    public:
        Digraph(int size) {
            adj.resize(size);
        }
        void addEdge(int v, int u) {
            adj[v].push_back(u);
        }
        vector<int> adjacent(int v) {
            return adj[v];
        }
    };
    class NFA {
        Digraph* g;
        string reg;
    public:
        NFA(string rx) {
            reg = rx;
            g = new Digraph(rx.length() + 1);
            for (int i = 0; i < rx.length(); i++) {
                if (rx[i] == '*') {
                    g->addEdge(i, i - 1);
                    g->addEdge(i, i + 1);
                    g->addEdge(i - 1, i);
                }
            }
        }
        bool matches(string txt) {
            vector<int> currStates;
            currStates.push_back(0);
            vector<bool> marked1;
            marked1.resize(reg.length() + 1);
            specializedDFS(0, marked1);
            for (int l = 0; l < reg.length() + 1; l++) {
                if (marked1[l]) currStates.push_back(l);

            }
            for (int i = 0; i < txt.length(); i++) {
                vector<int> reachableStates;
                // find all states reachable from these states (char matching)
                for (int j : currStates) {
                    if (j == reg.length()) {
                        if (i == txt.length()) {
                            reachableStates.push_back(j);
                            continue;
                        }
                    };
                    if (reg[j] == '.') {
                        reachableStates.push_back(j + 1);
                    }
                    else if (txt[i] == reg[j]) {
                        reachableStates.push_back(j + 1);
                    }
                }
                // add all states reachable from current states (epsilon dfs)
                currStates.clear();
                vector<bool> marked;
                marked.resize(reg.length() + 1);
                for (int k : reachableStates) {
                    specializedDFS(k, marked);
                }
                for (int l = 0; l < reg.length() + 1; l++) {
                    if (marked[l]) currStates.push_back(l);
                }
            }
            // check if end state was reached
            for (int v : currStates) {
                cout << "v " << v << "\n";
                if (v == reg.length()) return true;
            }
            return false;
        }
        void specializedDFS(int r, vector<bool>& marked) {
            marked[r] = true;
            // dfs with recursion
            for (int v : g->adjacent(r)) {
                if (!marked[v]) {
                    specializedDFS(v, marked);
                }
            }
        }
    };
};



