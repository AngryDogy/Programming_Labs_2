#!/bin/bash
folder=$1
cd $folder
output=report.md
echo "$(cat problem.md)" >> $output
for file in *.cpp
do
    name=$(echo $file)
    data=$(cat $file)
    echo '
## '$name'
``` cpp
'"$data"'
```' \
    >> $output
done
for file in *.h
do
    name=$(echo $file)
    data=$(cat $file)
    echo '## '$name'
``` cpp
'"$data"'
```' \
    >> $output
done
echo "$(cat result.md)" >> $output
