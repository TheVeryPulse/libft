#! /usr/bin/bash

exec=ftprintf_test

cc ftprintf_test.c -I../inc -L../lib -lft -o ../bin/$exec

# Run your program and capture its output
output=$(../bin/$exec)

# Define the expected output
expected_output="ft_printf test"

# Compare the actual output with the expected output
if [ "$output" == "$expected_output" ]; then
    echo "OK!"
else
    echo "KO!"
fi
rm ../bin/$exec
