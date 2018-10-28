#!/bin/bash

for (( i = 0; i < 10; i++ )); do
    ./genInt $1
    ./testInsert $1
    echo
done
