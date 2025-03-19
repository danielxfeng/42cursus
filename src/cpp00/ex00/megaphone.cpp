#include <iostream>

int main(int argc, char **argv) {
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else {
        for (int i = 1; i < argc; ++i) {
            std::string word = argv[i];
            for (size_t j = 0; j < word.length(); ++j)
                std::cout << (char)std::toupper(word[j]);
        }
    }
    std::cout << std:: endl;
    return EXIT_SUCCESS;
}
