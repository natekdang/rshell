#!/bin/bash

#tests commands with comments

./bin/rshell << 'EOF'

(echo a && echo b) || (echo c && echo d)

(echo a && (ls || echo b))

(echo a && (ls || echo b) && echo c)

(echo a && (echo || echo) || echo c)

([ src/f ] || echo a) && echo b

((echo a) || echd b) && errorr)

(echo hello))

(echo hello))

echow || (ls && echo yes)

[-d f ] || echo r

echo a && (echo b && (echo c && (echo d && echo e)))

echo a && (echo b && (echo c && (ech || echo out)))   

echo a || (echo d && echo c) && (echo a)

((((((((((((((((((echo a))))))))))))))))))

((((((((((((((((((echo a)))))&& echo b)))))))))))))

((((((((((((((((((echo a)))))&& echo b))))))))))))

((((((((((((((((((echo a))))) && echo c)))))))))))))

(echo a (echo b))

test -e (src/input.txt)

echo a && (echo b && exit)

echo a && (exit && echo cant see me!)

(echo a || echo d) || echo f)

()

()()()()

EOF