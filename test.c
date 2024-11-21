#define CONVEX_HULL_IMPLEMENTATION
#include <convex_hull.h>

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* file = fopen("points.txt", "r"); // TODO: error handling
    char buf[1024] = {};

    int points_count = 0;
    if (fgets(buf, sizeof(buf), file) != NULL)
    {
        if (sscanf(buf, "%d\n", &points_count) == 1)
        {
            printf("points_count = %d\n", points_count);
        } 
        else 
        {
            // TODO: error handling
        }
    }
    else
    {
        // TODO: error handling
    }


    float* points = calloc(points_count, sizeof(*points));
    float* hull = calloc(points_count, sizeof(*hull));

    for (int i = 0; i < points_count; i++)
    {
        points[i] = (float)(i);
    }

    ch_jarvis(points_count, points, hull);

    for (int i = 0; i < points_count; i++)
    {
        printf("%f\n", hull[i]);
    }

    free(points);
    free(hull);

    return 0;
}
 