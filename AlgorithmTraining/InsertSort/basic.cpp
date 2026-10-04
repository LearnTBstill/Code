void insert(int arr[],int n){//交换
    int mid=0;
    for(int i=1;i<n;i++){
        int k=i;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[k]){
                mid=arr[k];
                arr[k]=arr[j];
                arr[j]=mid;
                k--;
            }
            else{
                break;
            }
        }
    }
}

void insert2(int arr[],int n){//移动   这个方法更高效
    int temp=0,j=0;
    for(int i=1;i<n;i++){
        temp=arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}