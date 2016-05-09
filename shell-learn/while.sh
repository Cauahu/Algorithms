#!/bin/bash

counter=0
while [ $counter -lt 5 ] 
do
	counter=`expr $counter + 1`
	echo $counter
done
