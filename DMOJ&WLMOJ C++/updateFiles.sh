#!/bin/bash
for D in *; do
	cd "$D";
	if [ -f *.cpp ]; then
	# 	if [ -f src/**/*.java ]; then
	# 	mv src/**/*.java $D.java;
	# 	fi
		mv *.cpp $D.cpp;
		find . -type f ! -name '*.cpp' -delete
		# find . -type d -delete
		rm -r */
		echo "Updated Folder $D, Currect files $(ls)";
	elif [ -d src ]; then
		mv src/*.cpp $D.cpp;
		find . -type f ! -name '*.cpp' -delete
		# find . -type d -delete
		rm -r */
		echo "Updated Folder $D, Currect files $(ls)";
	else
		if [ ! -f *.cpp ]; then
		echo "				Unable to find files in $D";
		fi
	fi
	cd ..;
done

