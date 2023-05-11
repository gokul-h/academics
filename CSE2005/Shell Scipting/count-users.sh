#!/bin/sh
#Cout how many users are on the system

who | wc -l
#The who command shows all the users on the system - one per line. 
#The wc -l command prints how many lines it had as input

echo "At `date` there are `who | wc -l` users on the system"

# Identify if an user is using the system
# $1 - Command line argument
who | grep $1