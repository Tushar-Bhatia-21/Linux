#! /bin/bash

read -p"Hi, please enter your name: " name

read -p"Hi $name, What is your age?: " age

read -p"Hi $name, age: $age" 

#ARITHEMETIC OPERATORS

a=5
b=6

echo "$((a+b))"

echo "$((a**b))"

echo "$((a+=2))"

echo "$((a++))"

#Custom var naming

echo ${1}
echo ${2}
echo ${3}

#Password

read -p"Enter your password: " -s Pass

echo $Pass
#Password

read -p"Enter your password: " -s Pass

echo $Pass
#Password

read -p"Enter your password: " -s Pass

echo $Pass
