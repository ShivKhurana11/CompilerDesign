void check_keywords(FileLine lines[], int total_lines, FILE *output_file, int is_cpp) {
    const char *keywords_c[] = {"int", "float", "if", "else", "while", "for", "return"};
    const char *keywords_cpp[] = {"class", "public", "private", "protected", "new", "delete", "namespace", "template"};
    int keyword_count_c = sizeof(keywords_c) / sizeof(keywords_c[0]);
    int keyword_count_cpp = sizeof(keywords_cpp) / sizeof(keywords_cpp[0]);

    for (int i = 0; i < total_lines; i++) {
        for (int j = 0; j < keyword_count_c; j++) {
            if (strstr(lines[i].line_text, keywords_c[j])) {
                fprintf(output_file, "Line %d: Found keyword '%s'\n", lines[i].line_number, keywords_c[j]);
            }
        }
        if (is_cpp) {
            for (int j = 0; j < keyword_count_cpp; j++) {
                if (strstr(lines[i].line_text, keywords_cpp[j])) {
                    fprintf(output_file, "Line %d: Found keyword '%s'\n", lines[i].line_number, keywords_cpp[j]);
                }
            }
        }
    }
}