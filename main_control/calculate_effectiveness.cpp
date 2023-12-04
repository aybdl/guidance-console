#include<vector>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

float get_effectiveness();
float get_ability(const std::vector<float> ability);
std::vector<std::vector<float>> matrix_mutiplicate(std::vector<std::vector<float>>& A, std::vector<std::vector<float>>& B);
std::vector<std::vector<float>> get_availibility();
std::vector<std::vector<float>> get_credibility_matrix();
double calculate_combination(const std::vector<float>& failure_probabilities, const std::vector<int>& combination);
std::vector<std::vector<int>> generate_combinations(int n);
std::vector<float> calculate_fault_probabilities(const std::vector<float>& failure_probabilities);
int nchoosek(int n, int k);

float get_effectiveness(){
    //std::vector<float> ability_1(14, 0.99);
    //std::vector<float> ability_2(14, 0.90);
    //std::vector<float> ability_3(14, 0.85);

    //std::vector<std::vector<float>> ability_vec = {{get_ability(ability_1)}, {get_ability(ability_2)}, {get_ability(ability_3)},{0.0}};
    //std::vector<std::vector<float>> availibility_vec = {{0.9703,0.0294,0,0}};
    //std::vector<std::vector<float>> credibility_matrix = {{0.3012,0.4444,0.2186,0.0358},{0,0.4493,0.4420,0.1087},{0,0,0.6703,0.3297},{0,0,0,1}};
    std::vector<std::vector<float>> availibility_vec = get_availibility();
    std::vector<std::vector<float>> credibility_matrix = get_credibility_matrix();
    std::vector<std::vector<float>> ability_vec;
    float start = 0.98;
    float inter = start/(availibility_vec[0].size()-1);
    for(int i=availibility_vec[0].size(); i>0; --i) {
        std::vector<float> temp;
        temp.push_back(start);
        ability_vec.push_back(temp);
        start -= inter;
    }

    std::vector<std::vector<float>> mid = matrix_mutiplicate(availibility_vec, credibility_matrix);
    std::vector<std::vector<float>> ans = matrix_mutiplicate(mid, ability_vec);

    return ans[0][0];
}


float get_ability(const std::vector<float> ability){
    float width = ability[0];
    float depth = ability[1];
    float recognition = ability[2];
    float response_speed = ability[3];

    float commu_reliability = ability[4];
    float commu_radius = ability[5];
    float commu_delay = ability[6];

    float interference = ability[7];
    float navi_speed = ability[8];
    float contermeasure = ability[9];

    float att_direction = ability[10];
    float att_speed = ability[11];
    float att_angle = ability[12];
    float att_density = ability[13];


    std::vector<float> detecting_wei = {0.0814,0.0814,0.6077,0.2296};
    std::vector<float> commu_wei = {0.6483,0.1220,0.2297};
    std::vector<float> forma_wei = {0.5954,0.1283,0.2764};
    std::vector<float> att_wei = {0.1223,0.2270,0.4236,0.2270};

    float detec_prob = width*detecting_wei[0] + depth*detecting_wei[1] + recognition*detecting_wei[2] + response_speed*detecting_wei[3];
    float comu_prob = commu_reliability*commu_wei[0] + commu_radius*commu_wei[1] + commu_delay*commu_wei[2];
    float forma_prob = interference*forma_wei[0] + navi_speed*forma_wei[1] + contermeasure*forma_wei[2];
    float att_prob = att_direction*att_wei[0] + att_speed*att_wei[1] + att_angle*att_wei[2] + att_density*att_wei[3];

    float ability_num = detec_prob*comu_prob*forma_prob*att_prob;

    return ability_num;

}


std::vector<std::vector<float>> matrix_mutiplicate(std::vector<std::vector<float>>& A, std::vector<std::vector<float>>& B) {
    int A_row = A.size();
    int B_row = B.size();

    int A_col = A[0].size();
    int B_col = B[0].size();

    if(A_col == B_row) {
        std::vector<std::vector<float>> C(A_row, std::vector<float>(B_col));
        for(int i=0;i<A_row;++i) {
            for(int j=0;j<B_col;++j) {
                float cur=0;
                for(int k=0;k<A_col;++k) {
                    cur += A[i][k]*B[k][j];
                }
                C[i][j] = cur;
            }
        }
        return C;
    }
    std::vector<std::vector<float>> D={{}};
    return D;

}

