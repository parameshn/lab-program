#!/bin/bash
#4a) Write a shell program to Read two matrices , find addition and display 
#the input matrices and resultant in matrix format
echo "Enter the number of rows: "
read row 
echo "Enter the number of columns: "
read col

echo "Enter the elements of the first matrix:"
for ((i = 0; i < row; i++)); do
    for ((j = 0; j < col; j++)); do
        read mat1[$i,$j]
    done
done

echo "Enter the elements of the second matrix:"
for ((i = 0; i < row; i++)); do
    for ((j = 0; j < col; j++)); do
        read mat2[$i,$j]
    done
done

for ((i = 0; i < row; i++)); do
    for ((j = 0; j < col; j++)); do
        sum[$i,$j]=$((mat1[$i,$j] + mat2[$i,$j]))
    done
done

echo "Sum of matrices is:"
for ((i = 0; i < row; i++)); do
    for ((j = 0; j < col; j++)); do
        echo -n "${sum[$i,$j]} "
    done
    echo ""
done
