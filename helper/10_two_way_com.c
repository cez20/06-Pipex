/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_two_way_com.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:31:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/04 09:38:21 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h> // Library in order to use mkfifo
#include <sys/wait.h> // Library in order to use mkfifo
#include <sys/errno.h> // Library needed for errno command below. 
#include <fcntl.h>
#include <time.h> // necessary for srand(time(NULL) command 

// Video is entitled "Two way communication between processes (using pipes) in C".
// Essentially it explain the communication between two processes: a parent and a child.
// pipe() command allows the processes to communicated between them.  

// Parent always does the initial command. Then pipe (normally the child) will read and then
// write and then the parent will take over and write content on stdout or in file. 


/*int main (int argc, char *argv[])
{
	int p1[2];
	if (pipe(p1) == -1)
		return 1;
	int pid = fork(); // pid is a variable in which we put the value of fork. 
	if (pid == -1) // if fork returns -1 , it is a mistake. 
		return 2;
	if (pid == 0) // The child process takes a number that is given and multiplies it by 4. 
	{
		printf("The file descriptor for read in CHILD is %d\n", p1[0]);
		printf("The file descriptor for write in CHILD is %d\n", p1[1]);
		int x; 
		if (read(p1[0], &x, sizeof(x)) == -1) // when we read first file descriptor. If returns value -1, there is a mistake.  
			return 3; 
		printf("Received %d in read end of pipe in CHILD process.\n", x); // Used to show what number was received 
		x *= 4; // we multiply the number in x variable  by 4. 
		if (write(p1[1], &x, sizeof(x)) == -1) // We wrote number read in p1[0] in file descriptor assigned to p1[1]
			return 4;
		printf("Wrote %d in write end of pipe in CHILD process.\n", x); //Show what number was written in fd of p1[1]
	}
	else // This is the parent process in which we generate the number.
	{
		printf("The file descriptor for read in PARENT is %d\n", p1[0]);
		printf("The file descriptor for write in PARENT is %d\n", p1[1]);
		srand(time(NULL)); //make use of computer internal clock to control the choice of seed. Since time is changing, we ensure that the random number from 0 to 9 is always a different one 
		int y = rand() % 10; // y wille generate a random number between 0 - 9
		if (write(p1[1], &y, sizeof(y)) == -1)
			return 5;
		printf("Wrote %d in WRITE end of PARENT process.\n", y); // 
		wait(NULL); // The wait here seems to ensure that parent wait for child to do eveything it must do before going back to parent.
		if (read(p1[0], &y, sizeof(y)) == -1)
			return 6;
		printf("Result is %d is READ from pipe and then in WRITE end of PARENT process.\n ", y);
		//wait(NULL); // With this command, we make sur that child process is finished before printing out something. 
	}
	close(p1[0]); // CLose read end of pipe as we no longer need it
	close(p1[1]); // Close write end of pipe as we no longer need it.
	
	return (0);	
}*/


// Examples with two pipe calls
//

int main (int argc, char *argv[])
{
	int p1[2]; // First pipe created. Pipe from CHILD to PARENT
	int p2[2]; // Second pipe created. Pipe from PARENT to CHILD  

	if (pipe(p1) == -1)
		return 1;
	if (pipe(p2) == -1)
		return 1;
	int pid = fork(); // pid is a variable in which we put the value of fork. 
	if (pid == -1) // if fork returns -1 , it is a mistake. 
		return 2;
	if (pid == 0) // The child process takes a number that is given and multiplies it by 4. 
	{
		close(p1[0]); // We do not need to read from this pipe
		close(p2[1]); //WE do not need the write end of this. 
		int x; 
		if (read(p2[0], &x, sizeof(x)) == -1) // when we read first file descriptor. If returns value -1, there is a mistake.  
			return 3; 
		printf("Received %d in read end of pipe in CHILD process.\n", x); // Used to show what number was received 
		x *= 4; // we multiply the number in x variable  by 4. 
		if (write(p1[1], &x, sizeof(x)) == -1) // We wrote number read in p1[0] in file descriptor assigned to p1[1]
			return 4;
		printf("Wrote %d in write end of pipe in CHILD process.\n", x); //Show what number was written in fd of p1[1]
		close(p1[1]); // CLose close this end in parent process. 
		close(p2[0]); // Close this end in parent process
	}
	else // This is the parent process in which we generate the number.
	{
		close (p1[1]);
		close (p2[0]);
		srand(time(NULL)); //make use of computer internal clock to control the choice of seed. Since time is changing, we ensure that the random number from 0 to 9 is always a different one 
		int y = rand() % 10; // y wille generate a random number between 0 - 9
		if (write(p2[1], &y, sizeof(y)) == -1)
			return 5;
		printf("Wrote %d in WRITE end of PARENT process.\n", y); // 
		//wait(NULL); // The wait here seems to ensure that parent wait for child to do eveything it must do before going back to parent.
		if (read(p1[0], &y, sizeof(y)) == -1)
			return 6;
		printf("Result is %d is READ from pipe and then in WRITE end of PARENT process.\n", y);
		close(p1[0]); // CLose close this end in parent process. 
		close(p2[1]); // Close this end in parent process
		wait(NULL); // With this command, we make sur that child process is finished before printing out something. 
	}
	
	return (0);	
}