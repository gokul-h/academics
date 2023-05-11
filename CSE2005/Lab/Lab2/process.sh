#!/bin/sh
gcc fork.c -o fork
./fork
ps -a
# Kills one of the process created earlier
kill 5658 
ps -a