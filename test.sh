#!/bin/bash

# gcc -Wall -Werror -Wextra ./src/*.c ./docs/illegal_functions.c -o pipex

# to check the here_doc BONUS
# make bonus
# valgrind --leak-check=full --trace-children=yes ./pipex here_doc LIMITER cat cat file2

# to check the multiple fd bonus 
# make bonus
# valgrind --leak-check=full --trace-children=yes ./pipex Makefile cat cat "wc -l" file2

# to check the normal pipex
# make 
# valgrind --leak-check=full --trace-children=yes ./pipex Makefile cat cat file2
make re
echo THIS IS A TEST FILE > file1

# ------------------------------------ERRORS----------------------------------- 
printf "\033[1;32m----------------------------ERROR TEST----------------------------\n\033[1;0m"

printf "\033[1;33m--------------RUNNING THE TEST WITH NOT ENOUGH ARGUMENTS--------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./pipex file1 wc \n\033[1;0m"
./pipex file1 wc

printf "\n\033[1;33m--------------RUNNING THE TEST NOT ENOUGH ARGS-------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./pipex file1 wc file2 \n\033[1;0m"
./pipex file1 wc file2

printf "\n\033[1;33m--------------RUNNING THE TEST FOR LASS WC (COMMAND DO NOT EXIST)--------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./pipex file1 lass wc file2 \n\033[1;0m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH <file1 lass | wc >file3 \n\033[1;0m"
printf "\033[1;34mDIFF HAS BEEN DONE ON file2 file3\n\033[1;0m"
./pipex file1 lass wc file2
<file1 lass | wc >file3
diff file2 file3 

printf "\n\033[1;33m--------------RUNNING THE TEST FOR WC LASS--------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./pipex file1 wc lass file2 \n\033[1;0m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH <file1 wc | lass >file3 \n\033[1;0m"
printf "\033[1;34mDIFF HAS BEEN DONE ON file2 file3\n\033[1;0m"
./pipex file1 wc lass file2
<file1 wc | lass >file3
diff file2 file3 

printf "\n\033[1;33m--------------RUNNING THE TEST WITH A NON EXISTING INPUT FILE--------------\n\033[1;0m"
# printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./pipex YOURMOMA3 cat wc file2 \n\033[1;0m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH <YOURMOMA3 cat | wc >file3 \n\033[1;0m"
printf "\033[1;34mDIFF HAS BEEN DONE ON file2 file3\n\033[1;0m"
rm -rf OUTFILE
rm -rf YOURMOMA3
./pipex YOURMOMA3 cat wc OUTFILE
<YOURMOMA3 cat | wc >file3
diff OUTFILE file3
rm -rf OUTFILE
printf "\033[1;32mIF NO WRITING ON TERMINAL, EVERYTHING WORKED PROPERLY(you should still have 2 white line over this)\n\n\033[1;0m"

printf "\n\033[1;33m--------------RUNNING THE TEST WITH SAME INPUT FILE AS OUTPUT FILE--------------\n\033[1;0m"
# printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./pipex SameFile cat wc SameFile \n\033[1;0m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH<SameFile2 cat | wc >SameFile2 \n\033[1;0m"
printf "\033[1;34mDIFF HAS BEEN DONE ON SameFile Samefile2\n\033[1;0m"
echo THIS IS THE SAME > SameFile
echo THIS IS THE SAME > SameFile2
./pipex SameFile cat wc SameFile
<SameFile2 cat | wc >SameFile2
diff SameFile SameFile2
rm -rf SameFile SameFile2
printf "\033[1;32mIF NO WRITING BELOW EVERYTHING WORKED PROPERLY!\n\n\033[1;0m"

