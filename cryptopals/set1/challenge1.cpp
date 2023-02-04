
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

 string to_hex_binary(map<char, string> hex_map, string inp) {\
    string buffer;
    for(const auto& ch : inp) {
        string hex_val = hex_map[ch];
        for (int i = 0; i < 4; i++)
            buffer.push_back(hex_val[i]);
    }
    return buffer;
 }

int main() {
    string inp = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    // string inp = "4ab";

    // for(const auto& elem : hex_map) {
    //     std::cout << elem.first << " " << elem.second << "\n";
    // }

    map<char, string> hex_map = init_hex_map();
    string buffer = to_hex_binary(hex_map, inp);


    cout << "INput: " << inp << '\n';
    // cout << buffer << '\n';

    map<string, char> to_base64;
    int val = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
        to_base64[int_to_nary(val++, 6)] = c;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        to_base64[int_to_nary(val++, 6)] = c;
    }
    for (char c = '0'; c <= '9'; c++) {
        to_base64[int_to_nary(val++, 6)] = c;
    }
    to_base64[int_to_nary(val++, 6)] = '+';
    to_base64[int_to_nary(val++, 6)] = '/';

    string base64_out;

    for (int i = 0; i < buffer.length(); i += 6) {
        char b64 = to_base64[buffer.substr(i, 6)];
        base64_out.push_back(b64);
    }

    cout << "Out: " << base64_out << '\n';
}