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
LAB_NUMBER=${LAB#L}

if [[ -z "$LAB" ]]; then
    echo 'Supply argument $1'
    exit 1
fi

# Directory with the file structure of the archive.
OUTPUT_DIR=tmp/$LAB/

rm -f "$LAB.zip"
mkdir -p "$OUTPUT_DIR"

for task in $LAB/*; do
    # Include the report in the archive.
    if [[ "$task" = */report.doc ]]; then
        cp "$task" "$OUTPUT_DIR/Отчёт по работе №${LAB_NUMBER}.doc"
    fi

    # Skip stuff that isn't solutions.
    [[ "$task" != */Z*.cpp ]] && continue

    task=${task##*/}
    task_dir=$OUTPUT_DIR/${task%*.cpp}/

    mkdir -p "$TASK_DIR"

    # Convert to cp1251 to display Cyrillic.
    iconv -t cp1251 "$LAB/$task" > "$TASK_DIR/$task"
    iconv -t cp1251 portability.hpp > "$TASK_DIR/portability.hpp"

    # Extension is no longer needed.
    task=${task%.cpp}

    # Generate the project file by substituting ##var## in the template.

    project=$task_dir/$task.dev
    cp template.dev "$project"

    sed -i "s/##lab##/${LAB_NUMBER}/g" "$project"
    sed -i "s/##task##/${task#*_}/g" "$project"
done

# Workaround for excluding the parent directory, tmp.
cd tmp
zip -r ar.zip "$LAB"
cd ..

mv tmp/ar.zip "$LAB.zip"

rm -rf tmp/
