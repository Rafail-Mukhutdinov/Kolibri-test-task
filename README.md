[![kolibri](https://github.com/Rafail-Mukhutdinov/Kolibri_test_task/actions/workflows/Kolibri.yml/badge.svg)](https://github.com/Rafail-Mukhutdinov/Kolibri_test_task/actions/workflows/Kolibri.yml)
# Build on Qt 6.6.0
# Solution to the test task for LLC "NPO Kolibri"

The program modifies input files with a binary operation with a specified value.

## Workflow:

1. After launch, it is configured by the user:
    - mask of input files, for example .txt, testFile.bin
    - setting the need to delete input files or not
    - path to save the resulting files
    - actions when repeating the name of the output file: overwrite or modification, for example, a counter to the file name
    - work on a timer or a one-time launch
    - frequency of polling for the presence of an input file (timer)
    - 8-byte value for the binary operation of file modification

2. Functionality: modifies input files, for example XOR operation with an 8-byte variable entered from the form (Item 1,g)

3. Foolproof: if the input file is not closed - do not touch it.

Development environment QT Creator, programming language C++, operating system Windows, compiler MinGW.
