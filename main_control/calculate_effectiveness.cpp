#include<vector>


float get_ability(const std::vector<float> ability);
std::vector<std::vector<float>> matrix_mutiplicate(std::vector<std::vector<float>>& A, std::vector<std::vector<float>>& B);
float get_effectiveness();


float get_effectiveness(){
    std::vector<float> ability_1(14, 0.99);
    std::vector<float> ability_2(14, 0.90);
    std::vector<float> ability_3(14, 0.85);

    std::vector<std::vector<float>> ability_vec = {{get_ability(ability_1)}, {get_ability(ability_2)}, {get_ability(ability_3)},{0.0}};
    std::vector<std::vector<float>> availibility_vec = {{0.9703,0.0294,0,0}};
    std::vector<std::vector<float>> credibility_matrix = {{0.3012,0.4444,0.2186,0.0358},{0,0.4493,0.4420,0.1087},{0,0,0.6703,0.3297},{0,0,0,1}};

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


