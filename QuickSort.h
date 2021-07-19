typedef struct Table T;

struct Table {
    double * first;
    double * second;
    double * third;
};

void swap(double *x, double *y){
    double t = *x;
    *x = *y;
    *y = t;
}

double * selector(struct Table *t, int row){
    switch (row)
    {
    case 0:
        return t->first;
        break;
    case 1:
        return t->second;
        break;
    case 2:
        return t->third;
        break;

    }
}

int Partition(struct Table *A, int p, int r, int row, int base){
    double x = selector(A, base)[r];
    int i = p-1;
    for(int j=p;j<=r-1;j++)
        if(selector(A, base)[j]<=x){
            i++;
            for(int _=0; _<row;_++)
                swap(&selector(A, _)[i], &selector(A, _)[j]);
            }
    

    for(int _=0; _<row;_++)
        swap(&selector(A, _)[i+1], &selector(A, _)[r]);

    return i+1;
}

void QuickSort(struct Table *A, int p, int r, int row, int base){
    if(p<r){
        int q = Partition(A, p, r, row, base);
        QuickSort(A, p, q-1, row, base);
        QuickSort(A, q+1, r, row, base);
    }
}
