# Text Encryption Practice

This repository contains a C++ program that demonstrates a simple encryption technique by shifting the characters in each word of a given sentence based on a predefined encryption key.

## Overview

The program performs the following steps:
1. Splits the input sentence into words.
2. Shifts each word according to the encryption key.
3. Outputs the encrypted sentence.

## Encryption Key

The encryption key is a vector of pairs, where each pair consists of:
- The length of the word (or 0 for words longer than 4 characters).
- The number of characters to shift to the left.

Example encryption key:
```cpp
std::vector<std::pair<int, int>> key = { {1, 0}, {2, 1}, {3, 2}, {4, 1}, {0, 3} };
