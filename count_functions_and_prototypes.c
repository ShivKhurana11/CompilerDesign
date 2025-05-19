void count_functions_and_prototypes(FileLine lines[], int total_lines, FILE *output_file) {
    int function_count = 0;
    int prototype_count = 0;

    for (int i = 0; i < total_lines; i++) {
        if (is_valid_function_syntax(lines[i].line_text)) {
            if (strchr(lines[i].line_text, ';')) {
                prototype_count++;
            } else {
                function_count++;
            }
        }
    }
    fprintf(output_file, "Number of functions: %d\n", function_count);
    fprintf(output_file, "Number of function prototypes: %d\n", prototype_count);
}