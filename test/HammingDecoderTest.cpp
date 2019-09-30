#include <src/HammingDecoder.h>

#include <gtest/gtest.h>

class HammingDecoderTest : public ::testing::Test
{
public:
  HammingDecoder m_instance;
};

TEST_F(HammingDecoderTest, testDecode_empty)
{
  ASSERT_TRUE(m_instance.decode({}).empty());
}

TEST_F(HammingDecoderTest, testDecode_full)
{
  std::vector<uint8_t> data = {
    0b0000000, 0b1101001, 0b0101010, 0b1000011, 0b1001100, 0b0100101, 0b1100110, 0b0001111,
    0b1110000, 0b0011001, 0b1011010, 0b0110011, 0b0111100, 0b1010101, 0b0010110, 0b1111111
  };
  std::vector<uint8_t> expected = {
    0b0000, 0b0001, 0b0010, 0b0011, 0b0100, 0b0101, 0b0110, 0b0111,
    0b1000, 0b1001, 0b1010, 0b1011, 0b1100, 0b1101, 0b1110, 0b1111
  };
  const auto result = m_instance.decode(data);
  ASSERT_EQ(expected, result);
}

TEST_F(HammingDecoderTest, testDecode_errorFix)
{
  std::vector<uint8_t> data = {
    0b1101001, 0b1101001, 0b1101001, 0b1101001, 0b1101001, 0b1101001, 0b1101001
  };
  std::vector<uint8_t> expected = {
    0b0001, 0b0001, 0b0001, 0b0001, 0b0001, 0b0001, 0b0001
  };
  const auto result = m_instance.decode(data);
  ASSERT_EQ(expected, result);
}
