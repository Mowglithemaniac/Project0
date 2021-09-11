/*============================================================================
 Name        : README.txt
 Author      : Daniel Silbermann, s090116, Declined#8151 (Discord ID) 
 Date        : 29/09-20
 Last Updated: 11/09-21
 Description : This repository is created to include an introduction
               and overview into a number of subjects.
 ============================================================================*/


Directory   | C-code examples
Is set up to contain a number of C-code files, with a focus on syntax within
the different areas.
Files starting with the letter 'A' are meant to be useful in their own right
rather than merely showing syntax.

Files are compiled 


Directory   | Exercises
Setup to help the user gain some practical experience in some specific way.
Exercise 1.     : Figuring out why and how C codes can result in infinite
                  loops if you enter something other than a value.
Exercise 2.     : Intentionally creates a number of zombies, so that you can
                  experiment with the 'top' command, to see how the 'zombie'
                  paragraph can change, with the program is actively running.

Directory   | Guides
1 pdf                       : Configuring WSL and get it running with VSC.
Bash commands.txt           : An extensive guide regarding Bash, the command
                              console for Linux.
cmd commands.txt            : A brief list regarding some of the most commonly
                              used cmd command options.
Command tool help list.txt  : A file explaining detailed use about a few useful
                              and very specific commands, such as
                              nslookup, gcc, MPI, OpenMP, git

Directory   | Shell Examples
A lot of shell files to highlight syntax.
Note that file "B003 bsub.h" is to be used specifically on the LSF 10 cluster.
This is done by submitting it to the job queue, and let the server handle it.
Command:
$ bsub < B003\ bsub.sh
To view the job queue, use the command 'bjobs'
After a minute or two expect that the job will disappear, so you have a limited
amount of time to test it.

