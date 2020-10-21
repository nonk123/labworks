#!/usr/bin/env bash

# Package a labwork into a .zip with the following structure:
#
# L1.zip
# `-- Z1_1
#   `-- Z1_1.cpp
#   `-- P1_1.dev
# `-- Z1_2
#   `-- Z1_2.cpp
#   `-- P1_2.dev
# ...

# $1 - labwork to package.

LAB=$1

if [[ -z "$LAB" ]]; then
    echo 'Supply argument $1'
    exit 1
fi

TMP=tmp/$LAB/

rm -f "$LAB.zip"
mkdir -p "$TMP"

for task in $LAB/*; do
    # Skip stuff that isn't solutions.
    [[ "$task" != */Z*.cpp ]] && continue

    task=${task##*/}
    TASK_DIR=$TMP/${task%*.cpp}/

    mkdir -p "$TASK_DIR"

    # Convert to cp1251 to display Cyrillic.
    iconv -t cp1251 "$LAB/$task" > "$TASK_DIR/$task"
    iconv -t cp1251 portability.hpp > "$TASK_DIR/portability.hpp"

    # Extension is no longer needed.
    task=${task%.cpp}

    # Generate the project file by substituting ## values in the template.
    PROJECT=$TASK_DIR/$task.dev
    cp template.dev "$PROJECT"

    sed -i "s/##lab##/${LAB#L}/g" "$PROJECT"
    sed -i "s/##task##/${task#*_}/g" "$PROJECT"
done

# Workaround for excluding the parent directory, =tmp=.
cd tmp
zip -r ar.zip "$LAB"
cd ..

mv tmp/ar.zip "$LAB.zip"

rm -rf tmp/
