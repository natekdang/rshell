#!/bin/bash

#tests single commands


#This may or may not break things
./bin/rshell << 'EOF' 

echo hello

echo hello;

echo hello my darling, hello my ragtime gal

ls

ls;

cat main.cpp

pwd

ls;;;;

ls -a

ls |

echo why are we here; echo just to suffer?

echo snaaaaaaakeeeeeeeee

touch a.txt

rm a.txt

exewf

touch g.txt

cat g.txt

EOF




