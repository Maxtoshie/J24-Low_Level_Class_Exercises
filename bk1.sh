#!/bin/bash

# Check argument
if [ -z "$1" ]; then
    echo "Usage: mycc filename.c"
    exit 1
fi

filename=$(basename "$1" .c)

mkdir -p bin
gcc "$1" -o "./$filename"

echo "Executable created: ./$filename"
