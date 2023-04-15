// REPO SYNC
#include <windows.h>
#include <stdio.h>
#include <string.h>

// The main function, which takes two command-line arguments, the source directory and the destination directory
int main(int argc, char *argv[])
{
// Check if the user has provided both the source and the destination directories
if (argc < 3) {
printf("Usage: %s source_dir dest_dir\n", argv[0]);
return 1;
}

// Set the path to the rsync executable
char *rsync = "C:\\ProgramData\\chocolatey\\bin\\rsync.exe";
// Set the source and destination directories from command-line arguments
char *source_dir = argv[1];
char *dest_dir = argv[2];

// Define the arguments to be passed to the rsync command
char *args[7] = {
    rsync, // path to rsync executable
    "-avz", // rsync command line option
    "--delete", // rsync command line option
    source_dir, // source directory to sync
    dest_dir, // destination directory to sync
    "--log-file=sync.log", // rsync command line option to specify log file
    NULL // end of argument list
};

// Create process structures to store process information
STARTUPINFO si = { sizeof(si) };
PROCESS_INFORMATION pi;

// Create a command line string from the arguments array
char cmd_line[1024];
int i;
size_t offset = 0;
for (i = 0; args[i] != NULL; i++) {
    offset += snprintf(cmd_line + offset, 1024 - offset, "%s ", args[i]);
}

// Print the command to be run
printf("Running command: %s\n", cmd_line);

// Create the child process to run the rsync command
if (!CreateProcess(NULL, cmd_line, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
    // If the process creation fails, print the error message and exit the program
    fprintf(stderr, "CreateProcess failed (%d).\n", GetLastError());
    return 1;
}

// Wait for the child process to exit
WaitForSingleObject(pi.hProcess, INFINITE);

// Get the exit code of the child process
DWORD exit_code;
GetExitCodeProcess(pi.hProcess, &exit_code);

// Close process and thread handles to avoid resource leaks
CloseHandle(pi.hProcess);
CloseHandle(pi.hThread);

// Print the exit code of the child process
printf("Command exited with code %d.\n", exit_code);

// Return 0 to indicate success
return 0;
}

// Signal Handler

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_signal(int signal) {
    printf("\nReceived signal %d. Exiting...\n", signal);
    exit(EXIT_SUCCESS);
}

int main() {
    // Install the signal handler for SIGINT
    if (signal(SIGINT, handle_signal) == SIG_ERR) {
        perror("signal");
        return EXIT_FAILURE;
    }

    // Loop until CTRL+D is typed
    printf("Type CTRL+D to exit...\n");
    while (1) {
        if (getchar() == EOF) {
            handle_signal(SIGINT);
        }
    }

    return EXIT_SUCCESS;
}
