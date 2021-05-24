#include <stdio.h>
#include <math.h>

struct Point
{
    double x;
    double y;
};


void koch(int n, struct Point p1, struct Point p2)
{
    if (n == 0)
    {
        return;
    }
    struct Point s, t, u;
    double th = M_PI * 60.0 / 180.0;  // 度からラジアンへ単位を変更
    // p1, p2 -> s, t, u
    s.x = (2.0*p1.x + 1.0*p2.x) / 3.0;
    s.y = (2.0*p1.y + 1.0*p2.y) / 3.0;
    t.x = (1.0*p1.x + 2.0*p2.x) / 3.0;
    t.y = (1.0*p1.y + 2.0*p2.y) / 3.0;
    /* 回転行列 */
    u.x = (t.x - s.x)*cos(th) - (t.y - s.y)*sin(th) + s.x;
    u.y = (t.x - s.x)*sin(th) + (t.y - s.y)*cos(th) + s.y;

    koch(n - 1, p1, s);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(n - 1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(n - 1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(n - 1, t, p2);
}

int main(void)
{
    struct Point p1, p2;
    int n;
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;
    scanf("%d", &n);
    printf("%.8f %.8f\n", p1.x, p1.y);
    koch(n, p1, p2);
    printf("%.8f %.8f\n", p2.x, p2.y);
    return 0;
}