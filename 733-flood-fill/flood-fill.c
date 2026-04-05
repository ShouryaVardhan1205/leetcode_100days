void dfs(int** image, int m, int n, int x, int y, int original, int color) {
    // Boundary + color check
    if (x < 0 || y < 0 || x >= m || y >= n || image[x][y] != original)
        return;

    // Change color
    image[x][y] = color;

    // Explore 4 directions
    dfs(image, m, n, x + 1, y, original, color);
    dfs(image, m, n, x - 1, y, original, color);
    dfs(image, m, n, x, y + 1, original, color);
    dfs(image, m, n, x, y - 1, original, color);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int m = imageSize;
    int n = imageColSize[0];

    int original = image[sr][sc];

    // If color is same, no need to process
    if (original == color) {
        *returnSize = m;
        *returnColumnSizes = imageColSize;
        return image;
    }

    dfs(image, m, n, sr, sc, original, color);

    *returnSize = m;
    *returnColumnSizes = imageColSize;
    return image;
}