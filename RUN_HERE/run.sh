#!/bin/bash

# Step 1: Select Assignment Folder
echo "Select an Assignment Folder:"
folders=()
index=0  # Start from 0

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
if (( folder_index < 0 || folder_index >= ${#folders[@]} )); then
    echo "Invalid selection. Exiting."
    exit 1
fi

# Get selected folder
folder="${folders[$folder_index]}"

# Step 2: Check if the selected folder has subfolders (projects)
echo "Checking for subfolders in $folder..."
projects=()
index=1

# Check for subfolders (projects) in the selected folder
for dir in Assignments/"$folder"/*/; do
    if [[ -d "$dir" ]]; then
        projects+=("$(basename "$dir")")
        echo "$index) $(basename "$dir")"
        ((index++))
    fi
done

# If no subfolders are found, directly compile the files in the selected folder
if (( ${#projects[@]} == 0 )); then
    echo "Compiling .cpp files in $folder directly."
    cd "Assignments/$folder" || { echo "Failed to enter directory"; exit 1; }
    cpp_files=(*.cpp)
    if (( ${#cpp_files[@]} == 0 )); then
        echo "No .cpp files found in $folder"
        exit 1
    fi
    g++ -o main "${cpp_files[@]}" && ./main
    exit 0
fi

# Step 3: If subfolders (projects) exist, select a project
echo "Select a Project within $folder:"
read -p "#? " project_index

# Validate selection
if (( project_index < 1 || project_index > ${#projects[@]} )); then
    echo "Invalid selection. Exiting."
    exit 1
fi

# Get selected project
project="${projects[$((project_index - 1))]}"

# Step 4: Compile and Run the selected project
cd "Assignments/$folder/$project" || { echo "Failed to enter directory"; exit 1; }
cpp_files=(*.cpp)

# Check if there are .cpp files
if (( ${#cpp_files[@]} == 0 )); then
    echo "No .cpp files found in $project"
    exit 1
fi

# Compile all .cpp files together
g++ -o main "${cpp_files[@]}" && ./main
