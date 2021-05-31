#include <stdio.h>
#include <string.h>

#define PRINT_HELP        1
#define WITH_LINE_NUMBERS 2

void print_file(FILE *fp, int opts) {
    int read;
    int line_number = 1;
    int print_flag = (opts & WITH_LINE_NUMBERS) == WITH_LINE_NUMBERS;
    while((read = fgetc(fp)) != -1) {
        if(print_flag) {
            printf("%6d  ", line_number);
            print_flag = 0;
        }
        putchar(read);
        if(read == '\n') {
            line_number++;
            print_flag = (opts & WITH_LINE_NUMBERS) == WITH_LINE_NUMBERS;;
        }
    }
}

void perform_each(char *file_name, int opts) {
    FILE *fp = // file_name を読み込み専用で開く処理を書いてください．
    if(fp == NULL) {
        perror(file_name);
        return;
    }
    print_file(fp, opts);
    fclose(fp);
}

int parse_options(int argc, char *argv[]) {
    int i = 0, opts = 0;
    for(i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-h") == 0){
            opts = opts | PRINT_HELP;
        }
        else if(strcmp(argv[i], "-n") == 0){
            opts = opts | WITH_LINE_NUMBERS;
        }
    }
    return opts;
}

void print_help() {
    printf("mycat [OPTIONS] [FILEs...]\n\
OPTIONS\n\
    -n    行番号を出力する．\n\
    -h    このメッセージを出力する．\n");
}

int perform_impl(int argc, char *argv[], int opts) {
    int i = 0;
    int accepted_file = 0;
    for(i = 1; i < argc; i++){
        if(*argv[i] == '-') {
            continue;
        }
        perform_each(argv[i], opts);
        accepted_file++;
    }
    if(accepted_file == 0) {
        print_file(stdin, opts);
    }
    return 0;
}

int perform(int argc, char *argv[]) {
    int opts = parse_options(argc, argv);
    if((opts & PRINT_HELP) == PRINT_HELP) {
        print_help();
        return 0;
    }
    return perform_impl(argc, argv, opts);
}

int main(int argc, char *argv[]) {
  int status = perform(argc, argv);
  return status;
}
