#!/bin/bash

# Build the program
make

# Run the program with input 10 and capture output
echo "Running Fibonacci test with input 10..."
output=$(./fibo 10)
expected_output="55"

if [[ $output =~ $expected_output ]]; then
    echo "Test passed for input 10"
else
    echo "Test failed for input 10"
    echo "Expected: $expected_output"
    echo "Got: $output"
    exit 1
fi

# Run the program with input 5 and capture output
echo "Running Fibonacci test with input 5..."
output=$(./fibo 5)
expected_output="5"

if [[ $output =~ $expected_output ]]; then
    echo "Test passed for input 5"
else
    echo "Test failed for input 5"
    echo "Expected: $expected_output"
    echo "Got: $output"
    exit 1
fi

# Run the program with input 15 and capture output
echo "Running Fibonacci test with input 15..."
output=$(./fibo 15)
expected_output="610"

if [[ $output =~ $expected_output ]]; then
    echo "Test passed for input 15"
else
    echo "Test failed for input 15"
    echo "Expected: $expected_output"
    echo "Got: $output"
    exit 1
fi

# Clean up after tests
make clean

echo "All tests passed!"