printf "\n\033[1;33m--------------RUNNING THE TEST WITH AN ABSOLUTE PATH--------------\n\033[1;0m"
# printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./pipex SameFile cat wc SameFile \n\033[1;0m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH<SameFile2 cat | wc >SameFile2 \n\033[1;0m"
printf "\033[1;34mDIFF HAS BEEN DONE ON SameFile Samefile2\n\033[1;0m"
echo THIS IS THE SAME > SameFile
echo THIS IS THE SAME > SameFile2
./pipex SameFile "/bin/ls" "/bin/cat" SameFile
<SameFile2 "/bin/ls" | "/bin/cat" >SameFile2
diff SameFile SameFile2
rm -rf SameFile SameFile2
printf "\033[1;32mIF NO WRITING BELOW EVERYTHING WORKED PROPERLY!\n\n\033[1;0m"


printf "\n\033[1;33m--------------RUNNING THE TEST WITH ALWAYS UPDATING FILE--------------\n\033[1;0m"
# printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./pipex /dev/urandom/ cat wc SameFile2 \n\033[1;0m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH /dev/urandom/ cat | wc >SameFile3 \n\033[1;0m"
./pipex "/dev/urandom" "cat" "head -n 1" "SameFile2"
cat SameFile2
rm -rf SameFile2
printf "\033[1;32mIF NO WRITING BELOW EVERYTHING WORKED PROPERLY!\n\n\033[1;0m"

# ------------------------------------STD TEST----------------------------------- 


printf "\n\n\n\n\033[1;32m----------------------------STD TEST----------------------------\n\033[1;0m"
printf "\n\033[1;33m--------------RUNNING THE TEST WITH A NON EXISTING OUTPUT FILE--------------\n\033[1;0m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./pipex file1 ls wc YOURMOMA \n\033[1;0m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH <file1 ls wc >YOURMOMA2 \n\033[1;0m"
printf "\033[1;34mSCRIPT TEST IS DONE diff YOURMOMA YOURMOMA2\n\033[1;0m"
./pipex file1 cat wc YOURMOMA
<file1 cat | wc >YOURMOMA2
diff YOURMOMA YOURMOMA2
rm -rf YOURMOMA
rm -rf YOURMOMA2
printf "\033[1;32mIF NO WRITING ON TERMINAL BELOW, EVERYTHING WORKED PROPERLY\n\n\033[1;0m"

printf "\033[1;33m--------------RUNNING THE TEST FOR LS WC --------------\n\033[1;0m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./pipex file1 ls wc file2 \n\033[1;0m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH <file1 ls | wc >file3 \n\033[1;0m"
printf "\033[1;34mDIFF HAS BEEN DONE ON file2 file3\n\033[1;0m"
./pipex file1 ls wc file2
<file1 ls | wc >file3
diff file2 file3 
printf "\033[1;32mIF NO WRITING ON TERMINAL BELOW, EVEYTHING WORKED PROPERLY\n\n\033[1;0m"

printf "\033[1;33m--------------RUNNING THE TEST FOR ls -l and wc -l --------------\n\033[1;0m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./pipex file1 \"ls -l\" \"wc -l\" lass file2 \n\033[1;0m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH <file1 ls -l | wc -l >file3 \n\033[1;0m"
printf "\033[1;34mDIFF HAS BEEN DONE ON file2 file3\n\033[1;0m"
./pipex file1 "ls -l" "wc -l" file2
<file1 ls -l | wc -l >file3
diff file2 file3 
printf "\033[1;32mIF THE COMMANDS WORKED IF NO WRITING ON TERMINAL BELOW\n\n\n\n\n\n\033[1;0m"



# ------------------------------------VALGRIND PART----------------------------------- 
printf "\033[1;32m----------------------------VALGRIND PART----------------------------\n\n\n\033[1;0m"
printf "\033[1;34m--------------SCRIPT TESTING THE STANDARD PIPEX--------------\n\033[1;0m"
printf "\033[1;34m THE COMMAND IS : valgrind --leak-check=full --trace-children=yes ./pipex Makefile cat cat file2 \n\033[1;0m"
make fclean
make
valgrind --leak-check=full --trace-children=yes --show-leak-kinds=all ./pipex file1 cat cat file2

make fclean
rm -rf pipex.dSYM here_doc 
rm -rf YOURMOMA3


# valgrind --leak-check=full --trace-children=yes --show-leak-kinds=all --track-fds=yes