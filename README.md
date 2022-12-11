```txt
Name        : README.md
Author      : s090116, Declined#8151 (Discord ID) 
Date        : 29/09-20
Last Updated: 11/12-21
Description : This repository is created to include an introduction and overview
              into a number of subjects.
              If I'm the author the file is on copyright, else the source should
              be clearly defined within the folder
Copyright   : All rights reserved
```

***

# Directory information

**C-code examples** 
* The goal is to have a number of C-code examples regarding different topics, which can be used to understand the basics of a topic relatively quickly.
* Files are compiled with gcc, there's an extensive description of how to compile in the Guides folder "Command tool help.txt"

| Name | Description |
|:-----|:-----|
| 000-020    | A tl;dr introduction about different topics |
| 021-[???]  | Could be better, a number of files I've crammed in there |
| A[0??]     | Created to be useful in their own right |
| C[0??]     | Basic topics regarding pointers |
| D[0??]     | Files regarding Linked lists |

***

**Exercises**
Setup to help the user gain some practical experience in some specific way shape or form.

| Name | Description |
|:-----|:-----|
| Exercise 1 | Figuring out why and how C codes can result in infinite loops if you enter something other than a value. Essentially letting users figure out the liitation of scanf.
| Exercise 2 | Intentionally creates a number of zombies, so that you can experiment with the 'top' command, to see how the 'zombie' paragraph can change, with the command actively running.
| Exercise 3 | Working with files and strings
| Exercise 4 | Practical experience with stdout and stderr
| Exercise 5 | A brief exercise to test your knowledge of using a commandline and redirection
| Exercise 6 | (Not published) A semi programmable exercise with multiple aspects containing both analytical and programming skill.

***

**Guides**
Condensed information about topics.

| Name | Description |
|:-----|:-----|
| 1 pdf       | Configuring WSL and get it running with VSC. I didn't write this |
| Bash commands.txt | An extensive guide regarding Bash, the command console for Linux. |
| cmd commands.txt | A brief list regarding some of the most commonly used cmd command options. |
| Command tool help list.txt | A file explaining detailed use about a few useful and very specific commands, such as nslookup, gcc, MPI, OpenMP, git |

**Shell Examples**
Copy pasted of the net and from places.
A lot of shell files to highlight syntax.
Note that file "B003 bsub.h" is to be used specifically on the LSF 10 cluster.
This is done by submitting it to the job queue, and let the server handle it.

Command:

`$ bsub < B003\ bsub.sh` 

To view the job queue, use the command '`bjobs`'

After a minute or two expect that the job will disappear, so you have a limited amount of time to test it.

***

**Tools**
Setup to contain useful programs

| Name | Description |
|:-----|:-----|
| LC3-Decoder | jar file, graphical interface looks like crap, but it works. Converts machine language to Assembly. |


