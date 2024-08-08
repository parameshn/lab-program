#3. MAXIMUM OF 3 NOS.

echo "Enter 3 numbers : "
echo "no 1"
read a 
echo "no 2"
read b
echo "no 3"
read c
l=$a
if [ $b -gt $l ] 
then 
	l=$b
fi
if [ $c -gt $l ]
then
	l=$c
fi
echo "largest of $a $b $c is $l" 
