#!/bin/bash
for D in *; do
	cd "$D";
	if [ -d src ]; then
		if [ -f src/**/*.java ]; then
		mv src/**/*.java $D.java;
		fi
		find . -type f ! -name '*.java' -delete
		rm -r */
		echo "Updated Folder $D, Currect files $(ls)";
	else
		if [ ! -f *.java ]; then
		echo "				Unable to find files in $D";
		fi
	fi
	cd ..;
done

