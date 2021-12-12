#!/bin/bash

i=1

while [[ i -le 8 ]]
do
	cat ./ressources/test0$i.htr | ./hotrace > our.log
	cat ./ressources/test0$i.htr | ./hotbase > base.log
	diff -y --suppress-common-line our.log base.log #> diff$i.log
	echo "done $i"
	i=$((i + 1))
done
