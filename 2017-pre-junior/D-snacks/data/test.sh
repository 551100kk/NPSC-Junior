#!/bin/bash

exe=$1
path=$2
in=$3
out=$4

list=$(ls $path | grep $in)

counter=0
red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`
for input in $list
do
    counter=$((counter + 1))
    output=${input/.$in/.$out}
    runtime=$(time ($exe < $path/$input > tmp) 2>&1)
    runtime=$(echo "$runtime" | grep real)
    res=$(diff tmp $path/$output)
    if [[ $res != "" ]]
    then
        echo "${red}WA: $input $output $runtime${reset}"
        break
    else
        echo "${green}AC: $input $output $runtime${reset}"
    fi
done

