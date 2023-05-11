#!/bin/sh 
echo "Hello ${Name-Sir/Madam}, have a nice day" 
#Name="gokul"
echo "Hello ${Name=Sir/Madam}, have a nice day"
wordprefect ${WPTERM?"WPTERM not set, cannot run wordprefect"}
echo "Thank you $Name for doing something"
# Shell Programming in 24 hours 
echo "Present time is `date`"
echo "Present time is $(date +%Y)"
# Dont add unecessary spaces as result might get altered
Date=`date`
echo $Date