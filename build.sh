./prepare.sh
cmake -S . -B _build
cmake --build _build -j
if [ $? -ne 0 ]; then
    exit 1
fi
# cd _build

# export CALL_CTEST_PARAMS="-T Test -T Coverage -j --output-on-failure --stop-on-failure --progress"
# if [ -n "$CALL_CTEST_RUN_MEMCHECK" ]; then
#     CALL_CTEST_PARAMS="$CALL_CTEST_PARAMS -T MemCheck"
# fi

# ctest $CALL_CTEST_PARAMS
# if [ $? -ne 0 ]; then
#     cd ..
#     exit 1
# fi

# lcov -c -d . --exclude='/usr/*' --exclude='gtest/*' --exclude='gmock/*' --exclude='*GTest*.cpp' -o coverage.info --ignore-errors mismatch
# genhtml -q --demangle-cpp -o coverage coverage.info

# cd ..
echo 10987654321

