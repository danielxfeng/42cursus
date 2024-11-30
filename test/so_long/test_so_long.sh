#!/bin/bash

SRC_DIR="./src/so_long/"
TEST_DIR="./test/so_long/"
MAP_DIR="${TEST_DIR}/maps"
EXECUTABLE="${TEST_DIR}/so_long"

echo "Building project..."
make -C "${SRC_DIR}"
if [[ $? -ne 0 ]]; then
    echo "Build failed. Exiting."
    exit 1
fi

if [[ -f "${SRC_DIR}/so_long" ]]; then
    echo "Moving ${SRC_DIR}/so_long to ${EXECUTABLE}..."
    mv "${SRC_DIR}/so_long" "${EXECUTABLE}"
else
    echo "Executable not found in ${SRC_DIR}. Exiting."
    exit 1
fi

echo "Testing maps..."
for map in "${MAP_DIR}"/*; do
    echo "----------------------------------------"
    echo "Testing map: ${map}"
    echo "----------------------------------------"

    valgrind --leak-check=full --show-leak-kinds=all \
        "${EXECUTABLE}" "${map}"

    if echo "$valgrind_output" | grep -q "ERROR SUMMARY: [^0]"; then
        echo "$valgrind_output"
        echo "Valgrind reported errors for map: ${map}"
    elif [[ $valgrind_exit_code -ne 0 ]]; then
        echo "Program exited with status $valgrind_exit_code for map: ${map}"
    else
        echo "$valgrind_output"
        echo "Mem test passed for map: ${map}"
    fi
done

echo "----------------------------------------"
echo "Testing complete."
