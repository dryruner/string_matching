# String matching algorithm
## Overview
This package includes a lot of common algorithms for learning(and for use, sure!). I've already implemented 4 of them, they're:
* Brute force algorithm, with time complexity of <O((n-m+1)m)> (where n is the length of Target string and m is the length of Pattern string)
* FSM(Finite State Automaton method), with time complexity of <O(m * SIGMA) preprocessing and O(n) matching time>. SIGMA is the length of the charset of T.
* KMP algorithm, with <O(m) amortized preprocessing complexity and O(n) amortized matching time>.
* Shift-and algorithm, with the time complexity of <O(m) preprocessing and O(n) matching>, as long as m <= 64(or 32 if on a 32-bit machine).

## More...
I plan to add more string matching algorithms into it, like Rabin-Karp algo, BM algo, Sunday algo, AC Automaton, Suffix tree/ suffix array, etc. I cannot promise that I would accomplish all thw work before June, 2013 because now I'm looking for a job as a software engineer and I'll be graduated by May, 2013. But I think most of the work will be done by the end of 2013. 
Thanks, :)

## Main reference:
<CLRS>
