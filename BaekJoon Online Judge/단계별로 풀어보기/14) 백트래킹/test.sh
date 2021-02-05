#!/bin/bash

echo "Problem 15649_3"
for i in $(seq 1 11)
do
    echo "Input : $i $i"
    for x in $(seq 1 5)
    do
        echo "$i $i" | ./15649_3
    done
done



