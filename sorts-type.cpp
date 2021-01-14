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

void selection(std::vector<int> vec){
    std::cout << "selection sort: ";
    size_t lenght = vec.size();
    int min, min_idx, order = 0;
    for(size_t i = 0; i < lenght; i++){
        min = vec.at(order);
        min_idx = order;
        for (size_t j = order; j < lenght; j++){
            if (vec.at(j) <= min) {
                min = vec.at(j);
                min_idx = j;
            } 
        }
        std::swap(vec.at(order), vec.at(min_idx));
        order++;
    }
    show_vec(vec);
}