
## Parser

Section responsible for parsing line of prompt.
The result of the parser is the structure `t_pipeline` (located in minishell.h), which describes what and how should be executed.

Parsing steps:
- split the line into tokens
- split tokens into commands
- for each command:
	- set redirection
	- replace variables with their values
	- replace wildcards with file names
	- drop external quotation marks

### Outside API

`t_pipeline *parse(char *line)`

### Notes

- section contains tests (test_parser.c, tests_makefile); these files should be ditched when files will be copied to 42 repo