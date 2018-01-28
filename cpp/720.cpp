#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
class Node{
    public:
    unordered_map<char,Node*> t;
    bool insert(string s){
        if(t.find(s[0])==t.end()){
            if(s.size()==1){
                t[s[0]] = new Node();
                return true;
            }
            return false;
        }else{
            return t[s[0]]->insert(string(s.begin()+1,s.end()));
        }
    }
};
class Trie{
    public:
    string longest;
    Node *root;
    Trie(){
        root = new Node();
        longest = "";
    }
    void insert(string s){
        bool succ = root->insert(s);
        if(succ){
            if(s.size()>longest.size()){
                longest = s;
            }else if(s.size()==longest.size()){
                if(s<longest){
                    longest = s;
                }
            }
        }
    }
};



class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        Trie t;
        for(auto i:words){
            t.insert(i);
        }
        return t.longest;
    }
};