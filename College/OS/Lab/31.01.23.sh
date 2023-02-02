# Display Working Directory
var=$(pwd)
echo $var

echo""

#DATE-TIME

now="$(date +'%d/%T')"
echo "$now"


#Creating a Constant variable

Name=Tushar
echo $Name
readonly $Name

echo ""
#New Assignment
Name=ABC
echo $Name

#String Display
string='Hi my name is Tushar'
echo $string
echo ""

#String UPPERCASE
STRING='This is a string'
echo $STRING

echo ${STRING^^}

#String LOWERCASE

name=ABC
echo ${name,,}

#Print Specific char in a string

String='HI THIS IS A TEST'
echo ${String:15}

