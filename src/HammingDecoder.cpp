#include "HammingDecoder.h"

// |bit|p1|p2|d1|p3|d2|d3|d4|
// |---|--|--|--|--|--|--|--|
// |pos|6 |5 |4 |3 |2 |1 |0 |
uint8_t decode(const unsigned int number)
{
  std::vector<unsigned int> b(7);
  for(unsigned int i = 0; i < 7; ++i)
  {
    b[i] = (number >> i) & 1u;
  }

  // Вычисление синдрома
  auto s1 = b[6] ^ b[4] ^ b[1] ^ b[0];
  auto s2 = b[5] ^ b[4] ^ b[1] ^ b[0];
  auto s3 = b[3] ^ b[2] ^ b[1] ^ b[0];
  auto z = (s1 << 2u) | (s2 << 1u) | s3;
  switch (z) // исправляются только ошибки в информационных битах
  {
    case 3u:
      b[4] ^= 1u;
      break;
    case 5u:
      b[2] ^= 1u;
      break;
    case 6u:
      b[1] ^= 1u;
      break;
    case 7u:
      b[0] ^= 1u;
      break;
    default:
      break;
  }

  b[4] <<= 3u;
  b[2] <<= 2u;
  b[1] <<= 1u;
  return static_cast<uint8_t>(b[4] | b[2] | b[1] | b[0]);
}

std::vector<uint8_t> HammingDecoder::decode(const std::vector<uint8_t> &data)
{
  auto result = std::vector<uint8_t>();
  result.reserve(std::size(data));
  for (const auto &element : data)
    result.push_back(::decode(element));
  return result;
}
