Andreas's Shell
=====
This is a basic shell that can handle some basic commands on its own and sends others to the bash shell.
Upon startup you will be greated with a welcome, and when you see "awiede$ " you can enter your command. 

Basic Commands
=====

exit 

This exits the shell.

type filename

This reads in a file and prints out its contents.

copy file1 file2 

This reads in the first file and copies it to the second file.
If the second file exists it is erased and replaced with the contents of the first.
If the second file does not exist the shell creates the file.

delete filename

This deletes the file.

Other Commands
=====
If you enter a command that is not on the basic commands list, but is an executable command
in the bash shell, then the shell will run it. 
