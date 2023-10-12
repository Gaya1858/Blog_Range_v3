//
// Created by Terra Byte on 10/11/23.
//

#include "data_processing.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <range/v3/all.hpp>
#include <string>

std::vector<std::vector<std::string>> LoadCsv(const std::string &filename) {
    std::vector<std::vector<std::string>> data;  // A vector to store the loaded card data

    // Open the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        // If the file couldn't be opened, display an error message and return an empty vector
        std::cerr << "Failed to open file: " << filename << std::endl;
        return data; // Return an empty vector
    }

    // Read lines from the file and split them into three columns
    std::string line; // A string to store each line read from the file
    while (std::getline(file, line)) { // Read lines one by one from the file
        std::vector<std::string> columns; // A vector to store the columns of each line

        // Split the line into parts using the ',' delimiter and transform them into strings
        auto parts = line | ranges::views::split(',') | ranges::views::transform([](auto &&token) {
            return ranges::to<std::string>(token);
        });

        // Iterate through the parts and add them to the columns vector
        for (const std::string &part: parts) {
            columns.push_back(part);
        }

        // Add the columns of the current line to the cardData vector
        data.push_back(columns);
    }

    // Return the vector containing the loaded card data
    return data;
}

std::vector<std::pair<double, double>> DoubleData(const std::vector<std::vector<std::string>>& cardData)
{
    std::vector<std::pair<double, double>> data;

    ranges::for_each(
            cardData | ranges::views::filter([](const auto& card) { return card.size() == 2; }),
            [&data](const auto& card) {
                try {
                    double one = std::stod(card[0]);
                    double two = std::stod(card[1]);
                    data.emplace_back(one, two);
                }
                catch (const std::invalid_argument& e) {
                    std::cerr << "Invalid argument: " << e.what() << std::endl;
                }

            });

    return data;
}

void Descriptivestats(const std::vector<std::pair<double, double>>& data)
{
    // Extract the first and second values from the pairs
    auto firstValues = data | ranges::view::transform([](const std::pair<double, double>& pair) { return pair.first; });
    auto secondValues = data | ranges::view::transform([](const std::pair<double, double>& pair) { return pair.second; });
    //Calculate the mean for the first and second values
    double meanFirst = ranges::accumulate(firstValues, 0.0) / data.size();
    double meanSecond = ranges::accumulate(secondValues, 0.0) / data.size();

    // Calculate the variance for the first and second values
    double varianceFirst = ranges::accumulate(firstValues | ranges::views::transform([meanFirst](double d) { return (d - meanFirst) * (d - meanFirst); }), 0.0) / (data.size() - 1);
    double varianceSecond = ranges::accumulate(secondValues | ranges::views::transform([meanSecond](double d) { return (d - meanSecond) * (d - meanSecond); }), 0.0) / (data.size() - 1);

    // Calculate the standard deviation for the first and second values
    double standardDeviationFirst = std::sqrt(varianceFirst);
    double standardDeviationSecond = std::sqrt(varianceSecond);

    std::cout << "Standard Deviation for first values: " << standardDeviationFirst << std::endl;
    std::cout << "Standard Deviation for second values: " << standardDeviationSecond << std::endl;
}

void SortData(std::vector<std::pair<double, double>>& data)
{
    // Sort the data based on the first value of each pair
    data |= ranges::action::sort([](const std::pair<double, double>& a, const std::pair<double, double>& b) {
        return a.first < b.first;
    });

}