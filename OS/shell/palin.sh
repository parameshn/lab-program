#6.PALINDROME


echo "enter n"
read n
temp=$n
rev=0
while (( $temp>0 ))
do
	r=$((temp%10))
	rev=$((rev*10+r))
	temp=$((temp/10))
done
if [ $rev = $n ]
then 
	echo "palindrome"
else
	echo "not"
fi