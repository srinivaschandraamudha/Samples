#include<stdio.h>
#include<string.h>

//display: Displays a given string till null termination.
//Args:
// ip: char pointer to input string to be displayed.
void display(char *str)
{
    printf("\n");
    for(int length = 0; str[length] != '\0'; length++)
		printf("%c", str[length]);
}

//display: Displays a given string till null termination.
//Args:
// ip: char pointer to input string to be displayed.
int len(char *str)
{
    int length = 0;
    for(; str[length] != '\0'; length++){}
    return length;
}

//extract: Extracts first word from a given string. Determines
// word once a space is encountered and stroes it in output char pointer.
//Args:
// ip: char pointer to input string where first word is extracted.
// word: char pointer to output where first word is stored.
void extract(char *ip, char *word)
{    
    int i = 0;
    for(; ip[i] != ' ' ; i++)
    {
        if('\0' != ip[i])
            word[i] = ip[i];
        else
            break;
    }
    word[i] = '\0';
}


//reverse_words: Reverses a given string.
//Args:
// ip: char pointer to input string.
// op: char pointer to output string.
void reverse(char *ip, char *op)
{
    int str_len = len(ip);
    int index =  str_len - 1;
    for(int i = index; i >= 0; i--)
    {
        op[index - i] = ip[i];
    }
}

//reverse_words: Reverses the order of words in a given string and outputs them in op pointer.
//Args:
// ip: char pointer to input string.
// op: char pointer to output string.    
void reverse_words(char *ip, char *op)
{
    char output1[64];
    char temp[16];
    char temp_out[16];
    int str_len = len(ip);
    int temp_index = 0;
    reverse(ip, &output1[0]);
    int k = 0;
    for(int i = 0; i < str_len; i++)
    {
        if(output1[i] == ' ')
        {
            temp[i] = '\0';
            memset(temp_out, 0, sizeof(temp_out));
            reverse(&temp[0], &temp_out[0]);
            for(int j = 0; j < len(&temp_out[0]); j++, k++)
                op[k] = temp_out[j];
            k++;
            op[k] = ' ';
            temp_index = 0;
            memset(temp, 0, sizeof(temp));
        }
        else
        {
            temp[temp_index] = output1[i];
            temp_index++;
            if(i == str_len - 1)
            {
                temp[i+1] = '\0';
                memset(temp_out, 0, sizeof(temp_out));
                reverse(&temp[0], &temp_out[0]);
                for(int j = 0; j < len(&temp_out[0]); j++, k++)
                    op[k] = temp_out[j];
                temp_index = 0;
                memset(temp, 0, sizeof(temp));
            }
        }
    }
    op[k+1] = '\0';
}

void main()
{
    char input[64] = "This is a test";
    
    char output[64];
    printf("\n\nOrginal input:");
    display(&input[0]);
    reverse(&input[0], &output[0]);
    printf("\n\nReversing orginal input:");
    display(&output[0]);
    reverse_words(&input[0],&output[0]);
    printf("\n\nReversing order of words in orginal input:");
    display(&output[0]);    
}