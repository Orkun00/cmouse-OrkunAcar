#ifndef MAIN_H // Header guard to prevent multiple inclusions
#define MAIN_H

#include <stdio.h> // Include the standard I/O library
#include <stdlib.h> // Include the standard library
#include <fcntl.h> // Include the file control definitions library
#include <linux/input.h> // Include the Linux input device definitions library
#include <unistd.h> // Include UNIX standard functions library

#define Mouse "/dev/input/mouse0" // Define the path to the mouse input device

// Function Prototypes
void MouseInput(int fd); // Function prototype for the MouseInput function

#endif // MAIN_H // End of the header file
