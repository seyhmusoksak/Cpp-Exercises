#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <exception>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <climits>


class PmergeMe {
public:
    // Custom exception classes
    class InvalidInputException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Invalid input";
        }
    };

    class OutOfRangeException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Out of range";
        }
    };

    class NoInputException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "No input";
        }
    };

    // Main function to sort and display results
    static void sortAndPrint(int argc, char** argv);

private:    // Input parsing and validation
    static void parseInput(int argc, char** argv, std::vector<int>& out);

    // Vector sorting functions
    static void sortVector(std::vector<int>& vec);
    static void insertionSortVec(std::vector<int>& v, size_t left, size_t right);
    static void mergeVec(std::vector<int>& v, size_t left, size_t mid, size_t right);
    static void fordJohnsonVec(std::vector<int>& v, size_t left, size_t right);

    // Deque sorting functions
    static void sortDeque(std::deque<int>& deq);
    static void insertionSortDeq(std::deque<int>& d, size_t left, size_t right);
    static void mergeDeq(std::deque<int>& d, size_t left, size_t mid, size_t right);
    static void fordJohnsonDeq(std::deque<int>& d, size_t left, size_t right);

    // Utility functions
    static double getTimeDifference(clock_t start, clock_t end);
    static void printSequence(const std::vector<int>& vec, const std::string& label);

    // Private constructor to prevent instantiation (utility class)
    PmergeMe();
    PmergeMe(const PmergeMe&);
    PmergeMe& operator=(const PmergeMe&);
};

#endif
