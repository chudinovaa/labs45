#ifndef LAB4_IDECODER_H
#define LAB4_IDECODER_H

#include <cstdint>
#include <vector>

class IDecoder
{
  virtual std::vector<uint8_t> decode(const std::vector<uint8_t> &data) = 0;
};

#endif //LAB4_IDECODER_H
