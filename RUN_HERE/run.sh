#!/bin/bash
echo "Select Assignment to Run:"
select choice in $(ls Assignments); do
    cd "Assignments/$choice"  # Change directory to the selected assignment
    g++ -o main main.cpp && ./main
    break
done