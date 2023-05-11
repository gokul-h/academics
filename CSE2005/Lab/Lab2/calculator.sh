#!/bin/sh
# Calculator
echo "Calculator"
echo "Enter two numbers"
read a 
read b
echo "Select an Operation"
echo "1 - Addition"
echo "2 - Subtraction"
echo "3 - Multiplication"
echo "4 - Division"
echo "5 - Modulus"
read option

#Switch
case $option in 
    1)
        result=`expr $a + $b`;;
    2)
        result=`expr $a - $b`;;
    3)
        result=`expr $a \* $b`;;
    4)
        result=`echo " scale=3 ; $a / $b " | bc`;;
    5)
        result=`expr $a % $b`;;
esac

echo "The Result is $result"   