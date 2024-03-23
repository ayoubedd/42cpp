#pragma once

#include <cstdlib>
#include <vector>

bool isGreaterThanOrEqual(int one, int two);
std::vector<size_t> jacobthalSeq(size_t size);

template <typename Container>
void merge(typename Container::iterator begin,
           typename Container::iterator middle,
           typename Container::iterator end) {
  typename Container::iterator savedMiddle = middle;
  typename Container::iterator savedBegin = begin;
  Container res;

  typename Container::iterator tmp;
  while ((begin != savedMiddle) || (middle != end)) {

    if (begin == savedMiddle) {
      tmp = middle;
      middle++;
    } else if (middle == end) {
      tmp = begin;
      begin++;
    } else {
      if (begin->first < middle->first) {
        tmp = begin;
        begin++;
      } else {
        tmp = middle;
        middle++;
      }
    }

    res.push_back(*tmp);
  }

  for (size_t i = 0; i < res.size(); i++) {
    *savedBegin = res[i];
    savedBegin++;
  }
}

template <typename Container>
void mergeSort(typename Container::iterator begin,
               typename Container::iterator end) {
  typename Container::iterator middle = begin + (end - begin) / 2;

  if (end - begin > 1 && begin != end) {
    mergeSort<Container>(begin, middle);
    mergeSort<Container>(middle, end);
  }

  merge<Container>(begin, middle, end);
}

template <typename Container> void sortPairs(Container &elements) {
  typename Container::iterator begin = elements.begin();
  typename Container::iterator end = elements.end();

  while (begin != end) {
    if (begin->first < begin->second)
      std::swap(begin->first, begin->second);
    begin++;
  }
}

template <typename Container>
typename Container::iterator binarySearch(typename Container::iterator begin,
                                          typename Container::iterator end,
                                          bool (*f)(int, int), int value) {
  typename Container::iterator middle = begin + ((end - begin) / 2);

  if (begin >= end)
    return end;

  if (std::distance(begin, end) == 1 && f(*middle, value))
    return middle;

  if (*middle > value)
    return binarySearch<Container>(begin, middle, f, value);

  return binarySearch<Container>(middle + 1, end, f, value);
}

template <typename Container> Container parseInput(int argc, char *argv[]) {
  int i = 0;
  int numOne;
  int numTwo;
  Container elements;

  while (i + 1 < argc) {
    numOne = atoi(argv[i]);
    numTwo = atoi(argv[i + 1]);
    elements.push_back(std::make_pair(numOne, numTwo));
    i += 2;
  }

  return elements;
}

template <typename Container> void sortInputPairWise(Container &elements) {
  typename Container::size_type i = 0;

  while (i < elements.size()) {
    if (elements[i].first < elements[i].second)
      std::swap(elements[i].first, elements[i].second);
    i++;
  }
}

template <typename Container, typename InputContainer>
Container extractMainChain(const InputContainer &input) {
  Container res(input.size());
  typename InputContainer::size_type i = 0;

  while (i < input.size()) {
    res[i] = input[i].first;
    i++;
  }

  return res;
}

template <typename Container> void setPairIndexedInMainChain(Container &pairs) {
  typename Container::iterator begin = pairs.begin();
  typename Container::iterator end = pairs.end();
  typename Container::size_type i = 0;

  while (begin != end) {
    begin->first = i;
    i++;
    begin++;
  }
}

template <typename Container>
void updateIndexes(Container &elements, size_t i) {
  while (i < elements.size()) {
    elements[i].first++;
    i++;
  }
}

template <typename Container, typename PairedType>
void searchAndInsert(Container &mainChain, PairedType &pairs,
                     typename Container::iterator begin,
                     typename Container::iterator end, int value) {

  typename Container::iterator iter =
      binarySearch<Container>(begin, end, isGreaterThanOrEqual, value);
  mainChain.insert(iter, value);

  updateIndexes(pairs, std::distance(begin, iter));
}

template <typename PairedType, typename Type>
Type sort(int argc, char *argv[]) {
  bool isOdd = ((argc) % 2 == 0) ? false : true;
  int straggler;

  if (isOdd)
    straggler = atoi(argv[argc - 1]);

  std::vector<size_t> jacobseq = jacobthalSeq(argc - 1);
  std::vector<size_t>::iterator jacobseqIter =
      (argc - 1 > 3 ? jacobseq.begin() + 2 : jacobseq.begin());

  PairedType pairs = parseInput<PairedType>(argc, argv);

  sortInputPairWise<PairedType>(pairs);

  mergeSort<PairedType>(pairs.begin(), pairs.end());

  Type mainChain = extractMainChain<Type, PairedType>(pairs);
  setPairIndexedInMainChain<PairedType>(pairs);

  size_t i = 0;
  bool pushedJacob = false;

  while (i < pairs.size()) {
    size_t index;
    if (i < *jacobseqIter && pushedJacob == false &&
        *jacobseqIter < pairs.size()) {
      index = *jacobseqIter;
      pushedJacob = true;
      i--;
    } else if (i == *jacobseqIter && pushedJacob == true) {
      i = *jacobseqIter + 1;
      jacobseqIter++;
      pushedJacob = false;
      continue;
    } else {
      index = i;
    }

    typename Type::iterator searchRangeBegin = mainChain.begin();
    typename Type::iterator searchRangeEnd =
        mainChain.begin() + pairs[index].first;

    searchAndInsert(mainChain, pairs, searchRangeBegin, searchRangeEnd,
                    pairs[index].second);
    i++;
  }

  if (isOdd)
    searchAndInsert(mainChain, pairs, mainChain.begin(), mainChain.end(),
                    straggler);

  return mainChain;
}
