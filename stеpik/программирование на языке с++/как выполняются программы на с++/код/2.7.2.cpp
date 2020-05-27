void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min = 0;
    int minn = m[0][0];
    for ( int i = 0; i != rows; i++ )
        for ( int j = 0; j != cols ; j++ )
            if ( m[i][j] < minn )
            {
                minn = m[i][j];
                min = i;
            }
    int *n = m[0];
    m[0] = m[min];
    m[min] = n;
}
