int strstr(const char* text, const char* pattern) {

    int estr = 0, epattern = 0, k = 0;

    for (int i = 0; i >= 0; i++) {
        if (text[i] == '\0') {
            estr = i;
            break;
        }
    }

    for (int i = 0; i >= 0; i++) {
        if (pattern[i] == '\0') {
            epattern = i;
            break;
        }
    }
    if (epattern == 0) return 0;

    if (epattern > estr) return -1;

    for (int i = 0; i < (estr - epattern + 1); i++) {
        k = 0;
        for (int j = 0; j < (epattern); j++) {
            if (text[i + j] == pattern[j]) k++;
            else break;
        }
        if (k == (epattern)) return i;
    }
    return -1;
}