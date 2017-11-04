#!/bin/bash

#tests commands with comments

./bin/rshell << 'EOF'

echo hello #comment

ls #comment

#comment

echo hello again ##comment

##

rm #comment?

touch #morefiles

#heeeeeeloo0000000


EOF