std::vector<std::vector<float>> get_availibility() {
    float t = 100;
    float p = pow(10, -6);
    float one = 2*15*p*t;
    float two = 10*p*t;
    float three = 10*p*t;
    float four = 10*p*t;
    float five = 2*5*p*t;
    float six = 2*10*p*t;
    float seven = 4*5*p*t;
    float eight = 3*4*p*t;
    float nine = 3*4*p*t;
    float ten = 3*6*p*t;
    float eleven = 2*15*p*t;
    float twelve = 1*15*p*t;
    float thirteen = 12*3*p*t;
    float fourteen = 18*1*p*t;
    float fifteen = 4*1*p*t;
    float sixteen = 300*p*t;
    float seventeen = 5*p*t;
    float eighteen = 4*p*t;
    float nineteen = 8*p*t;
    float twenty = 6*p*t;

    std::vector<float> failure_probabilities = {};
    failure_probabilities.push_back(one);
    failure_probabilities.push_back(two);
    failure_probabilities.push_back(three);
    failure_probabilities.push_back(four);
    failure_probabilities.push_back(five);
    failure_probabilities.push_back(six);
    failure_probabilities.push_back(seven);
    failure_probabilities.push_back(eight);
    failure_probabilities.push_back(nine);
    failure_probabilities.push_back(ten);
    failure_probabilities.push_back(eleven);
    failure_probabilities.push_back(twelve);
    failure_probabilities.push_back(thirteen);
    failure_probabilities.push_back(fourteen);
    failure_probabilities.push_back(fifteen);
    failure_probabilities.push_back(sixteen);
    failure_probabilities.push_back(seventeen);
    failure_probabilities.push_back(eighteen);
    failure_probabilities.push_back(nineteen);
    failure_probabilities.push_back(twenty);

    std::vector<float> probabilities = calculate_fault_probabilities(failure_probabilities);
    std::vector<std::vector<float>> availibility;
    availibility.push_back(probabilities);
    return availibility;
}

std::vector<std::vector<float>> get_credibility_matrix(){
    float t = 100;
    float p = pow(10, -6);
    float one = 2*15*p*t;
    float two = 10*p*t;
    float three = 10*p*t;
    float four = 10*p*t;
    float five = 2*5*p*t;
    float six = 2*10*p*t;
    float seven = 4*5*p*t;
    float eight = 3*4*p*t;
    float nine = 3*4*p*t;
    float ten = 3*6*p*t;
    float eleven = 2*15*p*t;
    float twelve = 1*15*p*t;
    float thirteen = 12*3*p*t;
    float fourteen = 18*1*p*t;
    float fifteen = 4*1*p*t;
    float sixteen = 300*p*t;
    float seventeen = 5*p*t;
    float eighteen = 4*p*t;
    float nineteen = 8*p*t;
    float twenty = 6*p*t;

    std::vector<float> failure_probabilities = {};
    failure_probabilities.push_back(one);
    failure_probabilities.push_back(two);
    failure_probabilities.push_back(three);
    failure_probabilities.push_back(four);
    failure_probabilities.push_back(five);
    failure_probabilities.push_back(six);
    failure_probabilities.push_back(seven);
    failure_probabilities.push_back(eight);
    failure_probabilities.push_back(nine);
    failure_probabilities.push_back(ten);
    failure_probabilities.push_back(eleven);
    failure_probabilities.push_back(twelve);
    failure_probabilities.push_back(thirteen);
    failure_probabilities.push_back(fourteen);
    failure_probabilities.push_back(fifteen);
    failure_probabilities.push_back(sixteen);
    failure_probabilities.push_back(seventeen);
    failure_probabilities.push_back(eighteen);
    failure_probabilities.push_back(nineteen);
    failure_probabilities.push_back(twenty);

    int n = failure_probabilities.size();
    float MTBF = t/std::accumulate(failure_probabilities.begin(), failure_probabilities.end(), 0.0);
    float K = t/MTBF;
    std::vector<std::vector<float>> credibility_matrix(n+1, std::vector<float>(n+1));

    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            if (i == j) {
                credibility_matrix[i][j] = std::exp(-(n - i) * K);
            } else if (i > j) {
                credibility_matrix[i][j] = 0;
            } else {
                credibility_matrix[i][j] = nchoosek(n - i, j - i) * std::exp(-(n - j) * K) *
                                           std::pow((1 - std::exp(-K)), (j - i));
            }
        }
    }
    return credibility_matrix;
}

double calculate_combination(const std::vector<float>& failure_probabilities, const std::vector<int>& combination) {
    double result = 1.0;
    for (int index : combination) {
        result *= failure_probabilities[index];
    }
    return result;
}


std::vector<std::vector<int>> generate_combinations(int n) {
    std::vector<std::vector<int>> combinations;

    for (int i = 0; i < (1 << n); ++i) {
        std::vector<int> combination;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                combination.push_back(j);
            }
        }
        combinations.push_back(combination);
    }

    return combinations;
}


std::vector<float> calculate_fault_probabilities(const std::vector<float>& failure_probabilities) {
    int n = failure_probabilities.size();
    std::vector<float> probabilities(n + 1, 0.0);

    // 生成所有组合
    std::vector<std::vector<int>> all_combinations = generate_combinations(n);

    // 计算发生故障的概率
    for (const auto& combination : all_combinations) {
        double probability = calculate_combination(failure_probabilities, combination);
        int k = combination.size();
        probabilities[k] += probability;
    }

    // 计算总体概率
    probabilities[0] = 1 - std::accumulate(probabilities.begin()+1, probabilities.end(), 0.0);;

    return probabilities;
}


int nchoosek(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return nchoosek(n - 1, k - 1) + nchoosek(n - 1, k);
    }
}







