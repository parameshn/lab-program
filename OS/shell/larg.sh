#7.LARGEST NO IN AN ARRAY

echo "Enter the no. of elements: "
read n
echo "Enter the numbers: "
for(( i=0;i<n;i++ ))
do
	read num
	array[i]=$num
done
largest=${array[0]}
for(( i=1;i<n;i++ ))
do
	if [ ${array[i]} -gt $largest ]
	then
		largest=${array[i]}
	fi
done
echo "the largest number is: $largest"