#!/bin/bash

#tests commands with comments

./bin/rshell << 'EOF'

test -e input.txt

test input.txt

test -f input.txt

test -d input.txt

test input.teeext

test -e

test -e echo hello

test -f input.txt && echo file exists

test -d inrf.txt || echo file does not exist


EOF