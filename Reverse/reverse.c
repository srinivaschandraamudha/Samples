#include<stdio.h>
#include<string.h>

void display(char *str)
{
    printf("\n");
    for(int length = 0; str[length] != '\0'; length++)
		printf("%c", str[length]);
}

int len(char *str)
{
    int length = 0;
    for(; str[length] != '\0'; length++){}
    return length;
}

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

void insert(char *ip, char *op, char *word)
{
    int start_indx = len(ip) - len(op) - len(word);
    printf("\nDEBUG Y: start_indx = %d; ip_len = %d ; op_len = %d; word_len = %d \n", start_indx,len(ip),len(op),len(word));
    op[len(ip)] = '\0'; 
    if(start_indx - 1 > 0)
        op[start_indx - 1] = ' ';
    for(int i = 0; '\0' != word[i]; i++)
        op[start_indx + i] = word[i];
    printf("\nDEBUG X: %s\n", &op[0]);
}

void reverse(char *ip, char *op)
{
    int str_len = len(ip);
    int index =  str_len - 1;
    for(int i = index; i >= 0; i--)
    {
        op[index - i] = ip[i];
    }
}

void reverse_words(char *ip, char *op)
{
    printf("\nDEBUG X: reverse_words \n\n\n");
    char output1[64];
    char temp[16];
    char temp_out[16];
    int str_len = len(ip);
    int temp_index = 0;
    reverse(ip, &output1[0]);
    printf("\nDEBUG X: %s\n", &op[0]);
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
	//char input[64] = "This is a test";
    char input[] = "How is this possible";
    char output[64];
    
    display(&input[0]);
	reverse(&input[0], &output[0]);
    display(&output[0]);
    reverse_words(&input[0],&output[0]);
    display(&output[0]);
    
}