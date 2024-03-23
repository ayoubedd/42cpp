#include <cstddef>
#include <vector>

bool isGreaterThanOrEqual(int one, int two) { return one >= two; }

static size_t jacobthal(size_t nth) {
  if (nth == 0)
    return 0;

  if (nth == 1)
    return 1;

  return jacobthal(nth - 2) * 2 + jacobthal(nth - 1);
}

std::vector<size_t> jacobthalSeq(size_t size) {
  std::vector<size_t> res;

  size_t i = 0;

  while (true) {
    size_t value = jacobthal(i);
    res.push_back(value);
    if (value >= size)
      break;
    i++;
  }

  return res;
}
