#include <iostream>
#include <list>
#include <string>
#include <variant>

int main()
{
    std::list<std::variant<std::list<int>, std::list<std::string>>> list_of_lists;
    std::list<int> int_list = {1, 2, 3};
    std::list<std::string> string_list = {"one", "two", "three"};

    list_of_lists.push_back(int_list);
    list_of_lists.push_back(string_list);

    // Iterate over all std::variant elements.
    for (const auto& v : list_of_lists) {
        // Check if the variant holds a list of ints.
        if (std::holds_alternative<std::list<int>>(v)) {
            // 'v' holds a list of ints.
            for (auto i : std::get<std::list<int>>(v)) {
                std::cout << i << ' ';
            }
            std::cout << '\n';
        }
            // Check if the variant holds a list of strings.
        else if (std::holds_alternative<std::list<std::string>>(v)) {
            // 'v' holds a list of strings.
            for (const auto& s : std::get<std::list<std::string>>(v)) {
                std::cout << s << ' ';
            }
            std::cout << '\n';
        }
    }
}