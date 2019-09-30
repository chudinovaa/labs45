add_executable(hamming-coder-test HammingCoderTest.cpp)
target_link_libraries(hamming-coder-test hamming-coder gtest gtest_main Threads::Threads)
add_test(hamming-coder-test hamming-coder-test)

add_executable(hamming-decoder-test HammingDecoderTest.cpp)
target_link_libraries(hamming-decoder-test hamming-decoder gtest gtest_main Threads::Threads)
add_test(hamming-decoder-test hamming-decoder-test)
