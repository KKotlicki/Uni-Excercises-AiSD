// Zadanie: Mapa nieba
// Autor: Konrad Kotlicki
// Nr indeksu: 310958
#include <iostream>
#include <algorithm>
#include <vector>


// map_size - Number of spaces (elements) on the star map
// max_constellation_size - Size of the largest constellation
std::vector<int> id;
int map_size;
int max_constellation_size = 0;


void make_union(int p, int q)
{
    int pid = id[p];
    int qid = id[q];
    int size_of_component = 0;
    for (int i = 0; i < map_size; i++) {
        if (id[i] == qid) size_of_component++;
        else if (id[i] == pid) {
            id[i] = qid;
            size_of_component++;
        }
    }
    /// Set largest constellation size to the number of elements in component
    /// if greater than current largest constellation size
    if (size_of_component > max_constellation_size) max_constellation_size = size_of_component;
}


int main()
{
    // empty_count - Count of empty spaces (0) on the star map
    // map_side_legth - Number of columns (or rows) on the star map

    int empty_count = 0;
    int map_side_legth;
    std::cin>>map_side_legth;
    map_size= map_side_legth * map_side_legth;

    // Set id table's size to the size of the star map
    id.resize(map_size);

    /// Create star map in 1d table
    int star_map[map_size];
    for(int i=0; i < map_size; i++){
        std::cin >> star_map[i];
        // Set id table's init values
        id[i]=i;
    }

    /// Merge stars into constellations on id table
    for(int i=0; i < map_size; i++){
        if(star_map[i] == 1){
            // Set initial constellation size (for the case with only one star on map)
            if(max_constellation_size == 0) max_constellation_size++;

            // Merge with star on the right (if not empty)
            if(i < map_size - 1)
                if(star_map[i + 1] == 1 && i % map_side_legth != map_side_legth - 1){
                    make_union(i, i+1);
                }

            // Merge with star below (if not empty)
            if(i < map_size - map_side_legth)
                if(star_map[i + map_side_legth] == 1 && i < map_size - map_side_legth) {
                    make_union(i, i + map_side_legth);
                }
        }

        // Increment empty space counter if position holds value 0
        else empty_count++;
    }

    // Count distinct comdponents
    std::sort(id.begin(), id.end());
    int components_count = int(std::unique(id.begin(), id.end()) - id.begin());
    /// Calculate number of constellations
    int constellations_count = components_count - empty_count;

    /// Output
    std::cout << constellations_count << " " << max_constellation_size << "\n";
}
