# String matching algorithm
## Overview
This package includes a lot of common string matching algorithms for learning(and for use, sure!). I've already implemented 4 of them, they're:
* Brute force algorithm, with time complexity of __O((n-m+1)m)__ (where n is the length of Target string and m is the length of Pattern string)
* FSM(Finite State Automaton method), with time complexity of __O(m * SIGMA) preprocessing and O(n) matching time__. SIGMA is the length of the charset of T.
* KMP algorithm, with __O(m) amortized preprocessing complexity and O(n) amortized matching time__.
* Shift-and algorithm, with the time complexity of __O(m) preprocessing and O(n) matching__, as long as m &lt; 64(or 32 if on a 32-bit machine).

## More...
I plan to add more string matching algorithms into it, like Rabin-Karp algo, BM algo, Sunday algo, AC Automaton, Suffix tree/ suffix array, etc. I cannot promise that I would accomplish all thw work before June, 2013 because now I'm looking for a job as a software engineer and I'll be graduated by May, 2013. But I think most of the work will be done by the end of 2013. 
Thanks, :)

## Main reference:
__CLRS__
