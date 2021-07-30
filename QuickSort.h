typedef struct Table T;

struct Table {
    double * first; // weight
    double * second; // profit
    double * third; // proift/weight
    double * fourth; // index
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
    case 3:
        return t->fourth;
        break;

    }
}

int Partition(struct Table *A, int startingIndex, int endingIndex, int row, int sortAsPerRow){
    // let take ending index as pivit
    double pivit = selector(A, sortAsPerRow)[endingIndex];
    int i = startingIndex-1;
    for(int j=startingIndex; j <= endingIndex-1; j++)
        if(selector(A, sortAsPerRow)[j]<=pivit){
            i++;
            for(int _=0; _<row;_++)
                swap(&selector(A, _)[i], &selector(A, _)[j]);
            }
    

    for(int _=0; _<row;_++)
        swap(&selector(A, _)[i+1], &selector(A, _)[endingIndex]);

    return i+1;
}

void QuickSort(struct Table *A, int startingIndex, int endingIndex, int row, int sortAsPerRow){
    if(startingIndex < endingIndex){
        int pivitIndex = Partition(A, startingIndex, endingIndex, row, sortAsPerRow);
        QuickSort(A, startingIndex, pivitIndex-1, row, sortAsPerRow);
        QuickSort(A, pivitIndex+1, endingIndex, row, sortAsPerRow);
    }
}
