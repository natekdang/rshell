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

#(test src)

[ -d src ] #test

[ -f src # test ]

(echo a && echo b) && (echo b && # echoooo)

########

echo #####

### echo a

# echo a #

## echo a ##

EOF