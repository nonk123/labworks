#!/usr/bin/env bash

# Payload for make-screenshot.sh, started with `xterm`.

# $1 - task file (.cpp).
# $2 - output image file.
# $3 - input file.

## Imitate a real terminal.

# This has to be done.
source ~/.bashrc

# Print the PS1 prompt as if we're in the task directory.
PWD=${1##*/} printf "%s" "${PS1@P}"

# "Enter" compilation command.
echo "g++ -I. $1 && ./a.out"

## Compile and run.

compilation_output=$(mktemp -t "Z_XXXXXX.out")

g++ -I. -o $compilation_output "$1"

if (($? == 0)); then
    # Compilation succeeded. Start the program.

    input_interval=0.8

    # Print each line, with a small delay.
    while read line; do
        sleep $input_interval
        # Make the line visible in the terminal.
        echo "$line" > /dev/stderr
        echo "$line"
    done < "$3" | $compilation_output
else
    # Let the user see the error message.
    sleep 10
    exit 1
fi

# $WINDOWID = ID of the XTerm window, set by it.
maim -f png -g 500x500 -i $WINDOWID > "$2"
