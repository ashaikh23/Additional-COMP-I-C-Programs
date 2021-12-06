Boolean user_wishes_to_continue(void)
{
    char answer;
    printf("Do you wish to continue? (y/n) : ");
    scanf(" %c", &answer);
    clear_keyboard_buffer();
    while (answer != 'y' && answer != 'Y' &&
        answer != 'n' && answer != 'N')
    {
        printf("I'm sorry but I do not understand.\n");
        scanf(" %c", &answer);
        clear_keyboard_buffer();
    }

    return answer == 'y' || answer == 'Y';
}
