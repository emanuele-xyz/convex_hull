#pragma once

void ch_jarvis(int count, float* in, float* out);

#if defined(CONVEX_HULL_IMPLEMENTATION)
void ch_jarvis(int count, float* in, float* out)
{
    for (int i = 0; i < count; i++)
    {
        out[i] = in[i];
    }
}
#endif
