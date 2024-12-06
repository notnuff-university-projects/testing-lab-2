#include "parser.h"

#include <stdexcept>

namespace parser {
    std::vector<char> Parse(const std::string& input) {
        std::vector<char> result;

        for(int i = 0; i < input.size(); i++) {
            if( input[i] == ' ' ) continue;
            if( input[i] == '\n' && i==input.size() - 1 ) continue;


            result.push_back(input[i]);

            if(auto nextI = i + 1; nextI < input.size() && input[nextI] != ' ' ) {
                throw std::runtime_error("Wrong format");
            }
        }

        return result;
    }
}
