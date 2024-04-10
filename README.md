# Problem to Solve
***
### How to Solve
***
Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.
[Pyramid][pyramid]
screenshot of Mario jumping over adjacent pyramids

In a file called ```mario.c``` in a folder called ```mario-more```, implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:

```         #  #    ```
```        ##  ##   ```
```       ###  ###   ```
```      ####  ####   ```
And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive int between, say, 1 and 8, inclusive.

Examples
Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.

[pyramid]: https://upload.wikimedia.org/wikipedia/commons/a/a3/81_INF_DIV_SSI.jpg
