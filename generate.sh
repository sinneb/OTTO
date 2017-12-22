#!/bin/bash

otto_dir=$1

standardese --config $otto_dir/.standardese $(find $otto_dir/src -name "*.hpp" | sed "s/\n/ /")

find . -name "doc_*.html" -exec ./format.sh {} \;

./format.sh standardese_entities.html
./format.sh standardese_modules.html
./format.sh standardese_files.html

mv standardese_entities.html index.html
mv standardese_files.html files.html
mv standardese_modules.html modules.html

