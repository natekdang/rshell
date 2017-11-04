#!/bin/bash

#tests commands with ;, &&, or ||

./bin/rshell << 'EOF'
echo hello; echo goodbye

echu error || echo you should see me!

ecoh error && echo but not me

echo a || echo b || echo c

ls && echo lsworked || exit; echo testing

failm && echo 3 || echo 4; echo should work

touch a.txt b.txt c.txt d.txt 

rm a.txt b.txt c.txt d.txt

EOF