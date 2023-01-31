var=$(pwd)
echo $var

echo""

#DATE-TIME

now="$(date +'%d/%T')"
echo "$now"


#For Const only

Name=Tushar
echo $Name
readonly $Name

echo ""
#New Assignment
Name=Tushar
echo $Name

#String
string='Hi my name is Tushar'
echo $string
echo ""

#FOR UPPERCASE
STRING='This is a string'
echo $STRING

echo ${STRING^^}

#FOR LOWERCASE

name=ABC
echo ${name,,}

#Print Specific char in a string

String='HI THIS IS A TEST'
echo ${String:15}






