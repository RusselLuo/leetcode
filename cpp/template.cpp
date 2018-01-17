#include <iostream>
using namespace std;
template <typename T, typename U> T add(T a, U b) { return a + b; }
//可以指定某些模板参数，其余等待编译器推导

template <typename T> void printMulti(const T & t) { cout << t << endl; }
//base case of recursion of template inferring.
template <typename T, typename... Args>
void printMulti(const T &t, const Args &... rest) {
    cout << t << endl;
    printMulti(rest...);
}
//recursion case: pick the first argument and recurse on the rest of the arguments

int main() {
    std::cout << add<int>(1, 2) << std::endl;
    printMulti(1, 2, 3, 4, 5);
}

// template <typename... types> class tuple {};

// template <typename head, typename... tail>
// class tuple<head, tail...> : private tuple<tail> {
//     head h;
// };
// template <> class tuple<> {
// };
