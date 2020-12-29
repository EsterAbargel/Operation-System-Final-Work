


#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>

static int print_info(const char *fpath, const struct stat *sb, int tflags, struct FTW *ftwbuf)
{
    if (tflags == FTW_SL || tflags == FTW_SLN)
    {
        return 0;
    }
    printf("%c %ju %s\n", (tflags == FTW_D ? 'D' : 'F'), sb->st_ino, fpath + ftwbuf->base);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please provide path");
        return -1;
    }
    if (nftw(argv[1], print_info, 20, FTW_PHYS) == -1)
    {
        return -1;
    }
    return 0;
}
