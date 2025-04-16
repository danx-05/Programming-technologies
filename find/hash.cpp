#include <iostream>
#include <vector>
#include <string>
#include <cmath>
const int p = 37;
const int r = 21314323;
int power(int p, int m){
    int result = 1;
    for (int i = 0; i < m; i ++){
        result *= p;
        result = result % r;
    }
    return result;
}
int getAsciiCode(char c) {
    return static_cast<int>(c);
}

int hash(const std::string& s, int st, int end) {
    int result = 0;
    for (int i = st; i <= end; ++i) {
        result = (result * p + getAsciiCode(s[i])) % r;
    }
    return result;
}
bool equalString(const std::string& str1, int st, const std::string& str2) {
    for (size_t i = 0; i < str2.length(); ++i) {
        if (str1[st + i] != str2[i]) {
            return false;
        }
    }
    return true;
}
std::vector<int> findThroughHash(const std::string& s, const std::string& w) {
    std::vector<int> answer;
    int n = s.size();
    int m = w.size();

    int hashS = hash(s, 0, m - 1);
    int hashW = hash(w, 0, m - 1);

    for (int i = 0; i <= n - m; i ++){
        if (hashS == hashW){
            if (equalString(s,i,w)){
                answer.push_back(i);
            }
        }
        hashS = (p * hashS - (power(p, m) * getAsciiCode(s[i]) % r) + getAsciiCode(s[i+m])) % r;

        std::cout << i << " "<<hashS << std::endl;
    }
    return answer;
}

int main() {
    std::string text = "asdasdsadasdas";
    std::string pattern = "sd";
    std::vector<int> positions = findThroughHash(text, pattern);

    for (int pos : positions) {
        std::cout << "Найдено в позиции: " << pos << std::endl;
    }

    return 0;
}
