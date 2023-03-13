Description
This project covers dynamic memory allocation in the C programming language, specifically the use of malloc and free functions.

Requirements
This project requires a C compiler (such as gcc) and valgrind for memory leak checking.

Automatic vs Dynamic Allocation
Automatic allocation refers to the allocation of memory on the stack, where the size of the memory block is determined at compile time. This type of allocation is limited and has a fixed size, and the memory is automatically deallocated when the variable goes out of scope.

Dynamic allocation, on the other hand, refers to the allocation of memory on the heap, where the size of the memory block can be determined at runtime. This type of allocation allows for more flexibility, as well as the ability to allocate and deallocate memory as needed.

Malloc and Free
malloc is a C library function used for dynamic memory allocation. It allocates a block of memory of a specified size and returns a pointer of type void * to the first byte of the allocated memory block.

free is a C library function used for deallocating the memory block that was previously allocated using malloc. It takes a pointer to the memory block that was previously allocated using malloc and deallocates that block of memory, making it available for future use.

Why and When to Use Malloc
malloc should be used when a program needs to allocate memory at runtime, or when the required size of the memory block is not known at compile time. malloc is commonly used when working with arrays, strings, and structures.

How to use valgrind to check for memory leak
The tool can detect many different memory errors. For instance, it detects reads or writes before or after allocated memory blocks. It warns about the use of (partially) undefined values in conditional code or passing such values to system calls.
