#include <iostream>
#include "VectorFunctions.h"
#include "Vector2.h"
#include "Vector3.h"

int main()
{
    int width = 120;
    int height = 30;
    float aspect = (float)width / height;
    float pixelAspect = 11.0f / 24.0f;
    char gradient[] = " .:!/r(l1Z4H9W8$@";
    int gradientSize = std::size(gradient) - 2;

    char* screen = new char[width * height + 1];
    screen[width * height] = '\0';
    for (int t = 0; t <= 1000000; t++)
    {
        vector3 light = norm(vector3(sin(t * 0.01), cos(t * 0.01), -1.0));
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                vector2 uv = vector2(i, j) / vector2(width, height) * 2.0f - 1.0f;
                uv.x *= aspect * pixelAspect;
                vector3 ro = vector3(-2, 0, 0);
                vector3 rd = norm(vector3(1, uv));
                char pixel = ' ';
                int color = 0;
                vector2 intersection = sphere(ro, rd, 1);
                if (intersection.x > 0)
                {
                    vector3 itPoint = ro + rd * intersection.x;
                    vector3 n = norm(itPoint);
                    float diff = dot(n, light);
                    color = (int)(diff * 20);
                }
                color = clamp(color, 0, gradientSize);
                pixel = gradient[color];
                screen[i + j * width] = pixel;
            }
        }
        printf("%s", screen);
    }
}
