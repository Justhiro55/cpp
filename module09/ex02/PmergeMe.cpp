#include "PmergeMe.hpp"

// ----- constructor -----
template <typename T>
PmergeMe<T>::PmergeMe() {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &obj) {*this = obj;}

template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe &obj) {
    if (this != &obj) {
        _vector = obj._vector;
        _deque = obj._deque;
        _jacobsthalSequence = obj._jacobsthalSequence;
        _groupSizes = obj._groupSizes;
        _bigger = obj._bigger;
        _smaller = obj._smaller;
        _pending = obj._pending;
    }
    return *this;
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

// ----- member functions -----
template <typename T>
void PmergeMe<T>::parseInput(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.empty()) {
            throw std::invalid_argument("Error: Empty argument");
        }

        for (size_t j = 0; j < arg.length(); ++j) {
            if (!std::isdigit(arg[j])) {
                throw std::invalid_argument("Error: Invalid argument");
            }
        }

        int num = std::atoi(arg.c_str());
        if (num < 0 || num > std::numeric_limits<int>::max()) {
            throw std::out_of_range("Error: Number out of range");
        }
        _vector.push_back(num);
        _deque.push_back(num);
    }

    std::cout << YELLOW << "---------- Unsorted ----------" << RESET << std::endl << std::endl;
    displayList();
    std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::mergeInsertSort() {
    // std::cout << CYAN << "---------- Merge Insert Sort ----------" << RESET << std::endl << std::endl;

    // 開始時間：vector
    clock_t startVector = clock();

    mergeInsertSortVector();

    // 終了時間：vector
    clock_t endVector = clock();
    double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000;

    // 開始時間：deque
    clock_t startDeque = clock();
    mergeInsertSortDeque();
    clock_t endDeque = clock();
    double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000;

    // 結果表示
    displayResults(timeVector, timeDeque);
}

template <typename T>
void PmergeMe<T>::mergeInsertSortDeque() {
    if (_deque.size() <= 1) {
        return;
    }

    // 奇数の場合、最後の要素を取り出す
    int oddElement = -1;
    bool hasOddElement = false;
    if (_deque.size() % 2 == 1) {
        oddElement = _deque.back();
        _deque.pop_back();
        hasOddElement = true;
    }

    // ペアを作成
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < _deque.size(); i += 2) {
        int first = _deque[i];
        int second = -1;

        if (i + 1 < _deque.size()) {
            second = _deque[i + 1];
        }

        int bigger, smaller;
        if (first > second) {
            bigger = first;
            smaller = second;
        } else {
            bigger = second;
            smaller = first;
        }

        pairs.push_back(std::make_pair(bigger, smaller));
    }

    // 大きい方の要素
    std::deque<int> biggers;
    for (size_t i = 0; i < pairs.size(); ++i) {
        biggers.push_back(pairs[i].first);
    }

    // 大きい方の要素をソート
    if (biggers.size() > 1) {
        // 挿入ソートを実装
        for (size_t i = 1; i < biggers.size(); ++i) {
            int key = biggers[i];
            int j = i - 1;

            while (j >= 0 && biggers[j] > key) {
                biggers[j + 1] = biggers[j];
                --j;
            }

            biggers[j + 1] = key;
        }
    }

    // 結果配列を初期化
    std::deque<int> result = biggers;

    // 最初のペアの小さい方の要素を先頭に挿入
    result.push_front(pairs[0].second);

    // 挿入順序を決定
    std::vector<size_t> insertOrder;
    std::vector<size_t> groupSizes = generateGroupSizes(pairs.size() - 1);

    size_t processed = 0;
    for (size_t g = 0; g < groupSizes.size() && processed < pairs.size() - 1; ++g) {
        size_t currentGroup = groupSizes[g];
        size_t actualGroupSize;

        if (processed + currentGroup <= pairs.size() - 1) {
            actualGroupSize = currentGroup;
        } else {
            actualGroupSize = pairs.size() - 1 - processed;
        }

        for (size_t j = 0; j < actualGroupSize; ++j) {
            insertOrder.push_back(processed + (actualGroupSize - 1 - j));
        }
        processed += currentGroup;
    }

    // 挿入順序に従って小さい方の要素を挿入
    for (size_t i = 0; i < insertOrder.size(); ++i) {
        size_t idx = insertOrder[i];
        if (idx >= pairs.size() || idx == 0) continue; // 最初のペアはすでに挿入済み

        int valueToInsert = pairs[idx].second;

        // バイナリサーチで挿入位置を特定
        size_t left = 0;
        size_t right = result.size();

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < valueToInsert) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        result.insert(result.begin() + left, valueToInsert);
    }

    // 奇数の場合、取り出していた要素を適切な位置に挿入
    if (hasOddElement) {
        // バイナリサーチで挿入位置を特定
        size_t left = 0;
        size_t right = result.size();

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < oddElement) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        result.insert(result.begin() + left, oddElement);
    }

    // 結果をdequeに戻す
    _deque = result;
}

