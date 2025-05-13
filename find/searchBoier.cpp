#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

void badCharf(const string& pattern, vector<int>& badChar) {
    int size = pattern.size();
    // Заполняем таблицу последними вхождениями символов в шаблоне
    for (int i = 0; i < size; i++) {
        badChar[(int)pattern[i]] = i;
    }
}


int Search(const ststring& text, const string& pattern) {
    int m = pattern.size();
    int n = text.size();
    int count = 0;
    
    
    
    // Создаем таблицу плохих символов
    vector<int> badChar(256, -1);
    badCharf(pattern, badChar);
    
    int s = 0;
    
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }
        
        if (j < 0) {
            count ++;
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } else {

            s += max(1, j - badChar[text[s + j]]);
        }
    }
    return count;
}

int main() {
    string text = "212321321";
    string pattern = "2222";
    
    int ans = Search(text, pattern);
    std::cout << ans << std::endl;
    
    return 0;
}
