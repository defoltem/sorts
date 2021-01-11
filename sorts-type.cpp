#include "sorts-type.h"

void show_vec(std::vector<int> &vec){
    for(const int i:vec){
        std::cout << i << " ";
    }
    std::cout << '\n';
}

void bubble(std::vector<int> vec){
    std::cout << "bubble sort: ";
    size_t lenght = vec.size();
    for(size_t i = 0; i < lenght; i++){
        for(size_t j = 0; j < lenght; j++){
            if (j+1 < lenght){ // to prevent std::out_of_range
                if (vec.at(j) > vec.at(j+1)) std::swap(vec.at(j), vec.at(j+1));
            } else continue;
        }
    }
    show_vec(vec);
}