cmake -B ./build-with-coverage -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DCODE_COVERAGE=ON
cmake --build ./build-with-coverage -j 10
ctest --test-dir ./build-with-coverage
find ./build-with-coverage -name "*.gcda" -exec cp {} ./build-with-coverage/coverage-report \;
find ./build-with-coverage -name "*.gcno" -exec cp {} ./build-with-coverage/coverage-report \;
gcovr --exclude tests
gcovr --exclude tests --branches