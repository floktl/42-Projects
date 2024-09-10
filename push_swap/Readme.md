

  <h1>Push_Swap, a 42 Project</h1>

  <p>
    A Program using a sorting algorithm to sort two stacks!
  </p>

<br />

<!-- About the Project -->
# :star2: About the Project

This project is about a sorting algorithm for 2 stacks with limited operations

## Allowed operations:

### sa (swap a)
Swap the first 2 elements at the top of stack a.

### sb (swap b)
Swap the first 2 elements at the top of stack b.

### ss
sa and sb at the same time.

### pa (push a)
Take the first element at the top of b and put it at the top of a.

### pb (push b)
Take the first element at the top of a and put it at the top of b.

### ra (rotate a)
Shift up all elements of stack a by 1.
The first element becomes the last one.

### rb (rotate b)
Shift up all elements of stack b by 1.
The first element becomes the last one.

### rr
ra and rb at the same time.

### rra (reverse rotate a)
Shift down all elements of stack a by 1.
The last element becomes the first one.

### rrb (reverse rotate b)
Shift down all elements of stack b by 1.
The last element becomes the first one.

### rrr
rra and rrb at the same time.

8


<!-- Run Locally -->
# :running: Getting Started

## Clone the project

```bash
  git clone https://github.com/floktl/42-projects/push_swap
```

## Go to the project directory and compile

```bash
  cd push_swap && make
```

## running the programm with a random unsorted ammount of positive or negative numbers (no duplicates)

```bash
  ./push_swap 4 3 5 2 1 
```

## the operations, which sorts the number fasted with my algorithm will be displayed as output

```bash
rra
pb
ra
ra
ra
pb
sa
pa
pa
```

<!-- Explainations -->
# :star: Algorithm details

```C

void	sorting_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	rot_a;
	int	rot_b;

	rot_a = 0;
	rot_b = 0;
  // check if the stack is already sorted
	if (check_if_sorted(*stack_a) == 1)
		return ;
  // until the number of numbers is bigger than 3, the big algorithm runs
	if (count_nodes(*stack_a) > 3)
	{
		while (count_nodes(*stack_a) > 3)
		{
      //  function to calculate the lowest number of operations to push a number from
      //  stack a to stack b
			op_calc(*stack_a, *stack_b, &rot_a, &rot_b);
      //  rotating both stacks at once, if possible, to save operations
			rotate_both(&rot_a, &rot_b, stack_a, stack_b);
      //  bring the best number from stack a on top of stack a and pushes to stack b
			prepare_and_push(stack_a, stack_b, rot_a, rot_b);
		}
    //  rotate stack b, until the highest number is on top
		rot_highest_to_top(stack_b);
	}
  // short algorithm with the 3 highest numbers from the start
	short_algorithm(stack_a, count_nodes(*stack_a));
  //  pushing all numbers back to stack a
	while (*stack_b != NULL)
		push_a(stack_a, stack_b);
  //  safety function to check if the stack is correctly sorted
	if (check_if_sorted(*stack_a) == 0)
		ft_printf("the stack is not properly sorted");
	return ;
}
```

<!-- Contact -->
# :handshake: Contact

Florian Keitel - https://www.linkedin.com/in/fkeitel/ - fl.keitel@gmail.com

Project Link: [https://github.com/floktl/WireframeVisualizer)](#https://github.com/floktl/WireframeVisualizer)]
