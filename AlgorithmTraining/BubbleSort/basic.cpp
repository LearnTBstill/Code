void bubble(int arr[],int n){
    int mid=0;
    for(int i=0;i<n-1;i++){
        bool flag=false;
        for(int j=n-1;j>i;j--){//j>i就好,j>0多余了
            if(arr[j]<arr[j-1]){
                mid=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=mid;
                flag =true;
            }
        }
        if(flag==false){
            return;
        }
    }
}