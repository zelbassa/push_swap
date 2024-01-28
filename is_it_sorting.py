import subprocess
import random
import pathlib
import time
from multiprocessing import Pool

def get_checker_path():
    script_directory = pathlib.Path(__file__).resolve().parent
    checker_path = script_directory / 'checker'
    return checker_path

def get_push_swap_path():
    script_directory = pathlib.Path(__file__).resolve().parent
    push_swap_path = script_directory / 'push_swap'
    return push_swap_path

def run_checker(generated_values):
    checker_path = get_checker_path()
    push_swap_path = get_push_swap_path()
    push_swap = subprocess.Popen([str(push_swap_path), *map(str, generated_values)], stdout=subprocess.PIPE)
    checker = subprocess.run([str(checker_path), *map(str, generated_values)], stdin=push_swap.stdout, capture_output=True, text=True)
    push_swap.stdout.close()
    return checker.stdout.strip(), generated_values

def main():
    push_swap_path = get_push_swap_path()
    checker_path = get_checker_path()

    if push_swap_path.exists() and push_swap_path.is_file() and push_swap_path.stat().st_mode & 0o111 and checker_path.exists() and checker_path.is_file() and checker_path.stat().st_mode & 0o111:

        values_count = int(input("Enter the number of values to generate: "))
        run_count = int(input("Enter the number of times to run the function: "))

        start_time = time.time()  # Record the start time

        with Pool() as pool:
            results = pool.map(run_checker, [random.sample(range(1, values_count + 1), values_count)
                                               for _ in range(run_count)])

        for result, sequence in results:
            if result == "KO":
                print(f"KO found with sequence: {' '.join(map(str, sequence))}")
                return

        print("All checks returned OK")

        end_time = time.time()
        execution_time = end_time - start_time

        print(f"Total execution time: {execution_time:.2f} seconds")

    else:
        print("Error: push_swap or checker executable not found in the same directory.")

if __name__ == "__main__":
    main()