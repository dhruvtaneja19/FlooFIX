#include "storage.hpp"
#include <sstream>
#include <unordered_map>

std::unordered_map<const int, std::string> fix_field_storage(const std::string &raw_str){
    std::unordered_map<const int, std::string> fields; // Declare the fields map
    std::stringstream ss(raw_str);
    std::string token;

    while(std::getline(ss, token, '\x01')){
        auto pos = token.find('=');
        if(pos == std::string::npos) continue;

        int tag = std::stoi(token.substr(0,pos));
        std::string value = token.substr(pos + 1);

        fields[tag] = value;
    }
    return fields;
}