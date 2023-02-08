#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    //check for appropriate # of CLI
    if(argc != 2)
    {
        printf("Type in 2 command Line Arguments");
        return 1;
    }
    //open card file
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        fprintf(stderr, "There Was An Error Opening File");
        return 2;
    }

    unsigned char buffer[512];
    int picnum = 0;
    char file_name[8];
    FILE *picture;

    //repeat a while loop until end of card
    while(fread(buffer, 512, sizeof(char), fp))
    {
            //start of a new jpeg?
            //yes
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
               (buffer[3] == 0xe0 || buffer[3] == 0xe1 || buffer[3] == 0xe2
               || buffer[3] == 0xe3 || buffer[3] == 0xe4 || buffer[3] == 0xe5 || buffer[3] == 0xe6
               || buffer[3] == 0xe7 || buffer[3] == 0xe8 || buffer[3] == 0xe9 || buffer[3] == 0xea
               || buffer[3] == 0xeb || buffer[3] == 0xec || buffer[3] == 0xed || buffer[3] == 0xee
               || buffer[3] == 0xef))
        {
            //increment number of pictures
            picnum++;

            //already found a JPEG?
            //yes
            if(picnum > 1)
                {
                    //close current jpeg
                    fclose(picture);

                    //save new jpg name in a string
                    sprintf(file_name, "%.03i.jpg", picnum);

                    //open new jpg
                    picture = fopen(file_name, "w");

                    //write block to jpg
                    fwrite(buffer, 512, 1, picture);
                }

                //no
                else
                {
                    //save new jpg name in a string
                    sprintf(file_name, "%.03i.jpg", picnum);

                    //open new jpg
                    picture = fopen(file_name, "w");

                    //write block to jpg
                    fwrite(buffer, 512, 1, picture);
                }
            }

            //no...
            else
            {
                //already found a JPEG?
                if(picnum > 0)
                {
                    fwrite(buffer, 512, 1, picture);
                }
            }
        }

    //close any remaining files
    fclose(picture);
    fclose(fp);
}