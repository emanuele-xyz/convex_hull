#define CONVEX_HULL_IMPLEMENTATION
#include <convex_hull.h>

#define _CRT_SECURE_NO_WARNINGS // NOTE: shut up Windows warning about unsafe calls to stdlib functions
#pragma warning( disable : 5045) // NOTE: shut up spectre mitigation warning

#include <stdio.h>
#include <stdlib.h>

#define POINTS_FILE "points.txt"

int main(void)
{
    // --------- resources ---------
    FILE* file = 0;
    int points_count = 0;
    int* points = 0;
    // -----------------------------
    
    file = fopen("points.txt", "rb");
    if (!file)
    {
        fprintf(stderr, "failed to open file '" POINTS_FILE "'\n");
        goto exit;
    }

    if (fscanf(file, "%d", &points_count) != 1)
    {
        fprintf(stderr, "failed to read number of points\n");
        goto exit;
    }

    points = calloc(points_count * 2, sizeof(*points));
    if (!points)
    {
        fprintf(stderr, "failed to callocate points data\n");
        goto exit;
    }

    for (int i = 0; i < points_count; i++)
    {
        int red_ints = fscanf(file, "%d %d", &points[i * 2 + 0], &points[i * 2 + 1]);
        if (red_ints != 2)
        {
            fprintf(stderr, "failed to read the %d-th point\n", i);
            goto exit;
        }
    }

    for (int i = 0; i < points_count; i++)
    {
        printf("%d %d\n", points[i * 2], points[i * 2 + 1]);
    }

exit:
    if (file) fclose(file);
    return 0;
}
 