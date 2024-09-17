import matplotlib.pyplot as plt
import matplotlib.patches as patches
import subprocess
import os
import sys
from contextlib import contextmanager

# Suppress output from subprocess commands
@contextmanager
def suppress_output():
    with open(os.devnull, 'w') as fnull:
        old_stdout = sys.stdout
        old_stderr = sys.stderr
        sys.stdout = fnull
        sys.stderr = fnull
        try:
            yield
        finally:
            sys.stdout = old_stdout
            sys.stderr = old_stderr

def read_coordinates(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()

    if len(lines) < 5:
        raise ValueError("coordinates.txt does not have the expected number of lines.")

    # Unpack triangle vertices
    triangle = [tuple(map(float, line.strip().split())) for line in lines[:3]]
    point = tuple(map(float, lines[3].strip().split()))
    status = lines[4].strip()

    return triangle, point, status

def plot_triangle_and_point(triangle, point, status):
    # Unpack triangle vertices
    x1, y1 = triangle[0]
    x2, y2 = triangle[1]
    x3, y3 = triangle[2]

    # Unpack point
    px, py = point

    # Clear the current figure
    plt.clf()

    # Plot the triangle
    triangle_x = [x1, x2, x3, x1]
    triangle_y = [y1, y2, y3, y1]
    plt.plot(triangle_x, triangle_y, 'b-')  # Blue line for the triangle

    # Plot the point
    if status == "inside":
        plt.plot(px, py, 'go', markersize=10)  # Green point if inside
        plt.text(px, py, ' Inside ', color='green', fontsize=12, ha='right')
    else:
        plt.plot(px, py, 'ro', markersize=10)  # Red point if outside
        plt.text(px, py, ' Outside ', color='red', fontsize=12, ha='right')

    # Set the plot limits
    plt.xlim(min(x1, x2, x3, px) - 1, max(x1, x2, x3, px) + 1)
    plt.ylim(min(y1, y2, y3, py) - 1, max(y1, y2, y3, py) + 1)

    # Label the axes
    plt.xlabel('X')
    plt.ylabel('Y')

    # Add a grid
    plt.grid(True)

    # Add a legend
    plt.legend(['Triangle', 'Point'])

    # Add a title to explain color coding
    plt.title('Green: Point is inside the triangle\nRed: Point is outside the triangle')

    # Show the plot
    plt.draw()
    plt.pause(0.1)

def on_click(event):
    if event.inaxes is not None:  # Ensure the click is within the plot area
        x, y = event.xdata, event.ydata
        print(f"Clicked at ({x:.2f}, {y:.2f})")

        # Run the C++ program with the clicked coordinates
        try:
            with suppress_output():
                result = subprocess.run(['./Fixed', str(x), str(y)], check=True)
        except subprocess.CalledProcessError as e:
            print(f"Error running Fixed: {e}")
            return

        # Check if coordinates.txt was created
        if not os.path.isfile('coordinates.txt'):
            print("coordinates.txt not found. Ensure the C++ program ran successfully.")
            return

        # Read coordinates from file and plot
        try:
            triangle, point, status = read_coordinates('coordinates.txt')
            plot_triangle_and_point(triangle, point, status)
        except Exception as e:
            print(f"Error: {e}")

if __name__ == '__main__':
    plt.ion()  # Turn on interactive mode
    fig, ax = plt.subplots()
    fig.canvas.mpl_connect('button_press_event', on_click)  # Connect the mouse click event

    while True:
        # Prompt the user for new coordinates
        x = input("Enter x-coordinate: ")
        y = input("Enter y-coordinate: ")

        try:
            # Run the C++ program with new coordinates
            with suppress_output():
                result = subprocess.run(['./Fixed', x, y], check=True)
        except subprocess.CalledProcessError as e:
            print(f"Error running Fixed: {e}")
            continue

        # Check if coordinates.txt was created
        if not os.path.isfile('coordinates.txt'):
            print("coordinates.txt not found. Ensure the C++ program ran successfully.")
            continue

        # Read coordinates from file and plot
        try:
            triangle, point, status = read_coordinates('coordinates.txt')
            plot_triangle_and_point(triangle, point, status)
        except Exception as e:
            print(f"Error: {e}")

        # Ask the user if they want to enter new coordinates
        again = input("Do you want to enter new coordinates? (yes/no): ").strip().lower()
        if again != 'yes':
            break

    plt.ioff()  # Turn off interactive mode
    plt.show()  # Ensure the final plot is displayed
