# Summary

The goal of this project is to recreate a command shell in C++. This command shell is known as rshell. It can take commands and chain them using && (and) and || (or). 

We parsed the user input using the Boost tokenizer and converted the tokens into a postfix notation. Our connectors (;, ||, &&) served as the operators for our tree. The commands and their arguments make up the operands.

We implemented a postfix binary tree to handle commands and connectors.  

## How to Use

## Known Bugs

## Authors

Mark Zemlany
mzeml001@ucr.edu

Nathan Dang
ndang008@ucr.edu

## License

This project is licensed under the BSD-3-Clause license. See the LICENSE.md file for details