template <typename T>
std::vector<size_t> PmergeMe<T>::generateGroupSizes(size_t n) {
    std::vector<size_t> sizes;
    if (n == 0) return sizes;

    // 最初の2つは固定
    sizes.push_back(2);
    if (n == 1) return sizes;
    sizes.push_back(2);

    size_t sumSoFar = sizes[0] + sizes[1];

    // ここでは k を段階的に上げながら作り続ける
    size_t k = 2;
    while (sumSoFar < n) {
        size_t power = static_cast<size_t>(1) << (k + 1); // 2^(k+1)
        size_t nextSize = power - sizes.back();
        sizes.push_back(nextSize);
        sumSoFar += nextSize;
        ++k;
    }

    return sizes;
}

template <typename T>
void PmergeMe<T>::displayList() {
    size_t vectorSize = _vector.size();
    std::cout << "[vector]" << std::endl;

    std::cout << std::endl;
    for (size_t i = 0; i < vectorSize; ++i) {
        std::cout << "Vector[" << i << "] = " << _vector[i] << std::endl;
    }
    std::cout << std::endl;

    size_t dequeSize = _deque.size();
    std::cout << "[deque]" << std::endl;

    std::cout << std::endl;
    for (size_t i = 0; i < dequeSize; ++i) {
        std::cout << "Deque[" << i << "] = " << _deque[i] << std::endl;
    }

    std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::binaryInsert(T &container, const typename T::value_type &value) {
    typename T::iterator pos = std::lower_bound(container.begin(), container.end(), value);
    container.insert(pos, value);
}

template <typename T>
void PmergeMe<T>::mergeInsertSortVector() {
    if (_vector.size() <= 1) {
        return;
    }

    // 奇数の場合、最後の要素を取り出す
    int oddElement = -1;
    bool hasOddElement = false;
    if (_vector.size() % 2 == 1) {
        oddElement = _vector.back();
        _vector.pop_back();
        hasOddElement = true;
    }

    // ペアを作成
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < _vector.size(); i += 2) {
        int first = _vector[i];
        int second = -1;

        if (i + 1 < _vector.size()) {
            second = _vector[i + 1];
        }

        // 各ペアで大小関係を比較
        int bigger, smaller;
        if (first > second) {
            bigger = first;
            smaller = second;
        } else {
            bigger = second;
            smaller = first;
        }

        pairs.push_back(std::make_pair(bigger, smaller));
    }

    // 大きい方の要素を取り出す
    std::vector<int> biggers;
    for (size_t i = 0; i < pairs.size(); ++i) {
        biggers.push_back(pairs[i].first);
    }

    // 大きい要素をソート
    if (biggers.size() > 1) {
        // 挿入ソートを使用する例
        for (size_t i = 1; i < biggers.size(); ++i) {
            int key = biggers[i];
            int j = i - 1;

            while (j >= 0 && biggers[j] > key) {
                biggers[j + 1] = biggers[j];
                --j;
            }

            biggers[j + 1] = key;
        }
    }

    // 結果配列を初期化（最初は大きい方の要素だけ）
    std::vector<int> result = biggers;

    // 最初のペアの小さい方の要素を先頭に挿入
    result.insert(result.begin(), pairs[0].second);

    // ヤコブスタール数列に基づいて挿入順序を決定
    std::vector<size_t> insertOrder;
    _groupSizes = generateGroupSizes(pairs.size() - 1);

    size_t processed = 0;
    for (size_t g = 0; g < _groupSizes.size() && processed < pairs.size() - 1; ++g) {
        size_t currentGroup = _groupSizes[g];
        size_t actualGroupSize;

        if (processed + currentGroup <= pairs.size() - 1) {
            actualGroupSize = currentGroup;
        } else {
            actualGroupSize = pairs.size() - 1 - processed;
        }

        for (size_t j = 0; j < actualGroupSize; ++j) {
            insertOrder.push_back(processed + (actualGroupSize - 1 - j));
        }
        processed += currentGroup;
    }

    // 挿入順序に従って小さい方の要素を挿入
    for (size_t i = 0; i < insertOrder.size(); ++i) {
        size_t idx = insertOrder[i];
        if (idx >= pairs.size() || idx == 0) continue; // 最初のペアはすでに挿入済み

        int valueToInsert = pairs[idx].second;

        // バイナリサーチで挿入位置を特定（std::lower_boundを使わない場合）
        size_t left = 0;
        size_t right = result.size();

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < valueToInsert) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        result.insert(result.begin() + left, valueToInsert);
    }

    // 奇数の場合、取り出していた要素を適切な位置に挿入
    if (hasOddElement) {
        // バイナリサーチで挿入位置を特定
        size_t left = 0;
        size_t right = result.size();

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < oddElement) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        result.insert(result.begin() + left, oddElement);
    }

    // 結果をvectorに戻す
    _vector = result;
}

