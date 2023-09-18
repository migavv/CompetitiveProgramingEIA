//
// Created by migav on 3/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

class TrieNode {

public:
    TrieNode * children[26] {nullptr};
    // A flag that marks if the word ends on this particular node.
    bool end_of_word;
    // Character stored in this node
    char letter;
    TrieNode() {
        end_of_word = false;
        letter = '\0';
    }
};

class Trie {
public:
    TrieNode root;
    void InsertP (string str) {
        TrieNode * current = &root;
        for (size_t i = 0; i < str.size(); i++) {
            if (current->children[str.at(i)-'a'] == NULL) {
                current->children[str.at(i)-'a'] = new TrieNode;
                current->children[str.at(i)-'a']->letter = str.at(i);
            }
            current = current->children[str.at(i)-'a'];
        }
        current->end_of_word = true;
    }
    void InsertS (string str) {
        TrieNode * current = &root;
        for (int i = (int)str.length() - 1; i >= 0; --i) {
            if (current->children[str.at(i)-'a'] == nullptr) {
                current->children[str.at(i)-'a'] = new TrieNode;
                current->children[str.at(i)-'a']->letter = str.at(i);
            }
            current = current->children[str.at(i)-'a'];
        }
        current->end_of_word = true;
    }

    TrieNode * Search (string str) {
        TrieNode * current = &root;
        for (size_t i = 0; i < str.size(); i++) {
            if (current->children[str.at(i)-'a']) {
                current = current->children[str.at(i)-'a'];
            } else {
                current = nullptr;
                break;
            }
        }
        return current;
    }
};

class Pids {
public:
    Trie pre, suf;
};

int main() {
    int q, t;
    bool rev;
    string name;
    Pids p1, p2;
    cin >> q;
    while(q--) {
        cin >> t;
        switch(t) {
            case 1:
                cin >> name;
                if(rev) {
                    p1.pre.InsertP(name);
                    p1.suf.InsertS(name);
                }
                else {
                    p2.pre.InsertP(name);
                    p2.suf.InsertS(name);
                }
                break;
            case 2:
                cin >> name;
                TrieNode *curr;
                if(rev) {
                    curr = p1.pre.Search(name);
                    if(curr == nullptr)
                        curr = p2.suf.Search(name);
                }
                else {
                    curr = p2.pre.Search(name);
                    if(curr == nullptr)
                        curr = p1.suf.Search(name);
                }
                if(curr != nullptr)
                    cout << 1;
                else cout << 0;
                cout << endl;
                break;
            case 3:
                rev = !rev;
                break;
        }
    }
}