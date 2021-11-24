// Zadanie: Głosowanie
// Autor: Konrad Kotlicki
// Nr indeksu: 310958
#include <iostream>

int main(){
    int n, m;

    std::cin >> n >> m;

    int* candidate_table = new int[n+1]{0};
    int max_candidate_vote_count = 0;

    for(int i = 0; i < m; i++){
        int vote;
        std::cin >> vote;
        candidate_table[vote]++;

        if(vote == 0 || max_candidate_vote_count >= candidate_table[vote]) continue;

        max_candidate_vote_count = candidate_table[vote];
    }

    for(int i = 1; i < n+1; i++){
        if(max_candidate_vote_count != candidate_table[i]) continue;

        std::cout << i << " ";
    }

    delete [] candidate_table;
    return 0;
}
