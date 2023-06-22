# C++ Double Linked List

## Description
This is a mini project of a C++ Double Linked List. You can add, delete and find elements in the list as of 09/06/2023. New methods might be added in the future.

The linked list can only work with numeric types right now (`int`, `float`, `double` etc.). It won't work for `std::string` or similar structures.

The linked list can hold duplicate elements. Each `Delete` will delete all of the elements that hold a specific value.
## Compilation
The building requires `CMake`. Build as follows:
```
cmake <build-dir>
```
then navigate to the building dir and just call `make`. This will create an executable file called `list`.
NOTE: In order to run the `make` concurrently you can run `make -j <number_of_threads>`

## Testing
There is some testing that tests the basic functionality of the methods in the `DoubleList`.
