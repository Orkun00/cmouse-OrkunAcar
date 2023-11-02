#include "main.h" // Include the main header file for declarations and constants

int main() {
    int fd; // File descriptor for the mouse input device
    fd = open(Mouse, O_RDONLY); // Open the mouse input device in read-only mode
    
    if (fd == -1) { // Check if opening the device failed
        perror("Error opening device"); // Print an error message
        exit(EXIT_FAILURE); // Terminate the program with a failure status
    }
    
    printf("Relative position (x,y) since start:\n\n"); // Display a message
    MouseInput(fd); // Call the MouseInput function to track mouse movements
    close(fd); // Close the mouse input device
    return 0; // Return 0 to indicate successful program execution
}

void MouseInput(int fd) {
    char data[3]; // Array to store mouse input data
    int x = 0, y = 0; // Variables to store mouse movement offsets
    
    while (read(fd, data, sizeof(data)) > 0) { // Read mouse input data
        x += (signed char)data[1]; // Update the x offset
        y += (signed char)data[2]; // Update the y offset
        printf("\rX: %5d, Y: %5d", x, y); // Display the updated mouse coordinates
        fflush(stdout); // Flush the standard output to ensure immediate display
    }
}
