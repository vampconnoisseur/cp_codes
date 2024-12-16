#include <iostream>
#include <vector>
using namespace std;

char getPreviousChar(char ch)
{
    if (ch == 'A')
        return 'Z';
    return ch - 1;
}

char getNextChar(char ch)
{
    if (ch == 'Z')
        return 'A';
    return ch + 1;
}

void rotateAntiClockwise(int r, int c, int s, int K, vector<vector<char>> &v)
{
    for (int k = 0; k < K; k++)
    {
        int top = r, left = c;
        int bottom = r + s - 1, right = c + s - 1;

        char firstVal = v[top][left];

        for (int i = left; i < right; i++)
        {
            v[top][i] = v[top][i + 1];
        }

        for (int i = top; i < bottom; i++)
        {
            v[i][right] = v[i + 1][right];
        }

        for (int i = right; i > left; i--)
        {
            v[bottom][i] = v[bottom][i - 1];
        }

        for (int i = bottom; i > top; i--)
        {
            v[i][left] = v[i - 1][left];
        }

        v[top + 1][left] = firstVal;
    }

    for (int i = r; i < r + s; i++)
    {
        for (int j = c; j < c + s; j++)
        {
            if (i == r || i == r + s - 1 || j == c || j == c + s - 1)
            {
                v[i][j] = getPreviousChar(v[i][j]);
            }
        }
    }
}

void rotateClockwise(int r, int c, int s, int K, vector<vector<char>> &v)
{
    for (int k = 0; k < K; k++)
    {
        int top = r, left = c;
        int bottom = r + s - 1, right = c + s - 1;

        char firstVal = v[top][left];

        for (int i = top; i < bottom; i++)
        {
            v[i][left] = v[i + 1][left];
        }

        for (int i = left; i < right; i++)
        {
            v[bottom][i] = v[bottom][i + 1];
        }

        for (int i = bottom; i > top; i--)
        {
            v[i][right] = v[i - 1][right];
        }

        for (int i = right; i > left; i--)
        {
            v[top][i] = v[top][i - 1];
        }

        v[top][left + 1] = firstVal;
    }

    for (int i = r; i < r + s; i++)
    {
        for (int j = c; j < c + s; j++)
        {
            if (i == r || i == r + s - 1 || j == c || j == c + s - 1)
            {
                v[i][j] = getNextChar(v[i][j]);
            }
        }
    }
}

void processQuery(int r, int c, int s, vector<vector<char>> &v)
{
    int numLayers = (s + 1) / 2;
    for (int layer = 1; layer <= numLayers; layer++)
    {
        int layerSize = s - (2 * (layer - 1));
        if (layerSize <= 0)
            break;

        if (layerSize == 1)
            continue;

        int layerR = r + (layer - 1);
        int layerC = c + (layer - 1);

        int K = layer;

        if (layer % 2 == 1)
        {
            rotateAntiClockwise(layerR, layerC, layerSize, K, v);
        }
        else
        {
            rotateClockwise(layerR, layerC, layerSize, K, v);
        }
    }
}

int main()
{
    int n, q;
    cin >> n;

    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    cin >> q;

    vector<vector<int>> que(q, vector<int>(3));
    for (int i = 0; i < q; i++)
    {
        cin >> que[i][0] >> que[i][1] >> que[i][2];
    }

    for (int i = 0; i < q; i++)
    {
        int r = que[i][0];
        int c = que[i][1];
        int s = que[i][2];

        processQuery(r, c, s, v);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j];
        }
    }

    return 0;
}