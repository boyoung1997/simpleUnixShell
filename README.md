# simpleUnixShell
### simple Unix shell project - assignment in Operating System class (2017-1, Hanyang Univ)

• This project is for the Linux

• Shell can be run in two ways : Interactive mode & Batch mode

• In interactive mode, shell displays a prompt and user types in a command at
the prompt.

• Each line may contain multiple commands separated with the ; character.

• Each command separated by ; character should be run simultaneously. It
means that multiple processes run their command concurrently and parent
process should wait all children before printing the next prompt.

• In batch mode, shell is started by specifying a batch file on its command line.
The batch file contains the list of commands that should be executed.

• In batch mode, you don’t need to display a prompt, but should echo each
line you read from the batch file back to the user before executing it.

• In both interactive and batch mode, shell stops accepting new commands
when it sees the quit command or reaches the end of the input stream (i.e.,
the end of file or user types Ctrl+D)
