#include "PmergeMe.hpp"

// Threshold for switching from merge sort to insertion sort
const size_t INSERTION_SORT_THRESHOLD = 32;


bool isPositiveInteger(const std::string& s) {
    if (s.empty())
        return false;

    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        if (!std::isdigit(*it))
            return false;
    }
    return true;
}


void PmergeMe::parseInput(int argc, char** argv, std::vector<int>& out) {
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);

        // Check if string contains only digits
        if (!isPositiveInteger(arg)) {
            throw InvalidInputException();
        }

        // Convert to number and validate range
        char* endptr;
        long val = std::strtol(arg.c_str(), &endptr, 10);
        if (*endptr != '\0' || val <= 0 || val > INT_MAX) {
            throw OutOfRangeException();
        }

        out.push_back(static_cast<int>(val));
    }

    if (out.empty()) {
        throw NoInputException();
    }
}

void PmergeMe::insertionSortVec(std::vector<int>& v, size_t left, size_t right) {
    for (size_t i = left + 1; i <= right; ++i) {
        int key = v[i];
        size_t j = i;

        // Move elements greater than key one position ahead
        while (j > left && v[j - 1] > key) {
            v[j] = v[j - 1];
            --j;
        }
        v[j] = key;
    }
}

void PmergeMe::mergeVec(std::vector<int>& v, size_t left, size_t mid, size_t right) {
    // Create temporary arrays for left and right subarrays
    std::vector<int> leftArray;
    std::vector<int> rightArray;

    // Copy data to temporary arrays
    for (size_t i = left; i <= mid; ++i)
        leftArray.push_back(v[i]);
    for (size_t i = mid + 1; i <= right; ++i)
        rightArray.push_back(v[i]);

    // Merge the temporary arrays back into v[left..right]
    size_t i = 0, j = 0, k = left;

    while (i < leftArray.size() && j < rightArray.size()) {
        if (leftArray[i] <= rightArray[j]) {
            v[k] = leftArray[i];
            i++;
        } else {
            v[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < leftArray.size()) {
        v[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < rightArray.size()) {
        v[k] = rightArray[j];
        j++;
        k++;
    }
}

void PmergeMe::fordJohnsonVec(std::vector<int>& v, size_t left, size_t right) {
    // Use insertion sort for small arrays
    if (right - left <= INSERTION_SORT_THRESHOLD) {
        insertionSortVec(v, left, right);
        return;
    }

    // Divide and conquer
    size_t mid = left + (right - left) / 2;
    fordJohnsonVec(v, left, mid);
    fordJohnsonVec(v, mid + 1, right);
    mergeVec(v, left, mid, right);
}

void PmergeMe::sortVector(std::vector<int>& vec) {
    if (vec.size() <= 1)
        return;
    fordJohnsonVec(vec, 0, vec.size() - 1);
}

void PmergeMe::insertionSortDeq(std::deque<int>& d, size_t left, size_t right) {
    for (size_t i = left + 1; i <= right; ++i) {
        int key = d[i];
        size_t j = i;

        // Move elements greater than key one position ahead
        while (j > left && d[j - 1] > key) {
            d[j] = d[j - 1];
            --j;
        }
        d[j] = key;
    }
}


void PmergeMe::mergeDeq(std::deque<int>& d, size_t left, size_t mid, size_t right) {
    // Create temporary deques for left and right subarrays
    std::deque<int> leftArray;
    std::deque<int> rightArray;

    // Copy data to temporary deques
    for (size_t i = left; i <= mid; ++i)
        leftArray.push_back(d[i]);
    for (size_t i = mid + 1; i <= right; ++i)
        rightArray.push_back(d[i]);

    // Merge the temporary deques back into d[left..right]
    size_t i = 0, j = 0, k = left;

    while (i < leftArray.size() && j < rightArray.size()) {
        if (leftArray[i] <= rightArray[j]) {
            d[k] = leftArray[i];
            i++;
        } else {
            d[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < leftArray.size()) {
        d[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < rightArray.size()) {
        d[k] = rightArray[j];
        j++;
        k++;
    }
}

void PmergeMe::fordJohnsonDeq(std::deque<int>& d, size_t left, size_t right) {
    // Use insertion sort for small arrays
    if (right - left <= INSERTION_SORT_THRESHOLD) {
        insertionSortDeq(d, left, right);
        return;
    }

    // Divide and conquer
    size_t mid = left + (right - left) / 2;
    fordJohnsonDeq(d, left, mid);
    fordJohnsonDeq(d, mid + 1, right);
    mergeDeq(d, left, mid, right);
}

void PmergeMe::sortDeque(std::deque<int>& deq) {
    if (deq.size() <= 1)
        return;
    fordJohnsonDeq(deq, 0, deq.size() - 1);
}

double PmergeMe::getTimeDifference(clock_t start, clock_t end) {
    return ((double)(end - start) / CLOCKS_PER_SEC) * 1000000.0;
}


void PmergeMe::printSequence(const std::vector<int>& vec, const std::string& label) {
    std::cout << label << ": ";

    const size_t MAX_DISPLAY = 8; // Show first 4 and last 4 elements for large sequences

    if (vec.size() <= MAX_DISPLAY) {
        // Show all elements for small sequences
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i + 1 < vec.size())
                std::cout << " ";
        }
    } else {
        // Show first few elements
        for (size_t i = 0; i < MAX_DISPLAY / 2; ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << "[...] ";
        // Show last few elements
        for (size_t i = vec.size() - MAX_DISPLAY / 2; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i + 1 < vec.size())
                std::cout << " ";
        }
    }
    std::cout << std::endl;
}


void PmergeMe::sortAndPrint(int argc, char** argv) {
    // Parse input
    std::vector<int> input;
    parseInput(argc, argv, input);

    // Print original sequence
    printSequence(input, "Before");

    // Sort with vector
    std::vector<int> vec = input;
    clock_t startVec = clock();
    sortVector(vec);
    clock_t endVec = clock();
    double vecTime = getTimeDifference(startVec, endVec);

    // Sort with deque
    std::deque<int> deq;
    for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it) {
        deq.push_back(*it);
    }

    clock_t startDeq = clock();
    sortDeque(deq);
    clock_t endDeq = clock();
    double deqTime = getTimeDifference(startDeq, endDeq);

    // Print sorted sequence
    printSequence(vec, "After");

    // Print timing results
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << deqTime << " us" << std::endl;
}
