#!/bin/bash


backup_dir="backups"
mkdir -p "$backup_dir"

Time=(date +%Y%m%d_%H%M%S)


for dir in "$@"; do

    if [ -d "$dir" ]; then

        backup_filename="backup_$Time.tar.gz"
        tar -czf "$backup_dir/$backup_filename" "$dir"

        echo "Done"
    else
        echo "Error"
    fi
done
