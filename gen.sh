#!/bin/zsh
num=$@
if [ -d "./testcases/Random/$num" ]; then
  rm -rf ./testcases/Random/$num
fi

if [ ! -f "./testcases/Inverse/test-$num.in" ]; then
  touch ./testcases/Ordered/test-$num.in
  touch ./testcases/Inverse/test-$num.in

  for ((i = 1; i <= $num; i ++)) do
    echo $i >> ./testcases/Ordered/test-$num.in
  done

  for ((i=$num; i > 0; i --)) do
    echo $i >> ./testcases/Inverse/test-$num.in
  done

fi

mkdir ./testcases/Random/$num
for ((i = 1; i <= 10; i ++)) do
  touch ./testcases/Random/$num/test-$i.in
  shuf -i 1-$num -n $num > ./testcases/Random/$num/test-$i.in
done
