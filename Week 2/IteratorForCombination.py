/*
Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
*/

from itertools import combinations
class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        
        self.char = list(map(str, characters))
        self.arr = list(combinations(self.char, combinationLength))

    def next(self) -> str:
        return ''.join(self.arr.pop(0))

    def hasNext(self) -> bool:
        return len(self.arr) > 0 
