echo "0Enter the file name: "
read file
echo "Enter the word: "
read word
echo file before removing the word $word:
cat $file
grep -v -i $word $file > test
mv test $file
echo file after removing word $word:
cat $file

