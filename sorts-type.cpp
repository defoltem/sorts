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
void insertion(std::vector<int> vec){
    std::vector<int>::iterator it1 = vec.begin();
    std::vector<int>::iterator it2 = vec.begin()+1;
    std::cout << "insertion sort: ";
    size_t lenght = vec.size();
    bool isequal = false;
    size_t idx = 1;
    for (size_t i = 0; i < lenght; i++){
        if (idx == lenght) break;
        for (size_t j = 0; j < lenght; j++){
            if (idx == lenght) break;
                while (it1 != it2){
                    if (*it1 > *it2) { 
                        isequal = false;
                        break;
                    }
                    else ++it1;
                }
                if(!isequal) { 
                vec.emplace(it1, *it2);
                it1 = vec.begin();
                it2 = vec.begin()+idx;
                vec.erase(it2+1);
                it2 = vec.begin()+idx;
                isequal = true;
                } else {
                    it1 = vec.begin();
                    it2++;
                    idx++;
                }
        }
    }
    show_vec(vec);
}

void gnome(std::vector<int> vec){
    std::cout << "gnome sort: ";
    size_t lenght = vec.size();
    size_t i = 0;
    while (i < lenght){
        if (i == 0) i++; 
        else if (vec.at(i) >= vec.at(i-1)) i++;
        else if (vec.at(i) < vec.at(i-1)){
            std::swap(vec.at(i), vec.at(i-1));
            i--;
        }
    }
    show_vec(vec);
}

void odd_even(std::vector<int> vec){
    std::cout << "odd-even sort: ";
    size_t lenght = vec.size();
    size_t i;
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for (i = 1; i <= lenght-2; i+=2) {
            if(vec.at(i) > vec.at(i+1)) { 
                sorted = false;
                std::swap(vec.at(i), vec.at(i+1));
            }
        } 
        for (i = 0; i <= lenght-2; i+=2) {
            if(vec.at(i) > vec.at(i+1)) { 
                sorted = false;
                std::swap(vec.at(i), vec.at(i+1));
            }
        } 
    }
    show_vec(vec);
}

void for_sleep(std::vector<int> &vec, int elm, int &k, bool &last_element){
    std::this_thread::sleep_for(std::chrono::milliseconds(elm)); // in any negative case - change to seconds
    vec.at(k) = elm;
    k++;
    if (k == vec.size()) last_element = true;
}

void sleep(std::vector<int> vec){
    std::cout << "sleep sort: ";
    int k = 0;
    bool last_element = false;
    size_t lenght = vec.size();
    for(size_t i = 0; i < lenght; i++){
        std::thread tr(std::bind(for_sleep, std::ref(vec), vec.at(i), std::ref(k), std::ref(last_element)));
        tr.detach();
    }
    while (1) {
        if (last_element) break;
        };
    show_vec(vec);
}

void cocktail(std::vector<int> vec){
    std::cout << "cocktail sort: ";
    size_t lenght = vec.size();
    size_t start = 0;
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for (size_t i = start; i < lenght-1; i++){
            if (vec.at(i) > vec.at(i+1)){
                sorted = false;
                std::swap(vec.at(i), vec.at(i+1));
            }
        }
        if (sorted) break;
                for (size_t i = lenght; i > start-1; i--){
            if (vec.at(i) < vec.at(i-1)){
                sorted = false;
                std::swap(vec.at(i), vec.at(i-1));
            }
        }        
    };
    show_vec(vec);
}

int max(std::vector<int> &vec, size_t curr_len){
    size_t maximum = 0;
    for(size_t i = 0; i < curr_len; i++){
        if (vec.at(i) > vec.at(maximum)) maximum = i;
    }
    return maximum;
}

void roll(std::vector<int> &vec, size_t curr_len){
    size_t start = 0;
    while(start < curr_len){
        std::swap(vec.at(curr_len), vec.at(start));
        start++;
        curr_len--;
    }
}

void pancake(std::vector<int> vec){
    std::cout << "pancake sort: ";
    size_t lenght = vec.size();
    for(;lenght > 1; lenght--){
        size_t maximum = max(vec, lenght);
        if (maximum != lenght-1){
            roll(vec, maximum);
            roll(vec, lenght-1);
        }
    }
    show_vec(vec);
}