#! /bin/bash
p=1
s=1
mkdir /test
cd /test
touch 7181nvi.php
cd -
while [ $p -eq $s ]
do
echo "Vedite nazvanie faila"
read name
lines=$(find -name $name | wc -l)
if [ $lines -ne 0 ];
then
echo "Name:" $name
find -name $name -exec stat --format $'Type: %F \n Size: %s \n Vladelec: %U \n Prava dostupa: %A \n Modify: %y' "{}" \;
else
echo "error"
fi
echo "Prodoljit rabotu s programmoi? (1=Y/2=N)"
read p
done
echo "end"
