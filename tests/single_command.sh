#!/bin/bash

#tests single commands

./a.out << EOF
echo hello world, what a lovely day
EOF

./a.out << EOF
ls
EOF



