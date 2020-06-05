# Welcome to Abacus-Lang
This was inspired by [Brain Fuck](https://en.wikipedia.org/wiki/Brainfuck).</br>
Like **BF** instructions are single characters and are very limited.</br>
However in theory this is turing complete.
## Explained
### Memory
Memory composes of Rods, which hold Beads.</br>
By default (**const unsigned int LeftStart = 10**) each Rod starts with 10 Beads on the left,</br>
These can only be shifted from one side of the Rod to the other.</br>
**NEVER** creating going above the initial 10 Beads total on the Rod.
### Instructions
| Char | Effect |
|--|--|
| > | Move a bead from Left to Right |
| < | Move a bead from Right to Left |
| U | Go Up a Rod |
| D | Go Down a Rod |
| L | Do if Left **NOT** 0 |
| R | Do if Right **NOT** 0 |
| ] | End of if |
Console R/W coming soon
## Notation
Rod 0 = R0</br>
Rod 0 Left Beads = R0L</br>
Rod 0 Right Beads = ROR</br></br>

So for Rod 1</br>
R1, R1L, R1R respectively
## Examples
### Add 2 Values
Assuming the 2 rows are sequential (R0, R1)</br>
`DR<U>D]`</br>
This loops until the Right beads of the R1 is 0</br>
Each time **R1R-1** and then **R0R+1**
### Multiplying 2 Values
Assuming the 2 rows are sequential (R0, R1)</br>
`R<UR<DD>D>UUU]DDR<UU>DD]U]`</br>
**R1R-1**</br>
Destructively duplicates **R0** into **R2**, **R3**</br>
Copies **R2** back to **R0**</br>
This loops till **R1R**==0</br>
Hence **R3** will become the multiplied sum
