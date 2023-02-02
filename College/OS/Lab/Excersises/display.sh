echo Directory
for item in *
do
	if [ -d $item ]
	then 
		echo $item
	fi
done
echo file
for item in *
do
	if [ -f $item ]
	then 
		echo $item
	fi
done



