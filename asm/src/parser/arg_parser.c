/*
** EPITECH PROJECT, 2020
** arg_parser.c
** File description:
** arg_parser.c
*/

#include <stdlib.h>

char *arg_parser[16][11] = {
                {"%\0", NULL}, {"%r\0", "ir", NULL}, {"ri","rr", NULL},
                {"rrr", NULL}, {"rrr", NULL},
                {"rrr", "sr%r", "rir", "%rr", "%%r",
                "%ir", "irr", "i%r", "iir", NULL},
                {"rrr", "r%r", "rir", "%rr", "%%r", "%ir", "irr", "i%r",
                "iir", NULL},
                {"rrr", "r%r", "rir", "%rr", "%%r", "%ir", "irr", "i%r",
                "iir", NULL},
                {"r\0", NULL},
                {"r%r", "rrr", "%%r", "%rr", "i%r", "irr", NULL},
                {"rrr", "rr%", "r%r", "r%%", "rir", "ri%", NULL},
                {"%\0", NULL}, {"%r", "ir", NULL},
                {"rrr", "%rr", "%%r", "irr", "i%r", "i%%", NULL},
                {"%\0", NULL}, {"r\0", NULL}
};