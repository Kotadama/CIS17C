#!/bin/bash
echo "Select Assignment to Run:"
select choice in "Assignment0A" "Assignment0B"; do
    cd $choice  # Change directory to the selected assignment
    g++ -o main main.cpp && ./main
    break
done
