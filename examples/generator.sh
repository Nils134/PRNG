#!/bin/bash
while IFS= read -r line; do
  
  for number in {1..1000000}
  do
  printf '0%s0000\n' $(echo "scale=8; $RANDOM/32768" | bc )
  done
done
