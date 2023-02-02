echo "Enter the first number: "
read num1
echo $num1
echo ""

echo "Enter the second number: "
read num2
echo $num2
echo ""

echo "Press 1. To add"
echo ""
echo "Press 2. To subtract"
echo ""
echo "Press 3. To multiply"
echo ""
echo "Press 4. To Divide"
echo ""
read x

case $x in
	"1") echo "$((num1+num2))"
		;;
	"2") echo "$((num1-num2))"
		;;
	"3") echo "$num1*$num2" | bc
		;;
	"4") echo "$num1/$num2" | bc
		;;
	esac

