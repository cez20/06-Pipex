/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   26_calling_multiple_forks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:18:53 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/06 15:15:52 by cemenjiv         ###   ########.fr       */
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

// Video is entitled "Calling fork multiple times (part 2)" 
// Explanation of drawing from 9:23 a 12:25 is the best.  

#define PROCESS_NUM 3 // macro that determines the number of processes. It is settled to 3. 

int main(int argc, char* argv[]) {
    int pids[PROCESS_NUM]; // Variable pids will store the processes. 
    int pipes[PROCESS_NUM + 1][2]; // PROCESS_NUM + 1 (determines number of pipes). The [2] determines the number of FDs per pipe. 
    int i;
    for (i = 0; i < (PROCESS_NUM + 1); i++) {
        if (pipe(pipes[i]) == -1) { // This command will create 4 pipes and if any of them returns -1, there is an error
            printf("Error with creating pipe\n");
            return 1;
        }
    }

    // for (i = 0; i < PROCESS_NUM; i++) { // This loop would be a mistake because the fork would be called on each parent and child 
    //     fork();
	
	
	for (i = 0; i < PROCESS_NUM; i++) { // This loop will create 1 process, execute all commands below and then  
        pids[i] = fork();
        if (pids[i] == -1) {
            printf("Error with creating process\n");
            return 2;
        }
        if (pids[i] == 0) { // Condition to verify if we are in the child process. 
            // Child process
            int j;
            for (j = 0; j < PROCESS_NUM + 1; j++) { // Loop to close all pipes that are not necessary 
                if (i != j) {
                    close(pipes[j][0]); // Try to visualize this. 
                }
                if (i + 1 != j) {
                    close(pipes[j][1]); // Try to visualize this. 
                }
            }
            int x;
            if (read(pipes[i][0], &x, sizeof(int)) == -1) { // Error handling 
                printf("Error at reading\n");
                return 3;
            }
            printf("(%d) Got %d\n", i, x); // printing number that was read. 
            x++; // This allows us increase the number passed in pipe by 1.  
            if (write(pipes[i + 1][1], &x, sizeof(int)) == -1) { // Error handling 
                printf("Error at writing\n");
                return 4;
            }
            printf("(%d) Sent %d\n", i, x); // Imprime le chiffre qui a ete ecrit a l'autre bout du pipe
            close(pipes[i][0]); // Ferme le read pipe venant d'etre utilise 
            close(pipes[i + 1][1]); //Ferme le write pipe venant d'etre utilise 
            return 0; // Met fin au child process qui vient d'etre utiliser avant de recommencer la loop. 
        }
    }

    // Main process : this is the parent process. 
    int j;
    for (j = 0; j < PROCESS_NUM + 1; j++) {
        if (j != PROCESS_NUM) { // This avoir that we close the parent process read end
            close(pipes[j][0]);
        }
        if (j != 0) { // This avoid that we close the parent process write end. 
            close(pipes[j][1]);
        }
    }
    int y = 5; // Initial number that we start with in parent process. 
    printf("Main process sent %d\n", y); // prints the number 
    if (write(pipes[0][1], &y, sizeof(int)) == -1) { // the number is written and then goes through all child process 
        printf("Error at writing\n");
        return 4;
    }
    if (read(pipes[PROCESS_NUM][0], &y, sizeof(int)) == -1) { // Read "read pipe" after going through all childs.
        printf("Error at reading\n");
        return 3;
    }
    printf("The final result is %d\n", y); // Prints the final result
	close (pipes[0][1]);
    close(pipes[PROCESS_NUM][0]); // Close the final read pipe 

    for (i = 0; i < PROCESS_NUM; i++) { 
        wait(NULL); // Command that makes sure that we wait for all child process. 
    }
    return 0;
}