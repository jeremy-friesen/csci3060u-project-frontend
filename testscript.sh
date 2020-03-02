#!/bin/bash

# clear the previous test results
: > test_results.txt
: > diff_log.txt

cd Test_Cases
transactions=( login logout create delete advertise bid refund addCredit )

# for each transaction to test
for i in "${transactions[@]}"
do
  echo "$i:"
  # for each test case
  for j in $i/inputs/*
  do
    filename=$(basename $j)
    
    # delete the daily transaction file before running program
    : > "$i/test_transactions/$filename"
    touch "$i/test_transactions/$filename"

    # run program with alternate io files
    ../src/a.out currentusers.txt availableitems.txt $i/test_transactions/$filename < $j > $i/test_outputs/$filename
    
    # find if there's a difference between expected output and generated output
    if diff $i/test_outputs/$filename $i/outputs/$filename;
    then
      echo "TEST $filename OUTPUT: GOOD" >> ../test_results.txt
    else
      echo "TEST $filename OUTPUT: BAD" >> ../test_results.txt

      # add diff to diff log
      echo "______________________________________________" >> ../diff_log.txt
      echo "TEST $filename OUTPUT: BAD" >> ../diff_log.txt
      diff $i/test_outputs/$filename $i/outputs/$filename >> ../diff_log.txt
      echo $'\n\n' >> ../diff_log.txt
    fi

    # find if there's a difference between expected transaction file and generated transaction file
    if diff "$i/test_transactions/$filename" "$i/transactions/$filename";
    then
      # ad
      echo "TEST $filename TRANSACTION: GOOD" >> ../test_results.txt
    else
      echo "TEST $filename TRANSACTION: BAD" >> ../test_results.txt

      # add diff to diff_log
      echo "______________________________________________" >> ../diff_log.txt
      echo "TEST $filename TRANSACTION: BAD" >> ../diff_log.txt
      diff $i/test_transactions/$filename $i/transactions/$filename >> ../diff_log.txt
      echo $'\n\n' >> ../diff_log.txt
    fi
  done
done