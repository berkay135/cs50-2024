<details open>
<summary>Week 1</summary>
<br>
# Week 1

## Problem to Solve Mario
***
### How to Solve
***
Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.

![Pyramid][pyramid]

In a file called ```mario.c``` in a folder called ```mario-more```, implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:

        #  #    
       ##  ##   
      ###  ###   
     ####  ####   
     
And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive int between, say, 1 and 8, inclusive.

<details open>
<summary>Examples</summary>
<br>
Here’s how the program might work if the user inputs 8 when prompted:
        
```
$ ./mario
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########      
```

If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:

```
$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

</details>
</details>

## Problem to Solve Credit

[pyramid]: img/pyramids.png
