#include "tokenizer.hpp"
#include <sstream>

namespace fix {
    constexpr char soh_del = '\x01';

    std::string preprocess_delimeter(const std::string &input){
        std::string good_str = input;
        
        for(auto &ch : good_str){
            if(ch == '|') ch = soh_del;
        }
        return good_str;
    }

    std::vector<std::string> tokenize(const std::string &input){
        std::vector<std::string> tokens;
        std::size_t start = 0;

        while (start <= input.size()) {
            const std::size_t end = input.find(soh_del, start);
            if (end == std::string::npos) {
                if (start < input.size()) {
                    tokens.push_back(input.substr(start));
                }
                break;
            }
            if (end > start) {
                tokens.push_back(input.substr(start, end - start));
            }
            start = end + 1;
        }

        return tokens;
    }

}