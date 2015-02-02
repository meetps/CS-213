#!/bin/bash
rm Entry_Logs.txt
rm Exit_Logs.txt
g++ assignment1_b.cpp -o input_generator
./input_generator < input_sizes.txt
g++ assignment1_a.cpp -o sort
./sort > output_logs.txt
cat output_logs.txt