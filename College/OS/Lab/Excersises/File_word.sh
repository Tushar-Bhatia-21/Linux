echo "Enter the file name: "

read fname

echo "Enter the starting line number: "
read s

echo "Enter the ending line number: "
read n

sed -n $s,$n\p $fname | cat>newline

cat newline


