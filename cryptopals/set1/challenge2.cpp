
#include <map>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

char* int_to_nary(int num, int n_bits) {
    char* val = new char[n_bits];
    int pos = n_bits - 1;
    while (pos >= 0) {
        val[pos--] = num % 2 == 0 ? '0' : '1';
        num /= 2;
    }
    return val;
}

 map<char, string> init_hex_map() {
    map<char, string> hex_map;
    int val = 0;
    for (char c = '0'; c <= '9'; c++) {
        hex_map[c] = int_to_nary(val++, 4);
    }
    for (char c = 'a'; c <= 'f'; c++) {
        hex_map[c] = int_to_nary(val++, 4);
    }
    return hex_map;
 }

 string to_hex_binary(map<char, string> hex_map, string inp) {
    string buffer;
    for(const auto& ch : inp) {
        string hex_val = hex_map[ch];
        for (int i = 0; i < 4; i++)
            buffer.push_back(hex_val[i]);
    }
    return buffer;
 }

 map<string, char> init_inv_hex_map() {
    map<string, char> inv_hex_map;
    int val = 0;
    for (char c = '0'; c <= '9'; c++) {
        inv_hex_map[int_to_nary(val++, 4)] = c;
    }
    for (char c = 'a'; c <= 'f'; c++) {
        inv_hex_map[int_to_nary(val++, 4)] = c;
    }
    return inv_hex_map;
 }

 int main() {
    string str_a = "1c0111001f010100061a024b53535009181c";
    string str_b = "686974207468652062756c6c277320657965";
    auto hex_map = init_hex_map();

    auto hex_buf_a = to_hex_binary(hex_map, str_a);
    auto hex_buf_b = to_hex_binary(hex_map, str_b);

    string xored;
    auto inv_hex_map = init_inv_hex_map();

    for (int i = 0; i < hex_buf_a.length(); i += 4) {
        int num_a_i = stoi(hex_buf_a.substr(i, 4), 0, 2);
        int num_b_i = stoi(hex_buf_b.substr(i, 4), 0, 2);
        int xor_val = num_a_i ^ num_b_i;

        xored.push_back(inv_hex_map[int_to_nary(xor_val, 4)]);
    }

    cout << "Xored hex: " << xored << "\n";

 }