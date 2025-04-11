#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <vector>


std::vector<int> zfunc(const std::string& s){
    int n = s.size();
    std::vector<int> z(n,0);
    int l = -1; int r = -1;
    for (int i = 1; i < n; ++i){
        if (l <= i && i <= r){
            z[i] = std::min(z[i-l], r-i+1);
        }
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]){
            ++z[i];
        }
        if (i + z[i] - 1 > r){
            l = i; r = i + z[i] - 1;
        }
    }
    for (int i = 0; i < n; i++){
        std::cout << z[i] << " ";
    }
    std::cout << std::endl;
    return z;
}
int findInStr(const std::string& p, const std::string& s){
    std::string concat;
    concat.reserve(p.size() + s.size() + 1);
    concat = p + "#" + s;
    std::vector<int> z = zfunc(concat);
    int k = 0;
    size_t len = p.size();
    size_t n = concat.size();
    for (int i = 1; i < n; i++){
        if (z[i] == len){ k++; }
    }
    return k;
    
    
}

int main() {
	std::string p = "Hello";
	std::string s = "Hel3lodff dffsHellof Hello HelaaaHelloaaHeHellolloaa";
	std::cout << findInStr(p,s);
    
    
    return 0;
}
