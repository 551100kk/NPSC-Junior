#!/bin/bash

prob=$1

red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`

input=testdata/$prob.in
output=testdata/$prob.out

./$prob < $input > tmp

runtime=$(time (./$prob < $input > tmp) 2>&1)
runtime=$(echo "$runtime" | grep real)
res=$(diff tmp $output -b 2>&1)
if [[ $res != "" ]]
then
    echo "${red}WA: $input $output $runtime${reset}"
    # break
else
    echo "${green}AC: $input $output $runtime${reset}"
fi
