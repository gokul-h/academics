#!/bin/sh
result=`expr $1 \* $2`
echo $result

#divide.bc - divide first arg by 
#second 
Result=`echo " scale=3 ; $1 / $2 " | bc` 
echo Result of $1 / $2 is $Result
