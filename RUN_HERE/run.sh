#!/bin/bash

# Step 1: Select Assignment Folder
echo "Select an Assignment Folder:"
folders=()
index=1

# Populate folders array manually
for dir in Assignments/*/; do
    if [[ -d "$dir" ]]; then
        folders+=("$(basename "$dir")")
        echo "$index) $(basename "$dir")"
        ((index++))
    fi
done

# Read user input
read -p "#? " folder_index

# Validate selection
if (( folder_index < 1 || folder_index > ${#folders[@]} )); then
    echo "Invalid selection. Exiting."
    exit 1
fi

# Get selected folder
folder="${folders[$((folder_index - 1))]}"

# Step 2: Select Assignment Inside Folder
echo "Select a Project within $folder:"
projects=()
index=1

# Populate projects array manually
for dir in Assignments/"$folder"/*/; do
    if [[ -d "$dir" ]]; then
        projects+=("$(basename "$dir")")
        echo "$index) $(basename "$dir")"
        ((index++))
    fi
done

# Read user input
read -p "#? " project_index

# Validate selection
if (( project_index < 1 || project_index > ${#projects[@]} )); then
    echo "Invalid selection. Exiting."
    exit 1
fi

# Get selected project
project="${projects[$((project_index - 1))]}"

# Step 3: Compile and Run
cd "Assignments/$folder/$project" || { echo "Failed to enter directory"; exit 1; }

if [[ -f main.cpp ]]; then
    g++ -o main main.cpp && ./main
else
    echo "Error: main.cpp not found in $project"
fi
``
