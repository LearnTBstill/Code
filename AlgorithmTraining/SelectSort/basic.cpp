void selectsort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int min=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int mid=arr[i];
            arr[i]=arr[min];//光赋值不行得交换
            arr[min]=mid;
        }
    }
}