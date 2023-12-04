#ifndef CALCULATE_EFFECTIVENESS_H
#define CALCULATE_EFFECTIVENESS_H

#include<vector>


float get_ability(const std::vector<float> ability);
std::vector<std::vector<float>> matrix_mutiplicate(std::vector<std::vector<float>>& A, std::vector<std::vector<float>>& B);
float get_effectiveness();


std::vector<std::vector<float>> get_availibility();
std::vector<std::vector<float>> get_credibility_matrix();
double calculate_combination(const std::vector<float>& failure_probabilities, const std::vector<int>& combination);
std::vector<std::vector<int>> generate_combinations(int n);
std::vector<float> calculate_fault_probabilities(const std::vector<float>& failure_probabilities);
int nchoosek(int n, int k);

#endif // CALCULATE_EFFECTIVENESS_H
