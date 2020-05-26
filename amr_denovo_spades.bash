#!/bin/bash

#foler is FASTQ folder which inlcudes all files for each isolates 
folder=/Users/Yan/basespace/Run1/AMR_Run1-170288118/FASTQ_Generation_2020-05-22_11_24_13Z-252951699
#cd $folder
foldername=`ls $folder`
for each in $foldername # read each folder 
do
	dir=$each
	cd $folder/$dir #change directory to the working folder 
	ls  >  name.txt
	while read line
	do
		if [[ $line == *"R1"* ]]
		then
			filename1=$line
		fi
		if [[ $line == *"R2"* ]] 
		then
			filename2=$line
		fi
	done < name.txt
	echo $filename1 $filename2
	spades.py -1 $filename1 -2 $filename2 -o assemble
done


