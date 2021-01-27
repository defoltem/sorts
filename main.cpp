#include "sorts-type.h"

int main(){
    std::vector<int> vec = {7, 5, 3, 10, 2, 3, 4, 12, 1};
    std::cout << "original vector: ";
    show_vec(vec);
    std::cout << "--------------\n";
    bubble(vec);
    selection(vec);
    insertion(vec);
    gnome(vec);
    odd_even(vec);
    sleep(vec);
    return 0;
}