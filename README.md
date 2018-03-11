# Scanner

> The first stage of compiling, the scanner, is usually based on a finite-state machine (FSM). It has encoded within it information on the possible sequences of characters that can be contained within any of the tokens it handles (individual instances of these character sequences are termed lexemes). For example, an integer token may contain any sequence of numerical digit characters. In many cases, the first non-whitespace character can be used to deduce the kind of token that follows and subsequent input characters are then processed one at a time until reaching a character that is not in the set of characters acceptable for that token (this is termed the maximal munch, or longest match, rule). In some languages, the lexeme creation rules are more complex and may involve backtracking over previously read characters. For example, in C, one 'L' character is not enough to distinguish between an identifier that begins with 'L' and a wide-character string literal.

From [Wikipedia](https://en.wikipedia.org/wiki/Lexical_analysis).


## Deterministic Finite Automaton
![Deterministic Finite Automaton](deterministic-finite-automaton.png)

To edit import `deterministic-finite-automaton.json` at https://merfoo.github.io/fsm/