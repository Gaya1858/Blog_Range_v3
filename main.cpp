#include <iostream>

#include <vector>
#include <range/v3/all.hpp>

#include "data_processing.h"

int main() {

    std::vector<std::vector<std::string>> cardData = LoadCsv("/Users/terra/Desktop/Fall2023/CSE491/Blog/Blog_Range_v3/swedish_insurance.csv");

    std::vector<std::pair<double, double>> data = DoubleData(cardData);
    Descriptivestats(data);
    SortData(data);

    // using foreach and filter and print all elements in the venctor.
    ranges::for_each(
            data | ranges::views::filter([](const auto& card) { return card.first < 10.0 && card.second < 90.0; }),
            [](const auto& card) {
                std::cout << "X: " << card.first << ", Y: " << card.second << std::endl;
            });

    /// finds max element based on first value
    auto maxElement = ranges::max_element(data, [](const std::pair<double, double>& a, const std::pair<double, double>& b){
        return a.first < b.first;
    });
    std::cout<< "Max 0f x: "<<maxElement->first << " | "<< "Max 0f Y: "<< maxElement->second << std::endl;

    // Aggregation: Calculate the sum of all first and second values
    double sumFirst = ranges::accumulate(data | ranges::views::transform([](const std::pair<double, double>& pair) {
        return pair.first;
    }), 0.0);

    std::cout << "Sum of X: " << sumFirst << std::endl;

    // Filtering: Filter data where the first value is greater than 3.0
    auto filteredData = data | ranges::views::filter([](const std::pair<double, double>& pair) {
        return pair.first > 3.0;
    });

    // Mapping: Square the first and second values
    auto squaredData = data | ranges::views::transform([](const std::pair<double, double>& pair) {
        return std::make_pair(pair.first * pair.first, pair.second * pair.second);
    });

    // Grouping: Group data by the first value
    auto groupedData = data | ranges::views::group_by([](const std::pair<double, double>& a, const std::pair<double, double>& b) {
        return a.first == b.first;
    });

    // Sorting: Sort data based on the second value in descending order
    data |= ranges::action::sort([](const std::pair<double, double>& a, const std::pair<double, double>& b) {
        return a.second > b.second;
    });

    // Searching: Find the first element where the second value is equal to 6.0
    auto foundElement = ranges::find(data, std::make_pair(5.0, 6.0));


    // Joining: Concatenate two copies of the data into a single range
    auto concatenatedData = ranges::views::concat(data, data);

    // Output the results
    std::cout << "Filtered Data:" << std::endl;
    for (const auto& pair : filteredData) {
        std::cout << "First: " << pair.first << ", Second: " << pair.second << std::endl;
    }

    std::cout << "Squared Data:" << std::endl;
    for (const auto& pair : squaredData) {
        std::cout << "First Squared: " << pair.first << ", Second Squared: " << pair.second << std::endl;
    }

    std::cout << "Grouped Data:" << std::endl;
    for (const auto& group : groupedData) {
        std::cout << "Group Key: " << group.front().first << std::endl;
        for (const auto& pair : group) {
            std::cout << "First: " << pair.first << ", Second: " << pair.second << std::endl;
        }
    }

    std::cout << "Sorted Data:" << std::endl;
    for (const auto& pair : data) {
        std::cout << "First: " << pair.first << ", Second: " << pair.second << std::endl;
    }

    if (foundElement != data.end()) {
        std::cout << "Found Element: First = " << foundElement->first << ", Second = " << foundElement->second << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }


    std::cout << "Concatenated Data:" << std::endl;
    for (const auto& pair : concatenatedData) {
        std::cout << "First: " << pair.first << ", Second: " << pair.second << std::endl;
    }

    return 0;
}
