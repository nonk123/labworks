#!/usr/bin/env bash

# Make a screenshot of running a task.
#
# This starts an XTerm process, starts a "payload" script with specified input
# (see below), creates a screenshot of it with `maim`, and puts it inside the
# task's image directory.

# $1 - task file (.cpp) to compile.
# $2 - optional suffix for the output image.
# stdin - task args. Each space is equivalent to pressing Return.

if [[ -z "$1" ]]; then
    echo 'Specify $1'
    exit 1
fi

input=$(mktemp -t "input_XXXXX")

# Write each space-separated argument on its own line.
tr " " "\\n" > $input

output_dir=${1%/*}/img/
mkdir -p "$output_dir"

# For, e.g., L2/Z2_1.cpp, this will become L2/img/Z2_1.png
output=${1##*/}
output=$output_dir/${output%.*}

# Add suffix if it isn't empty.
[[ -n "$2" ]] && output=${output##}_$2

output=${output}.png

xterm -e $PWD/payload.sh "$1" "$output" $input
