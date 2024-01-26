import subprocess
import random
import pathlib
import time


def get_push_swap_path():
    script_directory = pathlib.Path(__file__).resolve().parent
    push_swap_path = script_directory / 'push_swap'
    return push_swap_path


def main():
    push_swap_path = get_push_swap_path()

    if push_swap_path.exists() and push_swap_path.is_file():

        values_count = int(input("Enter the number of values to generate: "))
        run_count = int(input("Enter the number of times to run the function: "))

        start_time = time.time()  # Record the start time

        total_lines = 0
        max_lines = -1
        min_lines = float('inf')
        sequence_with_max_lines = None

        for run in range(1, run_count + 1):
            generated_values = random.sample(range(1, values_count + 1), values_count)
            result = subprocess.run([str(push_swap_path), *map(str, generated_values)], capture_output=True, text=True)
            lines = len(result.stdout.splitlines())
            total_lines += lines
            if max_lines == -1 or lines > max_lines:
                max_lines = lines
                sequence_with_max_lines = generated_values.copy()

            if min_lines == -1 or lines < min_lines:
                min_lines = lines

        average_lines = total_lines // run_count

        end_time = time.time()
        execution_time = end_time - start_time

        print(f"Maximum lines: {max_lines}")
        print(" ".join(map(str, sequence_with_max_lines)))
        print(f"Minimum lines: {min_lines}")
        print(f"Average lines: {average_lines}")
        print(f"Total execution time: {execution_time:.2f} seconds")

    else:
        print("Error: push_swap executable not found in the same directory.")


if __name__ == "__main__":
    main()
