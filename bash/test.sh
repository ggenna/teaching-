#!/bin/bash
for i in $*
 do
	if [ $i = "FOLD" ]
	then
		 echo "NIENTE"	
		 
	else
	   touch $i
	fi
done