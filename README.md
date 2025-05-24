# Assembler Project

## Project Overview

This project implements a fully functional assembler written in C.  
It translates assembly language source files into machine code using a multi-stage process, including lexical analysis, preprocessing, a two-pass assembly procedure, error detection, and code generation.  
The assembler is modularly designed to allow easy maintenance and extension.

## Project Goals

- Translate assembly code into machine instructions  
- Support macros and preprocessing directives  
- Build symbol tables and resolve addresses in two passes  
- Provide detailed error reporting  
- Maintain clear modular structure with separation of concerns  

---

## Project Structure and Components

### Core Modules

- **assembler.c**  
  The main driver program coordinating all assembly phases: preprocessing, lexical analysis, passes, and output generation.

- **lexer.c / lexer.h**  
  Tokenizes the input source code into tokens for parsing. Handles lexical rules for assembly language.

- **preproc.c / preproc.h**  
  Preprocessor module that processes macros, includes, and cleans up the source before actual assembly.

- **first_pass.c / first_pass.h**  
  The first pass scans the source to identify symbols, labels, and create symbol tables, but does not generate final code.

- **second_pass.c / second_pass.h**  
  The second pass completes address resolution and translates instructions into machine code or intermediate format.

- **code_conversion.c / code_conversion.h**  
  Converts parsed instructions and operands into binary or object code.

### Supporting Modules

- **handle_text.c / handle_text.h**  
  Utilities for text parsing, manipulation, and line processing.

- **table.c / table.h** and **data_strct.c / data_strct.h**  
  Implement data structures such as symbol tables, opcode tables, and support data for assembly.

- **Errors.c / Errors.h**  
  Handles error detection, logging, and reporting throughout all stages.

- **util.c / util.h**  
  General utility functions used across modules.

- **globals.h**  
  Global constants, macros, and shared definitions.

---

## Build Instructions

### Requirements

- GCC or compatible C compiler  
- Make utility  

### Build

Run the following command to compile the assembler:

```bash
make
```

This compiles all source files and produces the executable named `assembler`.

### Clean

To clean object files and the executable:

```bash
make clean
```

---

## Usage

### Basic Usage

Run the assembler with an assembly source file as input:

```bash
./assembler source.asm
```

The assembler will process the file, generate machine code or object files, and produce logs/errors as applicable.

### Input File Format

- Standard assembly language syntax  
- Supports macros and preprocessing directives  
- Label declarations and instruction syntax consistent with the assembler's defined language rules

### Output

- Machine code or object code file(s) corresponding to the input source  
- Error and warning messages printed to console or log files

---

## Development Notes

- The assembler is designed for educational use and modular extensibility  
- New features such as additional instruction sets, output formats, or optimizations can be integrated by adding modules or extending existing ones  
- The lexer and preprocessor can be adjusted for different assembly dialects  
- Error handling is centralized for consistent reporting

---

## Troubleshooting and Tips

- Ensure source files conform to the expected syntax  
- Use verbose or debug mode (if implemented) to trace issues  
- Clean and rebuild project if you encounter build errors  
- Consult the source comments for detailed function descriptions  

---

## License

This project is provided as-is for educational purposes. You may modify and distribute it freely with proper attribution.

---

## Contact

For questions or contributions, please contact the project maintainer.

---