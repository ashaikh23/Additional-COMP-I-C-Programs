char* read_string(FILE* fp, char buffer[], int size)
{
    //skip over leading blanks
    int noc;
    char c;
    int i = 0;
    noc = fscanf(fp, " %c", &c);
    if (noc != 1 || size < 2)
    {
        return NULL;
    }
    buffer[i] = c;
    i++;
    noc = fscanf(fp, "%c", &c);
    while (noc == 1 && !isspace(c) && i < size - 1)
    {
        buffer[i] = c;
        i++;
        noc = fscanf(fp, "%c", &c);
    }

    if (noc == 1)
    {
        ungetc(c, fp);
    }    
    buffer[i] = '\0';
    return buffer;
}
