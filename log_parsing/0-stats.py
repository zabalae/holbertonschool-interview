#!/usr/bin/python3
import sys
import signal

# Initialize global variables
total_size = 0
status_counts = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0
}
line_count = 0


def print_stats():
    """Prints the statistics so far."""
    print(f"File size: {total_size}")
    for code in sorted(status_counts):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")


def signal_handler(sig, frame):
    """Handles the interrupt signal (CTRL + C) to print stats."""
    print_stats()
    sys.exit(0)

# Register the signal handler for CTRL + C
signal.signal(signal.SIGINT, signal_handler)

try:
    for line in sys.stdin:
        try:
            # Parse the line using the expected format
            parts = line.split()
            if len(parts) < 7:
                continue

            ip = parts[0]
            date = parts[3] + " " + parts[4]
            request = parts[5] + " " + parts[6] + " " + parts[7]
            status_code = int(parts[8])
            file_size = int(parts[9])

            # Update total size
            total_size += file_size

            # Update status code count
            if status_code in status_counts:
                status_counts[status_code] += 1

            line_count += 1

            # Print stats every 10 lines
            if line_count % 10 == 0:
                print_stats()

        except Exception:
            # Ignore lines that don't match the format
            continue

except KeyboardInterrupt:
    # Handle keyboard interruption and print the stats
    print_stats()
    sys.exit(0)
