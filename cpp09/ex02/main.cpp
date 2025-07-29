/**
 * PmergeMe - Ford-Johnson sorting algorithm demonstration
 * Compares performance between std::vector and std::deque
 */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
    try {
        // Check for minimum arguments
        if (argc < 2) {
            std::cerr << "Error: No arguments provided" << std::endl;
            std::cerr << "Usage: " << argv[0] << " [positive integers...]" << std::endl;
            return 1;
        }

        // Sort and display results
        PmergeMe::sortAndPrint(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}