template <typename T>
std::vector<std::pair<int, int> > PmergeMe<T>::createPairs(const std::vector<int> &vec) {
    std::cout << "-------------- Create pairs --------------" << std::endl;
    std::vector<std::pair<int, int> > pairs;
    PmergeMe<T> pm;
    for (size_t i = 0; i < vec.size(); i += 2) {
        int first = vec[i];
        int second;
        std::cout << "i: " << i / 2 + 1 << std::endl;
        std::cout << "first: " << first;

        if (i + 1 >= vec.size()) {
            std::cout << ", second is set to -1 (Odd number of elements)" << std::endl;
            second = -1;
        } else {
            second = vec[i + 1];
            std::cout << ", second: " << second << std::endl;
        }
        std::cout << std::endl;

        // 各ペアで大小関係を比較
        int bigger, smaller;
        if (first > second) {
            bigger = first;
            smaller = second;
        } else {
            bigger = second;
            smaller = first;
        }

        pm._vector.push_back(bigger);
        pairs.push_back(std::make_pair(bigger, smaller));
    }
    if (pm._vector.size() > 1) {
        std::cout << "Pairs: ";
        for (size_t i = 0; i < pm._vector.size(); ++i) {
            std::cout << pm._vector[i] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl << "[ recursive createpairs ]" << std::endl << std::endl;
        pm.createPairs(pm._vector);
    }
    std::cout << "-----------------------------------------" << std::endl << std::endl;
    return pairs;
}

template <typename T>
void PmergeMe<T>::displayResults(double timeVector, double timeDeque) {
    std::cout << GREEN << "---------- Result ----------" << RESET << std::endl << std::endl;

    // ソート後の配列を表示
    displayList();


    // 実行時間を表示
    std::cout << "\n\nTime to process a range of " << _vector.size()
              << " elements with std::vector : " << timeVector << " ms" << std::endl;
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque : " << timeDeque << " ms" << std::endl;

    bool vectorSorted = true;
    for (size_t i = 1; i < _vector.size(); ++i) {
        if (_vector[i] < _vector[i-1]) {
            vectorSorted = false;
            break;
        }
    }

    std::cout << "Vector sorted: ";
    if (vectorSorted) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    bool dequeSorted = true;
    for (size_t i = 1; i < _deque.size(); ++i) {
        if (_deque[i] < _deque[i-1]) {
            dequeSorted = false;
            break;
        }
    }

    std::cout << "Deque sorted: ";
    if (dequeSorted) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}

template <typename T>
void PmergeMe<T>::printVector() {
    for (size_t i = 0; i < _vector.size(); ++i) {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;
}

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;
template class PmergeMe<std::list<int> >;
