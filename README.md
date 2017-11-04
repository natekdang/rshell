# Summary

The goal of this project is to recreate a command shell in C++. This command shell is known as rshell. It can take commands and chain them using the connectors: '&&' (and), '||' (or), ';' (semicolon). 

We parsed the user input using the Boost tokenizer and converted the tokens into a postfix notation in order for our binary tree implementation to work. Our connectors (;, ||, &&) served as the operators for our tree (internal nodes). The commands and their arguments make up the operands (leaves).

Once we had our tokens in postfix notation we iterated through the vector of tokens and converted each token into either an Executable (Command/Exit) object or a Connector (And/Or/Semicolon) object, and used the postfix binary tree algorithm in order to build our tree.  

Once our tree was built we called execute() on the root of the tree, which will iterate through the entire tree calling execute() on all the nodes in the desired order.  



## How to Use

Input bash commands on a single line. Seperate commands using connectors:

|| == OR, if the left command fails the right command executes
&& == AND, if left command succeeds, then right command executes
; == Next command executes

exit == exits the command line

## Known Bugs

As of right now, ending a command with a connector is not valid. Connectors cannot be leading, ending, or consecutive

exit(0) command causes 5 possible blocks of memory leakage

If you echo quotation marks, they are echoed as well


## Authors

Mark Zemlany
mzeml001@ucr.edu

Nathan Dang
ndang008@ucr.edu

## License

This project is licensed under the BSD-3-Clause license. See the LICENSE.md file for details


