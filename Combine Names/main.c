char* combine_names(char first_name[], char last_name[], char full_name[], int size)
{
    int i = 0;
    int j = 0;
    while (first_name[i] != '\0' && i < size - 1)
    {
        full_name[i] = first_name[i];
        i++;
    }
    if (i < size - 1)

    {
        full_name[i] = ' ';
        i++;
    }

    while (last_name[j] != '\0' && i < size - 1)
    {
        full_name[i] = last_name[j];
        i++;
        j++;
    }
    full_name[i] = '\0';
    return full_name;
}
