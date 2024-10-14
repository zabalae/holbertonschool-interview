#!/usr/bin/python3
"""
Log Parsing Script

This script reads log entries from standard input, processes them line by line, 
and computes metrics such as total file size and counts of HTTP status codes.
The log format is expected to follow the format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

- After every 10 lines of input, the script outputs the current statistics.
- It also outputs statistics if interrupted with CTRL+C (SIGINT).

Metrics Computed:
- Total file size: The sum of all the file sizes parsed from the logs.
- Number of occurrences for each HTTP status code (for the codes: 200, 301, 400, 401, 403, 404, 405, 500).

How to run:
- You can pipe log data into this script. For example:
    $ ./log_generator.py | ./log_parsing.py

"""

import sys
import signal

# Declare global variables before modifying them
global total_size
global line_count

# Initialize global variables for total file size and status code counts
total_size = 0  # Tracks the total size of all file sizes in the logs
status_counts = {  # Tracks occurrences of specific HTTP status codes
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0
}
line_count = 0  # Keeps track of how many lines have been processed


def print_stats():
    """
    Prints the statistics from the log parsing process.

    - Outputs the total file size so far.
    - Outputs the count of each HTTP status code in ascending order if the code has appeared.
    """
    print(f"File size: {total_size}")
    for code in sorted(status_counts):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")


def signal_handler(sig, frame):
    """
    Handles the SIGINT signal (triggered by CTRL+C).
    
    When the script is interrupted, it prints the current statistics before exiting.

    Args:
        sig: The signal number.
        frame: The current stack frame (ignored in this case).
    """
    print_stats()  # Output the stats before exiting
    sys.exit(0)  # Gracefully exit the script


# Register the signal handler for SIGINT (Ctrl + C)
signal.signal(signal.SIGINT, signal_handler)

# Main execution loop to process lines from standard input
if __name__ == "__main__":
    try:
        for line in sys.stdin:
            try:
                # Split the log line by whitespace to parse its components
                parts = line.split()

                # Ensure the line follows the expected format by checking part count
                if len(parts) < 7:
                    continue  # Skip lines that don't match the format

                # Extract necessary fields from the log line
                ip = parts[0]  # IP address
                date = parts[3] + " " + parts[4]  # Date field
                request = parts[5] + " " + parts[6] + " " + parts[7]  # HTTP request
                status_code = int(parts[8])  # Status code (should be an integer)
                file_size = int(parts[9])  # File size (should be an integer)

                # Update the total file size
                total_size += file_size

                # Update the count of the status code if it's in the expected set
                if status_code in status_counts:
                    status_counts[status_code] += 1

                # Increment the line counter
                line_count += 1

                # Print stats every 10 lines
                if line_count % 10 == 0:
                    print_stats()

            except Exception:
                # If an error occurs (e.g., invalid line format), skip the line
                continue

    except KeyboardInterrupt:
        # If the script is interrupted by a keyboard interrupt, print the final stats
        print_stats()
        sys.exit(0)
