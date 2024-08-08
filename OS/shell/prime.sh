#8. PRIME NUMBERS


echo "enter the lower limit"
read l
echo "enter the upper limit"
read u
if [ $u -lt $l ] || [ $u -eq 0 ] || [ $l -eq 0 ]; then
echo "invalid entry"
exit 1
fi
echo "prime numbers between $l and $u are : "
for(( num=l;num<=u;num++ ))
do
	is_prime=1
	for(( i=2;i*i<=num;i++ )) 
	do
		if [ $(( num%i )) -eq 0 ]
		then
			is_prime=0
			break
		fi
	done
	if [ $is_prime -eq 1 ];then
		echo $num
	fi
done