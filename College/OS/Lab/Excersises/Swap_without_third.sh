read -p "Enter the first number: " a

read -p "Enter the second number: " b
echo""
echo "Before swapping"
echo""
echo "First number is: $a"
echo "Second number is: $b"

a=$((a+b))
b=$((a-b))
a=$((a-b))
echo""
echo "After Swapping"
echo""
echo "First number is: $a"
echo "Second number is: $b"
