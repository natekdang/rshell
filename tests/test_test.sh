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

test -d src/input.txt

[ -e input.txt ]

[ input.txt ]

[ -f input.txt ]

[ -f input.txt ]

[ -f src\input.txt ]

[ -e src\input.txt ]

[ -d src\input.txt ]

[ src\input.txt ]

[src\input.txt]

test

[]

[ ]

[ src/a.out ]

EOF