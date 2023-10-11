#include <iostream>
#include "data_processing.h"
#include <iostream>
#include <fstream>

int main() {
    std::ifstream infile("swedish_insurance.csv");

    if (infile.is_open()) {
        auto lines = ranges::istream_view<std::string>(infile);
        auto fields = ranges::views::all(lines) | ranges::views::transform([](auto const& line) {
            return ranges::views::split(line, ',');
        });

        for (auto const& field : fields) {
            // Process the field
            std::cout << field << std::endl;
        }
    } else {
        std::cout << "Failed" << std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
