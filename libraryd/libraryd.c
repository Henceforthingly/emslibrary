/*
 * Copyright (c) 2015 Callum O'Brien
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to 
 * deal in the Software without restriction, including without limitation the 
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is 
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main (int argc, char *argc[])
{
    pid_t pid, sid;

    // fork the process
    pid = fork();

    // if something terrible happened
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    // if we are the parent process
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // if execution reaches here we're the child

    // set umask to zero
    umask(0);

    // open connection to syslog server
    openlog(argv[0],LOG_NOWAIT|LOG_PID,LOG_USER); 
    syslog(LOG_NOTICE, "Successfully started daemon\n"); 

    // create a new sid for the child
    sid = setsid();
    if (sid < 0) {
            syslog(LOG_ERR, "Could not create process group\n");
                exit(EXIT_FAILURE);
    }

    // change working dir
    if ((chdir("/")) < 0) {
            syslog(LOG_ERR, "Could not change working directory to /\n");
                exit(EXIT_FAILURE);
    }

    // close standard file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // main loop
    for (;;) {
        // TODO: main loop of the program
    }

    // close logs
    closelog();

}

