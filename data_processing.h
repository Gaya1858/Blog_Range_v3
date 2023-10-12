#pragma once

#include <string>
#include <vector>

std::vector<std::vector<std::string>> LoadCsv(const std::string& filename);
std::vector<std::pair<double, double>> DoubleData(const std::vector<std::vector<std::string>>& cardData);
void Descriptivestats(const std::vector<std::pair<double, double>>& data);
void SortData(std::vector<std::pair<double, double>>& data);