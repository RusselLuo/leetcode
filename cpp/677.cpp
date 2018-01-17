#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class MapSum {
  public:
    /** Initialize your data structure here. */
    MapSum() {
        this->k = 0;
        this->val = 0;
    }

    void insert(string key, int val) {
        if (key.size() == 0) {
            this->val = val;
            return;
        }
        if (children.find(key[0]) == children.end()) {
            children[key[0]] = new MapSum();
        }
        children[key[0]]->insert(string(key.begin() + 1, key.end()), val);
    }

    int sum(string prefix) {
        if (prefix.size() == 0) {
            return getAllVal();
        }
        if (children.find(prefix[0]) == children.end())
            return 0;
        return children[prefix[0]]->sum(
            string(prefix.begin() + 1, prefix.end()));
    }
    int getAllVal() {
        if (children.size() == 0) {
            return val;
        }
        int subSum = 0;
        for (auto it : this->children) {
            cout << it.first << endl;
            subSum += (it.second)->getAllVal();
        }
        return subSum + val;
    }

  private:
    char k;
    int val;
    unordered_map<char, MapSum *> children;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

int main() {
    MapSum m;
    m.insert("a", 3);
    m.sum("ap");
    m.insert("b", 2);
    m.sum("a");
    cout << m.sum("ap") << endl;
}