#!/bin/bash

echo "Problem Solving Start!"
mkdir $1 && cd $1 && echo "// BOJ $1번: $2" >> $1.cpp && code $1.cpp