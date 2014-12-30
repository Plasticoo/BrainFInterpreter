#include <stdio.h>
#include <string.h>

#define MAX 256

void brainfuck(char* bfstring)
{
        int bfarray[300000] = {0};
        int instruction_slot = 0;
        int data_slot = 0;
        int lloop = 0;

        while (instruction_slot < (int)strlen(bfstring))
        {
                int instruction_slot_next = 1;
                char slot_char = bfstring[instruction_slot];
                int data = bfarray[data_slot];

                switch (slot_char)
                {
                        case '>':
                                data_slot++;
                                break;
                        case '<':
                                data_slot--;
                                break;
                        case '+':
                                bfarray[data_slot]=(data+1)%MAX;
                                break;
                        case '-':
                                bfarray[data_slot]=(data-1)%MAX;
                                break;
                        case '.':
                                printf("%c", data);
                                break;
                        case ',':
                        {
                                char input = getchar();
                                bfarray[data_slot] = (int)input;
                                break;
                        }
                        case '[':
                        {
                                if (data == 0)
                                {
                                        instruction_slot_next = 0;
                                        lloop = 1;

                                        while (lloop>0)
                                        {
                                                instruction_slot++;
                                                slot_char = bfstring[instruction_slot];

                                                if (slot_char == '[') {lloop++;}
                                                if (slot_char == ']') {lloop--;}
                                        }
                                        instruction_slot++;
                                }
                                break;
                        }
                        case ']':
                        {
                                if (data != 0)
                                {
                                        instruction_slot_next = 0;
                                        lloop = 1;

                                        while (lloop>0)
                                        {
                                                instruction_slot--;
                                                slot_char = bfstring[instruction_slot];

                                                if (slot_char == '[') {lloop--;}
                                                if (slot_char == ']') {lloop++;}
                                        }
                                        instruction_slot++;
                                }
                                break;
                        }
                }

                if (instruction_slot_next)
                {
                        instruction_slot++;
                }
        }
}

int main()
{
        char* bfstr = "+++++++++++>+>>>>++++++++++++++++++++++++++++++++++++++++++++>++++++++++++++++++++++++++++++++<<<<<<[>[>>>>>>+>+<<<<<<<-]>>>>>>>[<<<<<<<+>>>>>>>-]<[>++++++++++[-<-[>>+>+<<<-]>>>[<<<+>>>-]+<[>[-]<[-]]>[<<[>>>+<<<-]>>[-]]<<]>>>[>>+>+<<<-]>>>[<<<+>>>-]+<[>[-]<[-]]>[<<+>>[-]]<<<<<<<]>>>>>[++++++++++++++++++++++++++++++++++++++++++++++++.[-]]++++++++++<[->-<]>++++++++++++++++++++++++++++++++++++++++++++++++.[-]<<<<<<<<<<<<[>>>+>+<<<<-]>>>>[<<<<+>>>>-]<-[>>.>.<<<[-]]<<[>>+>+<<<-]>>>[<<<+>>>-]<<[<+>-]>[<+>-]<<<-]";

        brainfuck(bfstr);putchar('\n');

        return 1;
}
