//
//  main.cpp
//  AK2_Lab3
//
//  Created by Katerina Kravchenko on 03.11.20.
//  Copyright © 2020 Katerina Kravchenko. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int main (int argc, char *argv[])
{
    int c;
    bool flag_a = false;
    bool flag_f = false;
    bool flag_h = false;
    bool flag_n = false;
    bool flag_v = false;
    char * file_name = "AK2_Lab3";
    double version = 1.0;
    
    while (1)
    {
        static struct option long_options[] =
        {
            {"author",     no_argument,       0, 'a'},
            {"help",       no_argument,       0, 'h'},
            {"file",    required_argument,    0, 'f'},
            {"name",       no_argument,       0, 'n'},
            {"version",    no_argument,       0, 'v'},
            {0, 0, 0, 0}
        };
        
        int option_index = 0;
        
        c = getopt_long (argc, argv, "ahnvf:",
                         long_options, &option_index);
        
        if (c == -1)
            break;
        
        switch (c)
        {
            case 0:
                if (long_options[option_index].flag != 0)
                    break;
                printf ("option %s", long_options[option_index].name);
                if (optarg)
                    printf (" with arg %s", optarg);
                printf ("\n");
                break;
                
            case 'a':
                if (!flag_a){
                    puts ("Author: Katerina Kravchenko");
                    flag_a = true;
                }
                break;
                
            case 'f': {
                if (!flag_f) {
                    file_name = optarg;
                    printf("File name changed to '%s' \n", optarg);
                    flag_f = true;
                }
                break;
            }
                
            case 'h':
                if (!flag_h){
                    puts ("Avaiable options:" \
                          "\n-a --author                       - project author" \
                          "\n-f<filename> --file=<filename>    - set file name" \
                          "\n-n --n                            - take file name" \
                          "\n-h --help                         - help" \
                          "\n-v --version                      - program's version");
                    flag_h = true;
                }
                break;
            
            case 'n':
                if (!flag_n){
                    printf("File name: %s\n",file_name);
                    flag_n = true;
                }
                break;
                
            case 'v':
                if (!flag_v){
                    printf("Version: %.2f\n", version);
                    flag_v = true;
                }
                break;
                
            case '?':
                break;
                
            default:
                abort ();
        }
    }
    
    return 0;
}
