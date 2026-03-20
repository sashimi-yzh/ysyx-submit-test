#!/bin/bash

# $1 is the filelist.f containing the list of .sv files
# $2 is the output directory for the STA results

list=$(cat $1 | grep -v '/' | grep -v 'ram' | grep -v 'Queue' | sed 's/\.sv//' | sort -r)
if [ -z "$list" ]; then
		echo "No valid .sv files found in $1"
		exit 1
fi

echo "$list" | xargs -I {} -P 6 sh -c 'echo "Processing {}"; make sta-area STA_DEST={} > /dev/null; echo "Finished {}"'

results=$(echo "$list" | while read -r file; do
	ls $2 | grep "$file" | xargs -I {} cat "$2/{}/synth_stat.txt" | grep 'area' | awk -F"'" '!seen[$2]++ {
			name=$2
			gsub(/^\\/, "", name)
			area=$NF
			gsub(":", "", area)
			print name, area
	}' 
done)
uniq_result=$(echo "$results" | sort -k2 -nr | column -t | uniq)
echo "$uniq_result"
echo "$uniq_result" | awk '{print $1 "," $2}' > "$2/all_area.csv"
