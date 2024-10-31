#!/bin/zsh
sortsArray=("bubble" "counting" "heap" "insertion" "merge" "quick" "radix" "selection" "shell")
numberArray=(100 1000 10000 100000)
if [ -d "./results/heap" ]; then
  for i in ${sortsArray[@]}; do
    rm -rf ./results/$i
  done 
fi

for i in ${sortsArray[@]}; do
  for j in ${numberArray[@]}; do
    mkdir -p ./results/$i/Reverse/$j
    touch ./results/$i/Reverse/$j/result.out
    mkdir -p ./results/$i/Sorted/$j
    touch ./results/$i/Sorted/$j/result.out
    mkdir -p ./results/$i/Random/$j
    touch ./results/$i/Random/$j/result.out
  done
done 

for i in ${sortsArray[@]}; do
  echo "testando" $i
  for j in ${numberArray[@]}; do
    echo "Numero de casos" $j
    ./src/main $i < ./testcases/Sorted/test-$j.in > ./results/$i/Sorted/$j/result.out
    echo "Sorted foi"
    ./src/main $i < ./testcases/Reverse/test-$j.in > ./results/$i/Reverse/$j/result.out
    echo "Reverse foi"
    for k in {1..10}; do
      ./src/main $i < ./testcases/Random/$j/test-$k.in >> ./results/$i/Random/$j/result.out
      echo "Random" $k "foi"
    done
  done
done 
