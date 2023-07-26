#!/bin/bash

# given directory
dir_path="/home/`whoami`/Projects/Simulator"

# function to handle each file
handle_file() {
  local file_path="$1"
  if [[ "$file_path" == *".cpp" || "$file_path" == *".hpp" ]]; then
    echo "formatting $file_path"
    clang-format -i --style=WebKit $file_path
  fi
}

# function to handle each directory
handle_dir() {
  local dir_path="$1"
  local sub_path
  for sub_path in "$dir_path"/*; do
    if [ -d "$sub_path" ]; then
      if [[ "$sub_path" != *"/submodules"* && "$sub_path" != *"/build"* ]]; then
        handle_dir "$sub_path" "$style"
      fi
    elif [ -f "$sub_path" ]; then
      handle_file "$sub_path" "$style"
    fi
  done
}

handle_dir "$dir_path"