#include <vector>
#include <iostream>
#include <algorithm>
#include <thread>
#include <functional>
#include <chrono>
void show_vec(std::vector<int> &vec);
void for_sleep(std::vector<int> &vec, int elm, int &k, bool &last_element);
void bubble(std::vector<int> vec);
void selection(std::vector<int> vec);
void insertion(std::vector<int> vec);
void gnome(std::vector<int> vec);
void odd_even(std::vector<int> vec);
void sleep(std::vector<int> vec);
void cocktail(std::vector<int> vec);