#include <cmath>
#include "HammingCoder.h"

uint8_t encode(const unsigned int number)
{
  auto d1 = number >> 3u & 1u;
  auto d2 = number >> 2u & 1u;
  auto d3 = number >> 1u & 1u;
  auto d4 = number & 1u;
  auto p1 = d1 ^d2 ^d4;
  auto p2 = d1 ^d3 ^d4;
  auto p3 = d2 ^d3 ^d4;
  p1 <<= 6u;
  p2 <<= 5u;
  d1 <<= 4u;
  p3 <<= 3u;
  d2 <<= 2u;
  d3 <<= 1u;
  return static_cast<uint8_t>(p1 | p2 | p3 | d1 | d2 | d3 | d4);
}

std::vector<uint8_t> HammingCoder::encode(const std::vector<uint8_t> &data)
{
  auto result = std::vector<uint8_t>();
  result.reserve(std::size(data));
  for (const auto &element : data)
    result.push_back(::encode(element));
  return result;
}
