#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdbool.h>

const char *strerrorname_np(int errnum);
const char *strerrordesc_np(int errnum);


void print_errno_info(int i) {
    printf("%4d %-16s %s\n", i, strerrorname_np(i), strerrordesc_np(i));
}


bool find_err_by_name(char* query) {
    bool found = false;
    size_t len = strlen(query);

    for (int i = 0; i <= 255; i++) {
        const char* errname = strerrorname_np(i);
        if (errname == NULL) continue;

        if (strncasecmp(errname, query, len) == 0) {
            found = true;
            print_errno_info(i);
        }
    }

    return found;
}


int main(int argc, char** argv) {
    // default (no args): List all error codes
    if (argc < 2) {
        for (int i = 0; i <= 255; i++) if (strerrorname_np(i))
            print_errno_info(i);
        return 0;
    }
    // wrong usage (someone tried to pass in a flag, or gave too many args)
    else if (argc > 2 || argv[1][0] == '-') {
        fprintf(stderr, "Usage: errno [ERRORID | ERRORNAME]\n");
        return 1;
    }
    // when query starts with e or E, find errors with names matching the query
    else if ((argv[1][0] | 32) == 'e') {
        if (!find_err_by_name(argv[1])) {
            fprintf(stderr, "\033[31mError with name '%s' not found\033[0m\n", argv[1]);
            return 1;
        }
        return 0;
    }
    // try to find error with numeric id
    else {
        int id;
        if (sscanf(argv[1], "%d", &id) != 1) {
            fprintf(stderr, "\033[31m'%s' is not a valid error id or name\033[0m\n", argv[1]);
            return 1;
        }
        if (!strerrorname_np(id)) {
            fprintf(stderr, "\033[31mError with id %d not found\033[0m\n", id);
            return 1;
        }
        print_errno_info(id);
        return 0;
    }
}
