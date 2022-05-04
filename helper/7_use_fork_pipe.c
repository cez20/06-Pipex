/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_use_fork_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:54:21 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/04 07:38:20 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/errno.h> // Library needed for errno command below. 

// Video called "Practical use for fork and pipe in C"
// The main purpose of program below is to sum up number of arr[], but to divide the first half of this array in parent process and other half in parent
// 


int main (int argc, char **argv)
{
	int arr[] = { 1, 2, 3 , 4, 1 , 2};
	int arrSize = sizeof(arr)/ sizeof(int); // operation that gives us number of integers in array. 
	int start, end;
	int fd[2];
	if (pipe(fd) == -1)
	{
		return 1;
	}
	int id= fork();
	if (id == -1)
		return 2;
	if (id == 0) // The child process will calculate the first 3 numbers of array 
	{
		start = 0;
		end = start + arrSize / 2;
	}
	else // The parent process will calculate the last 3 numbers of array.  
	{
		start = arrSize / 2;
		end = arrSize;
	}
	int sum = 0;
	int i;
	for(i = start; i < end; i++) // with this for loop, both parent and child process will calculate sum of their numbers
		sum += arr[i];
	printf("Calculated partial sum: %d\n", sum); // Each process will calc
	if (id == 0) // child process 
	{
		close(fd[0]); // close fd[0] because we don't read from in child process
		write(fd[1], &sum, sizeof(sum)); // Boucle for calculed sum of first 3 numbers. We write it
		printf("The sum is : %d\n", sum);
		close (fd[1]);
	}
	else // parent process 
	{
		int sumFromChild; // The variable sumFromChild will allow us to copy content of child process == 6
		close(fd[1]); // we close fd[1] which was the fd in which we wrote.When pipe, the ouput of fd[1] becomes the input of read
		read(fd[0], &sumFromChild, sizeof(sumFromChild)); //stdout (fd[1]) is transfered to stdin(fd[0])
		close(fd[0]);

		int totalSum = sum + sumFromChild;
		printf("Total sum is %d\n", totalSum);
		wait(NULL); // We put wait(NULL) here because this way, both process (child and parent) are done simultaneously. If we put it a the begiggin of this condition, child would be done and then parent would start.
	}
	return (0);	
}