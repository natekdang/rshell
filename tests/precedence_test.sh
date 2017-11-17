#!/bin/bash

#tests commands with comments

./bin/rshell << 'EOF'

(echo a && echo b) || (echo c && echo d)

(echo a && (ls || echo b))

(echo a && (ls || echo b) && echo c)

(echo a && (echo || echo) || echo c)

EOF