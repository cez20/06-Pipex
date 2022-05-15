/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:21:11 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/09 13:31:22 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main (void)
{
    char cmd[] = "/bin/ls"; // This field is the directory where commands are in macOs
    char *argVec[] = {"ls", "-l", NULL};
    char *envVec[] = {NULL};
    
    printf("Start of execve call %s\n", cmd);
    printf("================================================\n");
    if(execve(cmd, argVec, envVec) == -1)
        perror("Could not execute execve\n");
    printf("OOPS, something is wrong!\n");
    return 0;
}