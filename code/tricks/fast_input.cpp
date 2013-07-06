void readn(register int *n) {
    int sign = 1;
    register char c;
    *n = 0;
    while((c = getc_unlocked(stdin)) != '\n') {
        switch(c) {
            case '-': sign = -1; break;
            case ' ': goto hell;
            case '\n': goto hell;
            default: *n *= 10; *n += c - '0'; break;
        }
    }
hell:
    *n *= sign;
}
