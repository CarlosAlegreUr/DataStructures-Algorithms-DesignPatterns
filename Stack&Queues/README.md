# Stacks and Queues

Basic implementations of stack, queue, and deque. Each of these data structures has its own folder containing the respective source code. Additionally, the `node.h` file contains the code for a `Node` class that is utilized by all the implementations.

## Templates

If you desire to have the `Node` class support multiple data types, you will need to modify the `Node` class to use templates. This will allow the `Node` class to hold any data type, not just integers. To achieve this, change the integer data type of the `data` member in the `Node` class to a template type, and update the respective stack, queue, and deque implementations to accommodate the changes made to the `Node` class.
