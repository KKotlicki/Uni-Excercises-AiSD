// Zadanie: Ranking
// Autor: Konrad Kotlicki
// Nr indeksu: 310958
#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
    // N - number of scores (input)
    // scores - vector of scores (input)
    // rankPlace - vector of ranks in ascending order
    // rankInScoresOrder - vector of ranks in input scores order
    int N;
    std::cin >> N;
    std::vector<std::pair <int, int>> scores;
    std::vector<int> rankPlace, rankInScoresOrder;

    // Set vectors' size to the number of scores
    scores.resize(N);
    rankPlace.resize(N);
    rankInScoresOrder.resize(N);

    // Input scores and assign them to the scores vector
    for (int i=0; i < N; i++){
        int pointCount;
        std::cin >> pointCount;
        scores.emplace_back(pointCount, i);
    }


    /// Sort in descending order by scores
    std::sort(scores.rbegin(), scores.rend());

    /// Build a ranking vector corresponding to the sorted scores
    int previousRank = 1;
    int previousScore = 0;
    for (int i=0; i < N; i++) {
        // if score value is the same as previous one
        if (i != 0 && scores[i].first == previousScore) {
            rankPlace[i] = previousRank;
        }
        else {
            rankPlace[i] = i + 1;
            previousRank = i + 1;
            previousScore = scores[i].first;
        }
    }

    /// Build a ranking vector in order of input scores and values of corresponding ranking
    for (int i=0; i < N; i++) rankInScoresOrder[scores[i].second] = rankPlace[i];


    /// Output
    for (int i=0; i < N; i++){
        std::cout << rankInScoresOrder[i] << std::endl;
    }
}
