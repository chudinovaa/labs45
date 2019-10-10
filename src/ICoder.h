#ifndef LAB4_ICODER_H
#define LAB4_ICODER_H

#include <cstdint>
#include <vector>

class ICoder
{
public:
  virtual std::vector<uint8_t> encode(const std::vector<uint8_t> &data) = 0;
};

#endif //LAB4_ICODER_H
