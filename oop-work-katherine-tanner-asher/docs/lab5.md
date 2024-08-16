# Lab 5
* Members: Asher Garvens, Katherine Feng, and Tanner Sharon
## Split of work:
* Tanner did 8-9, Katherine did 1-3, 7, Asher did 4-6
* Tanner did through parts of the testing and Asher did most of the commenting to even the load more.
## Process:
1. Create and implement LSCommand (Katherine)
- Added getFileNames to the AbstractFileSystem class to get all the names of 
  the files in the file system.
- in execute: Pulled off the m flag if it was set, iterated through each file 
  name, opened the file to visit the file with the basic display visitor if 
  the m flag was set, and then closed the file.
- I made sure to not 
  dynamically allocate the visitor object so that I didn't have to worry 
  about managing the memory of the visitor and just passed the visitor by 
  reference for the accept method for each file.
- If the flag was not set, I 
  just printed out 2 files each line by using a counter and modulo to check 
  how many files were on each line.

2. Create and implement RemoveCommand (Katherine)
- I first checked if there was a file name given, and then I just called the 
  deleteFile method with the file system pointer member variable of the 
  command and returned the success of the deleteFile method.

3. Modify the TouchCommand (Katherine)
- To add an option for password-protected files, I checked for a p flag in 
  the input string.
- If it was set, I made a new PasswordProxy file and passed the original 
  file created in the studio into the constructor.
- Either way, the file (password-protected or not) was added to the file system
- If the file wasn't successfully added, then I made sure to delete the file 
  pointer to avoid memory problems.

4. Create and implement support for MacroCommands (Katherine)
- I created a new class MacroCommand with all the necessary member variables 
  and methods. 
- For execute, I called the parsing strategy to parse the input given for 
  the execute method and put the arguments into a vector.
- For each group of arguments, I called execute on the corresponding individual command in the 
  macro command, passing the corresponding string into the method.
- After each individual command, I made sure that it was successfully 
  executed. If not, I returned the error and made sure no other commands 
  were executed.

5. Add the rename command (Tanner)
- I created a new class, RenameParsingStrategy
- The parsing strategy splits the input into 2 file names and then pushes 
  back a string containing the existing file name with a space and then the 
  new file name to be used for the copy command.
- Then, the existing file name is pushed back as the next string in the 
  vector to be used by the remove command to delete this new file.
- An initial input string with no space returns an empty vector. An input 
  string with improper file names will be handled by the individual commands 
  in the macro command, so any possible error is avoided in the parsing 
  strategy.

6. Add support for an additional MacroCommand (Tanner)
- I chose to add a MacroCommand for cat + ds, invoked by using "es" (edit 
  and show)
- All I had to do to implement this was add a new parsing strategy class.
- the parse method of ESParsingStrategy checks for the flags supported by 
  cat and ds ("-a" and "-d") and sets these flags if necessary. The method 
  looks for a file name as well.
- Then, the method pushes back the file name and the append flag if set for 
  the first string in the vector to be used by the cat command.
- The method pushes back the file name and the data only flag if set to be 
  used by the ds command.
- To use this macro command, you just have to create a macro command and add 
  cat and ds to the macro command in order and then set the parsing strategy 
  as ESParsingStrategy. 

# CatCommand (Asher)
- For Cat command, I started with trying to figure out how to parse the input since I had not worked with Katherina on 
  her part. I made sure to add plenty of checks to give the information in order to make testing later easier. I made a
  bool for the flag part since I had to use it in multiple locations. I broke it up into another function that prompts
  input. When I finished, I tested everything by adding the command to the prompt and testing it with the procedure that 
  I will describe below as it is the method that I will use for all three of the commands that I made.
- 
# Testing Procedure
- For each of the commands, I started by creating all 4 permutations of files, each type and with or without a password. 
  I then went on to call display, cat and other commands to test if all the functionality worked. I know that some of 
  these commands were not yet implemented in the order of documentation but after I did, I made sure to test them all.
  For testing display specifically, I manually inserted files into the file system in order to ensure they were working
  properly. 
# Cp and Ds Commands (Asher)
- For display command, for the display command, I just decided to use the visitor and the rest of the implementation was 
  straightforward. Once I finished it , I built everything on the first try and tested it according to my Testing Process
  above. 
- Cp Command was the hardest to implement. I had to create a clone method in the AbstractFile.h and then the appropriate
  parts in the test and image file. Those implementations were simple but I had to make another constructor that allowed
  for a file of the same type to get passed in. This way more of the cloning was contained in the __File.cpp instead of 
  in the Cp Command file. After creating that part, I just had to make sure that the file extensions always matched. 
  everything built on the first try and I tested in all according to the Testing Process.
- The only thing that I resolved after testing was that I had an error with how the PasswordProxy was being read after
  entering the password. I fixed it and that fixed all the issues that I was encountering while testing ds and cp. 
  
  

# Extra Credit Notes
* Add a new concrete visitor that exports the file and maybe make a command that is only called if the program quits via "q" 
* Create a new directory that contains all these exported files so that its not messy

We created a new display visitor that would create text files depending on the type of file that was exported. We built 
our functions that would build a name and move the files into the target directory. There were no errors on build after
we finished the code. We tested on all the 4 combinations of files txt and img with and without passwords. All of which
worked as expected meaning when "q" was entered, they were all exported successfully and the user was informed of such
through the console. We added error handling since the destination directory is changeable in the constants.h. Otherwise
everything worked well wit the extra credit.