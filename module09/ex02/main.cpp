#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cerr << "Error: No arguments provided." << std::endl;
        return EXIT_FAILURE;
    }

    PmergeMe sorter;

    try {
        // 入力の解析
        sorter.parseInput(argc, argv);

        // ソートを実行
        sorter.mergeInsertSort();

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}
