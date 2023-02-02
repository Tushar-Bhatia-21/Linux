read -p "Enter the value of N: " n

x=0
y=1
i=2

echo "The fibonacci series is: "

while [ $i -lt $n ]
do
	i=`expr $i + 1`
	z=`expr $x + $y`
	echo "$z"

	x=$y
	y=$z
done

